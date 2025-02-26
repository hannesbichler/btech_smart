/*
 * ur_modbus.c
 *
 *  Created on: 19.06.2017
 *      Author: hannes
 */

#include <btech_ur20_modbus_device.h>
#include <btech_ur20_modules.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if !defined(_WIN32)
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#else
#include <winsock.h>
#endif
#include <sys/types.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>

/** private defines */
#define BUFSIZE 1024
#define MODBUS_UR20_DEVICE "0x00000004"

extern char* btech_popStr(char** str, char delim) {}
extern int btech_registerHardware(
	btech_iec_device* (*btech_create_device)(const char* config)) {}
extern struct hostent FAR* PASCAL FAR gethostbyname(const char FAR* name) {}
extern SOCKET PASCAL FAR socket(int af, int type, int protocol) {}

int btech_ur20_setProperties(const char* config, btech_iec_device *device) {
	char *tmp;
	btech_ur20_modbus_device *dev = NULL;
	tmp = (char *) config;

	if (!config || !device)
		return -1;
	dev = (btech_ur20_modbus_device *) device->deviceinfo;

	if (!dev)
		return -1;

	dev->hostname = btech_popStr(&tmp, ';');
	dev->portno = atoi(btech_popStr(&tmp, '\n'));
	return 0;
}

int btech_ur20_finishCreate(btech_iec_device *device) {
	btech_ur20_create_read_message((btech_ur20_modbus_device*)device);
}

int btech_ur20_setModule(const char* config, btech_iec_device *device) {
	char *tmp;
	btech_ur20_modbus_device *dev = NULL;
	tmp = (char *) config;

	if (!config || !device)
		return -1;
	dev = (btech_ur20_modbus_device *) device->deviceinfo;

	if (!dev)
		return -1;

	if (strstr(config, DIG_INPUT) != NULL) {
		dev->digitalInCount++;
		if (dev->digitalInCount == 1)
			dev->inmodules = malloc(sizeof(btech_ur20_module));
		else
			dev->inmodules = realloc(dev->inmodules, sizeof(btech_ur20_module));
		// initialize input module
		btech_ur20_16di_p_module_initialize(&dev->inmodules[dev->digitalInCount -1]);
	} else if (strstr(config, DIG_INPUT) != NULL) {
		dev->digitalInCount++;
		if (dev->digitalInCount == 1)
			dev->inmodules = malloc(sizeof(btech_ur20_module));
		else
			dev->inmodules = realloc(dev->inmodules, sizeof(btech_ur20_module));
		// initialize input module
		btech_ur20_16di_p_module_initialize(&dev->inmodules[dev->digitalInCount -1]);
	}

	return 0;
}

btech_iec_device *btech_ur20_create(const char* config) {
	btech_iec_device *device = NULL;
	btech_ur20_modbus_device *dev = NULL;

	if (!config)
		return NULL;

	// now decode configuration string, if it is for me
	if (strcmp(config, MODBUS_UR20_DEVICE) == 0) {
		device = malloc(sizeof(btech_iec_device));
		if (device == NULL)
		{
			// TODO add log
			return NULL;
		}
		dev = malloc(sizeof(btech_ur20_modbus_device));
		if (dev == NULL)
		{
			// TODO add log
			return NULL;
		}
		// init device
		btech_ur20_deviceInit(dev);
		device->deviceinfo = dev;
		device->btech_setprops = btech_ur20_setProperties;
		device->btech_connect = btech_ur20_connect;
		device->btech_read = btech_ur20_read;
		device->btech_write = btech_ur20_write_values;
		device->btech_finishCreate = btech_ur20_finishCreate;
		device->connection_state = 0;
		return device;
	}
	return NULL;
}

int btech_ur20_registerHardware() {
	btech_registerHardware(btech_ur20_create);
	return 1;
}

int btech_ur20_deviceInit(btech_ur20_modbus_device *device) {
	if (!device)
		return -1;
	device->hostname = "localhost";
	device->portno = -1;
	device->transID = 0;
	device->digitalInCount = 0;
	device->digitalOutCount = 0;
	device->inmodules = NULL;
	device->outmodules = NULL;
	device->readmessage = NULL;
	return 1;
}

