/*
 * Comet_UA_Software_Client.h
 *
 *  Created on: Oct 29, 2012
 *      Author: hannes
 */

#ifndef BTECH_CLIENT_H_
#define BTECH_CLIENT_H_

#if !defined(_WIN32)
#include <netinet/in.h>
#else
#include <winsock.h>
#endif
#include <stdio.h>
#include "btech_iec_datapoints.h"

//#include "btech_iec_datapoints.h"

typedef struct btech_client_ btech_client;
typedef struct btech_out_message_ btech_out_message;

struct btech_out_message_
{
	int bytecount;
	char *byte;
	// pointer to next message
	btech_out_message *prevMessage;
	btech_out_message *nextMessage;
};

int btech_out_message_initialize(btech_out_message *message);
int btech_out_message_clear(btech_out_message *message);

struct btech_client_
{
	int socket;
	char buffer[1024];
	int readcount;

	// linked list with all outg
	btech_out_message *outmessages;
	btech_out_message *lastoutmessages;

	// reference to original variables
	iec_softplc_variables *registeredVars;

	// reference to backup variables
	// for each write to client call
	// we need to copy variables
	iec_softplc_variables *backupVars;

	btech_client *prevClient;
	btech_client *nextClient;

	int generalQuery;
	struct sockaddr_in addr;
	long int lastmessagetime;
};

int btech_client_initialize(btech_client *client);
int btech_client_clear(btech_client *client);

#endif /* BTECH_CLIENT_H_ */
