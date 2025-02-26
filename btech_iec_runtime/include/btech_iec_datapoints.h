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
 * btech_iec_datapoints.h                                                    *
 *  Created on: May 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/

#ifndef BTECH_IEC_DATAPOINTS_H_
#define BTECH_IEC_DATAPOINTS_H_

#include <string.h>

typedef int BOOL;
typedef int SINT;
typedef int INT;
typedef long DINT;
typedef long LINT;

typedef unsigned int USINT;
typedef unsigned int UINT;
typedef unsigned long UDINT;
typedef unsigned long ULINT;

typedef float REAL;
typedef double LREAL;

typedef struct iec_datapoint_  iec_datapoint;
//typedef struct iec_hw_definition_ iec_hw_definition;

typedef struct iec_bool_datapoint_ iec_bool_datapoint;
typedef struct iec_sint_datapoint_ iec_sint_datapoint;
typedef struct iec_int_datapoint_ iec_int_datapoint;
typedef struct iec_dint_datapoint_ iec_dint_datapoint;
typedef struct iec_lint_datapoint_ iec_lint_datapoint;

typedef struct iec_usint_datapoint_ iec_usint_datapoint;
typedef struct iec_uint_datapoint_ iec_uint_datapoint;
typedef struct iec_udint_datapoint_ iec_udint_datapoint;
typedef struct iec_ulint_datapoint_ iec_ulint_datapoint;

typedef struct iec_real_datapoint_ iec_real_datapoint;
typedef struct iec_lreal_datapoint_ iec_lreal_datapoint;

typedef struct iec_time_datapoint_ iec_time_datapoint;
typedef struct iec_date_datapoint_ iec_date_datapoint;

typedef struct iec_tod_datapoint_ iec_tod_datapoint;
typedef struct iec_dt_datapoint_ iec_dt_datapoint;

typedef struct iec_string_datapoint_ iec_string_datapoint;
typedef struct iec_byte_datapoint_ iec_byte_datapoint;
typedef struct iec_word_datapoint_ iec_word_datapoint;
typedef struct iec_dword_datapoint_ iec_dword_datapoint;
typedef struct iec_lword_datapoint_ iec_lword_datapoint;
typedef struct iec_wstring_datapoint_ iec_wstring_datapoint;

typedef struct iec_softplc_variables_ iec_softplc_variables;
//typedef struct iec_softplcio_var_ 		iec_softplcio_var;

typedef int (*transform2Internal)(char *buffer, iec_datapoint *dp);
typedef int (*transform2Wire)(char *buffer, iec_datapoint *dp);

typedef int (*setDPValue)(void *value, iec_datapoint *dp);

int btech_iec_softplc_variables_initialize(iec_softplc_variables *vars);
int btech_iec_softplc_variables_clear(iec_softplc_variables *vars);

struct iec_softplc_variables_
{
	// maps variablenames to long handle
	iec_datapoint **varMap;
	int varMapCount;
//	map<string, long> varMap;

// maps long handle to plc variables
//	comet_hashmap handleMap;
//	map<long, SoftPLCVariable> handleMap;

// handle iopin combination
//	iec_datapoint **outPutVars;
//	int outPutVarsCount;
//	comet_hashmap outPutVar;
//	map<long, SoftPLCIOVar*> outPutVar;

// handle iopin combination
//	iec_datapoint **inPutVars;
//	int inPutVarsCount;
//	map<long, SoftPLCIOVar*> inPutVar;

};

struct iec_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;
	long handle;

	setDPValue setdpvalue;
	void *value;
};

int btech_iec_bool_datapoint_initialize(iec_bool_datapoint *dp);
int btech_transform2internal_bool(char *buffer, iec_datapoint *dp);
int btech_transform2wire_bool(char *buffer, iec_datapoint *dp);
int btech_setDPValue_bool(void *value, iec_datapoint *dp);

struct iec_bool_datapoint_
{
	// indicates that the variable should be written to hmi client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations to hmi wire protocol
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;
	int *value;

};

