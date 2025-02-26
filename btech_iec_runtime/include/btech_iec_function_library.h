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
 * btech_iec_function_library.h                                              *
 *  Created on: May 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/

#ifndef BTECH_IEC_FUNCTION_LIBRARY_H_
#define BTECH_IEC_FUNCTION_LIBRARY_H_

#include "btech_iec_datapoints.h"

// ready defined complex function block types
typedef struct iec_comparison_functionblock_ iec_comparison_functionblock;
typedef struct iec_setreset_functionblock_ iec_setreset_functionblock;
typedef struct iec_resetset_functionblock_ iec_resetset_functionblock;
typedef struct iec_edgedetection_functionblock_ iec_edgedetection_functionblock;
typedef struct iec_ctu_functionblock_ iec_ctu_functionblock;
typedef struct iec_ctd_functionblock_ iec_ctd_functionblock;
typedef struct iec_ctud_functionblock_ iec_ctud_functionblock;
typedef struct iec_timer_functionblock_ iec_timer_functionblock;
typedef struct iec_rtc_functionblock_ iec_rtc_functionblock;
typedef struct iec_rising_edge_ iec_rising_edge;
typedef struct iec_folling_edge_ iec_folling_edge;
typedef struct iec_toggle_ iec_toggle;
typedef struct iec_multi_rising_switch_ iec_multi_rising_switch;
typedef struct iec_rollo_switch_ iec_rollo_switch;
typedef struct iec_or_ iec_or;
// ------------------------------------------------------
//
// 		structures for flip flop function blocks
//
// ------------------------------------------------------
struct iec_setreset_functionblock_
{
	int s1; /* var_input  */
	int r; /* var_input  */
	int q1; /* var_output */
};

struct iec_resetset_functionblock_
{
	int s; /* var_input  */
	int r1; /* var_input  */
	int q1; /* var_output */
};

// ------------------------------------------------------
//
// 		structures for edge detection function blocks
//
// ------------------------------------------------------
struct iec_edgedetection_functionblock_
{
	int clk; /* var_input  */
	int q; /* var_output */
};

// ------------------------------------------------------
//
// 		structures for counters function blocks
//
// ------------------------------------------------------
struct iec_ctu_functionblock_
{
	int cu; /* var_input  */
	int r; /* var_input  */
	int pv; /* var_input  */
	int q; /* var_output */
	int cv; /* var_output */
};

struct iec_ctd_functionblock_
{
	int cd; /* var_input  */
	int ld; /* var_input  */
	int pv; /* var_input  */
	int q; /* var_output */
	int cv; /* var_output */
};

struct iec_ctud_functionblock_
{
	int cu; /* var_input  */
	int cd; /* var_input  */
	int r; /* var_input  */
	int ld; /* var_input  */
	int pv; /* var_input  */
	int qu; /* var_output */
	int qd; /* var_output */
	int cv; /* var_output */
};

// ------------------------------------------------------
//
// 		structures for timer function blocks
//
// ------------------------------------------------------
struct iec_timer_functionblock_
{
	int timeout;
};

struct iec_rtc_functionblock_
{
	int in; /* var_input  */
	long pdt; /* var_input  */
	int q; /* var_output */
	long cdt; /* var_output */
};

// ------------------------------------------------------
//
// 		structures for comparison function blocks
//
// ------------------------------------------------------
struct iec_comparison_functionblock_
{
	int en; /* var_input  */
	int in1; /* var_input  */
	int in2; /* var_input  */
	int eno; /* var_output */
	int q; /* var_output */
};

struct iec_rising_edge_
{
	int en; /* var_input  */
	iec_bool_datapoint *input; /* var_input  */
	iec_bool_datapoint *oldvalue; /* var_input  */
	iec_bool_datapoint *output; /* var_output  */
	int q; /* var_output */
};

struct iec_folling_edge_
{
	int en; /* var_input  */
	iec_bool_datapoint *input; /* var_input  */
	iec_bool_datapoint *oldvalue; /* var_input  */
	iec_bool_datapoint *output; /* var_output  */
	int q; /* var_output */
};

