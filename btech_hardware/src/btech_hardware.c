/*****************************************************************************
 *                                                                           *
 * Copyright (c) 2018 Bichler Technologies GmbH. All rights reserved.        *
 *                                                                           *
 * Software License Agreement ("SLA") Version 1.0                            *
 *                                                                           *
 * Unless explicitly acquired and licensed from Licensor under another       *
 * license, the contents of this file are subject to the Software License    *
 * Agreement ("SLA") Version 2.6, or subsequent versions as allowed by the   *
 * SLA, and You may not copy or use this file in either source code or       *
 * executable form, except in compliance with the terms and conditions of    *
 * the SLA.                                                                  *
 *                                                                           *
 * All software distributed under the SLA is provided strictly on an "AS     *
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,       *
 * AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT      *
 * LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR   *
 * PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific   *
 * language governing rights and limitations under the SLA.                  *
 *                                                                           *
 * The complete license agreement can be found here:                         *
 * http://bichler.tech/License/SLA/1.0/                                      *
 *                                                                           *
 * btech_hardware.c                                                          *
 *  Created on: Aug 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/
#include "btech_hardware.h"
#include "btech_iec_logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

/******************************************************************
 *
 * auto generated hardware configuration
 *
 ****************************************************************** */
static btech_iec_device **devices;
static int deviceCount = 0;
static btech_iec_hardwareTypes hardware;

// public defines
#define MANUFACTURER			"manufacturer"
#define DEVICETYPE 			"devicetype"
#define DEVICEPROPERTIES 	"deviceproperties"
#define MODULE			      "module"
#define END_DEVICE			"end_device"

int btech_addHardwareType() {
	return 0;
}

/**
 * remove newline at end of string
 * please do not insert strings with newline between any chars
 */
int btech_removeNewLine(char *str) {
	char *p;
	p = str;
	char delim = '\n';

	while (*p != 0) {
		if (*p == delim) {
			*p = 0;
			return 0;
		}
		p++;
	}

	return 0;
}

/**
 * returns a substring till the delimiter occurs,
 * the input string will be shortened
 */
char *btech_popStr(char **str, char delim) {

	int count = 0;
	char *p;
	char *pop;
	p = *str;

	while (**str != delim && **str != 0 && **str != '\n') {
		(*str)++;
		count++;
	}

	// remove last char
	(*str)++;

	pop = malloc(count + 1);
	if (pop != NULL)
	{
		memcpy(pop, p, count);
		pop[count] = 0;
	}
	return pop;
}

int btech_split(const char * str, char delim, char ***array, int *length) {
	char *p;
	char **res;
	int count = 0;
	int k = 0;

	p = (char *) str;
	// Count occurance of delim in string
	while ((p = strchr(p, delim)) != NULL) {
		*p = 0; // Null terminate the deliminator.
		p++; // Skip past our new null
		count++;
	}
	if (strlen(str) > count)
		count++;

	// allocate dynamic array
	res = calloc(1, count * sizeof(char *));
	if (!res)
		return -1;

	p = (char *) str;
	for (k = 0; k < count; k++) {
		if (*p)
			res[k] = p;  // Copy start of string
		p = strchr(p, 0);    // Look for next null
		p++; // Start of next string
	}

	*array = res;
	*length = count;

	return 0;
}

/**
 * read hardware configuration from filesystem
 */
