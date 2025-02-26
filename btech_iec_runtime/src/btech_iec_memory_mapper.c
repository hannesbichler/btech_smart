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
 * btech_iec_memory_mapper.c                                                 *
 *  Created on: May 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/
#ifndef BTECH_IEC_MEMORY_H
#define BTECH_IEC_MEMORY_H

#include "btech_iec_memory_mapper.h"
#include "btech_iec_runtime.h"

/**
 * pointer offset to get the internal memory
 */
int g_memoryOffset;

int btech_Init_Memory() {
	// allocate memory for used by all variables
	//g_Global_Start_Memory = malloc(sizeof(char) * g_MaxMemorySize);

	return 1;
}

int btech_Memory_Clear() {
	g_memoryOffset = 0;
	g_internalMemory.actvarindex = 0;
	// free(g_internalMemory.vars);

	return 0;
}

void *btech_malloc(size_t size) {
	return 0;
}

#endif 					// BTECH_IEC_MEMORY_H
