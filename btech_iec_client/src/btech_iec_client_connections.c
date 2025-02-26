/*
 * comet_ua_client_soft_connections.c
 *
 *  Created on: Feb 9, 2013
 *      Author: hannes bichler
 */

#include "btech_iec_client_connections.h"
#include "btech_iec_memory_mapper.h"

//#define DEBUG_RUNTIME_WRITESINGLE 1
//#define DEBUG_RUNTIME_TRANSIDHAND 1
#define DEBUG_RUNTIME_SOFTCLIENTWRITE 1

//extern SOCKET socket(int af, int type, int protocol) {}

btech_memory g_internalMemory;

void *btech_client_connections(void *threadid)
{
	btech_createSofwareIO();
	while (1)
	{
		btech_readSoftwareInputs_v1_0_0();
		btech_writeSoftwareOutputs();
		// always wait 500 msec after each iteration
		usleep(100000);
	}
	return (0);
}

// ------------------------------------
extern int btech_startClientConnections()
{
	//pthread_t thread;
	long t;
	//pthread_create(&thread, NULL, btech_client_connections, (void *) &t);
	return 1;
}

int btech_createSofwareIO()
{
	struct sockaddr_in tcpservaddr;
	struct sockaddr_in dbgservaddr;
	struct sockaddr_in udpservaddr;
	u_long iMode = 1;

#ifdef DEBUG_INITIALISE
	printf("try to create tcp socket on port:%i!\n", TCPPortNumber);
#endif

	// create tcp socket object
	tcpsock = socket(AF_INET, SOCK_STREAM, 0);

	// create runtime socket
	if (tcpsock < 0)
		printf("Error: (%i) open tcp socket!\n", errno);
	else
	{
		// set non blocking read
#if !defined(_WIN32)
		fcntl(tcpsock, F_SETFL, O_NONBLOCK);
#else
		ioctlsocket(tcpsock, FIONBIO, &iMode);
#endif
		// initialize servaddr structure
		memset(&tcpservaddr, '0', sizeof(tcpservaddr));
//		bzero((char *)&servaddr, sizeof(servaddr));

		tcpservaddr.sin_port = htons(TCPPortNumber);
		tcpservaddr.sin_family = AF_INET;
		tcpservaddr.sin_addr.s_addr = htons(INADDR_ANY);

		// bind socket to any address
		bind(tcpsock, (struct sockaddr*) &tcpservaddr, sizeof(tcpservaddr));

		// listen for incoming client connections
		listen(tcpsock, 64);
	}

#ifdef DEBUG_INITIALISE
	printf("try to create udp socket on port:%i!\n", UDPPortNumber);
#endif
	udpsock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	// create udp runtime socket
	if (udpsock < 0)
		printf("Error udp opening socket!\n");
	else
	{
		// set non blocking read
#if !defined(_WIN32)
		fcntl(udpsock, F_SETFL, O_NONBLOCK);
#else
		ioctlsocket(udpsock, FIONBIO, &iMode);
#endif
		// initialize servaddr structure
		memset(&udpservaddr, '0', sizeof(udpservaddr));
		//		bzero((char *)&servaddr, sizeof(servaddr));

		udpservaddr.sin_port = htons(UDPPortNumber);
		udpservaddr.sin_family = AF_INET;
		udpservaddr.sin_addr.s_addr = htons(INADDR_ANY);

		// bind socket to any address
		bind(udpsock, (struct sockaddr*) &udpservaddr, sizeof(udpservaddr));

	}

#ifdef DEBUG_INITIALISE
	printf("try to create debug socket on port:%i!\n", DebugPortNumber);
#endif
	// create debug socket
	debugsock = socket(AF_INET, SOCK_STREAM, 0);

	if (debugsock < 0)
		printf("Error opening debug socket!\n");
	else
	{
		// set non blocking read
#if !defined(_WIN32)
		fcntl(debugsock, F_SETFL, O_NONBLOCK);
#else
		ioctlsocket(debugsock, FIONBIO, &iMode);
#endif
		// initialize servaddr structure
		memset(&dbgservaddr, '0', sizeof(dbgservaddr));
		//		bzero((char *)&servaddr, sizeof(servaddr));

		dbgservaddr.sin_port = htons(DebugPortNumber);
		dbgservaddr.sin_family = AF_INET;
		dbgservaddr.sin_addr.s_addr = htons(INADDR_ANY);

		// bind socket to any address
		bind(debugsock, (struct sockaddr*) &dbgservaddr, sizeof(dbgservaddr));

		// listen for incoming client connections
		listen(debugsock, 64);
	}
	return 0;
}

