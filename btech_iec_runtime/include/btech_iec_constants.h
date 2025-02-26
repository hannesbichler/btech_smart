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
 * btech_iec_constants.h                                                     *
 *  Created on: May 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/
#ifndef BTECH_IEC_CONSTANTS_H_
#define BTECH_IEC_CONSTANTS_H_

// timeout between each iteration
#define TASK_TIME_1MIC  1
#define TASK_TIME_10MIC  10
#define TASK_TIME_100MIC 100
#define TASK_TIME_1MIL   1000
#define TASK_TIME_10MIL  10000
#define TASK_TIME_100MIL 100000

/**
 * define maximum size of memory for the required controller
 */
#define BTECH_MAXMEMORY_SIZE_PLC_000 128
#define BTECH_MAXMEMORY_SIZE_PLC_0100 1024
#define BTECH_MAXMEMORY_SIZE_PLC_0200 2048
#define BTECH_MAXMEMORY_SIZE_PLC_0300 4096
#define BTECH_MAXMEMORY_SIZE_PLC_0400 10240
#define BTECH_MAXMEMORY_SIZE_PLC_1000 INT_MAX

/**
 * define possible cpu states
 */
#define BTECH_CPU_STATE_STOPPED  0				// cpu runs in stopped mode, no IO communication and program execution
#define BTECH_CPU_STATE_STARTING 1
#define BTECH_CPU_STATE_PROG     2
#define BTECH_CPU_STATE_RUNNING  3
#define BTECH_CPU_STATE_SHUTDOWN  4
#define BTECH_CPU_STATE_FAULT  5


/**
 * define internal memory sizes
 */
#define BTECH_MEMORY_SIZE_BYTE   1
#define BTECH_MEMORY_SIZE_INT    4
#define BTECH_MEMORY_SIZE_FLOAT  4
#define BTECH_MEMORY_SIZE_SHORT  2
#define BTECH_MEMORY_SIZE_CHAR   1
/**
 * management memory is used for plc status information
 */
#define BTECH_MAX_MANAGEMENT_MEMORY 256

#endif /* BTECH_IEC_CONSTANTS_H_ */
