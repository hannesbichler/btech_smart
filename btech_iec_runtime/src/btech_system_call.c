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
 * btech_system_call.c                                                       *
 * internal system interface for all system calls with real time behavior    *
 *   Created on: 26.12.2018                                                   *
 *      Author: hannes bichler                                               *
 *                                                                           *
 *****************************************************************************/
/*
 * btech_system_call.c
 * internal system interface for all system calls with real time behavior
 *  Created on: 26.12.2018
 *      Author: hannes bichler
 */


/**
 * include files to load iec program at runtime
 */
#if !defined(_WIN32)
#include "dirent.h"
#include <dlfcn.h>
#endif
#include "btech_iec_runtime.h"

enum SYSCALLSTATE
{
	STATE_INIT = 0,
	STATE_FINISH = 999
} ;

/**
 * this funciton stops all running programs,
 * it is always required before we make a manipulation of the program structure
 */
int btech_StopCPU(void *a_pContext)
{
	return STATE_FINISH;
}

int btech_StartCPU(void *a_pContext)
{
	return STATE_FINISH;
}

int btech_AddVariable(void *a_pContext)
{
	return STATE_FINISH;
}

/**
 * add one task to existing task structure
 * param:
 */
int btech_AddTask(void *a_pContext)
{
	iec_main_task g_IEC_Tasks;
	if(g_Akt_Taskcount == MAX_TASKS)
	{
		btech_iec_log_log(BTECH_IEC_LOG_DEBUG, __FILE__, __LINE__, "To many tasks exist, %i.", g_Akt_Taskcount);
	}
	else
	{
		//g_IEC_Tasks[g_Akt_Taskcount] = NULL;
		g_Akt_Taskcount ++;
	}
	return STATE_FINISH;
}

int btech_AddFunction(void *a_pContext)
{
	return STATE_FINISH;
}

int btech_AddFunctionBlock(void *a_pContext)
{
	return STATE_FINISH;
}

/**
 * loads the defined iec program which is provided as a compiled .o file in a defined directory
 *
 */
int btech_IECLoader(char *a_pProgram, char *a_pFunction)
{
	void *g_Handle;
	int (*loadIECProg)();

#if !defined(_WIN32)
	g_Handle = dlopen(a_pProgram/*"./libbtech_iec_prog.so"*/, RTLD_LAZY);
	if(g_Handle)
	{
		*(void **)(&loadIECProg) = dlsym(g_Handle, a_pFunction/*"loadIEC"*/);
		dlclose(g_Handle);
	}
	else
	{
		// no
	}
#else
#endif

	return STATE_FINISH;
}
