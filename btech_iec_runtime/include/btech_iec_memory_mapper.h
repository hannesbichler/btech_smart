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
 * btech_iec_memory_mapper.h                                                 *
 *  Created on: May 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/

#ifndef BTECH_IEC_MEMORY_MAPPER_H_
#define BTECH_IEC_MEMORY_MAPPER_H_

#include "btech_iec_datapoints.h"
#include <WinSock2.h>

typedef struct
{
	// --------------------------------
	// all variables in the system
	// --------------------------------
	iec_softplc_variables vars;

	// -------------------------------------------
	// actual index of last general variable
	// used to add a new variable
	// -------------------------------------------
	int actvarindex;

	// -------------------------------------------
	// actual index of last input variable
	// of hardware input
	// -------------------------------------------
//	int actinputindex;

	// -------------------------------------------
	// actual index of last output variable
	// of hardware output
	// -------------------------------------------
//	int actoutputindex;

//	iec_hw_definition *hwobjects;

	int hwobjectindex;
} btech_memory;

extern btech_memory g_internalMemory;


void *btech_malloc(size_t size);

/**
 * allocate all memory for used by all variables
 */
int btech_Init_Memory();

#endif /* BTECH_IEC_MEMORY_MAPPER_H_ */
