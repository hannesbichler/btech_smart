/*
 * ur20_16di_p.h
 *
 *  Created on: 08.06.2017
 *      Author: hannes
 */

#ifndef INCLUDE_BTECH_UR20_MODULES_H_
#define INCLUDE_BTECH_UR20_MODULES_H_

#include "btech_iec_datapoints.h"

struct  btech_ur20_module;

typedef struct btech_ur20_4di_p_module_ btech_ur20_4di_p_module;
typedef struct btech_ur20_4di_n_module_ btech_ur20_4di_n_module;
typedef struct btech_ur20_16di_p_module_ btech_ur20_16di_p_module;
typedef struct btech_ur20_16di_n_module_ btech_ur20_16di_n_module;
typedef struct btech_ur20_16do_p_module_ btech_ur20_16do_p_module;
typedef struct btech_ur20_16do_n_module_ btech_ur20_16do_n_module;

typedef int (*trans2Intern)(char *input, int index, struct btech_ur20_module *value);

typedef int (*trans2Device)(char *output, int index, struct btech_ur20_module *value);

typedef struct btech_ur20_module
{
	// indicates that the variable should be written to client
	int state;

	// number of bytes to transform between internal representation
	// and device representation
	int byteCount;

	// transformations
	trans2Intern Transform2Internal;
	trans2Device Transform2Device;

	iec_datapoint *dps;
} btech_ur20_module;

int btech_ur20_16di_p_module_initialize(btech_ur20_module *module);
int btech_transform2internal_16di_p(char *input, int index, btech_ur20_module *value);
int btech_transform2device_16di_p(char *output, int index, btech_ur20_module *value);

int btech_ur20_16do_p_module_initialize(btech_ur20_module *module);
int btech_transform2internal_16do_p(char *input, int index, btech_ur20_module *value);
int btech_transform2device_16do_p(char *output, int index, btech_ur20_module *value);
//int setDPValue_16di_p(void *value, iec_datapoint *dp);

#endif /* INCLUDE_BTECH_UR20_MODULES_H_ */
