/*
 * Comet_UA_Software_Client.cpp
 *
 *  Created on: Oct 29, 2012
 *      Author: hannes
 */

#include "btech_iec_client.h"

#include <string.h>
#include <stdlib.h>

extern int btech_iec_softplc_variables_clear(iec_softplc_variables* vars) {}

int btech_out_message_initialize(btech_out_message *message)
{
	if(message == NULL)
	{
		return -1;
	}

	message->byte = NULL;
	message->bytecount = 0;
	message->nextMessage = NULL;
	message->prevMessage = NULL;
	return 1;
}

int btech_out_message_clear(btech_out_message *message)
{
	if(message == NULL)
	{
		return -1;
	}

	free(message->byte);
	message->bytecount = 0;
	message->nextMessage = NULL;
	message->prevMessage = NULL;
	return 1;
}

int btech_client_initialize(btech_client *client)
{
	if(client == NULL)
	{
		return -1;
	}

	memset(client->buffer, '0', sizeof(client->buffer));
	client->readcount = 0;
	client->prevClient = NULL;
	client->nextClient = NULL;
	client->outmessages = NULL;
	client->socket = -1;
	client->generalQuery = -1;
	client->registeredVars = NULL;

	return 1;
}

int btech_client_clear(btech_client *client)
{
#ifdef DEBUG_RUNTIME
	printf("clean up all memory for client!\n");
#endif
	if(client == NULL)
	{
		return -1;
	}

	btech_out_message *message = client->outmessages;
	btech_out_message *tmpmessage;

	client->nextClient = NULL;
	client->prevClient = NULL;

	btech_iec_softplc_variables_clear(client->registeredVars);
	btech_iec_softplc_variables_clear(client->backupVars);

	client->readcount = 0;

	if(message != NULL)
	{
		while(message->nextMessage != NULL)
		{
			message = message->nextMessage;
		}
	}


	if(message != NULL)
	{
		tmpmessage = message;
		message = message->prevMessage;

		btech_out_message_clear(tmpmessage);
		free(tmpmessage);
	}

	client->generalQuery = -1;

	return 1;
}