int btech_readHardwareConfig(void) {
	FILE * fp;
	char * line = NULL;
	char * tmpline = NULL;
	size_t len = 0;

#if !defined(_WIN32)
	ssize_t read;
#else
	size_t read;
#endif
	btech_iec_device* device;
	btech_iec_device** newdevices;
	char *property = NULL;
	char *propvalue = NULL;

	fp = fopen("hardware", "r");
	if (fp == NULL) {
//		btech_iec_log_log(BTECH_IEC_LOG_ERROR, "btech_hardware.c", 149,
//				"No hardware configuration found!");
		// TODO show error led flashing
		return -1;
	}
	while ((read = getline(&line, &len, fp)) != -1) {
		if (!line)
			continue;
		tmpline = line;
		property = btech_popStr(&tmpline, '=');
		propvalue = btech_popStr(&tmpline, '\n');
		/* devicetype found? */
#if 1
		if (property == NULL || propvalue == NULL)
		{
			// TODO log message
			continue;
		}
		if (strstr(property, DEVICETYPE) != NULL) {
		}
		else if (strstr(property, DEVICETYPE) != NULL) {

			for (int i = 0; i < hardware.registerdHWTypesCnt; i++) {
				device = (*hardware.createDevice[i])(propvalue);
				if (device) {
					// add device to devicelist
					deviceCount++;
					if (deviceCount == 1)
					{
						devices = malloc(sizeof(btech_iec_device*));
						if (devices == NULL)
						{
							// TODO log instantiation problem
							break;
						}
					}
					else
					{
						newdevices = realloc(devices,
							sizeof(btech_iec_device*) * deviceCount);
						if (newdevices == NULL)
						{
							// TODO log instantiation problem
							break;
						}
						devices = newdevices;
					}
					// add device to devices
					devices[deviceCount - 1] = device;
					break;
				}
			}

		} else if (strstr(property, DEVICEPROPERTIES) != NULL) {
			if (device != NULL)
				device->btech_setprops(propvalue, device);
		} else if (strstr(property, MODULE) != NULL) {
			if (device != NULL)
				device->btech_setmodule(propvalue, device);
		} else if (strstr(property, END_DEVICE) != NULL) {
			device->btech_finishCreate(device);
			device = NULL;
		}
#endif
// 		send properties to device to generate a new one
		if (property)
			free(property);
		if (propvalue)
			free(propvalue);
		if (line) {
			free(line);
			line = NULL;
		}
	}
	fclose(fp);

	return 1;
}

/**
 * register hardware type creation to hardware management
 */
int btech_registerHardware(
		btech_iec_device * (*btech_create_device)(const char* config)) {
	void* newdevices = NULL;
#if 1
	
	if (hardware.registerdHWTypesCnt == 0)
	{
		hardware.createDevice = malloc(sizeof(hardware.createDevice));
		if (hardware.createDevice == NULL)
		{
			return -1;
		}
	}
	else
	{
		newdevices = realloc(hardware.createDevice,
			sizeof(hardware.createDevice));
		if (newdevices == NULL)
		{
			return 0;
		}
		hardware.createDevice = newdevices;
	}
	hardware.registerdHWTypesCnt++;
	hardware.createDevice[hardware.registerdHWTypesCnt - 1] = btech_create_device;
#endif
	return 1;
}

// -----------------------------------------------------------------------------------
// read all hardware inputs, if not possible, so we can not work correctly
// -----------------------------------------------------------------------------------
int btech_readHardwareInputs() {

	for (int i = 0; i < deviceCount; i++) {
		if (devices[i]->connection_state < 0)
			devices[i]->btech_connect(devices[i]);
//			btech_ur20_connect(&devices[i]);
		// check connection state once again
		if (devices[i]->connection_state < 0) {
			// TODO error stop program working, indicate hardware error
			return -1;
		}
		devices[i]->btech_read(devices[i]);			// performs a read request on the defined hardware module
	}
	return 0;
}

// -----------------------------------
// write all hardware outputs
// -----------------------------------
int btech_writeHardwareOutputs() {
	for (int i = 0; i < deviceCount; i++) {
		if (devices[i]->connection_state < 0)
			devices[i]->btech_connect(devices[i]);
//		if (devices[i].sockfd < 0)
//			btech_ur20_connect(&devices[i]);

		if (devices[i]->connection_state < 0) {
			// TODO error stop program working, indicate hardware error
			return -1;
		}
		devices[i]->btech_write(devices[i]);		// performs a write call to the defined hardware module

	}
	return 0;
}
