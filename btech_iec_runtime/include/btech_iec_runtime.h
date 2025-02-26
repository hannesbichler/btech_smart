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
 * btech_iec_runtime.h                                                       *
 *  Created on: May 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/

#ifndef BTECH_IEC_RUNTIME_H_
#define BTECH_IEC_RUNTIME_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <stdarg.h>
#if !defined(_WIN32)
#include <unistd.h>
#endif
#include <fcntl.h>
#include <limits.h>

#include "btech_iec_memory_mapper.h"
//#include "comet_ua_software_client.h"
//#include "comet_ua_client_soft_connections.h"
#include "btech_iec_constants.h"
#include "btech_iec_datapoints.h"
#include "btech_iec_program.h"
#include "btech_iec_constants.h"
#include "btech_iec_logger.h"


#define RUN_CLIENTCONN 1

/**
 * maximal 56 tasks per cpu are allowed
 */
#define MAX_TASKS 56

//typedef int (*task_10mic)();
//typedef int (*task_100mic)();
//typedef int (*task_1mil)();
//typedef int (*task_10mil)();
//typedef int (*task_100mil)();
//typedef int (*task_custom)();

typedef int (*taskFunc)();

typedef struct
{
	int taskID;
	char *taskName;
	long taskTimeout;
	long lastRun;
	int taskSize;
	int taskFunc;

//	int task_10mic_count;		// count of 10 mic seconds tasks
//	task_10mic Task_10mic;
//	int task_100mic_count;		// count of 100 mic seconds tasks
//	task_100mic Task_100mic;
//	int task_1mil_count;		// count of 1 mil seconds tasks
//	task_1mil Task_1mil;
//	int task_10mil_count;		// count of 10 mil seconds tasks
//	task_10mil Task_10mil;
//	int task_100mil_count;		// count of 100 mil seconds tasks
//	task_100mil Task_100mil;
//	int task_custom_count;		// count of custom mic seconds tasks
//	task_custom Task_Custom;
} iec_main_task;

int g_Akt_Taskcount;

extern iec_main_task g_IEC_Tasks[];

int Task_10mic();
int Task_100mic();
int Task_1mil();
int Task_10mil();
int Task_100mil();
int Task_Custom();

/**
 * global cpu state
 */
int g_BTech_CPU_State;// = BTECH_CPU_STATE_STOPPED;

/**
 * global pointer to memory start address
 */
char *g_Global_Start_Memory;// = 0;

/**
 * index to connect actual variable with memory
 */
int g_Global_Act_Var_Index;// = 0;

/**
 * set max memory size to global variable
 */
int g_MaxMemorySize;// = BTECH_MAXMEMORY_SIZE_PLC_000;

int btech_mainloop(void);

// -----------------------------------
// call all read functions
// read from hardware, bus,..
// -----------------------------------
int btech_readInputs();

// -----------------------------------
// read all hardware inputs
// -----------------------------------
//int btech_readHardwareInputs();

// -----------------------------------
// call all write functions
// write to hardware, bus,..
// -----------------------------------
int btech_writeOutputs();

// -----------------------------------
// write to hardware outputs
// -----------------------------------
//int btech_writeHardwareOutputs();

// -------------------------------------
// initialize array with all
// variables for this runtime
// -------------------------------------
int btech_initGeneralVariables(int varcount);

// -------------------------------------
// add iec variable to the end of general variables list
// -------------------------------------
int btech_appendGeneralVariable(iec_datapoint *dp, char *varName);

// -------------------------------------
// add iec variable to general variables list
// deprecated
// -------------------------------------
int btech_addGeneralVariable(iec_datapoint *dp, char *varName);

// -------------------------------------
// add a input variable to the general
// variable list and the input list
// -------------------------------------
int btech_addInputVariable(iec_datapoint *dp, char *varName, int pinNr, char *muxName,
		int muxMode);

#endif /* BTECH_IEC_RUNTIME_H_ */