// --------------------------------------------------------------------------------
//
//				signed integer data points
//
// --------------------------------------------------------------------------------
int btech_iec_sint_datapoint_initialize(iec_sint_datapoint *dp);
int btech_transform2internal_sint(char *buffer, iec_datapoint *dp);
int btech_transform2wire_sint(char *buffer, iec_datapoint *dp);
int btech_setDPValue_sint(void *value, iec_datapoint *dp);

struct iec_sint_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;
	int *value;
};

int btech_iec_int_datapoint_initialize(iec_int_datapoint *dp);
int btech_transform2internal_int(char *buffer, iec_datapoint *dp);
int btech_transform2wire_int(char *buffer, iec_datapoint *dp);
int btech_setDPValue_int(void *value, iec_datapoint *dp);

struct iec_int_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	int *value;
};

int btech_iec_dint_datapoint_initialize(iec_dint_datapoint *dp);
int btech_transform2internal_dint(char *buffer, iec_datapoint *dp);
int btech_transform2wire_dint(char *buffer, iec_datapoint *dp);
int btech_setDPValue_dint(void *value, iec_datapoint *dp);

struct iec_dint_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	int *value;
};

int btech_iec_lint_datapoint_initialize(iec_lint_datapoint *dp);
int btech_transform2internal_lint(char *buffer, iec_datapoint *dp);
int btech_transform2wire_lint(char *buffer, iec_datapoint *dp);
int btech_setDPValue_lint(void *value, iec_datapoint *dp);

struct iec_lint_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	long *value;
};

// --------------------------------------------------------------------------------
//
//				unsigned integer data points
//
// --------------------------------------------------------------------------------
int btech_iec_usint_datapoint_initialize(iec_usint_datapoint *dp);
int btech_transform2internal_usint(char *buffer, iec_datapoint *dp);
int btech_transform2wire_usint(char *buffer, iec_datapoint *dp);
int btech_setDPValue_usint(void *value, iec_datapoint *dp);

struct iec_usint_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;
	int *value;
};

int btech_iec_uint_datapoint_initialize(iec_uint_datapoint *dp);
int btech_transform2internal_uint(char *buffer, iec_datapoint *dp);
int btech_transform2wire_uint(char *buffer, iec_datapoint *dp);
int btech_setDPValue_uint(void *value, iec_datapoint *dp);

struct iec_uint_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	int *value;
};

int btech_iec_udint_datapoint_initialize(iec_udint_datapoint *dp);
int btech_transform2internal_udint(char *buffer, iec_datapoint *dp);
int btech_transform2wire_udint(char *buffer, iec_datapoint *dp);
int btech_setDPValue_udint(void *value, iec_datapoint *dp);

struct iec_udint_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	int *value;
};

int btech_iec_ulint_datapoint_initialize(iec_ulint_datapoint *dp);
int btech_transform2internal_ulint(char *buffer, iec_datapoint *dp);
int btech_transform2wire_ulint(char *buffer, iec_datapoint *dp);
int btech_setDPValue_ulint(void *value, iec_datapoint *dp);

struct iec_ulint_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	long *value;
};

// --------------------------------------------------------------------------------
//
//				signed floating data points
//
// --------------------------------------------------------------------------------
int btech_iec_real_datapoint_initialize(iec_real_datapoint *dp);
int btech_transform2internal_real(char *buffer, iec_datapoint *dp);
int btech_transform2wire_real(char *buffer, iec_datapoint *dp);
int btech_setDPValue_real(void *value, iec_datapoint *dp);

struct iec_real_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	float *value;
};

int btech_iec_lreal_datapoint_initialize(iec_lreal_datapoint *dp);
int btech_transform2internal_lreal(char *buffer, iec_datapoint *dp);
int btech_transform2wire_lreal(char *buffer, iec_datapoint *dp);
int btech_setDPValue_lreal(void *value, iec_datapoint *dp);

struct iec_lreal_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	double *value;
};

