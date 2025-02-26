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
 * btech_hardware.h                                                          *
 *  Created on: Aug 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/
#ifndef BTECH_HARDWARE_H_
#define BTECH_HARDWARE_H_

typedef struct btech_iec_device_ btech_iec_device;
struct btech_iec_hardwareTypes;

/*
 * define function pointers to communicate with hardware
 */
typedef int (*btech_connect_)(btech_iec_device *device);
typedef int (*btech_write_)(btech_iec_device *device);
typedef int (*btech_read_)(btech_iec_device *device);
typedef btech_iec_device *(*btech_create_device)(const char* config);
typedef int (*btech_setProperties)(const char* config, btech_iec_device *device);
typedef int (*btech_setModule)(const char* config, btech_iec_device *device);
typedef int (*btech_finishCreate_)(btech_iec_device *device);

int btech_registerHardware(
		btech_iec_device * (*btech_create_device)(const char* config));

/**
 * read hardware configuration from filesystem
 */
int btech_readHardwareConfig(void);
char *btech_popStr(char **str, char delim);
int btech_split(const char * str, char delim, char ***array, int *length);

/**
 * base device struct for each hardware device,
 * it can be an ip device or an io module,....
 */
struct btech_iec_device_ {
	void *deviceinfo;
	int connection_state;
	btech_setProperties btech_setprops;
	btech_setModule btech_setmodule;
	btech_connect_ btech_connect;
	btech_write_ btech_write;
	btech_read_ btech_read;
	btech_finishCreate_ btech_finishCreate;
};

typedef struct btech_iec_hardwareTypes {
	int registerdHWTypesCnt;
	btech_create_device *createDevice;
} btech_iec_hardwareTypes;

#endif /* BTECH_HARDWARE_H_ */
