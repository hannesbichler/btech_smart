/*
 * comet_ua_client_soft_connections.h
 *
 *  Created on: Feb 9, 2013
 *      Author: hannes
 */

#ifndef BTECH_CLIENT_CONNECTIONS_H_
#define BTECH_CLIENT_CONNECTIONS_H_

// all arm system headers
#if !defined(_WIN32)
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#else
#include <winsock2.h>
#include <ws2tcpip.h>
//#include <thread>
#endif
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>

#include "btech_iec_client.h"
//#include "btech_iec_memory_mapper.h"

// port number for tcp connection
// tcp connection should only be used for ethernet connections
#define TCPPortNumber 36666

// port number for udp connection
// udp connection should be used if connection is not stable
#define UDPPortNumber 37777

// debut port number
#define DebugPortNumber 37000

// tcp server socket file descriptor
int tcpsock;

// udp server socket file descriptor
int udpsock;

// debug server socket
int debugsock;

// ----------------------------------------------------------------------------
// all connected tcp software clients
// softclient --> softclient --> softclient --> softclienttail
// ----------------------------------------------------------------------------
btech_client *tcpsoftclients;

// ----------------------------------------------------------------------------
// the last connected tcp client
// ----------------------------------------------------------------------------
btech_client *tcpsoftclientstail;

// ----------------------------------------------------------------------------
// all connected udp software clients
// softclient --> softclient --> softclient --> softclienttail
// ----------------------------------------------------------------------------
btech_client *udpsoftclients;

// ----------------------------------------------------------------------------
// the last connected udp client
// ----------------------------------------------------------------------------
btech_client *udpsoftclientstail;

// ----------------------------------------------------------------------------
// connection to debug client
// only one client can be connected
// for debug at once
// ----------------------------------------------------------------------------
btech_client *debugClient;

// ----------------------------------------------------------------------------
// all request id to handle from client connnection
// ----------------------------------------------------------------------------
enum requests
{
	// translate a variable name to an internal long handle
	TRANSLATEIDTOHANDLEREQUEST = 1,
	// registers a variable via handle for notification after value changes
	REGISTERHANDLEREQUEST = 3,
	// unregisters a variable via handle
	UNREGISTERHANDLEREQUEST = 4,
	// a general query request, send all registers variables to the client
	GENERALQUERYREQUEST = 5,
	// a single write from or to a client
	WRITESINGLEREQUEST = 6,
	// a complex write from or to a client
	WRITECOMPLEXREQUEST = 7,
	// a single read from or to a client
	READSINGLEREQUEST = 8,
	// a complex read from or to a client
	READCOMPLEXREQUEST = 9
};

// ----------------------------------------------------------------------------
// all response id to handle from client connnection
// ----------------------------------------------------------------------------
enum responses
{
	// response with the long handle for a variable name
	TRANSLATEIDTOHANDLERESPONSE = 11,
	// response with success of handle registration
	REGISTERHANDLERESPONSE = 13,
	// response with success of unregister handle
	UNREGISTERHANDLERESPONSE,
	// response with success of general query
	GENERALQUERYRESPONSE,
	// response with success of simple write
	WRITESINGLERESPONSE,
	// response with success of complex write
	WRITECOMPLEXRESPONSE,
	// response with value of one variable
	READSINGLERESPONSE,
	// response with values of some variables
	READCOMPLEXRESPONSE
};

// ----------------------------------------------------------------------------
// all message status codes from client requests and responses
// ----------------------------------------------------------------------------
enum messagestatus
{
	// all right, no error found
	NONERROR = 0,
	//
	IDNOTFOUND,
	HANDLENORFOUND,
	WRITENOTPOSSIBLE,
	READNOTPOSSIBLE,
	MESSAGENOTCORRECT,
	CUSTOMERROR
};

// ----------------------------------------------------------------------------
// thread function, which handles all communication with any software clients
// over tcp and udp
// ----------------------------------------------------------------------------
void *btech_client_connections(void *threadid);

// ----------------------------------
// create all software IOs
// ----------------------------------
int btech_createSofwareIO();

// -------------------
// read from each udp or tcp client and decode messages
// -------------------
int btech_readSoftwareInputs_v1_0_0();

// ------------------------------
// write value changes to each client which has
//
int btech_writeSoftwareOutputs();

// -------------------------------------------------
// write all value changes for the connected client
// -------------------------------------------------
int btech_writeSoftwareOutputsForClient(btech_client *client);

// -------------------------------------------------
// write all values to the debug client
// -------------------------------------------------
int btech_writeDebugOutputs();

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
char *btech_createDummyMessage(int length, int commandId);

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
int btech_setmessagelength(char *message, int length);

int btech_setstatusbyte(char *message, int status);

int btech_setmessagehandle(char *message, long handle);

// -------------------------------------
// cleans all allocated memory for clients
// -------------------------------------
int btech_cleanUp(void);

#endif /* BTECH_CLIENT_CONNECTIONS_H_ */
