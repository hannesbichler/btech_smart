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
 * btech_iec_logger.h                                                              *
 *  Created on: May 24, 2018                                                      *
 *      Author: hannes                                                      *
 *                                                                           *
 *****************************************************************************/
#ifndef BTECH_IEC_LOGGER_H_
#define BTECH_IEC_LOGGER_H_

#include <stdio.h>

#define LOG_VERSION "0.1.0"

typedef void (*btech_iec_log_LockFn)(void *udata, int lock);

enum
{
	BTECH_IEC_LOG_TRACE,
	BTECH_IEC_LOG_DEBUG,
	BTECH_IEC_LOG_INFO,
	BTECH_IEC_LOG_WARN,
	BTECH_IEC_LOG_ERROR,
	BTECH_IEC_LOG_FATAL
};

#define btech_iec_log_trace(...) btech_iec_log_log(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define btech_iec_log_debug(...) btech_iec_log_log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define btech_iec_log_info(...)  btech_iec_log_log(LOG_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define btech_iec_log_warn(...)  btech_iec_log_log(LOG_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define btech_iec_log_error(...) btech_iec_log_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define btech_iec_log_fatal(...) btech_iec_log_log(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)

void btech_iec_log_set_udata(void *udata);
void btech_iec_log_set_lock(btech_iec_log_LockFn fn);
void btech_iec_log_set_fp(FILE *fp);
void btech_iec_log_set_level(int level);
void btech_iec_log_set_quiet(int enable);

void btech_iec_log_log(int level, const char *file, int line, const char *fmt,
		...);

#endif /* BTECH_IEC_LOGGER_H_ */
