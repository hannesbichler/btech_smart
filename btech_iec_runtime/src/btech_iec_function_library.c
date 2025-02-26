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
 * btech_iec_function_library.c                                              *
 *  Created on: May 19, 2018                                                 *
 *      Author: hannes                                                       *
 *                                                                           *
 *****************************************************************************/

#include "btech_iec_function_library.h"

int equal_func(iec_comparison_functionblock *comparison)
{
	// set the eno like en
	comparison->eno = comparison->en;
	if (!comparison->en)
	{
		// the en is not enabled, so do not change the internal values
		return 0;
	}

	comparison->q = comparison->in1 == comparison->in2;

	return 1;
}

/*
int equal_func(void *comparison1, void *comparison2, int size)
{
	if(comparison1==0||comparison2==0)
		return 0;
	return memcmp(comparison1, comparison2, size);
}*/

int notequal_func(iec_comparison_functionblock *comparison)
{
	// set the eno like en
	comparison->eno = comparison->en;
	if (!comparison->en)
	{
		// the en is not enabled, so do not change the internal values
		return 0;
	}

	comparison->q = comparison->in1 != comparison->in2;

	return 1;
}

int greaterthan_func(iec_comparison_functionblock *comparison)
{
	// set the eno like en
	comparison->eno = comparison->en;
	if (!comparison->en)
	{
		// the en is not enabled, so do not change the internal values
		return 0;
	}

	comparison->q = comparison->in1 > comparison->in2;

	return 1;
}

int lessthan_func(iec_comparison_functionblock *comparison)
{
	// set the eno like en
	comparison->eno = comparison->en;
	if (!comparison->en)
	{
		// the en is not enabled, so do not change the internal values
		return 0;
	}

	comparison->q = comparison->in1 < comparison->in2;

	return 1;
}

int greaterequal_func(iec_comparison_functionblock *comparison)
{
	// set the eno like en
	comparison->eno = comparison->en;
	if (!comparison->en)
	{
		// the en is not enabled, so do not change the internal values
		return 0;
	}

	comparison->q = comparison->in1 >= comparison->in2;

	return 1;
}

int lessequal_func(iec_comparison_functionblock *comparison)
{
	// set the eno like en
	comparison->eno = comparison->en;
	if (!comparison->en)
	{
		// the en is not enabled, so do not change the internal values
		return 0;
	}

	comparison->q = comparison->in1 <= comparison->in2;

	return 1;
}

int iec_rising_edge_func(iec_rising_edge *rising)
//		iec_bool_datapoint *input, iec_bool_datapoint *oldvalue,
//		iec_bool_datapoint *output)
{
	if (*rising->input->value == 1
			&& *rising->input->value != *rising->oldvalue->value)
	{
		rising->oldvalue->setdpvalue(rising->input->value,
				(iec_datapoint*) rising->oldvalue);
		rising->output->setdpvalue(rising->input->value,
				(iec_datapoint*) rising->output);
	}
	else
	{
		rising->oldvalue->setdpvalue(rising->input->value,
				(iec_datapoint*) rising->oldvalue);
		int value = 0;
		rising->output->setdpvalue(&value, (iec_datapoint*) rising->output);
	}
	return 0;
}

/**
 * its necessary to store the old value
 */
int iec_folling_edge_func(iec_folling_edge *folling)
//		iec_bool_datapoint *input,
//		iec_bool_datapoint *oldvalue, iec_bool_datapoint *output)
{
	if (*folling->input->value == 0
			&& *folling->input->value != *folling->oldvalue->value)
	{
		folling->oldvalue->setdpvalue(folling->input->value,
				(iec_datapoint*) folling->oldvalue);
		int value = 1;
		folling->output->setdpvalue(&value, (iec_datapoint*) folling->output);
	}
	else
	{
		folling->oldvalue->setdpvalue(folling->input->value,
				(iec_datapoint*) folling->oldvalue);
		int value = 0;
		folling->output->setdpvalue(&value, (iec_datapoint*) folling->output);
	}
	return 0;
}

/**
 * its necessary to store the old value
 */
int iec_toggle_func(iec_toggle *toggle)
//		iec_bool_datapoint *input, iec_bool_datapoint *oldvalue,
//		iec_bool_datapoint *output)
{
	/*
	 * only toggle value if input is true
	 */
	if (*toggle->input->value == 1)
	{
		if (*toggle->oldvalue->value == 1)
		{
			int value = 0;
			toggle->oldvalue->setdpvalue(&value, (iec_datapoint*) toggle->oldvalue);
			toggle->output->setdpvalue(&value, (iec_datapoint*) toggle->output);
		}
		else
		{
			int value = 1;
			toggle->oldvalue->setdpvalue(&value, (iec_datapoint*) toggle->oldvalue);
			toggle->output->setdpvalue(&value, (iec_datapoint*) toggle->output);
		}
	}
	return 0;
}