// --------------------------------------------------------------------------------
//
//				time data points
//
// --------------------------------------------------------------------------------
int btech_iec_time_datapoint_initialize(iec_time_datapoint *dp);
int btech_transform2internal_time(char *buffer, iec_datapoint *dp);
int btech_transform2wire_time(char *buffer, iec_datapoint *dp);
int btech_setDPValue_time(void *value, iec_datapoint *dp);

struct iec_time_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	double *value;
};

int btech_iec_date_datapoint_initialize(iec_date_datapoint *dp);
int btech_transform2internal_date(char *buffer, iec_datapoint *dp);
int btech_transform2wire_date(char *buffer, iec_datapoint *dp);
int btech_setDPValue_date(void *value, iec_datapoint *dp);

struct iec_date_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	double *value;
};

int btech_iec_tod_datapoint_initialize(iec_tod_datapoint *dp);
int btech_transform2internal_tod(char *buffer, iec_datapoint *dp);
int btech_transform2wire_tod(char *buffer, iec_datapoint *dp);
int btech_setDPValue_tod(void *value, iec_datapoint *dp);

struct iec_tod_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	double *value;
};

int btech_iec_dt_datapoint_initialize(iec_dt_datapoint *dp);
int btech_transform2internal_dt(char *buffer, iec_datapoint *dp);
int btech_transform2wire_dt(char *buffer, iec_datapoint *dp);
int btech_setDPValue_dt(void *value, iec_datapoint *dp);

struct iec_dt_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	double *value;
};

int btech_iec_string_datapoint_initialize(iec_string_datapoint *dp);
int btech_transform2internal_string(char *buffer, iec_datapoint *dp);
int btech_transform2wire_string(char *buffer, iec_datapoint *dp);
int btech_setDPValue_string(void *value, iec_datapoint *dp);

struct iec_string_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	double *value;
};

int btech_iec_byte_datapoint_initialize(iec_byte_datapoint *dp);
int btech_transform2internal_byte(char *buffer, iec_datapoint *dp);
int btech_transform2wire_byte(char *buffer, iec_datapoint *dp);
int btech_setDPValue_byte(void *value, iec_datapoint *dp);

struct iec_byte_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	char *value;
};
// --------------------------------------------------------------------------------
//
//				byte and string data points
//
// --------------------------------------------------------------------------------

int btech_iec_word_datapoint_initialize(iec_word_datapoint *dp);
int btech_transform2internal_word(char *buffer, iec_datapoint *dp);
int btech_transform2wire_word(char *buffer, iec_datapoint *dp);
int btech_setDPValue_word(void *value, iec_datapoint *dp);

struct iec_word_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	char *value; //[2];
};

int btech_iec_dword_datapoint_initialize(iec_dword_datapoint *dp);
int btech_transform2internal_dword(char *buffer, iec_datapoint *dp);
int btech_transform2wire_dword(char *buffer, iec_datapoint *dp);
int btech_setDPValue_dword(void *value, iec_datapoint *dp);

struct iec_dword_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	char *value; //[4];
};

int btech_iec_lword_datapoint_initialize(iec_lword_datapoint *dp);
int btech_transform2internal_lword(char *buffer, iec_datapoint *dp);
int btech_transform2wire_lword(char *buffer, iec_datapoint *dp);
int btech_setDPValue_lword(void *value, iec_datapoint *dp);

struct iec_lword_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	char *value; //[4];
};

int btech_iec_wstring_datapoint_initialize(iec_wstring_datapoint *dp);
int btech_transform2internal_wstring(char *buffer, iec_datapoint *dp);
int btech_transform2wire_wstring(char *buffer, iec_datapoint *dp);
int btech_setDPValue_wstring(void *value, iec_datapoint *dp);

struct iec_wstring_datapoint_
{
	// indicates that the variable should be written to client
	int dirty;

	char *varName;

	// number of bytes to transform between internal representation
	// and wire representation
	int byteCount;

	// transformations
	transform2Internal Transform2Internal;
	transform2Wire Transform2Wire;

	long handle;

	setDPValue setdpvalue;

	char *value; //[4];
};

#endif // IEC_DATAPOINTS_H_
