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
 * btech_ur20_modbus_device.c                                                *
 *  Created on: 26.05.2017                                                   *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/
/*
 * ur20_modbus_device.h
 *
 *  Created on: 19.06.2017
 *      Author: hannes
 */

#ifndef INCLUDE_BTECH_UR20_MODBUS_DEVICE_H_
#define INCLUDE_BTECH_UR20_MODBUS_DEVICE_H_

#include "btech_hardware.h"
#include "btech_ur20_modules.h"

#define DIG_INPUT "0x00049FC2"

/**
 * struct for an u-remote modbus device, with all necessary properties
 */
typedef struct btech_ur20_modbus_device
{
	/* ip address or hostname of u-remote station */
	char *hostname;
	int portno;
	int digitalInCount;
	btech_ur20_module *inmodules;
	int digitalOutCount;
	btech_ur20_module *outmodules;
	int transID;
	/* filedescriptor to socket	 */
	int sockfd;

	char *readmessage;
} btech_ur20_modbus_device;

/**
 * register this uremote modebus hardware
 */
int btech_ur20_registerHardware(void);

/**
 * initialize an u-remote modbus device
 */
int btech_ur20_deviceInit(btech_ur20_modbus_device *device);

/**
 * connect to the u-remote coupler
 */
int btech_ur20_connect(btech_iec_device *device);

/**
 * create a read message for an u-remote modbus device
 */
int btech_ur20_create_read_messages(btech_ur20_modbus_device *devices, int deviceCount);

/**
 * create a read message for all input and output modules
 *
 * param modules all u-remote io modules
 * param count number of modules
 * param transactionid actual transaction id
 */
int btech_ur20_create_read_message(btech_ur20_modbus_device *device);

/**
 *
 */
int btech_ur20_read(btech_iec_device *device);

/**
 * write message to modebus
 */
int btech_ur20_write(btech_ur20_modbus_device *device, char *message);

/**
 * get a bit from an integer value
 */
int btech_ur20_get_bit(int n, int bit);

/**
 * set a bit to an integer value
 */
int btech_ur20_set_bit(int *number, int bit, int value);

/**
 *
 */
int btech_ur20_write_values(btech_iec_device * device);

#endif /* INCLUDE_BTECH_UR20_MODBUS_DEVICE_H_ */
