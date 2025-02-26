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
 * btech_iec_datapoints.c                                                    *
 *  Created on: May 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/

/** standard libraries */
#include <stdlib.h>

/** btech libraries */
#include "btech_iec_datapoints.h"

int btech_iec_softplc_variables_initialize(iec_softplc_variables *vars)
{
	if (vars == NULL)
	{
		return -1;
	}

	vars->varMap = NULL;
	vars->varMapCount = 0;
	return 1;
}

int btech_iec_softplc_variables_clear(iec_softplc_variables *vars)
{
	if (vars == NULL)
	{
		return -1;
	}

	if (vars->varMap != NULL)
	{
		free(vars->varMap);
		vars->varMap = NULL;
	}
	vars->varMapCount = 0;
	return 1;
}

int btech_transform2internal_bool(char *buffer, iec_datapoint *dp)
{
	*((iec_bool_datapoint*) dp)->value = buffer[0];

	return 1;
}

int btech_transform2wire_bool(char *buffer, iec_datapoint *dp)
{
	*buffer = *((iec_bool_datapoint*) dp)->value;
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the value should be written
// to any connected client.
// function returns 1 if the value changes, otherwise 0
int btech_setDPValue_bool(void *value, iec_datapoint *dp)
{
	if (*((iec_bool_datapoint*) dp)->value != *(int*) value)
	{
		*((iec_bool_datapoint*) dp)->value = *(int*) value;
		((iec_bool_datapoint*) dp)->dirty = 1;
		return 1;
	}

	return 0;
}

int btech_iec_bool_datapoint_initialize(iec_bool_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 1;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_bool;
	dp->Transform2Wire = btech_transform2wire_bool;

	dp->setdpvalue = btech_setDPValue_bool;

	return 1;
}

// --------------------------------------------------------------------------------
//
//				signed integer data points
//
// --------------------------------------------------------------------------------
int btech_transform2internal_sint(char *buffer, iec_datapoint *dp)
{
	int value = (int) buffer[1];
	value += (int) buffer[0] * 256;

	*((iec_sint_datapoint*) dp)->value = value;
	return 1;
}

int btech_transform2wire_sint(char *buffer, iec_datapoint *dp)
{
	buffer[0] = (*((iec_sint_datapoint*) dp)->value / 256) % 256;
	buffer[1] = *((iec_sint_datapoint*) dp)->value % 256;

	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_sint(void *value, iec_datapoint *dp)
{
	if (*((iec_sint_datapoint*) dp)->value != *(int*) value)
	{
		*((iec_sint_datapoint*) dp)->value = *(int*) value;
		((iec_sint_datapoint*) dp)->dirty = 1;
		return 0;
	}
	return 1;
}

int btech_iec_sint_datapoint_initialize(iec_sint_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 2;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_sint;
	dp->Transform2Wire = btech_transform2wire_sint;

	dp->setdpvalue = btech_setDPValue_sint;
	return 1;
}

int btech_transform2internal_int(char *buffer, iec_datapoint *dp)
{
	int value = (int) buffer[1];
	value += (int) buffer[0] * 256;

	*((iec_int_datapoint*) dp)->value = value;
	return 1;
}

int btech_transform2wire_int(char *buffer, iec_datapoint *dp)
{
	buffer[0] = (*((iec_int_datapoint*) dp)->value / 256) % 256;
	buffer[1] = *((iec_int_datapoint*) dp)->value % 256;

	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_int(void *value, iec_datapoint *dp)
{
	if (*((iec_int_datapoint*) dp)->value != *(int*) value)
	{
		*((iec_int_datapoint*) dp)->value = *(int*) value;
		((iec_int_datapoint*) dp)->dirty = 1;
		return 0;
	}
	return 1;
}

int btech_iec_int_datapoint_initialize(iec_int_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 2;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_int;
	dp->Transform2Wire = btech_transform2wire_int;

	dp->setdpvalue = btech_setDPValue_int;
	return 1;
}

int btech_transform2internal_dint(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 3; ii >= 0; ii--)
	{
		((iec_dint_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_dint(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_dint_datapoint*) dp)->value;

	for (ii = 3; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_dint(void *value, iec_datapoint *dp)
{
	if (*((iec_dint_datapoint*) dp)->value != *(int*) value)
	{
		*((iec_dint_datapoint*) dp)->value = *(int*) value;
		((iec_dint_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_dint_datapoint_initialize(iec_dint_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 4;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_dint;
	dp->Transform2Wire = btech_transform2wire_dint;

	dp->setdpvalue = btech_setDPValue_dint;
	return 1;
}

int btech_transform2internal_lint(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 7; ii >= 0; ii--)
	{
		((iec_lint_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_lint(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_lint_datapoint*) dp)->value;

	for (ii = 7; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_lint(void *value, iec_datapoint *dp)
{
	if (*((iec_lint_datapoint*) dp)->value != *(long*) value)
	{
		*((iec_lint_datapoint*) dp)->value = *(long*) value;
		((iec_lint_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_lint_datapoint_initialize(iec_lint_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 4;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_lint;
	dp->Transform2Wire = btech_transform2wire_lint;

	dp->setdpvalue = btech_setDPValue_lint;
	return 1;
}

// --------------------------------------------------------------------------------
//
//				unsigned integer data points
//
// --------------------------------------------------------------------------------

int btech_transform2internal_usint(char *buffer, iec_datapoint *dp)
{
	int value = (int) buffer[1];
	value += (int) buffer[0] * 256;

	*((iec_usint_datapoint*) dp)->value = value;
	return 1;
}

int btech_transform2wire_usint(char *buffer, iec_datapoint *dp)
{
	buffer[0] = (*((iec_usint_datapoint*) dp)->value / 256) % 256;
	buffer[1] = *((iec_usint_datapoint*) dp)->value % 256;

	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_usint(void *value, iec_datapoint *dp)
{
	if (*((iec_usint_datapoint*) dp)->value != *(int*) value)
	{
		*((iec_usint_datapoint*) dp)->value = *(int*) value;
		((iec_usint_datapoint*) dp)->dirty = 1;
		return 0;
	}
	return 1;
}

int btech_iec_usint_datapoint_initialize(iec_usint_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 2;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_usint;
	dp->Transform2Wire = btech_transform2wire_usint;

	dp->setdpvalue = btech_setDPValue_usint;
	return 1;
}

int btech_transform2internal_uint(char *buffer, iec_datapoint *dp)
{
	int value = (int) buffer[1];
	value += (int) buffer[0] * 256;

	*((iec_uint_datapoint*) dp)->value = value;
	return 1;
}

int btech_transform2wire_uint(char *buffer, iec_datapoint *dp)
{
	buffer[0] = (*((iec_uint_datapoint*) dp)->value / 256) % 256;
	buffer[1] = *((iec_uint_datapoint*) dp)->value % 256;

	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_uint(void *value, iec_datapoint *dp)
{
	if (*((iec_uint_datapoint*) dp)->value != *(int*) value)
	{
		*((iec_uint_datapoint*) dp)->value = *(int*) value;
		((iec_uint_datapoint*) dp)->dirty = 1;
		return 0;
	}
	return 1;
}

int btech_iec_uint_datapoint_initialize(iec_uint_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 2;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_uint;
	dp->Transform2Wire = btech_transform2wire_uint;

	dp->setdpvalue = btech_setDPValue_uint;
	return 1;
}

int btech_transform2internal_udint(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 3; ii >= 0; ii--)
	{
		((iec_udint_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_udint(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_udint_datapoint*) dp)->value;

	for (ii = 3; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_udint(void *value, iec_datapoint *dp)
{
	if (*((iec_udint_datapoint*) dp)->value != *(int*) value)
	{
		*((iec_udint_datapoint*) dp)->value = *(int*) value;
		((iec_udint_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_udint_datapoint_initialize(iec_udint_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 4;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_udint;
	dp->Transform2Wire = btech_transform2wire_udint;

	dp->setdpvalue = btech_setDPValue_udint;
	return 1;
}

int btech_transform2internal_ulint(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 7; ii >= 0; ii--)
	{
		((iec_ulint_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_ulint(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_ulint_datapoint*) dp)->value;

	for (ii = 7; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_ulint(void *value, iec_datapoint *dp)
{
	if (*((iec_ulint_datapoint*) dp)->value != *(long*) value)
	{
		*((iec_ulint_datapoint*) dp)->value = *(long*) value;
		((iec_ulint_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_ulint_datapoint_initialize(iec_ulint_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 4;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_ulint;
	dp->Transform2Wire = btech_transform2wire_ulint;

	dp->setdpvalue = btech_setDPValue_ulint;
	return 1;
}

// --------------------------------------------------------------------------------
//
//				floating data points
//
// --------------------------------------------------------------------------------
int btech_transform2internal_real(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 7; ii >= 0; ii--)
	{
		((iec_real_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_real(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_real_datapoint*) dp)->value;

	for (ii = 7; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_real(void *value, iec_datapoint *dp)
{
	if (*((iec_real_datapoint*) dp)->value != *(float*) value)
	{
		*((iec_real_datapoint*) dp)->value = *(float*) value;
		((iec_real_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_real_datapoint_initialize(iec_real_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 4;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_real;
	dp->Transform2Wire = btech_transform2wire_real;

	dp->setdpvalue = btech_setDPValue_real;
	return 1;
}

int btech_transform2internal_lreal(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 7; ii >= 0; ii--)
	{
		((iec_lreal_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_lreal(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_lreal_datapoint*) dp)->value;

	for (ii = 7; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_lreal(void *value, iec_datapoint *dp)
{
	if (*((iec_lreal_datapoint*) dp)->value != *(double*) value)
	{
		*((iec_lreal_datapoint*) dp)->value = *(double*) value;
		((iec_lreal_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_lreal_datapoint_initialize(iec_lreal_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 8;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_lreal;
	dp->Transform2Wire = btech_transform2wire_lreal;

	dp->setdpvalue = btech_setDPValue_lreal;
	return 1;
}

// --------------------------------------------------------------------------------
//
//				time and date data points
//
// --------------------------------------------------------------------------------

int btech_transform2internal_time(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 7; ii >= 0; ii--)
	{
		((iec_time_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_time(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_time_datapoint*) dp)->value;

	for (ii = 7; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_time(void *value, iec_datapoint *dp)
{
	if (*((iec_time_datapoint*) dp)->value != *(double*) value)
	{
		*((iec_time_datapoint*) dp)->value = *(double*) value;
		((iec_time_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_time_datapoint_initialize(iec_time_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 8;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_time;
	dp->Transform2Wire = btech_transform2wire_time;

	dp->setdpvalue = btech_setDPValue_time;
	return 1;
}

int btech_transform2internal_date(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 7; ii >= 0; ii--)
	{
		((iec_date_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_date(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_date_datapoint*) dp)->value;

	for (ii = 7; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_date(void *value, iec_datapoint *dp)
{
	if (*((iec_date_datapoint*) dp)->value != *(double*) value)
	{
		*((iec_date_datapoint*) dp)->value = *(double*) value;
		((iec_date_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_date_datapoint_initialize(iec_date_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 8;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_date;
	dp->Transform2Wire = btech_transform2wire_date;

	dp->setdpvalue = btech_setDPValue_date;
	return 1;
}

int btech_transform2internal_tod(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 7; ii >= 0; ii--)
	{
		((iec_tod_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_tod(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_tod_datapoint*) dp)->value;

	for (ii = 7; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_tod(void *value, iec_datapoint *dp)
{
	if (*((iec_tod_datapoint*) dp)->value != *(double*) value)
	{
		*((iec_tod_datapoint*) dp)->value = *(double*) value;
		((iec_tod_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_tod_datapoint_initialize(iec_tod_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 8;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_tod;
	dp->Transform2Wire = btech_transform2wire_tod;

	dp->setdpvalue = btech_setDPValue_tod;
	return 1;
}

int btech_transform2internal_dt(char *buffer, iec_datapoint *dp)
{
	int ii;
	int multi = 0;
	for (ii = 7; ii >= 0; ii--)
	{
		((iec_dt_datapoint*) dp)->value += (int) buffer[ii] * multi;
		multi = 256;
	}

	return 1;
}

int btech_transform2wire_dt(char *buffer, iec_datapoint *dp)
{
	int ii;
	int value = *((iec_dt_datapoint*) dp)->value;

	for (ii = 7; ii >= 0; ii--)
	{
		buffer[ii] = (char) (value % 256);
		value /= 256;
	}
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_dt(void *value, iec_datapoint *dp)
{
	if (*((iec_dt_datapoint*) dp)->value != *(double*) value)
	{
		*((iec_dt_datapoint*) dp)->value = *(double*) value;
		((iec_dt_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_dt_datapoint_initialize(iec_dt_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 8;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_dt;
	dp->Transform2Wire = btech_transform2wire_dt;

	dp->setdpvalue = btech_setDPValue_dt;
	return 1;
}

int btech_transform2internal_string(char *buffer, iec_datapoint *dp)
{
	*((iec_string_datapoint*) dp)->value = buffer[0];

	return 1;
}

int btech_transform2wire_string(char *buffer, iec_datapoint *dp)
{
	buffer[0] = *((iec_string_datapoint*) dp)->value;
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
// function returns 1 if the value changes, otherwise 0
int btech_setDPValue_string(void *value, iec_datapoint *dp)
{
	if (*((iec_string_datapoint*) dp)->value != *(int*) value)
	{
		*((iec_string_datapoint*) dp)->value = *(int*) value;
		((iec_string_datapoint*) dp)->dirty = 1;
		return 1;
	}

	return 0;
}

int btech_iec_string_datapoint_initialize(iec_string_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 1;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_string;
	dp->Transform2Wire = btech_transform2wire_string;

	dp->setdpvalue = btech_setDPValue_string;
	return 1;
}

int btech_transform2internal_byte(char *buffer, iec_datapoint *dp)
{
	*((iec_byte_datapoint*) dp)->value = buffer[0];

	return 1;
}

int btech_transform2wire_byte(char *buffer, iec_datapoint *dp)
{
	buffer[0] = *((iec_byte_datapoint*) dp)->value;
	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
// function returns 1 if the value changes, otherwise 0
int btech_setDPValue_byte(void *value, iec_datapoint *dp)
{
	if (*((iec_byte_datapoint*) dp)->value != *(int*) value)
	{
		*((iec_byte_datapoint*) dp)->value = *(int*) value;
		((iec_byte_datapoint*) dp)->dirty = 1;
		return 1;
	}

	return 0;
}

int btech_iec_byte_datapoint_initialize(iec_byte_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 1;
	dp->dirty = 0;
	dp->value = malloc(sizeof(int));
	*dp->value = 0;

	dp->Transform2Internal = btech_transform2internal_byte;
	dp->Transform2Wire = btech_transform2wire_byte;

	dp->setdpvalue = btech_setDPValue_byte;
	return 1;
}

int btech_transform2internal_word(char *buffer, iec_datapoint *dp)
{
	memccpy(((iec_word_datapoint*) dp)->value, buffer,
			((iec_word_datapoint*) dp)->byteCount, 1);

	return 1;
}

int btech_transform2wire_word(char *buffer, iec_datapoint *dp)
{
	_memccpy(buffer, ((iec_word_datapoint*) dp)->value,
			((iec_word_datapoint*) dp)->byteCount, 1);

	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_word(void *value, iec_datapoint *dp)
{
	if (memcmp(((iec_word_datapoint*) dp)->value, value, 2) != 0)
	{
		memcpy(((iec_word_datapoint*) dp)->value, value, 2);
		((iec_word_datapoint*) dp)->dirty = 1;
		return 1;
	}
	return 0;
}

int btech_iec_word_datapoint_initialize(iec_word_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 2;
	dp->dirty = 0;

	dp->value = malloc(sizeof(char) * 2);
	dp->value[0] = 0;
	dp->value[1] = 0;

	dp->Transform2Internal = btech_transform2internal_word;
	dp->Transform2Wire = btech_transform2wire_word;

	dp->setdpvalue = btech_setDPValue_word;
	return 1;
}

int btech_transform2internal_dword(char *buffer, iec_datapoint *dp)
{
	_memccpy(((iec_dword_datapoint*) dp)->value, buffer,
			((iec_dword_datapoint*) dp)->byteCount, 1);

	return 1;
}

int btech_transform2wire_dword(char *buffer, iec_datapoint *dp)
{
	memccpy(buffer, ((iec_dword_datapoint*) dp)->value,
			((iec_dword_datapoint*) dp)->byteCount, 1);

	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_dword(void *value, iec_datapoint *dp)
{
	if (memcmp(((iec_dword_datapoint*) dp)->value, value, 4) != 0)
	{
		memcpy(((iec_dword_datapoint*) dp)->value, value, 4);
		((iec_dword_datapoint*) dp)->dirty = 1;
		return 1;
	}

	return 0;
}

int btech_iec_dword_datapoint_initialize(iec_dword_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 4;
	dp->dirty = 0;
	dp->value = malloc(sizeof(char) * 4);

	dp->value[0] = 0;
	dp->value[1] = 0;
	dp->value[2] = 0;
	dp->value[3] = 0;

	dp->Transform2Internal = btech_transform2internal_dword;
	dp->Transform2Wire = btech_transform2wire_dword;

	dp->setdpvalue = btech_setDPValue_dword;
	return 1;
}

int btech_transform2internal_lword(char *buffer, iec_datapoint *dp)
{
	memccpy(((iec_lword_datapoint*) dp)->value, buffer,
			((iec_lword_datapoint*) dp)->byteCount, 1);

	return 1;
}

int btech_transform2wire_lword(char *buffer, iec_datapoint *dp)
{
	_memccpy(buffer, ((iec_lword_datapoint*) dp)->value,
			((iec_lword_datapoint*) dp)->byteCount, 1);

	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_lword(void *value, iec_datapoint *dp)
{
	if (memcmp(((iec_lword_datapoint*) dp)->value, value, 4) != 0)
	{
		memcpy(((iec_lword_datapoint*) dp)->value, value, 4);
		((iec_lword_datapoint*) dp)->dirty = 1;
		return 1;
	}

	return 0;
}

int btech_iec_lword_datapoint_initialize(iec_lword_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 4;
	dp->dirty = 0;
	dp->value = malloc(sizeof(char) * 4);
	dp->value[0] = 0;
	dp->value[1] = 0;
	dp->value[2] = 0;
	dp->value[3] = 0;

	dp->Transform2Internal = btech_transform2internal_lword;
	dp->Transform2Wire = btech_transform2wire_lword;

	dp->setdpvalue = btech_setDPValue_lword;
	return 1;
}

int btech_transform2internal_wstring(char *buffer, iec_datapoint *dp)
{
	memccpy(((iec_wstring_datapoint*) dp)->value, buffer,
			((iec_wstring_datapoint*) dp)->byteCount, 1);

	return 1;
}

int btech_transform2wire_wstring(char *buffer, iec_datapoint *dp)
{
	memccpy(buffer, ((iec_wstring_datapoint*) dp)->value,
			((iec_wstring_datapoint*) dp)->byteCount, 1);

	return 1;
}

// function pointer implementation to set the dp value if it differs
// and also set the dirty flag, to indicate the the value should be written
// to any connected client.
int btech_setDPValue_wstring(void *value, iec_datapoint *dp)
{
	if (memcmp(((iec_wstring_datapoint*) dp)->value, value, 4) != 0)
	{
		memcpy(((iec_wstring_datapoint*) dp)->value, value, 4);
		((iec_wstring_datapoint*) dp)->dirty = 1;
		return 1;
	}

	return 0;
}

int btech_iec_wstring_datapoint_initialize(iec_wstring_datapoint *dp)
{
	if (dp == NULL)
	{
		return -1;
	}

	dp->byteCount = 4;
	dp->dirty = 0;
	dp->value = malloc(sizeof(char) * 4);
	dp->value[0] = 0;
	dp->value[1] = 0;
	dp->value[2] = 0;
	dp->value[3] = 0;

	dp->Transform2Internal = btech_transform2internal_wstring;
	dp->Transform2Wire = btech_transform2wire_wstring;

	dp->setdpvalue = btech_setDPValue_wstring;
	return 1;
}
