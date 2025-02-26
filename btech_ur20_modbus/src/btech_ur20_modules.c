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

#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>

#include "btech_ur20_modbus_device.h"
#include "btech_ur20_modules.h"

extern int btech_iec_bool_datapoint_initialize(iec_bool_datapoint* dp) {}
extern int btech_setDPValue_bool(void* value, iec_datapoint* dp) {}

/**
 *
 */
int btech_transform2internal_16di_p(char *input, int index, btech_ur20_module *values)
{
	int inv = 0;
	int mod1 = 0;
	int bit = 0;

	inv = input[index];
	inv = inv >= 0 ? inv : inv * -1;
	mod1 = inv * 256;					// first module
	inv = input[index + 1];
	inv = inv >= 0 ? inv : inv * -1;
	mod1 += inv;					// first module
	for (int i = 0; i < 16; i++)
	{
		bit = btech_ur20_get_bit(mod1, i);

		if (bit != *((iec_bool_datapoint*) &values->dps[i])->value)
		{
#ifdef DEBUG_RUNTIME
			printf("input_%i changed: %i\n", i, bit);
#endif
			btech_setDPValue_bool(&bit, &(values->dps[i]));
		}
//		((iec_bool_datapoint*) &values->dps[i])->value = bit;
	}
	fflush(stdout);
	return 0;
}

int btech_transform2internal_16do_p(char *input, int index, btech_ur20_module *values)
{
	int inv = 0;
	int mod1 = 0;
	bool bit = false;

	inv = input[index];
	inv = inv >= 0 ? inv : inv * -1;
	mod1 = inv * 256;					// first module
	inv = input[index + 1];
	inv = inv >= 0 ? inv : inv * -1;
	mod1 += inv;					// first module
	for (int i = 0; i < 16; i++)
	{
		bit = btech_ur20_get_bit(mod1, i);

		if (bit != *((iec_bool_datapoint*) &values->dps[i])->value)
		{
#ifdef DEBUG_RUNTIME
			printf("input_%i changed: %i\n", i, bit);
#endif
			values->dps[i].setdpvalue(&bit, &(values->dps[i]));
		}

	}

	return 0;
}

int btech_transform2device_16di_p(char *input, int index, btech_ur20_module *values)
{
	return 0;
}

int btech_transform2device_16do_p(char *input, int index, btech_ur20_module *values)
{
	int value = 0;
	for (int i = 0; i < 16; i++)
	{
		btech_ur20_set_bit(&value, i, *((iec_bool_datapoint*) &values->dps[i])->value);
	}
	input[index] = (char) (value / 256);
	input[index + 1] = (char) (value % 256);
	return 0;
}

int btech_ur20_16di_p_module_initialize(btech_ur20_module *module)
{
	if (module == NULL)
	{
		return -1;
	}

	module->byteCount = 2;
	module->state = 0;

	module->Transform2Internal = btech_transform2internal_16di_p;
	module->Transform2Device = btech_transform2device_16di_p;

	module->dps = malloc(16 * sizeof(iec_bool_datapoint));
	if (module->dps == NULL)
	{
		return -2;
	}
	for (int i = 0; i < 16; i++)
		btech_iec_bool_datapoint_initialize((iec_bool_datapoint *) &module->dps[i]);
	return 1;
}

int btech_ur20_16do_p_module_initialize(btech_ur20_module *module)
{
	if (module == NULL)
	{
		return -1;
	}

	module->byteCount = 2;
	module->state = 0;

	module->Transform2Internal = btech_transform2internal_16do_p;
	module->Transform2Device = btech_transform2device_16do_p;

	module->dps = malloc(16 * sizeof(iec_bool_datapoint));
	if (module->dps == NULL)
	{
		return -2;
	}
	for (int i = 0; i < 16; i++)
	{
		btech_iec_bool_datapoint_initialize((iec_bool_datapoint*)&module->dps[i]);
	}
	return 1;
}