// --------------------------------------------------
// v1_0_0 only supports a simple protocol
// without any checks for protocol correctness
// --------------------------------------------------
int btech_readSoftwareInputs_v1_0_0()
{
	int s = -1;
	char buffer[256];
	int ii;
	struct sockaddr_in udpclientAddr;
	u_long iMode = 1;
	socklen_t len;
	char mesg[1024];
	int udpClientFound = 0;

	btech_client *client;
	//vector<Comet_UA_Software_Client>::iterator cit;

#ifdef DEBUG_RUNTIME
	printf("read udp software clients!\n");
#endif
	/**
	 * 			try to get message from upd client
	 */
	memset(&buffer, '0', sizeof(buffer));
	recvfrom(udpsock, mesg, 1024, 0, (struct sockaddr *) &udpclientAddr, &len);
	if (len > 0)
	{
		// we got a new message
		// now try to find the correct client
		client = udpsoftclients;
		while (client != NULL)
		{
			if (client->addr.sin_port == udpclientAddr.sin_port
					&& client->addr.sin_addr.s_addr == udpclientAddr.sin_addr.s_addr)
			{
				udpClientFound = 1;
				// set message time to client
				time((time_t*) &client->lastmessagetime);
				break;
			}
			client = client->nextClient;
		}
		if (!udpClientFound)
		{
			// we couldn't find the right client so we need to create a new one
			client = malloc(sizeof(btech_client));// = new Comet_UA_Software_Client();
			btech_client_initialize(client);
			client->addr.sin_port = udpclientAddr.sin_port;
			client->addr.sin_addr.s_addr = udpclientAddr.sin_addr.s_addr;
			client->addr.sin_family = udpclientAddr.sin_family;
			time((time_t*) &client->lastmessagetime);

			clock();
			if (udpsoftclients == NULL)
			{
				udpsoftclients = client;
				udpsoftclientstail = client;
			}
			else
			{
				client->prevClient = udpsoftclientstail;
				udpsoftclientstail->nextClient = client;
				udpsoftclientstail = client;
			}
		}
	}

#ifdef DEBUG_RUNTIME
	printf("get new software-client from tcp-port!\n");
#endif
	// first try to get new incoming client connection
	s = accept(tcpsock, (struct sockaddr*) NULL, NULL);
	// cout << "new run\n";
	if (s > -1)
	{
		// set client socket non blocking
#if !defined(_WIN32)
		fcntl(s, F_SETFL, O_NONBLOCK);
#else
		ioctlsocket(s, FIONBIO, &iMode);
#endif
		client = malloc(sizeof(btech_client));	// = new Comet_UA_Software_Client();
		btech_client_initialize(client);
		client->socket = s;

		if (tcpsoftclients == NULL)
		{
			tcpsoftclients = client;
			tcpsoftclientstail = client;
		}
		else
		{
			client->prevClient = tcpsoftclientstail;
			tcpsoftclientstail->nextClient = client;
			tcpsoftclientstail = client;
		}
	}

#ifdef DEBUG_RUNTIME
	printf("read tcp software clients!\n");
#endif
	client = tcpsoftclients;
//	for(int i = 0; i < softclients.size(); i++)
	while (client != NULL)
	{

		memset(&buffer, '0', sizeof(buffer));
		// try read from new client
		int r = recv(client->socket, buffer, sizeof(buffer), 0);
		if (r > 0)
		{
			if (r > 0)
			{
				// we get now data from client
				memcpy(client->buffer + client->readcount, buffer, r);

#ifdef DEBUG_RUNTIME
				printf("read %i bytes!\n", r);
#endif
				// add data count to new data
				client->readcount += r;
			}
		}
		else if (r == 0 || (r == -1 && errno != EAGAIN))
		{
			//
			if (tcpsoftclients == client && tcpsoftclients == tcpsoftclientstail)
			{
				// we have only one connected client
				btech_client_clear(tcpsoftclients);
				free(client);
				client = NULL;
				tcpsoftclients = NULL;
				tcpsoftclientstail = NULL;
				continue;
			}
			else if (tcpsoftclients == client)
			{
				// we have more then one clients connected
				// and the client to remove is the first client
				tcpsoftclients = tcpsoftclients->nextClient;
				tcpsoftclients->prevClient = NULL;
				btech_client_clear(client);
				free(client);
				client = tcpsoftclients;
				continue;
			}
			else
			{
				if (client == tcpsoftclientstail)
				{
					// the client to delete is the last client
					tcpsoftclientstail = client->prevClient;
					tcpsoftclientstail->nextClient = NULL;
					btech_client_clear(client);
					free(client);
					client = NULL;
					continue;
				}
			}
		}

		// check if we have more than 2 bytes
		if (client->readcount > 2)
		{
#ifdef DEBUG_RUNTIME
			printf("client readcount: %i bytes!\n", client->readcount);
#endif
			// check if we have all data to parse the request
			// buffer[1] contains the message length without 2 bytes(command id, bytecount)
			int commandId = (int) client->buffer[0];
			int length = (int) client->buffer[1];
			//char status = client->buffer[2];

#ifdef DEBUG_RUNTIME
			printf("message length: %i bytes! Client read-count %i \n", length,
					client->readcount);
#endif
			// check if we have complete messages
			if (length + 3 <= client->readcount)
			{

				// change the new readcount without this message length
				client->readcount -= (length + 3);

				// copy the full message
				char *b = malloc(sizeof(char) * (length + 1));

				memcpy(b, client->buffer + 3, length);
				b[length] = 0;
#ifdef DEBUG_RUNTIME
				printf("copy important data to message %i!\n", length);
#endif

				// now remove message from	 client
				memcpy(client->buffer, client->buffer + length + 3, client->readcount);

#ifdef DEBUG_RUNTIME
				printf("copy important data to message, command %i!\n", commandId);
#endif
				btech_out_message *message = malloc(sizeof(btech_out_message));
				btech_out_message_initialize(message);

#ifdef DEBUG_RUNTIME
				printf("initialize new message!\n");
#endif
				// check which commandId we got
				if (commandId == TRANSLATEIDTOHANDLEREQUEST)
				{
#ifdef DEBUG_RUNTIME_TRANSIDHAND
					printf("translate id to handle request for %s found!\n", b);
#endif
					// we have a varid2handle command
					iec_datapoint *dp;

#ifdef DEBUG_RUNTIME_TRANSIDHAND
					printf("actual var index: %i !\n", g_internalMemory.actvarindex);
#endif
					for (ii = 0; ii < g_internalMemory.actvarindex; ii++)
					{
						dp = g_internalMemory.vars.varMap[ii];
#ifdef DEBUG_RUNTIME_TRANSIDHAND
						printf("check var with index: %i name: %s!\n", ii, dp->varName);
#endif
						if (dp != NULL)
						{
							if (dp->varName != NULL)
							{
								if (strcmp(dp->varName, b) == 0)
								{
									break;
								}
								else
								{
									dp = NULL;
								}
							}
						}
					}

					// create a dummy error message
					message->byte = btech_createDummyMessage(7,
							TRANSLATEIDTOHANDLERESPONSE);
					btech_setmessagelength(message->byte, 4);
					btech_setstatusbyte(message->byte, -1);
					message->bytecount = 7;

					if (dp != NULL)
					{
						btech_setstatusbyte(message->byte, 0);
						btech_setmessagehandle(message->byte, dp->handle);
					}
				}
				else if (commandId == REGISTERHANDLEREQUEST)
				{
#ifdef DEBUG_RUNTIME_REGISTERHANDLE
					printf("register handle request found!\n");
#endif
					// we have a registerId command
					long handle = 0;

					for (ii = 0; ii < 3; ii++)
					{
						handle += ((int) b[ii] * 256);
					}

					handle += (int) b[3];

#ifdef DEBUG_RUNTIME_REGISTERHANDLE
					printf("register handle %i !\n", (int) handle);
#endif

					iec_datapoint *dp;
					// try to find variable by handle
					for (ii = 0; ii < g_internalMemory.actvarindex; ii++)
					{
						dp = g_internalMemory.vars.varMap[ii];
						if (dp != NULL)
						{
							if (dp->varName != NULL)
							{
								if (handle == dp->handle)
								{
									break;
								}
								else
								{
									dp = NULL;
								}
							}
						}
					}

#ifdef DEBUG_RUNTIME_REGISTERHANDLE
					printf("dp for handle %i found!\n", (int) handle);
#endif
					// create a dummy error message
					message->byte = btech_createDummyMessage(7, REGISTERHANDLERESPONSE);
					btech_setmessagelength(message->byte, 4);
					btech_setstatusbyte(message->byte, -1);
					message->bytecount = 7;

					if (dp != NULL)
					{
						if (client->registeredVars == NULL)
						{
							client->registeredVars = malloc(sizeof(iec_softplc_variables));
							btech_iec_softplc_variables_initialize(client->registeredVars);
							client->registeredVars->varMap = malloc(sizeof(iec_datapoint *));
							client->registeredVars->varMap[0] = dp;
							client->registeredVars->varMapCount = 1;
						}
						else
						{
							client->registeredVars->varMap = realloc(
									client->registeredVars->varMap,
									++client->registeredVars->varMapCount
											* sizeof(iec_datapoint*));
							client->registeredVars->varMap[client->registeredVars->varMapCount
									- 1] = dp;
						}

						btech_setstatusbyte(message->byte, 0);
						btech_setmessagehandle(message->byte, dp->handle);

#ifdef DEBUG_RUNTIME_REGISTERHANDLE
						printf("register handle response complete!\n");
#endif
					}
				}
				else if (commandId == UNREGISTERHANDLEREQUEST)
				{
#ifdef DEBUG_RUNTIME_UNREGISTERHANDLE
					printf("unregister handle request found!\n");
#endif
					// we have a unregisterId command
					long handle = 0;
					handle = (int) b[0];
					iec_datapoint *dp;

					for (ii = 0; ii < 3; ii++)
					{
						handle += ((int) b[ii] * 256);
					}

					handle += (int) b[3];

					if (client->registeredVars != NULL)
					{
						for (ii = 0; ii < client->registeredVars->varMapCount; ii++)
						{
							dp = client->registeredVars->varMap[ii];
							if (dp->handle == handle)
							{
								break;
							}
							else
							{
								dp = NULL;
							}
						}
					}

					btech_out_message *message = malloc(sizeof(btech_out_message));
					btech_out_message_initialize(message);

					// create a dummy error message
					message->byte = btech_createDummyMessage(7, UNREGISTERHANDLERESPONSE);
					btech_setmessagelength(message->byte, 5);
					btech_setstatusbyte(message->byte, -1);
					message->bytecount = 7;

					if (dp != NULL)
					{
						// increment pointer index to get the next datapoint pointer
						ii++;
						// now we remove dp from list
						for (; ii < client->registeredVars->varMapCount; ii++)
						{
							client->registeredVars->varMap[ii - 1] =
									client->registeredVars->varMap[ii];
						}
						client->registeredVars->varMapCount--;
						if (client->registeredVars->varMapCount == 0)
						{
							free(client->registeredVars->varMap);
							client->registeredVars->varMap = NULL;
						}
						else
						{
							client->registeredVars->varMap = realloc(
									client->registeredVars->varMap,
									client->registeredVars->varMapCount);
						}

						btech_setstatusbyte(message->byte, 0);
						btech_setmessagehandle(message->byte, dp->handle);
					}
				}
				else if (commandId == GENERALQUERYREQUEST)
				{
#ifdef DEBUG_RUNTIME_GENERALQUERY
					printf("general query request found!\n");
#endif
					// we have a general request command
					// so set the general query flag to client to publish all variables for that client

					client->generalQuery = 1;

					btech_out_message *message = malloc(sizeof(btech_out_message));
					btech_out_message_initialize(message);

					// create a dummy error message
					message->byte = btech_createDummyMessage(3, GENERALQUERYRESPONSE);
					btech_setmessagelength(message->byte, 1);
					btech_setstatusbyte(message->byte, 0);
					message->bytecount = 3;
				}
				else if (commandId == WRITESINGLEREQUEST)
				{
#ifdef DEBUG_RUNTIME_WRITESINGLE
					printf("write single request found!\n");
#endif

					// we have a write command
					long handle = 0;

					for (ii = 0; ii < 3; ii++)
					{
						handle += ((long) b[ii] * 256);
					}
					handle += (long) b[3];

					// try to find variable by handle
					iec_datapoint *dp;
					if (client->registeredVars != NULL)
					{
						for (ii = 0; ii < client->registeredVars->varMapCount; ii++)
						{
#ifdef DEBUG_RUNTIME_WRITESINGLE
							printf("look for variable count %i!\n", ii);
#endif
							if (client->registeredVars->varMap[ii]->handle == handle)
							{
								dp = client->registeredVars->varMap[ii];
								// now set value to variable
								dp->Transform2Internal(b + 4, dp);
								dp->dirty = 1;
								break;
							}
							else
							{
								dp = NULL;
							}
						}
					}
					else
					{
#ifdef DEBUG_RUNTIME_WRITESINGLE
						printf("no datapoint registered to write!\n");
#endif
					}
#ifdef DEBUG_RUNTIME_WRITESINGLE
					printf("create dummy error message for write single response!\n");
#endif
					// create a dummy error message
					message->byte = btech_createDummyMessage(7, WRITESINGLERESPONSE);
					btech_setmessagelength(message->byte, 4);
					btech_setstatusbyte(message->byte, -1);
					message->bytecount = 7;

					if (dp != NULL)
					{
						btech_setstatusbyte(message->byte, 0);
						btech_setmessagehandle(message->byte, dp->handle);
#ifdef DEBUG_RUNTIME_WRITESINGLE
						printf("set status byte to good for write single response!\n");
#endif
					}
				}
#ifdef DEBUG_RUNTIME
				printf("message passed!\n");
#endif
				free(b);

#ifdef DEBUG_RUNTIME
				printf("try to send message to client!\n");
#endif
				if (send(client->socket, message->byte, message->bytecount, 0) == -1)
				{
					// TODO remove client from list
					return -1;
				}
#ifdef DEBUG_RUNTIME
				printf("message sent successfully to client!\n");
#endif
				/**
				 if(client->outmessages == NULL)
				 {
				 client->outmessages = message;
				 }
				 if(client->lastoutmessages == NULL)
				 client->lastoutmessages = message;
				 else
				 client->lastoutmessages->nextMessage = message;
				 */
			}
		}

#ifdef DEBUG_RUNTIME
		printf("try to take next client!\n");
#endif
		client = client->nextClient;
#ifdef DEBUG_RUNTIME
		printf("next client found!\n");
#endif
	}

#ifdef DEBUG_RUNTIME
	printf("read loop ok!\n");
#endif
	return 0;
}