int btech_ur20_connect(btech_iec_device *dev) {
	btech_ur20_modbus_device *device;

#if !defined(_WIN32)
	struct sockaddr_in serveraddr;
	struct timeval tv;
	fd_set sdset;
	socklen_t len;
#else
#endif

	struct hostent *server;
	long arg;
	int timeout = 2000;
	int valopt;

	if (!dev) {
		return -1;
	}

	device = (btech_ur20_modbus_device *) dev->deviceinfo;
	/* socket: create the socket */
#if !defined(_WIN32)
	device->sockfd = socket(AF_INET, SOCK_STREAM, 0);
#else
	device->sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
#endif

	if (device->sockfd < 0) {
#ifdef DEBUG_ERROR
		perror("ERROR opening socket");
#endif
		return device->sockfd;
	}

	/* gethostbyname: get the server's DNS entry */
	server = gethostbyname(device->hostname);
	if (server == NULL) {
#ifdef DEBUG_ERROR
		fprintf(stderr, "ERROR, no such host as %s\n", device->hostname);
#endif
		return -1;
	}

	/* build the server's Internet address */
#if !defined(_WIN32)

	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	bcopy((char *) server->h_addr,
	(char *)&serveraddr.sin_addr.s_addr, server->h_length);
	serveraddr.sin_port = htons(device->portno);

	// Set socket to non-blocking
	arg = fcntl(device->sockfd, F_GETFL, NULL);
	arg |= O_NONBLOCK;
	fcntl(device->sockfd, F_SETFL, arg);
	// Connect with time limit

	if (connect(device->sockfd, (__CONST_SOCKADDR_ARG) &serveraddr,
			sizeof(serveraddr)) < 0) {
		if (errno == EINPROGRESS) {
			tv.tv_sec = 0;
			tv.tv_usec = timeout;
			FD_ZERO(&sdset);
			FD_SET(device->sockfd, &sdset);

			if (select(device->sockfd + 1, NULL, &sdset, NULL, &tv) > 0) {
				len = sizeof(int);
				getsockopt(device->sockfd, SOL_SOCKET, SO_ERROR,
						(void*) (&valopt), &len);
				if (valopt) {
#ifdef DEBUG_ERROR
					fprintf(stderr, "connect() error %d - %s\n", valopt,
							strerror(valopt));
#endif
					close(device->sockfd);
					device->sockfd = -1;
				}
				// connection established
//					result = 0;
			} else {
#ifdef DEBUG_ERROR
				fprintf(stderr, "connect() timed out\n");
#endif
				close(device->sockfd);
				device->sockfd = -1;
			}
		} else {
#ifdef DEBUG_ERROR

			fprintf(stderr, "connect() error %d - %s\n", errno, strerror(errno));
#endif
		}
	}
	arg = fcntl(device->sockfd, F_GETFL, NULL);
	arg &= (~O_NONBLOCK);
	fcntl(device->sockfd, F_SETFL, arg);
#else

#endif
	/* connect: create a connection with the server */
//	if (connect(device->sockfd, (__CONST_SOCKADDR_ARG) &serveraddr,
//			sizeof(serveraddr)) < 0)
//	{
//		perror("ERROR connecting");
//		close(device->sockfd);
//		device->sockfd = -1;
//	}
	return device->sockfd;
}

int btech_ur20_create_read_messages(btech_ur20_modbus_device *devices,
		int deviceCount) {
	/**
	 * create read message for each device
	 */
	for (int i = 0; i < deviceCount; i++) {

		btech_ur20_create_read_message(&devices[0]);
	}

	return 0;
}

int btech_ur20_create_read_message(btech_ur20_modbus_device *device) {
	// create length of read data
	int length = 0;
	char *message;
	size_t array_length = 12;

	/**
	 * create byte length to read
	 */
	for (int i = 0; i < device->digitalInCount; i++) {
		length += device->inmodules[i].byteCount;
	}

	message = malloc(array_length * sizeof(char));
	if (message == NULL)
	{
		// TODO add log
		return -1;
	}
	// first set header
	message[0] = (char) (device->transID / 256);	// transactionID_0
	message[1] = (char) (device->transID % 256);	// transactionID_1
	message[2] = 0;		// protocolID_0
	message[3] = 0;		// protocolID_1
	message[4] = 0;		// header length
	message[5] = 6;		// header length
	message[6] = 0;					// unitid

	message[7] = (char) 3;
	message[8] = (char) (0x0000 / 256);
	message[9] = (char) (0x0000 % 256);
	message[10] = (char) (length / 256);
	message[11] = (char) (length % 256);

	device->readmessage = message;
	return 0;
}