struct iec_toggle_
{
	int en; /* var_input  */
	iec_bool_datapoint *input; /* var_input  */
	iec_bool_datapoint *oldvalue; /* var_input  */
	iec_bool_datapoint *output; /* var_output  */
	int q; /* var_output */
};

struct iec_multi_rising_switch_
{
	int en;
	iec_bool_datapoint **input;
	iec_bool_datapoint *oldrisingvalue; /* var_input  */
	iec_bool_datapoint *risingvalue; /* var_input  */
	iec_bool_datapoint *oldtogglevalue; /* var_input  */
	int inputcount;
	iec_bool_datapoint *output;
	int q;
};

struct iec_rollo_switch_
{
	int en;
	iec_bool_datapoint **inputup;
	iec_bool_datapoint **inputdown;
	iec_bool_datapoint **inputstop;
//	iec_bool_datapoint *oldrisingvalueup; /* var_input  */
//	iec_bool_datapoint *oldrisingvaluedown; /* var_input  */
//	iec_bool_datapoint *oldrisingvaluestop; /* var_input  */
//	iec_bool_datapoint *risingvalueup; /* var_input  */
//	iec_bool_datapoint *risingvaluedown; /* var_input  */
//	iec_bool_datapoint *risingvaluestop; /* var_input  */
//	iec_bool_datapoint *oldtogglevalueup; /* var_input  */
//	iec_bool_datapoint *oldtogglevaluedown; /* var_input  */
//	iec_bool_datapoint *oldtogglevaluestop; /* var_input  */
	int inputcountup;
	int inputcountdown;
	int inputcountstop;
	iec_bool_datapoint *outputup;
	iec_bool_datapoint *outputdown;
	int q;
};

struct iec_or_
{
	int en;
	iec_bool_datapoint **input;
	int inputcount;
	iec_bool_datapoint *output;
	int q;
};

/**
 * the equal function compares the in1 input and the in2 input if en flag is true,
 * if both have the same value, so return true, otherwise false.
 *
 * @param		the function element with en-flag and input1 and input2
 * @return	true or false, depending on inputs
 */
int iec_equal_func(iec_comparison_functionblock *comparison);
/**
 * the equal function compares the in1 input and the in2 input if en flag is true,
 * if both have the same value, so return true, otherwise false.
 *
 * @param		memory 1 to compare
 * @param		memory 2 to compare
 * @param		size of memory to compare
 * @return	true or false, depending on inputs
 */
//int equal_func(void *comparison1, void *comparison2, int size);
/**
 * the notequal function compares the in1 input and the in2 input if en flag is true,
 * if both have the same value, so return false, otherwise true.
 *
 * @param		the function element with en-flag and input1 and input2
 * @return	true or false, depending on inputs
 */
int iec_notequal_func(iec_comparison_functionblock *comparison);

/**
 * the notequal function compares the in1 input and the in2 input if en flag is true,
 * if both have the same value, so return false, otherwise true.
 *
 * @param		the function element with en-flag and input1 and input2
 * @return	true or false, depending on inputs
 */
int iec_greaterthan_func(iec_comparison_functionblock *comparison);

int lessthan_func(iec_comparison_functionblock *comparison);

int iec_greaterequal_func(iec_comparison_functionblock *comparison);

int iec_lessequal_func(iec_comparison_functionblock *comparison);

/**
 *
 */
int iec_rollo_func(iec_rollo_switch *rollo);

int iec_ton_func();

/**
 * to get the rising edge, it is required to store the old value in a data point
 */
int iec_rising_edge_func(iec_rising_edge *rising);
//		iec_bool_datapoint *input,
//		iec_bool_datapoint *oldvalue, iec_bool_datapoint *output);

int iec_folling_edge_func(iec_folling_edge *folling);
//		iec_bool_datapoint *input,
//		iec_bool_datapoint *oldvalue, iec_bool_datapoint *output);

int iec_toggle_func(iec_toggle *toggle);
//		iec_bool_datapoint *input, iec_bool_datapoint *oldvalue,
//		iec_bool_datapoint *output);

/**
 *
 */
int iec_multi_rising_switch_func(iec_multi_rising_switch *multi);

int iec_or_func(iec_or *iecor);

#endif /* COMET_UA_FUNCTION_LIBRARY_H_ */