int btech_writeSoftwareOutputs()
{
	// for loop iterator
	int ii;
	btech_client *client = tcpsoftclients;
	btech_client *client2erase;
//#ifdef DEBUG_RUNTIME_SOFTCLIENTWRITE
//	printf("start write software output!\n");
//#endif
	while (client != NULL)
	{
		if (btech_writeSoftwareOutputsForClient(client) == 1)
		{
//#ifdef DEBUG_RUNTIME_SOFTCLIENTWRITE
//			printf("write was successfully!\n");
//#endif
			// client write was successfully
			client = client->nextClient;
		}
		else
		{
			// we couldn't write to client -> so we delete him
			client2erase = client;
			client = client->nextClient;

			if (client == tcpsoftclients && tcpsoftclients == tcpsoftclientstail)
			{
				tcpsoftclients = NULL;
				tcpsoftclientstail = NULL;
			}

			btech_client_clear(client2erase);
			free(client2erase);
			client2erase = NULL;
		}

	}

	if (g_internalMemory.vars.varMap != NULL)
	{
//#ifdef DEBUG_RUNTIME_SOFTCLIENTWRITE
//		printf("reset dirty flag of all variables!\n");
//#endif
		// set all variables to written
		for (ii = 0; ii < g_internalMemory.vars.varMapCount; ii++)
		{
			if (g_internalMemory.vars.varMap[ii] != NULL)
				g_internalMemory.vars.varMap[ii]->dirty = 0;
		}
	}
	return 0;
}