int btech_ur20_write(btech_ur20_modbus_device *device, char *message) {
	if (message == NULL) {
#ifdef DEBUG_ERROR
		perror("no message to write");
#endif
		return -1;
	}
	int n = 0;
	device->transID++;
	message[0] = (char) (device->transID / 256);	// transactionID_0
	message[1] = (char) (device->transID % 256);	// transactionID_1
	n = write(device->sockfd, message, 12);
	if (n < 0) {
#ifdef DEBUG_ERROR
		perror("ERROR writing to socket");
#endif
		close(device->sockfd);
		device->sockfd = -1;
	}
	return n;
}

int btech_ur20_read(btech_iec_device *dev) {
	btech_ur20_modbus_device *device;

	if (!dev)
		return -1;

	device = (btech_ur20_modbus_device *) dev->deviceinfo;

	if (!device)
		return -1;
	// sleep 100 milli to get the whole message
#if !defined(_WIN32)
	usleep(100);
#else
	Sleep(100);
#endif

	// values = malloc(32 * sizeof(iec_bool_datapoint));
	char buf[BUFSIZE];
	int n = 0;
	/* print the server's reply */
	memset(buf, 0, BUFSIZE);
	n = read(device->sockfd, buf, BUFSIZE);
	if (n < 0) {
#ifdef DEBUG_ERROR
		perror("ERROR reading from socket");
#endif
		close(device->sockfd);
		device->sockfd = -1;
		return 0;
	}

	/**
	 * transform all char data to module
	 */
	for (int i = 0; i < device->digitalInCount; i++) {
		device->inmodules[i].Transform2Internal(buf,
				device->inmodules[i].byteCount * i + 9, &device->inmodules[i]);
	}

	return 1;
}

/**
 * write values only to output modules
 */
int btech_ur20_write_values(btech_iec_device *dev) {
	btech_ur20_modbus_device *device;
	// create read message
	// create length of read data
	int n = 0;
	char *message;
	size_t array_length = 13;
	int bytecount = 0;
	char buf[BUFSIZE];

	if (!dev)
		return -1;

	device = (btech_ur20_modbus_device *) dev->deviceinfo;

	for (int i = 0; i < device->digitalOutCount; i++) {
		bytecount += device->outmodules[i].byteCount;
	}

	message = malloc((array_length + bytecount) * sizeof(char));
	if (message == NULL)
	{
		// TODO add log
		return -1;
	}
	device->transID++;
	// first set header
	message[0] = (char) (device->transID / 256);	// transactionID_0
	message[1] = (char) (device->transID % 256);	// transactionID_1
	message[2] = 0;		// protocolID_0
	message[3] = 0;		// protocolID_1
	message[4] = 0;		// header length
	message[5] = 7 + bytecount;		// header length
	message[6] = 5;					// unitid

	message[7] = (char) 16; /** function code Preset Multiple Registers */

	message[8] = (char) (0x0800 / 256); /** The Data Address of the first register */
	message[9] = (char) (0x0800 % 256); /** The Data Address of the first register */

	message[10] = (char) ((bytecount / 2) / 256); /** The number of registers to write */
	message[11] = (char) ((bytecount / 2) % 256); /** The number of registers to write */

	message[12] = (char) bytecount; /** The number of data bytes to follow */

	/**
	 * fill all modul values to write
	 */
	for (int i = 0; i < device->digitalOutCount; i++) {
		device->outmodules[i].Transform2Device(message,
				13 + i * device->outmodules[i].byteCount,
				&device->outmodules[i]);
	}

	n = write(device->sockfd, message, array_length + bytecount);
	free(message);
	if (n < 0) {
#ifdef DEBUG_ERROR
		perror("ERROR writing to socket");
#endif
		close(device->sockfd);
		device->sockfd = -1;
		return false;
	}
#if !defined(_WIN32)
	usleep(100);
#else
	Sleep(100);
#endif
	n = read(device->sockfd, buf, BUFSIZE);
	if (n < 0) {
#ifdef DEBUG_ERROR
		perror("ERROR reading from socket");
#endif
		close(device->sockfd);
		device->sockfd = -1;
		return false;
	}
	return 1;
}

int btech_ur20_get_bit(int n, int bit) {
	return ((n >> bit) & 1) == 1 ? true : false;
}

int btech_ur20_set_bit(int *number, int bit, int value) {
	*number ^= (-value ^ *number) & (1 << bit);
	return 0;
}
