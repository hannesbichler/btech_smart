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
 * btech_iec_runtime.c                                                       *
 *  Created on: May 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/

#include "btech_iec_runtime.h"
//#include "open62541.h"
#if !defined(_WIN32)
#include "pthread.h"
#endif
#include <errno.h>

extern int btech_readHardwareInputs(void) {}
extern int btech_writeHardwareOutputs(void) {}
extern int btech_initialize_func(void) {}
extern int btech_startClientConnections(void) {}

/**
 * flag to run the mainloop vorever
 * this variable can be changed from outside
 */
volatile int g_Run;

volatile int g_State;

/**
 * global structure with all tasks for running at a defined time
 */
iec_main_task g_IEC_Tasks[MAX_TASKS];

// global memory
btech_memory g_internalMemory;

void sigkill(int sig) {
	g_Run = BTECH_CPU_STATE_STOPPED;
}
/**
 * set main loop running off
 */
void sigstop(int sig) {
	g_State = BTECH_CPU_STATE_STOPPED;
}

/**
 * set main loop running on
 */
void btech_sigstart(int sig) {
	g_State = BTECH_CPU_STATE_STARTING;
}

//void btech_init() {
	/**
	 * initialize task structure
	 */
	//g_IEC_Main_Tasks = malloc(sizeof(iec_main_task));
//}

int btech_shutdown() {
	// free all memory

	// free all IOs
	return 0;
}

static void *btech_schedule_opcua_rt(void *arg) {

	return 0;
}

int main(int argc, char **argv) {
	/*pthread_t rt1;
	struct sched_param rtparam = { .sched_priority = 42 };
	pthread_attr_t rtattr;
	sigset_t set;
*/
	int opt = 0;

	btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "start runtime loop.");
	while ((opt = getopt(argc, argv, "i:r:e:")) != -1) {
		switch (opt) {
		case 'i':
//#define DEBUG_INITIALISE 0
			break;
		case 'r':
//#define DEBUG_RUNTIME 0
			break;
		case 'e':
//#define DEBUG_ERROR 0
			break;
		}
	}

	// initialize task count
	g_Akt_Taskcount = 0;
	// initialize task structure and hardware configuration
	//btech_init();

	// initialize opc ua server functions
	/*UA_Server *g_pServer;
	UA_ServerConfig *config = UA_ServerConfig_new_default();
	UA_ServerConfig_set_customHostname(config, UA_STRING("172.17.0.200"));
	// first create an opc ua server object
	g_pServer = UA_Server_new(config);

	//informationModelLoader("/hbs");
	UA_Server_run_startup(g_pServer);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGTERM);
	sigaddset(&set, SIGHUP);
	pthread_sigmask(SIG_BLOCK, &set, NULL);
	pthread_attr_init(&rtattr);
	pthread_attr_setdetachstate(&rtattr, PTHREAD_CREATE_JOINABLE);
	pthread_attr_setinheritsched(&rtattr, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedpolicy(&rtattr, SCHED_FIFO);
	pthread_attr_setschedparam(&rtattr, &rtparam);
	// start opc ua thread
	errno = pthread_create(&rt1, &rtattr, &btech_schedule_opcua_rt, NULL);

	if (errno)
		fail("pthread_create");
	*/
	btech_mainloop();
}

int btech_mainloop() {
	g_Run = BTECH_CPU_STATE_STARTING;
	signal(SIGINT, sigstop);
#if !defined(_WIN32)
	signal(SIGKILL, sigstop);
#else
	signal(SIGTERM, sigstop);
#endif

#ifdef DEBUG_INITIALISE
	btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "start runtime loop.");
#endif
	while (g_Run) {
		if (g_State == BTECH_CPU_STATE_STARTING) {
#ifdef DEBUG_INITIALISE
			btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "initialize all runtime variables");
#endif
			btech_initialize_func();

#ifdef DEBUG_INITIALISE
			btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "create communication with udp and tcp clients.");
#endif
			btech_startClientConnections();
		}

		if (g_State == BTECH_CPU_STATE_STARTING
				|| g_State == BTECH_CPU_STATE_RUNNING) {
			// read all inputs (hardware & softinput if priority succeeded)
#ifdef DEBUG_RUNTIME
			btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "read all hardware and bus inputs.");
#endif
			btech_readInputs();

			// execute soft plc functions
#ifdef DEBUG_RUNTIME
			btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "execute softplc behavior.");
#endif
			btech_schedule_func();

			// write all outputs (soft & hardware)