// -------------------------------------------------
// write all software outputs for a connected client
// -------------------------------------------------
int btech_writeSoftwareOutputsForClient(btech_client *client)
{
//#ifdef DEBUG_RUNTIME_SOFTCLIENTWRITE
//	printf("try to write message to client!\n");
//#endif
	int ii;

	// check all registered variables if it should	 be written to a client
	// add a timestamp to each value write message
	if (client != NULL && client->registeredVars != NULL)
	{
		// first copy all variable to backup map
		//for(ii = 0; ii < client->registeredVars->varMapCount; ii++)
		//{
		//	client->backupVars->varMap[ii]->dirty = client->registeredVars->varMap[ii]->dirty;
		//}
		// check if the general query bit for the client is set,
		// so we need to publish all registered variables for that client
		for (ii = 0; ii < client->registeredVars->varMapCount; ii++)
		{
#ifdef DEBUG_RUNTIME_SOFTCLIENTWRITE
			printf("is var to sent to client %i!\n",
					client->registeredVars->varMap[ii]->dirty);
#endif
			if ((client->registeredVars->varMap[ii]->dirty || client->generalQuery)
					&& client->generalQuery != -1)
			{
				long handle = client->registeredVars->varMap[ii]->handle;
				// create value message
				char *buffer = btech_createDummyMessage(
						3 + 4 + client->registeredVars->varMap[ii]->byteCount,
						WRITESINGLEREQUEST);
				btech_setmessagelength(buffer,
						4 + client->registeredVars->varMap[ii]->byteCount);
				btech_setstatusbyte(buffer, -1);
				btech_setmessagehandle(buffer, handle);

//				char *ret = buffer + 6;
				client->registeredVars->varMap[ii]->Transform2Wire(buffer + 7,
						client->registeredVars->varMap[ii]);

#ifdef DEBUG_RUNTIME_SOFTCLIENTWRITE
				printf("write message to client %s!\n", buffer);
#endif
				if (send(client->socket, buffer,
						7 + client->registeredVars->varMap[ii]->byteCount, 0) == -1)
				{
					free(buffer);
					// client has disconnected so we need to indicate to remove him
					return -1;
				}
				// now we have sent the message or the client is not alive so free memory
				free(buffer);
			}
		}
	}

	if (client->generalQuery != -1)
	{
		client->generalQuery = 0;
	}

	/**
	 comet_ua_out_message *out = client->outmessages;
	 comet_ua_out_message *tmpout = NULL;

	 while(out != NULL)
	 {
	 tmpout = out;
	 if(send(client->socket, out->byte, out->bytecount, 0) == -1)
	 {
	 return -1;
	 }

	 out = out->nextMessage;

	 // now free memory
	 comet_ua_out_message_clear(tmpout);
	 free(tmpout);
	 }

	 client->outmessages = NULL;
	 client->lastoutmessages = NULL;
	 */
	return 1;
}

