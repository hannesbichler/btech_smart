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
 * btech_iec_logger.c                                                        *
 *  Created on: May 24, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#include "btech_iec_logger.h"

static struct
{
	void *udata;
	btech_iec_log_LockFn lock;
	FILE *fp;
	int level;
	int quiet;
} L;

static const char *level_names[] =
{ "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL" };

#ifdef LOG_USE_COLOR
static const char *level_colors[] =
{
	"\x1b[94m", "\x1b[36m", "\x1b[32m", "\x1b[33m", "\x1b[31m", "\x1b[35m"
};
#endif

static void lock(void)
{
	if (L.lock)
	{
		L.lock(L.udata, 1);
	}
}

static void unlock(void)
{
	if (L.lock)
	{
		L.lock(L.udata, 0);
	}
}

void btech_iec_log_set_udata(void *udata)
{
	L.udata = udata;
}

void btech_iec_log_set_lock(btech_iec_log_LockFn fn)
{
	L.lock = fn;
}

void btech_iec_log_set_fp(FILE *fp)
{
	L.fp = fp;
}

void btech_iec_log_set_level(int level)
{
	L.level = level;
}

void btech_iec_log_set_quiet(int enable)
{
	L.quiet = enable ? 1 : 0;
}

/**
 * loggs a message to a file
 */
void btech_iec_log_log(int a_nLevel, const char *a_pFileName, int a_nLine, const char *fmt,
		...)
{
	if (a_nLevel < L.level)
	{
		return;
	}

	/* Acquire lock */
	lock();

	/* Get current time */
	//time_t t = time(NULL);
	struct timespec spec;
#if !defined(_WIN32)
	clock_gettime(CLOCK_REALTIME, &spec);
#endif
	struct tm *lt = localtime(&spec.tv_sec);

	/* Log to stderr */
	if (!L.quiet)
	{
		va_list args;
		char buf[16];
		buf[strftime(buf, sizeof(buf), "%H:%M:%S", lt)] = '\0';

#ifdef LOG_USE_COLOR
		fprintf(
				stderr, "%s %s%-5s\x1b[0m \x1b[90m%s:%d:\x1b[0m ",
				buf, level_colors[level], level_names[level], file, line);
#else
		fprintf(stderr, "%s.%9ld %-5s %s:%d: ", buf, spec.tv_nsec,
				level_names[a_nLevel], a_pFileName, a_nLine);
#endif
		va_start(args, fmt);
		vfprintf(stderr, fmt, args);
		va_end(args);
		fprintf(stderr, "\n");
	}

	/* Log to file */
	if (L.fp)
	{
		va_list args;
		char buf[32];
		buf[strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", lt)] = '\0';
		fprintf(L.fp, "%s.%9ld %-5s %s:%d: ", buf, spec.tv_nsec, level_names[a_nLevel],
				a_pFileName, a_nLine);
		va_start(args, fmt);
		vfprintf(L.fp, fmt, args);
		va_end(args);
		fprintf(L.fp, "\n");
	}

	/* Release lock */
	unlock();
}