#ifdef DEBUG_RUNTIME
			btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "write all hardware and bus outputs.");
#endif
			btech_writeOutputs();

		}

		switch (g_State) {
		case BTECH_CPU_STATE_STARTING:	// if we have start finished

			g_State = BTECH_CPU_STATE_RUNNING;
			break;
		case BTECH_CPU_STATE_SHUTDOWN:
			btech_shutdown();
			g_State = BTECH_CPU_STATE_STOPPED;
			break;
		case BTECH_CPU_STATE_STOPPED:
			// do nothing
			usleep(TASK_TIME_100MIC);
			break;
		}
		// wait for next iteration
		usleep(TASK_TIME_1MIC);
	}

	// now try to close all sockets
	// cleanUp();

	return EXIT_SUCCESS;
}

/**
 * run the
 */
int btech_schedule_func() {
#if 0 // we change to only one task-function, but we have an array of task-functions
	if (g_IEC_Main_Task->Task_10mic) {
#ifdef DEBUG_RUNTIME
		// log start of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "start 10 mic task");
#endif
		g_IEC_Main_Task->Task_10mic();
#ifdef DEBUG_RUNTIME
		// log end of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "finish 10 mic task");
#endif
	}

	if (g_IEC_Main_Task->Task_100mic) {
#ifdef DEBUG_RUNTIME
		// log start of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "start 100 mic task");
#endif
		g_IEC_Main_Task->Task_100mic();
#ifdef DEBUG_RUNTIME
		// log end of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "finish 100 mic task");
#endif
	}
	if (g_IEC_Main_Task->Task_1mil) {
#ifdef DEBUG_RUNTIME
		// log end of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "start 1 mil task");
#endif
		g_IEC_Main_Task->Task_1mil();
#ifdef DEBUG_RUNTIME
		// log end of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "finish 1 mil task");
#endif
	}
	if (g_IEC_Main_Task->Task_10mil) {
#ifdef DEBUG_RUNTIME
		// log end of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "start 10 mil task");
#endif
		g_IEC_Main_Task->Task_10mil();
#ifdef DEBUG_RUNTIME
		// log end of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "finish 10 mil task");
#endif
	}
	if (g_IEC_Main_Task->Task_100mil) {
#ifdef DEBUG_RUNTIME
		// log end of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "start 100 mil task");
#endif

		g_IEC_Main_Task->Task_100mil();
#ifdef DEBUG_RUNTIME
		// log end of 10mic
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "finish 100 mil task");
#endif
	}
#else
	g_IEC_Tasks[0].taskTimeout;
#endif

	return 0;
}

int btech_initGeneralVariables(int varcount) {

	// first create memory for all variables for plc
	g_internalMemory.vars.varMap = malloc(varcount * sizeof(iec_datapoint*));
	g_internalMemory.vars.varMapCount = varcount;
	return 1;
}

int btech_appendGeneralVariable(iec_datapoint *dp, char *varName) {
	if (!g_internalMemory.vars.varMapCount) {
		g_internalMemory.vars.varMap = malloc(sizeof(iec_datapoint*));
	} else {
		g_internalMemory.vars.varMap =
				realloc(g_internalMemory.vars.varMap,
						(g_internalMemory.vars.varMapCount
								+ 1 * sizeof(iec_datapoint*)));
	}

	dp->handle = g_internalMemory.vars.varMapCount;
	dp->varName = malloc((strlen(varName) + 1) * sizeof(char));
	strcpy(dp->varName, varName);
	dp->varName[strlen(varName)] = 0;
	g_internalMemory.vars.varMap[g_internalMemory.vars.varMapCount] = dp;

	g_internalMemory.vars.varMapCount++;
	return 1;
}

int btech_addGeneralVariable(iec_datapoint *dp, char *varName) {
	dp->handle = g_internalMemory.actvarindex;
	// TODO check if the varname copy is OK
	dp->varName = malloc((strlen(varName) + 1) * sizeof(char));
	strcpy(dp->varName, varName);
	dp->varName[strlen(varName)] = 0;
	g_internalMemory.vars.varMap[g_internalMemory.actvarindex++] = dp;
	return 1;
}

/**
 * here we read all inputs of each underlying bus
 */
int btech_readInputs() {
	// read all hardware inputs
	btech_readHardwareInputs();
	return 0;
}

/**
 * here we write to all outputs of each underlying bus
 */
int btech_writeOutputs() {
	btech_writeHardwareOutputs();
	return 0;
}