int btech_writeDebugOutputs()
{
	int ii;
	int s;
	u_long iMode = 1;

	if (debugClient == NULL)
	{
		s = accept(debugsock, (struct sockaddr*) NULL, NULL);
		// cout << "new run\n";
		if (s > -1)
		{
			// set client socket non blocking
#if !defined(_WIN32)
			fcntl(s, F_SETFL, O_NONBLOCK);
#else
			ioctlsocket(s, FIONBIO, &iMode);
#endif
			debugClient = malloc(sizeof(btech_client)); //new Comet_UA_Software_Client();
			debugClient->socket = s;
			// cout << "debug client found!\n";
		}
		else
		{
			free(debugClient);
			debugClient = NULL;
		}
	}

	if (debugClient)
	{
		// now try to write all variable values
		// iterator for each variable
		//map<long, SoftPLCVariable>::iterator it;

		for (ii = 0; ii < g_internalMemory.vars.varMapCount; ii++)
		{
			// create value message
			char *buffer = malloc(
					2 + 4 + g_internalMemory.vars.varMap[ii]->byteCount * sizeof(char));
			buffer[0] = 10;
			buffer[1] = 2 + 4 + g_internalMemory.vars.varMap[ii]->byteCount;
			buffer[2] = -1;
			buffer[3] = 0;
			buffer[4] = 0;
			buffer[5] = 0;

			long handle = g_internalMemory.vars.varMap[ii]->handle;

			buffer[5] = handle % 256;
			buffer[4] = (handle / 256) % 256;
			buffer[3] = (handle / (256 * 256)) % 256;
			buffer[2] = (handle / (256 * 256 * 256)) % 256;

//			char *ret = buffer + 6;
			g_internalMemory.vars.varMap[ii]->Transform2Wire(buffer + 6,
					g_internalMemory.vars.varMap[ii]);

			if (send(debugClient->socket, buffer,
					2 + 6 + g_internalMemory.vars.varMap[ii]->byteCount, 0) == -1)
			{
				// client has disconnected so we need to remove him
				free(debugClient);
				debugClient = NULL;
				break;
			}
			// now we have sent the message or the client is not alive so free memory
			free(buffer);
		}
	}

	return 0;
}

// --------------------------------------------------------
// create an empty dummy message
// --------------------------------------------------------
char *btech_createDummyMessage(int length, int commandId)
{
	char *message;
	message = malloc(sizeof(char) * length);
	memset(message, 0, sizeof(char) * length);
	message[0] = commandId;
	return message;
}

int btech_setmessagelength(char *message, int length)
{
	message[1] = length;
	return 1;
}

int btech_setstatusbyte(char *message, int status)
{
	message[2] = status;
	return 1;
}

int btech_setmessagehandle(char *message, long handle)
{
	message[6] = handle % 256;
	message[5] = (handle / 256) % 256;
	message[4] = (handle / (256 * 256)) % 256;
	message[3] = (handle / (256 * 256 * 256)) % 256;
	return 1;
}

int btech_cleanUp(void)
{
	btech_client *client;

	while (tcpsoftclientstail != NULL)
	{
		client = tcpsoftclientstail;
		tcpsoftclientstail = tcpsoftclientstail->prevClient;
		if (client->socket > 0)
		{
			close(client->socket);
		}
		btech_client_clear(client);
		client = NULL;
	}

	// now close server socket
	close(tcpsock);

	return 1;
}