int iec_multi_rising_switch_func(iec_multi_rising_switch *multi)
{
//	int on = 0;
	for (int i = 0; i < multi->inputcount; i++)
	{
		/****************************************************************************
		 *  validate rising functionality
		 **************************************************************************** */
		if (*multi->input[i]->value == 1
				&& *multi->input[i]->value != *multi->oldrisingvalue[i].value)
		{
			multi->oldrisingvalue[i].setdpvalue(multi->input[i]->value,
					(iec_datapoint*) &multi->oldrisingvalue[i]);
			multi->risingvalue->setdpvalue(multi->input[i]->value,
					(iec_datapoint*) multi->risingvalue);
		}
		else
		{
			multi->oldrisingvalue[i].setdpvalue(multi->input[i]->value,
					(iec_datapoint*) &multi->oldrisingvalue[i]);
			int value = 0;
			multi->risingvalue->setdpvalue(&value,
					(iec_datapoint*) multi->risingvalue);
		}

		/****************************************************************************
		 *  validate toggle functionality
		 **************************************************************************** */
		if (*multi->risingvalue->value == 1)
		{
			/**
			 * rising value of one switch found
			 */
			if (*multi->oldtogglevalue->value == 1)
			{
				int value = 0;
				multi->oldtogglevalue->setdpvalue(&value,
						(iec_datapoint*) multi->oldtogglevalue);
				multi->output->setdpvalue(&value, (iec_datapoint*) multi->output);
				return value;
			}
			else
			{
				int value = 1;
				multi->oldtogglevalue->setdpvalue(&value,
						(iec_datapoint*) multi->oldtogglevalue);
				multi->output->setdpvalue(&value, (iec_datapoint*) multi->output);
				return value;
			}

		}
//		if (on == 1 || *multi->output->value == 1)
//			on = 1;
	}
//	multi->output->setdpvalue(&on, (iec_datapoint*) multi->output);
	return 0;
}

int iec_rollo_func(iec_rollo_switch *rollo)
{
	for (int i = 0; i < rollo->inputcountup; i++)
	{
		if (*rollo->inputup[i]->value == 1)
		{
			int value = 0;
			rollo->outputdown->setdpvalue(&value, (iec_datapoint*) rollo->outputdown);
			value = 1;
			rollo->outputup->setdpvalue(&value, (iec_datapoint*) rollo->outputup);
			return 1;
		}
	}

	for (int i = 0; i < rollo->inputcountdown; i++)
	{
		if (*rollo->inputdown[i]->value == 1)
		{
			int value = 0;
			rollo->outputup->setdpvalue(&value, (iec_datapoint*) rollo->outputup);
			value = 1;
			rollo->outputdown->setdpvalue(&value, (iec_datapoint*) rollo->outputdown);
			return 1;
		}
	}

	for (int i = 0; i < rollo->inputcountstop; i++)
	{
		if (*rollo->inputstop[i]->value == 1)
		{
			int value = 0;
			rollo->outputup->setdpvalue(&value, (iec_datapoint*) rollo->outputup);
			rollo->outputdown->setdpvalue(&value, (iec_datapoint*) rollo->outputdown);
			return 1;
		}
	}
	return 0;
}

/*
int iec_rollo_func(iec_rollo_switch *rollo)
{
	for (int i = 0; i < rollo->inputcountup; i++)
	{
		if (*rollo->inputup[i]->value == 1)
		{
			int value = 0;
			rollo->outputdown->setdpvalue(&value, (iec_datapoint*) rollo->outputdown);
			value = 1;
			rollo->outputup->setdpvalue(&value, (iec_datapoint*) rollo->outputup);
			return 1;
		}
	}

	for (int i = 0; i < rollo->inputcountdown; i++)
	{
		if (*rollo->inputdown[i]->value == 1)
		{
			int value = 0;
			rollo->outputup->setdpvalue(&value, (iec_datapoint*) rollo->outputup);
			value = 1;
			rollo->outputdown->setdpvalue(&value, (iec_datapoint*) rollo->outputdown);
			return 1;
		}
	}

	for (int i = 0; i < rollo->inputcountstop; i++)
	{
		if (*rollo->inputstop[i]->value == 1)
		{
			int value = 0;
			rollo->outputup->setdpvalue(&value, (iec_datapoint*) rollo->outputup);
			rollo->outputdown->setdpvalue(&value, (iec_datapoint*) rollo->outputdown);
			return 1;
		}
	}
	return 0;
}
*/

int iec_or_func(iec_or *iecor)
{
	int value = 0;
	for (int i = 0; i < iecor->inputcount; i++)
	{
		if (*iecor->input[i]->value == 1)
			value = 1;
	}
	iecor->output->setdpvalue(&value, (iec_datapoint *) iecor->output);
#ifdef DEBUG_RUNTIME
	printf("or output: %d\n", *iecor->output->value);
#endif
	return value;
}
