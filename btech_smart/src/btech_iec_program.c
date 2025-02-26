/**
 * this file is auto generated from Automation Studio
 * please do not change it manually
 */
#include <btech_ur20_modbus_device.h>
#include "btech_hardware.h"
#include <stdio.h>
#include <stdlib.h>
#include "btech_iec_datapoints.h"
#include "btech_iec_program.h"
#include "btech_iec_runtime.h"

// debug flag to log initialization commands
#define DEBUG_INITIALISE 1

// debug flag to log runtime commands
#define DEBUG_RUNTIME 1

#define DEBUG_ERROR 1

///*******************************************************************
// *
// * extern definitions
// *
// ******************************************************************/
extern int btech_ur20_registerHardware(void) {}
extern int btech_iec_bool_datapoint_initialize(iec_bool_datapoint* dp) {}
extern int iec_multi_rising_switch_func(iec_multi_rising_switch* multi) {}
extern int iec_rollo_func(iec_rollo_switch* rollo) {}
extern int btech_readHardwareConfig(void) {}
extern int btech_initGeneralVariables(int varcount) {}
extern int btech_addGeneralVariable(iec_datapoint* dp, char* varName) {}

///******************************************************************
// *
// * auto generated hardware configuration
// *
// ****************************************************************** */
//static btech_ur20_modbus_device *devices;
//static int deviceCount = 3;
//iec_main_task *g_IEC_Main_Task;

/******************************************************************
 *
 * auto generated global variables
 *
 ****************************************************************** */

/******************************************************************
 *
 * auto generated IOs
 *
 ****************************************************************** */
static iec_bool_datapoint *erdgFernsehzSoftTast = NULL;
static iec_bool_datapoint *erdgFernsehzRueckSoftTast = NULL;
static iec_bool_datapoint *erdgWintergMitteSoftTast = NULL;
static iec_bool_datapoint *erdgWintergHintenSoftTast = NULL;
static iec_bool_datapoint *erdgWintergWandSoftTast = NULL;
static iec_bool_datapoint *erdgEsszSoftTast = NULL;
static iec_bool_datapoint *erdgEsszKuechSoftTast = NULL;
static iec_bool_datapoint *erdgKuecheSoftTast = NULL;
static iec_bool_datapoint *erdgKuecheBoardSoftTast = NULL;

static iec_bool_datapoint *erdgSoftTast1Auf = NULL;
static iec_bool_datapoint *erdgSoftTast1Zu = NULL;
static iec_bool_datapoint *erdgSoftTast1Stop = NULL;

static iec_bool_datapoint *erdgSoftTastAllWintAuf = NULL;
static iec_bool_datapoint *erdgSoftTastAllWintZu = NULL;
static iec_bool_datapoint *erdgSoftTastAllWintStop = NULL;

static iec_bool_datapoint *erdgSoftTastAllKuechAuf = NULL;
static iec_bool_datapoint *erdgSoftTastAllKuechZu = NULL;
static iec_bool_datapoint *erdgSoftTastAllKuechStop = NULL;

static iec_bool_datapoint *erdgSoftTast2Auf = NULL;
static iec_bool_datapoint *erdgSoftTast2Zu = NULL;
static iec_bool_datapoint *erdgSoftTast2Stop = NULL;
static iec_bool_datapoint *erdgSoftTast3Auf = NULL;
static iec_bool_datapoint *erdgSoftTast3Zu = NULL;
static iec_bool_datapoint *erdgSoftTast3Stop = NULL;
static iec_bool_datapoint *erdgSoftTast4Auf = NULL;
static iec_bool_datapoint *erdgSoftTast4Zu = NULL;
static iec_bool_datapoint *erdgSoftTast4Stop = NULL;
static iec_bool_datapoint *erdgSoftTast5Auf = NULL;
static iec_bool_datapoint *erdgSoftTast5Zu = NULL;
static iec_bool_datapoint *erdgSoftTast5Stop = NULL;
static iec_bool_datapoint *erdgSoftTast6Auf = NULL;
static iec_bool_datapoint *erdgSoftTast6Zu = NULL;
static iec_bool_datapoint *erdgSoftTast6Stop = NULL;
static iec_bool_datapoint *erdgSoftTast7Auf = NULL;
static iec_bool_datapoint *erdgSoftTast7Zu = NULL;
static iec_bool_datapoint *erdgSoftTast7Stop = NULL;
static iec_bool_datapoint *erdgSoftTast8Auf = NULL;
static iec_bool_datapoint *erdgSoftTast8Zu = NULL;
static iec_bool_datapoint *erdgSoftTast8Stop = NULL;
static iec_bool_datapoint *erdgSoftTast9Auf = NULL;
static iec_bool_datapoint *erdgSoftTast9Zu = NULL;
static iec_bool_datapoint *erdgSoftTast9Stop = NULL;
static iec_bool_datapoint *erdgSoftTast10Auf = NULL;
static iec_bool_datapoint *erdgSoftTast10Zu = NULL;
static iec_bool_datapoint *erdgSoftTast10Stop = NULL;
static iec_bool_datapoint *erdgSoftTast11Auf = NULL;
static iec_bool_datapoint *erdgSoftTast11Zu = NULL;
static iec_bool_datapoint *erdgSoftTast11Stop = NULL;
static iec_bool_datapoint *erdgSoftTast12Auf = NULL;
static iec_bool_datapoint *erdgSoftTast12Zu = NULL;
static iec_bool_datapoint *erdgSoftTast12Stop = NULL;
static iec_bool_datapoint *erdgSoftTast13Auf = NULL;
static iec_bool_datapoint *erdgSoftTast13Zu = NULL;
static iec_bool_datapoint *erdgSoftTast13Stop = NULL;
static iec_bool_datapoint *erdgSoftTast14Auf = NULL;
static iec_bool_datapoint *erdgSoftTast14Zu = NULL;
static iec_bool_datapoint *erdgSoftTast14Stop = NULL;

static iec_bool_datapoint *stockSoftTast1Auf = NULL;
static iec_bool_datapoint *stockSoftTast1Zu = NULL;
static iec_bool_datapoint *stockSoftTast2Auf = NULL;
static iec_bool_datapoint *stockSoftTast2Zu = NULL;
static iec_bool_datapoint *stockSoftTast3Auf = NULL;
static iec_bool_datapoint *stockSoftTast3Zu = NULL;
static iec_bool_datapoint *stockSoftTast4Auf = NULL;
static iec_bool_datapoint *stockSoftTast4Zu = NULL;
static iec_bool_datapoint *stockSoftTast5Auf = NULL;
static iec_bool_datapoint *stockSoftTast5Zu = NULL;
static iec_bool_datapoint *stockSoftTast6Auf = NULL;
static iec_bool_datapoint *stockSoftTast6Zu = NULL;
static iec_bool_datapoint *stockSoftTast7Auf = NULL;
static iec_bool_datapoint *stockSoftTast7Zu = NULL;
static iec_bool_datapoint *stockSoftTast8Auf = NULL;
static iec_bool_datapoint *stockSoftTast8Zu = NULL;
static iec_bool_datapoint *stockSoftTast9Auf = NULL;
static iec_bool_datapoint *stockSoftTast9Zu = NULL;
static iec_bool_datapoint *stockSoftTast10Auf = NULL;
static iec_bool_datapoint *stockSoftTast10Zu = NULL;
static iec_bool_datapoint *stockSoftTast11Auf = NULL;
static iec_bool_datapoint *stockSoftTast11Zu = NULL;
static iec_bool_datapoint *stockSoftTast12Auf = NULL;
static iec_bool_datapoint *stockSoftTast12Zu = NULL;

static iec_bool_datapoint *erdgtaster1 = NULL;
static iec_bool_datapoint *erdgtaster2 = NULL;
static iec_bool_datapoint *erdgtaster3 = NULL;
static iec_bool_datapoint *erdgtaster4 = NULL;
static iec_bool_datapoint *erdgtaster5 = NULL;
static iec_bool_datapoint *erdgtaster6 = NULL;
static iec_bool_datapoint *erdgtaster7 = NULL;
static iec_bool_datapoint *erdgtaster8 = NULL;
static iec_bool_datapoint *erdgtaster9 = NULL;
static iec_bool_datapoint *erdgtaster10 = NULL;
static iec_bool_datapoint *erdgtaster11 = NULL;
static iec_bool_datapoint *erdgtaster12 = NULL;
static iec_bool_datapoint *erdgtaster13 = NULL;
static iec_bool_datapoint *erdgtaster14 = NULL;
static iec_bool_datapoint *erdgtaster15 = NULL;
static iec_bool_datapoint *erdgtaster16 = NULL;
static iec_bool_datapoint *erdgtaster17 = NULL;
static iec_bool_datapoint *erdgtaster18 = NULL;
static iec_bool_datapoint *erdgtaster19 = NULL;
static iec_bool_datapoint *erdgtaster20 = NULL;
static iec_bool_datapoint *erdgtaster21 = NULL;
static iec_bool_datapoint *erdgtaster22 = NULL;
static iec_bool_datapoint *erdgtaster23 = NULL;
static iec_bool_datapoint *erdgtaster24 = NULL;
static iec_bool_datapoint *erdgtaster25 = NULL;
static iec_bool_datapoint *erdgtaster26 = NULL;
static iec_bool_datapoint *erdgtaster27 = NULL;
static iec_bool_datapoint *erdgtaster28 = NULL;
static iec_bool_datapoint *erdgtaster29 = NULL;
static iec_bool_datapoint *erdgtaster30 = NULL;
static iec_bool_datapoint *erdgtaster31 = NULL;
static iec_bool_datapoint *erdgtaster32 = NULL;
static iec_bool_datapoint *erdgtaster33 = NULL;
static iec_bool_datapoint *erdgtaster34 = NULL;
static iec_bool_datapoint *erdgtaster35 = NULL;
static iec_bool_datapoint *erdgtaster36 = NULL;
static iec_bool_datapoint *erdgtaster37 = NULL;
static iec_bool_datapoint *erdgtaster38 = NULL;
static iec_bool_datapoint *erdgtaster39 = NULL;
static iec_bool_datapoint *erdgtaster40 = NULL;
static iec_bool_datapoint *erdgtaster41 = NULL;
static iec_bool_datapoint *erdgtaster42 = NULL;
static iec_bool_datapoint *erdgtaster43 = NULL;
static iec_bool_datapoint *erdgtaster44 = NULL;

static iec_bool_datapoint *kellertaster1 = NULL;
static iec_bool_datapoint *kellertaster2 = NULL;
static iec_bool_datapoint *kellertaster3 = NULL;
static iec_bool_datapoint *kellertaster4 = NULL;
static iec_bool_datapoint *kellertaster5 = NULL;
static iec_bool_datapoint *kellertaster6 = NULL;
static iec_bool_datapoint *kellertaster7 = NULL;
static iec_bool_datapoint *kellertaster8 = NULL;
static iec_bool_datapoint *kellertaster9 = NULL;
static iec_bool_datapoint *kellertaster10 = NULL;
static iec_bool_datapoint *kellertaster11 = NULL;
static iec_bool_datapoint *kellertaster12 = NULL;
static iec_bool_datapoint *kellertaster13 = NULL;
static iec_bool_datapoint *kellerstaubsauger15 = NULL;
static iec_bool_datapoint *kellerstaubsauger16 = NULL;

static iec_bool_datapoint *stocktaster1 = NULL;
static iec_bool_datapoint *stocktaster2 = NULL;
static iec_bool_datapoint *stocktaster3 = NULL;
static iec_bool_datapoint *stocktaster4 = NULL;
static iec_bool_datapoint *stocktaster5 = NULL;
static iec_bool_datapoint *stocktaster6 = NULL;
static iec_bool_datapoint *stocktaster7 = NULL;
static iec_bool_datapoint *stocktaster8 = NULL;
static iec_bool_datapoint *stocktaster9 = NULL;
static iec_bool_datapoint *stocktaster10 = NULL;
static iec_bool_datapoint *stocktaster11 = NULL;
static iec_bool_datapoint *stocktaster12 = NULL;
static iec_bool_datapoint *stocktaster13 = NULL;
static iec_bool_datapoint *stocktaster14 = NULL;
static iec_bool_datapoint *stocktaster15 = NULL;
static iec_bool_datapoint *stocktaster16 = NULL;
static iec_bool_datapoint *stocktaster17 = NULL;
static iec_bool_datapoint *stocktaster18 = NULL;
static iec_bool_datapoint *stocktaster19 = NULL;

static iec_bool_datapoint *erdglicht1 = NULL;
static iec_bool_datapoint *erdglicht2 = NULL;
static iec_bool_datapoint *erdglicht3 = NULL;
static iec_bool_datapoint *erdglicht4 = NULL;
static iec_bool_datapoint *erdglicht5 = NULL;
static iec_bool_datapoint *erdglicht6 = NULL;
static iec_bool_datapoint *erdglicht7 = NULL;
static iec_bool_datapoint *erdglicht8 = NULL;
static iec_bool_datapoint *erdglicht9 = NULL;
static iec_bool_datapoint *erdglicht10 = NULL;
static iec_bool_datapoint *erdglicht11 = NULL;

static iec_bool_datapoint *erdglicht21 = NULL;
static iec_bool_datapoint *erdglicht22 = NULL;
static iec_bool_datapoint *erdglicht23 = NULL;
static iec_bool_datapoint *erdglicht24 = NULL;
static iec_bool_datapoint *erdglicht25 = NULL;

static iec_bool_datapoint *erdglicht31 = NULL;
static iec_bool_datapoint *erdglicht32 = NULL;
static iec_bool_datapoint *erdglicht33 = NULL;
static iec_bool_datapoint *erdglicht34 = NULL;
static iec_bool_datapoint *erdglicht35 = NULL;			// Licht Garage 1
static iec_bool_datapoint *erdglicht36 = NULL;			// Licht Garage 2
static iec_bool_datapoint *erdglicht37 = NULL;
static iec_bool_datapoint *erdglicht38 = NULL;
static iec_bool_datapoint *erdglicht39 = NULL;
static iec_bool_datapoint *erdglicht40 = NULL;
static iec_bool_datapoint *erdglicht41 = NULL;
static iec_bool_datapoint *erdglicht42 = NULL;
static iec_bool_datapoint *erdglicht43 = NULL;

static iec_bool_datapoint *erdgmarkzu = NULL;
static iec_bool_datapoint *erdgmarkauf = NULL;

static iec_bool_datapoint *stocklicht1 = NULL;
static iec_bool_datapoint *stocklicht2 = NULL;
static iec_bool_datapoint *stocklicht3 = NULL;
static iec_bool_datapoint *stocklicht4 = NULL;
static iec_bool_datapoint *stocklicht5 = NULL;
static iec_bool_datapoint *stocklicht6 = NULL;
static iec_bool_datapoint *stocklicht7 = NULL;
static iec_bool_datapoint *stocklicht8 = NULL;
static iec_bool_datapoint *stocklicht9 = NULL;
static iec_bool_datapoint *stocklicht10 = NULL;

static iec_bool_datapoint *erdgroll2up = NULL;
static iec_bool_datapoint *erdgroll2down = NULL;
static iec_bool_datapoint *erdgroll3up = NULL;
static iec_bool_datapoint *erdgroll3down = NULL;
static iec_bool_datapoint *erdgroll4up = NULL;
static iec_bool_datapoint *erdgroll4down = NULL;
static iec_bool_datapoint *erdgroll5up = NULL;
static iec_bool_datapoint *erdgroll5down = NULL;
static iec_bool_datapoint *erdgroll6up = NULL;
static iec_bool_datapoint *erdgroll6down = NULL;
static iec_bool_datapoint *erdgroll7up = NULL;
static iec_bool_datapoint *erdgroll7down = NULL;
static iec_bool_datapoint *erdgroll8up = NULL;
static iec_bool_datapoint *erdgroll8down = NULL;
static iec_bool_datapoint *erdgroll9up = NULL;
static iec_bool_datapoint *erdgroll9down = NULL;
static iec_bool_datapoint *erdgroll10up = NULL;
static iec_bool_datapoint *erdgroll10down = NULL;
static iec_bool_datapoint *erdgroll11up = NULL;
static iec_bool_datapoint *erdgroll11down = NULL;
static iec_bool_datapoint *erdgroll12up = NULL;
static iec_bool_datapoint *erdgroll12down = NULL;
static iec_bool_datapoint *erdgroll13up = NULL;
static iec_bool_datapoint *erdgroll13down = NULL;
static iec_bool_datapoint *erdgroll14up = NULL;
static iec_bool_datapoint *erdgroll14down = NULL;

static iec_bool_datapoint *kellerlicht1 = NULL;
static iec_bool_datapoint *kellerlicht2 = NULL;
static iec_bool_datapoint *kellerlicht3 = NULL;
static iec_bool_datapoint *kellerlicht4 = NULL;
static iec_bool_datapoint *kellerlicht5 = NULL;
static iec_bool_datapoint *kellerlicht6 = NULL;
static iec_bool_datapoint *kellerlicht7 = NULL;
static iec_bool_datapoint *staubsauger = NULL;

/*
int main(int argc, char **argv)
{
	int opt = 0;
	while ((opt = getopt(argc, argv, "i:r:e:")) != -1)
	{
		switch (opt)
		{
		case 'i':
#define DEBUG_INITIALISE 1
			break;
		case 'r':
#define DEBUG_RUNTIME 1
			break;
		case 'e':
#define DEBUG_ERROR 1
			break;
		}
	}

	btech_mainloop();
}
*/

/********************************************************************
 *
 * helper variable declaration
 *
 ******************************************************************** */
static iec_multi_rising_switch *erdgLichtEsszimmer;
static iec_multi_rising_switch *erdgLichtKueche;
static iec_multi_rising_switch *erdgLichtKachelofen;
static iec_multi_rising_switch *erdgLichtEsszKueche;
static iec_multi_rising_switch *erdgLichtFernseher;
static iec_multi_rising_switch *erdgLichtFernseherWand;
static iec_multi_rising_switch *erdgLichtWintergMitte;
static iec_multi_rising_switch *erdgLichtWintergHinten;
static iec_multi_rising_switch *erdgLichtWintergWand;
static iec_multi_rising_switch *erdgLichtVorhaus;
static iec_multi_rising_switch *erdgLichtDurchgGarage;
static iec_multi_rising_switch *erdgLichtArbeitsz;
static iec_multi_rising_switch *erdgLichtKellerStiege;
static iec_multi_rising_switch *erdgLichtStockStiege;
static iec_multi_rising_switch *erdgLichtWC;
static iec_multi_rising_switch *erdgLichtEsszWand;
static iec_multi_rising_switch *erdgLichtKuecheBoard;
static iec_multi_rising_switch *erdgLichtGarage;
static iec_multi_rising_switch *erdgGaragentor;
static iec_multi_rising_switch *erdgLichtAussenEingang;
static iec_multi_rising_switch *erdgLichtAussenPosch;
static iec_multi_rising_switch *erdgLichtAussenHinten1;
static iec_multi_rising_switch *erdgLichtAussenHinten2;
static iec_multi_rising_switch *erdgLichtGarageStiege;
static iec_multi_rising_switch *erdgLichtGarageVorne;
static iec_multi_rising_switch *erdgLichtGarageHinten;
static iec_multi_rising_switch *erdgLichtGarageHintenWinterg;

static iec_multi_rising_switch *stockLichtVorhaus;
static iec_multi_rising_switch *stockLichtTimo;
static iec_multi_rising_switch *stockLichtDenise1;
static iec_multi_rising_switch *stockLichtDenise2;
static iec_multi_rising_switch *stockLichtSchlafz;
static iec_multi_rising_switch *stockLichtSchlafzRueck;
static iec_multi_rising_switch *stockLichtSchrankr;
static iec_multi_rising_switch *stockLichtBad;
static iec_multi_rising_switch *stockLichtWC;

static iec_rollo_switch *erdgMarkise;

//static iec_multi_rising_switch *erdgRollo2Auf;
static iec_rollo_switch *erdgRollo2;
static iec_rollo_switch *erdgRollo3;
static iec_rollo_switch *erdgRollo4;
static iec_rollo_switch *erdgRollo5;
static iec_rollo_switch *erdgRollo6;

static iec_rollo_switch *erdgRollo7;
static iec_rollo_switch *erdgRollo8;
static iec_rollo_switch *erdgRollo9;
static iec_rollo_switch *erdgRollo10;
static iec_rollo_switch *erdgRollo11;
static iec_rollo_switch *erdgRollo12;
static iec_rollo_switch *erdgRollo13;
static iec_rollo_switch *erdgRollo14;

static iec_multi_rising_switch *kellerLichtSpielzimmer;
static iec_multi_rising_switch *kellerLichtVorraum;
static iec_multi_rising_switch *kellerLichtBar;
static iec_multi_rising_switch *kellerLichtWC;
static iec_multi_rising_switch *kellerLichtWaschk;
static iec_multi_rising_switch *kellerLichtKaltraum;
static iec_multi_rising_switch *kellerLichtStaubsauger;

static iec_or *staubsaugerOr;

int btech_schedule_func1();

//iec_main_task *g_IEC_Main_Task;

int btech_initialize_func()
{

	btech_ur20_registerHardware();
	btech_readHardwareConfig();

#ifdef RUN_CLIENTCONN
	btech_startClientConnections();
#endif

	btech_initGeneralVariables(300);
	// TODO this should be done in hardware module
	//devices = malloc(sizeof(btech_ur20_modbus_device) * deviceCount);

	//if(!g_IEC_Main_Task)
//		printf("task structure not initialized!\n");

	//g_IEC_Main_Task->taskFunc = btech_schedule_func1;


	/******************************************************************
	 *
	 * initialize global variables
	 *
	 ****************************************************************** */

	/******************************************************************
	 *
	 * initialize all devices
	 * TODO this shuld be done in hardware module
	 ****************************************************************** *
	for (int i = 0; i < deviceCount; i++)
	{
#ifdef DEBUG_INITIALISE
		printf("initialize device%d\n", i);
#endif
		btech_ur20_deviceInit(&devices[i]);
	}

#ifdef DEBUG_INITIALISE
		printf("initialize devices finished\n");
#endif
	/******************************************************************
	 *
	 * initialize device0
	 *
	 ****************************************************************** */
	// btech_ur20_modbus_device *device = &devices[0];
	/**
	 * set address of u-remote coupler in ground floor
	 *
//	device->hostname = "10.0.0.29";
	device->hostname = "172.17.0.202";
	device->portno = 502;

	/**
	 * set all input modules
	 *
#ifdef DEBUG_INITIALISE
		printf("initialize digital input\n");
#endif
	device->digitalInCount = 3;
	device->inmodules = malloc(sizeof(btech_ur20_module) * 3);

	/**
	 * set all output modules
	 *
#ifdef DEBUG_INITIALISE
		printf("initialize digital output\n");
#endif
	device->digitalOutCount = 4;
	device->outmodules = malloc(sizeof(btech_ur20_module) * 4);

	/**
	 * initialize all input modules
	 *
	btech_ur20_16di_p_module_initialize(&device->inmodules[0]);
	btech_ur20_16di_p_module_initialize(&device->inmodules[1]);
	btech_ur20_16di_p_module_initialize(&device->inmodules[2]);

	/******************************************************************
	 *
	 * initialize all output modules
	 *
	btech_ur20_16do_p_module_initialize(&device->outmodules[0]);
	btech_ur20_16do_p_module_initialize(&device->outmodules[1]);
	btech_ur20_16do_p_module_initialize(&device->outmodules[2]);
	btech_ur20_16do_p_module_initialize(&device->outmodules[3]);

	/******************************************************************
	 *
	 * create the read message for the device
	 *
	 ****************************************************************** *
	btech_ur20_create_read_message(device);

	/******************************************************************
	 *
	 * initialize input mapping for device0
	 *
	 ****************************************************************** *
	erdgtaster1 = (iec_bool_datapoint *) &device->inmodules[0].dps[0];
	erdgtaster2 = (iec_bool_datapoint *) &device->inmodules[0].dps[1];
	erdgtaster3 = (iec_bool_datapoint *) &device->inmodules[0].dps[2];
	erdgtaster4 = (iec_bool_datapoint *) &device->inmodules[0].dps[3];
	erdgtaster5 = (iec_bool_datapoint *) &device->inmodules[0].dps[4];
	erdgtaster6 = (iec_bool_datapoint *) &device->inmodules[0].dps[5];
	erdgtaster7 = (iec_bool_datapoint *) &device->inmodules[0].dps[6];
	erdgtaster8 = (iec_bool_datapoint *) &device->inmodules[0].dps[7];
	erdgtaster9 = (iec_bool_datapoint *) &device->inmodules[0].dps[8];
	erdgtaster10 = (iec_bool_datapoint *) &device->inmodules[0].dps[9];
	erdgtaster11 = (iec_bool_datapoint *) &device->inmodules[0].dps[10];
	erdgtaster12 = (iec_bool_datapoint *) &device->inmodules[0].dps[11];
	erdgtaster13 = (iec_bool_datapoint *) &device->inmodules[0].dps[12];
	erdgtaster14 = (iec_bool_datapoint *) &device->inmodules[0].dps[13];
	erdgtaster15 = (iec_bool_datapoint *) &device->inmodules[0].dps[14];
	erdgtaster16 = (iec_bool_datapoint *) &device->inmodules[0].dps[15];

	erdgtaster17 = (iec_bool_datapoint *) &device->inmodules[1].dps[0];
	erdgtaster18 = (iec_bool_datapoint *) &device->inmodules[1].dps[1];
	erdgtaster19 = (iec_bool_datapoint *) &device->inmodules[1].dps[2];
	erdgtaster20 = (iec_bool_datapoint *) &device->inmodules[1].dps[3];
	erdgtaster21 = (iec_bool_datapoint *) &device->inmodules[1].dps[4];
	erdgtaster22 = (iec_bool_datapoint *) &device->inmodules[1].dps[5];
	erdgtaster23 = (iec_bool_datapoint *) &device->inmodules[1].dps[6];
	erdgtaster24 = (iec_bool_datapoint *) &device->inmodules[1].dps[7];
	erdgtaster25 = (iec_bool_datapoint *) &device->inmodules[1].dps[8];
	erdgtaster26 = (iec_bool_datapoint *) &device->inmodules[1].dps[9];
	erdgtaster27 = (iec_bool_datapoint *) &device->inmodules[1].dps[10];
	erdgtaster28 = (iec_bool_datapoint *) &device->inmodules[1].dps[11];
	erdgtaster29 = (iec_bool_datapoint *) &device->inmodules[1].dps[12];
	erdgtaster30 = (iec_bool_datapoint *) &device->inmodules[1].dps[13];
	erdgtaster31 = (iec_bool_datapoint *) &device->inmodules[1].dps[14];
	erdgtaster32 = (iec_bool_datapoint *) &device->inmodules[1].dps[15];
	erdgtaster33 = (iec_bool_datapoint *) &device->inmodules[2].dps[0];
	erdgtaster34 = (iec_bool_datapoint *) &device->inmodules[2].dps[1];
	erdgtaster35 = (iec_bool_datapoint *) &device->inmodules[2].dps[2];
	erdgtaster36 = (iec_bool_datapoint *) &device->inmodules[2].dps[3];
	erdgtaster37 = (iec_bool_datapoint *) &device->inmodules[2].dps[4];
	erdgtaster38 = (iec_bool_datapoint *) &device->inmodules[2].dps[5];
	erdgtaster39 = (iec_bool_datapoint *) &device->inmodules[2].dps[6];
	erdgtaster40 = (iec_bool_datapoint *) &device->inmodules[2].dps[7];
	erdgtaster41 = (iec_bool_datapoint *) &device->inmodules[2].dps[8];
	erdgtaster42 = (iec_bool_datapoint *) &device->inmodules[2].dps[9];
	erdgtaster43 = (iec_bool_datapoint *) &device->inmodules[2].dps[10];
	erdgtaster44 = (iec_bool_datapoint *) &device->inmodules[2].dps[11];

	/**********************************************************
	 *
	 * add input variables to general variables identified by its name
	 *
	 ********************************************************* */
	btech_addGeneralVariable((iec_datapoint*) erdgtaster1, "erdgtaster1");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster2, "erdgtaster2");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster3, "erdgtaster3");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster4, "erdgtaster4");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster5, "erdgtaster5");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster6, "erdgtaster6");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster7, "erdgtaster7");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster8, "erdgtaster8");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster9, "erdgtaster9");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster10, "erdgtaster10");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster11, "erdgtaster11");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster12, "erdgtaster12");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster13, "erdgtaster13");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster14, "erdgtaster14");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster15, "erdgtaster15");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster16, "erdgtaster16");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster17, "erdgtaster17");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster18, "erdgtaster18");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster19, "erdgtaster19");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster20, "erdgtaster20");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster21, "erdgtaster21");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster22, "erdgtaster22");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster23, "erdgtaster23");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster24, "erdgtaster24");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster25, "erdgtaster25");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster26, "erdgtaster26");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster27, "erdgtaster27");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster28, "erdgtaster28");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster29, "erdgtaster29");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster30, "erdgtaster30");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster31, "erdgtaster31");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster32, "erdgtaster32");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster33, "erdgtaster33");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster34, "erdgtaster34");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster35, "erdgtaster35");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster36, "erdgtaster36");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster37, "erdgtaster37");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster38, "erdgtaster38");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster39, "erdgtaster39");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster40, "erdgtaster40");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster41, "erdgtaster41");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster42, "erdgtaster42");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster43, "erdgtaster43");
	btech_addGeneralVariable((iec_datapoint*) erdgtaster44, "erdgtaster44");

	erdgEsszSoftTast = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgEsszSoftTast);
	btech_addGeneralVariable((iec_datapoint*) erdgEsszSoftTast, "erdgEsszSoftTast");

	erdgFernsehzSoftTast = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgFernsehzSoftTast);
	btech_addGeneralVariable((iec_datapoint*) erdgFernsehzSoftTast,
			"erdgFernsehzSoftTast");

	erdgFernsehzRueckSoftTast = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgFernsehzRueckSoftTast);
	btech_addGeneralVariable((iec_datapoint*) erdgFernsehzRueckSoftTast,
			"erdgFernsehzRueckSoftTast");

	erdgWintergMitteSoftTast = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgWintergMitteSoftTast);
	btech_addGeneralVariable((iec_datapoint*) erdgWintergMitteSoftTast,
			"erdgWintergMitteSoftTast");

	erdgWintergHintenSoftTast = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgWintergHintenSoftTast);
	btech_addGeneralVariable((iec_datapoint*) erdgWintergHintenSoftTast,
			"erdgWintergHintenSoftTast");

	erdgWintergWandSoftTast = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgWintergWandSoftTast);
	btech_addGeneralVariable((iec_datapoint*) erdgWintergWandSoftTast,
			"erdgWintergWandSoftTast");

	erdgEsszKuechSoftTast = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgEsszKuechSoftTast);
	btech_addGeneralVariable((iec_datapoint*) erdgEsszKuechSoftTast,
			"erdgEsszKuechSoftTast");

	erdgKuecheSoftTast = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgKuecheSoftTast);
	btech_addGeneralVariable((iec_datapoint*) erdgKuecheSoftTast, "erdgKuecheSoftTast");

	erdgKuecheBoardSoftTast = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgKuecheBoardSoftTast);
	btech_addGeneralVariable((iec_datapoint*) erdgKuecheBoardSoftTast,
			"erdgKuecheBoardSoftTast");

	erdgSoftTast1Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast1Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast1Auf, "erdgSoftTast1Auf");

	erdgSoftTastAllWintAuf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTastAllWintAuf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTastAllWintAuf,
			"erdgSoftTastAllWintAuf");

	erdgSoftTastAllKuechAuf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTastAllKuechAuf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTastAllKuechAuf,
			"erdgSoftTastAllKuechAuf");

	erdgSoftTast2Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast2Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast2Auf, "erdgSoftTast2Auf");
	erdgSoftTast3Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast3Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast3Auf, "erdgSoftTast3Auf");
	erdgSoftTast4Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast4Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast4Auf, "erdgSoftTast4Auf");
	erdgSoftTast5Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast5Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast5Auf, "erdgSoftTast5Auf");
	erdgSoftTast6Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast6Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast6Auf, "erdgSoftTast6Auf");
	erdgSoftTast7Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast7Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast7Auf, "erdgSoftTast7Auf");
	erdgSoftTast8Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast8Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast8Auf, "erdgSoftTast8Auf");
	erdgSoftTast9Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast9Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast9Auf, "erdgSoftTast9Auf");
	erdgSoftTast10Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast10Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast10Auf, "erdgSoftTast10Auf");
	erdgSoftTast11Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast11Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast11Auf, "erdgSoftTast11Auf");
	erdgSoftTast12Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast12Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast12Auf, "erdgSoftTast12Auf");
	erdgSoftTast13Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast13Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast13Auf, "erdgSoftTast13Auf");
	erdgSoftTast14Auf = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast14Auf);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast14Auf, "erdgSoftTast14Auf");

	erdgSoftTast1Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast1Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast1Zu, "erdgSoftTast1Zu");

	erdgSoftTastAllWintZu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTastAllWintZu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTastAllWintZu,
			"erdgSoftTastAllWintZu");

	erdgSoftTastAllKuechZu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTastAllKuechZu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTastAllKuechZu,
			"erdgSoftTastAllKuechZu");

	erdgSoftTast2Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast2Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast2Zu, "erdgSoftTast2Zu");
	erdgSoftTast3Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast3Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast3Zu, "erdgSoftTast3Zu");
	erdgSoftTast4Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast4Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast4Zu, "erdgSoftTast4Zu");

	erdgSoftTast5Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast5Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast5Zu, "erdgSoftTast5Zu");
	erdgSoftTast6Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast6Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast6Zu, "erdgSoftTast6Zu");
	erdgSoftTast7Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast7Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast7Zu, "erdgSoftTast7Zu");
	erdgSoftTast8Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast8Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast8Zu, "erdgSoftTast8Zu");
	erdgSoftTast9Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast9Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast9Zu, "erdgSoftTast9Zu");
	erdgSoftTast10Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast10Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast10Zu, "erdgSoftTast10Zu");
	erdgSoftTast11Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast11Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast11Zu, "erdgSoftTast11Zu");
	erdgSoftTast12Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast12Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast12Zu, "erdgSoftTast12Zu");
	erdgSoftTast13Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast13Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast13Zu, "erdgSoftTast13Zu");
	erdgSoftTast14Zu = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast14Zu);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast14Zu, "erdgSoftTast14Zu");

	erdgSoftTast1Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast1Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast1Stop, "erdgSoftTast1Stop");

	erdgSoftTastAllWintStop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTastAllWintStop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTastAllWintStop,
			"erdgSoftTastAllWintStop");

	erdgSoftTastAllKuechStop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTastAllKuechStop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTastAllKuechStop,
			"erdgSoftTastAllKuechStop");

	erdgSoftTast2Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast2Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast2Stop, "erdgSoftTast2Stop");
	erdgSoftTast3Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast3Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast3Stop, "erdgSoftTast3Stop");
	erdgSoftTast4Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast4Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast4Stop, "erdgSoftTast4Stop");
	erdgSoftTast5Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast5Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast5Stop, "erdgSoftTast5Stop");
	erdgSoftTast6Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast6Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast6Stop, "erdgSoftTast6Stop");
	erdgSoftTast7Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast7Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast7Stop, "erdgSoftTast7Stop");
	erdgSoftTast8Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast8Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast8Stop, "erdgSoftTast8Stop");
	erdgSoftTast9Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast9Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast9Stop, "erdgSoftTast9Stop");
	erdgSoftTast10Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast10Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast10Stop, "erdgSoftTast10Stop");
	erdgSoftTast11Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast11Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast11Stop, "erdgSoftTast11Stop");
	erdgSoftTast12Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast12Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast12Stop, "erdgSoftTast12Stop");
	erdgSoftTast13Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast13Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast13Stop, "erdgSoftTast13Stop");
	erdgSoftTast14Stop = malloc(sizeof(iec_bool_datapoint));
	btech_iec_bool_datapoint_initialize(erdgSoftTast14Stop);
	btech_addGeneralVariable((iec_datapoint*) erdgSoftTast14Stop, "erdgSoftTast14Stop");
	/******************************************************************
	 *
	 * initialize input mapping for device0
	 *
	 ****************************************************************** *
	erdgmarkauf = (iec_bool_datapoint *) &device->outmodules[0].dps[0];
	erdgmarkzu = (iec_bool_datapoint *) &device->outmodules[0].dps[1];
	erdgroll2up = (iec_bool_datapoint *) &device->outmodules[0].dps[2];
	erdgroll2down = (iec_bool_datapoint *) &device->outmodules[0].dps[3];
	erdgroll3up = (iec_bool_datapoint *) &device->outmodules[0].dps[4];
	erdgroll3down = (iec_bool_datapoint *) &device->outmodules[0].dps[5];
	erdgroll4up = (iec_bool_datapoint *) &device->outmodules[0].dps[6];
	erdgroll4down = (iec_bool_datapoint *) &device->outmodules[0].dps[7];
	erdgroll5up = (iec_bool_datapoint *) &device->outmodules[0].dps[8];
	erdgroll5down = (iec_bool_datapoint *) &device->outmodules[0].dps[9];
	erdgroll6up = (iec_bool_datapoint *) &device->outmodules[0].dps[10];
	erdgroll6down = (iec_bool_datapoint *) &device->outmodules[0].dps[11];
	erdgroll7up = (iec_bool_datapoint *) &device->outmodules[0].dps[12];
	erdgroll7down = (iec_bool_datapoint *) &device->outmodules[0].dps[13];
	erdgroll8up = (iec_bool_datapoint *) &device->outmodules[0].dps[14];
	erdgroll8down = (iec_bool_datapoint *) &device->outmodules[0].dps[15];

	erdgroll9up = (iec_bool_datapoint *) &device->outmodules[1].dps[0];
	erdgroll9down = (iec_bool_datapoint *) &device->outmodules[1].dps[1];
	erdgroll10up = (iec_bool_datapoint *) &device->outmodules[1].dps[2];
	erdgroll10down = (iec_bool_datapoint *) &device->outmodules[1].dps[3];
	erdgroll11up = (iec_bool_datapoint *) &device->outmodules[1].dps[4];
	erdgroll11down = (iec_bool_datapoint *) &device->outmodules[1].dps[5];
	erdgroll12up = (iec_bool_datapoint *) &device->outmodules[1].dps[6];
	erdgroll12down = (iec_bool_datapoint *) &device->outmodules[1].dps[7];
	erdgroll13up = (iec_bool_datapoint *) &device->outmodules[1].dps[8];
	erdgroll13down = (iec_bool_datapoint *) &device->outmodules[1].dps[9];
	erdgroll14up = (iec_bool_datapoint *) &device->outmodules[1].dps[10];
	erdgroll14down = (iec_bool_datapoint *) &device->outmodules[1].dps[11];

	erdglicht1 = (iec_bool_datapoint *) &device->outmodules[2].dps[0];
	erdglicht2 = (iec_bool_datapoint *) &device->outmodules[2].dps[1];
	erdglicht3 = (iec_bool_datapoint *) &device->outmodules[2].dps[2];
	erdglicht4 = (iec_bool_datapoint *) &device->outmodules[2].dps[3];
	erdglicht5 = (iec_bool_datapoint *) &device->outmodules[2].dps[4];
	erdglicht6 = (iec_bool_datapoint *) &device->outmodules[2].dps[5];
	erdglicht7 = (iec_bool_datapoint *) &device->outmodules[2].dps[6];
	erdglicht8 = (iec_bool_datapoint *) &device->outmodules[2].dps[7];
	erdglicht9 = (iec_bool_datapoint *) &device->outmodules[2].dps[8];
	erdglicht10 = (iec_bool_datapoint *) &device->outmodules[2].dps[9];
	erdglicht11 = (iec_bool_datapoint *) &device->outmodules[2].dps[10];

	erdglicht21 = (iec_bool_datapoint *) &device->outmodules[2].dps[11];
	erdglicht22 = (iec_bool_datapoint *) &device->outmodules[2].dps[12];
	erdglicht23 = (iec_bool_datapoint *) &device->outmodules[2].dps[13];
	erdglicht24 = (iec_bool_datapoint *) &device->outmodules[2].dps[14];
	erdglicht25 = (iec_bool_datapoint *) &device->outmodules[2].dps[15];

	erdglicht31 = (iec_bool_datapoint *) &device->outmodules[3].dps[0];
	erdglicht32 = (iec_bool_datapoint *) &device->outmodules[3].dps[1];
	erdglicht33 = (iec_bool_datapoint *) &device->outmodules[3].dps[2];
	erdglicht34 = (iec_bool_datapoint *) &device->outmodules[3].dps[3];
	erdglicht35 = (iec_bool_datapoint *) &device->outmodules[3].dps[4];
	erdglicht36 = (iec_bool_datapoint *) &device->outmodules[3].dps[5];
	erdglicht37 = (iec_bool_datapoint *) &device->outmodules[3].dps[6];
	erdglicht38 = (iec_bool_datapoint *) &device->outmodules[3].dps[7];
	erdglicht39 = (iec_bool_datapoint *) &device->outmodules[3].dps[8];
	erdglicht40 = (iec_bool_datapoint *) &device->outmodules[3].dps[9];
	erdglicht41 = (iec_bool_datapoint *) &device->outmodules[3].dps[10];
	erdglicht42 = (iec_bool_datapoint *) &device->outmodules[3].dps[11];
	erdglicht43 = (iec_bool_datapoint *) &device->outmodules[3].dps[12];
//	erdglicht40 = (iec_bool_datapoint *) &device->outmodules[3].dps[9];

	/**********************************************************
	 *
	 * add output variables to general variables identified by its name
	 *
	 ********************************************************* */
	btech_addGeneralVariable((iec_datapoint*) erdgmarkauf, "erdgmarkauf");
	btech_addGeneralVariable((iec_datapoint*) erdgmarkzu, "erdgmarkzu");
	btech_addGeneralVariable((iec_datapoint*) erdgroll2up, "erdgroll2up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll2down, "erdgroll2down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll3up, "erdgroll3up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll3down, "erdgroll3down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll4up, "erdgroll4up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll4down, "erdgroll4down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll5up, "erdgroll5up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll5down, "erdgroll5down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll6up, "erdgroll6up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll6down, "erdgroll6down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll7up, "erdgroll7up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll7down, "erdgroll7down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll8up, "erdgroll8up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll8down, "erdgroll8down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll9up, "erdgroll9up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll9down, "erdgroll9down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll10up, "erdgroll10up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll10down, "erdgroll10down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll11up, "erdgroll11up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll11down, "erdgroll11down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll12up, "erdgroll12up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll12down, "erdgroll12down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll13up, "erdgroll13up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll13down, "erdgroll13down");
	btech_addGeneralVariable((iec_datapoint*) erdgroll14up, "erdgroll14up");
	btech_addGeneralVariable((iec_datapoint*) erdgroll14down, "erdgroll14down");

	btech_addGeneralVariable((iec_datapoint*) erdglicht1, "erdglicht1");
	btech_addGeneralVariable((iec_datapoint*) erdglicht2, "erdglicht2");
	btech_addGeneralVariable((iec_datapoint*) erdglicht3, "erdglicht3");
	btech_addGeneralVariable((iec_datapoint*) erdglicht4, "erdglicht4");
	btech_addGeneralVariable((iec_datapoint*) erdglicht5, "erdglicht5");
	btech_addGeneralVariable((iec_datapoint*) erdglicht6, "erdglicht6");
	btech_addGeneralVariable((iec_datapoint*) erdglicht7, "erdglicht7");
	btech_addGeneralVariable((iec_datapoint*) erdglicht8, "erdglicht8");
	btech_addGeneralVariable((iec_datapoint*) erdglicht9, "erdglicht9");
	btech_addGeneralVariable((iec_datapoint*) erdglicht10, "erdglicht10");
	btech_addGeneralVariable((iec_datapoint*) erdglicht11, "erdglicht11");
	btech_addGeneralVariable((iec_datapoint*) erdglicht21, "erdglicht21");
	btech_addGeneralVariable((iec_datapoint*) erdglicht22, "erdglicht22");
	btech_addGeneralVariable((iec_datapoint*) erdglicht23, "erdglicht23");
	btech_addGeneralVariable((iec_datapoint*) erdglicht24, "erdglicht24");
	btech_addGeneralVariable((iec_datapoint*) erdglicht25, "erdglicht25");
	btech_addGeneralVariable((iec_datapoint*) erdglicht31, "erdglicht31");
	btech_addGeneralVariable((iec_datapoint*) erdglicht32, "erdglicht32");
	btech_addGeneralVariable((iec_datapoint*) erdglicht33, "erdglicht33");
	btech_addGeneralVariable((iec_datapoint*) erdglicht34, "erdglicht34");
	btech_addGeneralVariable((iec_datapoint*) erdglicht35, "erdglicht35");
	btech_addGeneralVariable((iec_datapoint*) erdglicht36, "erdglicht36");
	btech_addGeneralVariable((iec_datapoint*) erdglicht37, "erdglicht37");
	btech_addGeneralVariable((iec_datapoint*) erdglicht38, "erdglicht38");
	btech_addGeneralVariable((iec_datapoint*) erdglicht39, "erdglicht39");
	btech_addGeneralVariable((iec_datapoint*) erdglicht40, "erdglicht40");
	btech_addGeneralVariable((iec_datapoint*) erdglicht41, "erdglicht41");
	btech_addGeneralVariable((iec_datapoint*) erdglicht42, "erdglicht42");
	btech_addGeneralVariable((iec_datapoint*) erdglicht43, "erdglicht43");

	/******************************************************************
	 *
	 * initialize global variables
	 *
	 ***************************************d************************* */
	erdgLichtFernseher = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtFernseher->input = malloc(sizeof(iec_bool_datapoint*) * 3);
	erdgLichtFernseher->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 3);
	erdgLichtFernseher->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtFernseher->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtFernseher->inputcount = 3;
	erdgLichtFernseher->input[0] = erdgtaster1;
	erdgLichtFernseher->input[1] = erdgtaster32;
	erdgLichtFernseher->input[2] = erdgFernsehzSoftTast;
	btech_iec_bool_datapoint_initialize(&erdgLichtFernseher->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtFernseher->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(&erdgLichtFernseher->oldrisingvalue[2]);
	btech_iec_bool_datapoint_initialize(erdgLichtFernseher->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtFernseher->oldtogglevalue);
	erdgLichtFernseher->output = erdglicht1;

	erdgLichtKachelofen = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtKachelofen->input = malloc(sizeof(iec_bool_datapoint*));
	erdgLichtKachelofen->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtKachelofen->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtKachelofen->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtKachelofen->inputcount = 1;
	erdgLichtKachelofen->input[0] = erdgtaster6;
	btech_iec_bool_datapoint_initialize(&erdgLichtKachelofen->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(erdgLichtKachelofen->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtKachelofen->oldtogglevalue);
	erdgLichtKachelofen->output = erdglicht2;

	erdgLichtEsszimmer = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtEsszimmer->input = malloc(sizeof(iec_bool_datapoint*) * 3);
	erdgLichtEsszimmer->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 3);
	erdgLichtEsszimmer->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtEsszimmer->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtEsszimmer->inputcount = 3;
	erdgLichtEsszimmer->input[0] = erdgtaster8;
	erdgLichtEsszimmer->input[1] = erdgtaster9;
	erdgLichtEsszimmer->input[2] = erdgEsszSoftTast;
	btech_iec_bool_datapoint_initialize(&erdgLichtEsszimmer->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtEsszimmer->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(&erdgLichtEsszimmer->oldrisingvalue[2]);
	btech_iec_bool_datapoint_initialize(erdgLichtEsszimmer->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtEsszimmer->oldtogglevalue);
	erdgLichtEsszimmer->output = erdglicht3;

	erdgLichtEsszKueche = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtEsszKueche->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtEsszKueche->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 2);
	erdgLichtEsszKueche->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtEsszKueche->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtEsszKueche->inputcount = 2;
	erdgLichtEsszKueche->input[0] = erdgtaster10;
	erdgLichtEsszKueche->input[1] = erdgtaster44;
	btech_iec_bool_datapoint_initialize(&erdgLichtEsszKueche->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtEsszKueche->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtEsszKueche->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtEsszKueche->oldtogglevalue);
	erdgLichtEsszKueche->output = erdglicht4;

	erdgLichtKueche = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtKueche->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtKueche->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 2);
	erdgLichtKueche->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtKueche->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtKueche->inputcount = 2;
	erdgLichtKueche->input[0] = erdgtaster11;
	erdgLichtKueche->input[1] = erdgtaster43;
	btech_iec_bool_datapoint_initialize(&erdgLichtKueche->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtKueche->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtKueche->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtKueche->oldtogglevalue);
	erdgLichtKueche->output = erdglicht5;

	erdgLichtVorhaus = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtVorhaus->input = malloc(sizeof(iec_bool_datapoint*) * 3);
	erdgLichtVorhaus->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 3);
	erdgLichtVorhaus->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtVorhaus->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtVorhaus->inputcount = 3;
	erdgLichtVorhaus->input[0] = erdgtaster17;
	erdgLichtVorhaus->input[1] = erdgtaster18;
	erdgLichtVorhaus->input[2] = erdgtaster20;
	btech_iec_bool_datapoint_initialize(&erdgLichtVorhaus->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtVorhaus->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(&erdgLichtVorhaus->oldrisingvalue[2]);
	btech_iec_bool_datapoint_initialize(erdgLichtVorhaus->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtVorhaus->oldtogglevalue);
	erdgLichtVorhaus->output = erdglicht6;

	erdgLichtDurchgGarage = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtDurchgGarage->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtDurchgGarage->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint) * 2);
	erdgLichtDurchgGarage->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtDurchgGarage->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtDurchgGarage->inputcount = 2;
	erdgLichtDurchgGarage->input[0] = erdgtaster22;
	erdgLichtDurchgGarage->input[1] = erdgtaster24;
	btech_iec_bool_datapoint_initialize(&erdgLichtDurchgGarage->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtDurchgGarage->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtDurchgGarage->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtDurchgGarage->oldtogglevalue);
	erdgLichtDurchgGarage->output = erdglicht7;

	erdgLichtArbeitsz = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtArbeitsz->input = malloc(sizeof(iec_bool_datapoint*));
	erdgLichtArbeitsz->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtArbeitsz->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtArbeitsz->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtArbeitsz->inputcount = 1;
	erdgLichtArbeitsz->input[0] = erdgtaster23;
	btech_iec_bool_datapoint_initialize(&erdgLichtArbeitsz->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(erdgLichtArbeitsz->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtArbeitsz->oldtogglevalue);
	erdgLichtArbeitsz->output = erdglicht8;

	erdgLichtWintergWand = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtWintergWand->input = malloc(sizeof(iec_bool_datapoint*)*2);
	erdgLichtWintergWand->oldrisingvalue = malloc(sizeof(iec_bool_datapoint)*2);
	erdgLichtWintergWand->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtWintergWand->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtWintergWand->inputcount = 2;
	erdgLichtWintergWand->input[0] = erdgtaster3;
	erdgLichtWintergWand->input[1] = erdgWintergWandSoftTast;
	btech_iec_bool_datapoint_initialize(&erdgLichtWintergWand->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtWintergWand->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtWintergWand->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtWintergWand->oldtogglevalue);
	erdgLichtWintergWand->output = erdglicht10;

	erdgLichtWC = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtWC->input = malloc(sizeof(iec_bool_datapoint*));
	erdgLichtWC->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtWC->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtWC->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtWC->inputcount = 1;
	erdgLichtWC->input[0] = erdgtaster16;
	btech_iec_bool_datapoint_initialize(&erdgLichtWC->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(erdgLichtWC->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtWC->oldtogglevalue);
	erdgLichtWC->output = erdglicht11;

	erdgLichtWintergMitte = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtWintergMitte->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtWintergMitte->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint) * 2);
	erdgLichtWintergMitte->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtWintergMitte->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtWintergMitte->inputcount = 2;
	erdgLichtWintergMitte->input[0] = erdgtaster30;
	erdgLichtWintergMitte->input[1] = erdgWintergMitteSoftTast;
	btech_iec_bool_datapoint_initialize(&erdgLichtWintergMitte->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtWintergMitte->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtWintergMitte->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtWintergMitte->oldtogglevalue);
	erdgLichtWintergMitte->output = erdglicht21;

	erdgLichtWintergHinten = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtWintergHinten->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtWintergHinten->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint) * 2);
	erdgLichtWintergHinten->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtWintergHinten->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtWintergHinten->inputcount = 2;
	erdgLichtWintergHinten->input[0] = erdgtaster3;
	erdgLichtWintergHinten->input[1] = erdgWintergHintenSoftTast;
	btech_iec_bool_datapoint_initialize(&erdgLichtWintergHinten->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtWintergHinten->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtWintergHinten->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtWintergHinten->oldtogglevalue);
	erdgLichtWintergHinten->output = erdglicht22;

	erdgLichtFernseherWand = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtFernseherWand->input = malloc(sizeof(iec_bool_datapoint*) * 3);
	erdgLichtFernseherWand->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint) * 3);
	erdgLichtFernseherWand->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtFernseherWand->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtFernseherWand->inputcount = 3;
	erdgLichtFernseherWand->input[0] = erdgtaster2;
	erdgLichtFernseherWand->input[1] = erdgtaster31;
	erdgLichtFernseherWand->input[2] = erdgFernsehzRueckSoftTast;
	btech_iec_bool_datapoint_initialize(&erdgLichtFernseherWand->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtFernseherWand->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(&erdgLichtFernseherWand->oldrisingvalue[2]);
	btech_iec_bool_datapoint_initialize(erdgLichtFernseherWand->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtFernseherWand->oldtogglevalue);
	erdgLichtFernseherWand->output = erdglicht23;

	erdgLichtEsszWand = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtEsszWand->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtEsszWand->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 2);
	erdgLichtEsszWand->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtEsszWand->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtEsszWand->inputcount = 2;
	erdgLichtEsszWand->input[0] = erdgtaster35;
	erdgLichtEsszWand->input[1] = erdgEsszKuechSoftTast;
	btech_iec_bool_datapoint_initialize(&erdgLichtEsszWand->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtEsszWand->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtEsszWand->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtEsszWand->oldtogglevalue);
	erdgLichtEsszWand->output = erdglicht24;

	erdgLichtKuecheBoard = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtKuecheBoard->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtKuecheBoard->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 2);
	erdgLichtKuecheBoard->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtKuecheBoard->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtKuecheBoard->inputcount = 2;
	erdgLichtKuecheBoard->input[0] = erdgtaster12;
	erdgLichtKuecheBoard->input[1] = erdgKuecheBoardSoftTast;
	btech_iec_bool_datapoint_initialize(&erdgLichtKuecheBoard->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtKuecheBoard->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtKuecheBoard->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtKuecheBoard->oldtogglevalue);
	erdgLichtKuecheBoard->output = erdglicht25;

	erdgLichtGarage = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtGarage->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtGarage->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 2);
	erdgLichtGarage->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtGarage->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtGarage->inputcount = 2;
	erdgLichtGarage->input[0] = erdgtaster25;
	erdgLichtGarage->input[1] = erdgtaster39;
	btech_iec_bool_datapoint_initialize(&erdgLichtGarage->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtGarage->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtGarage->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtGarage->oldtogglevalue);
	erdgLichtGarage->output = erdglicht35;
	erdglicht36->value = erdglicht35->value;

//	erdgGaragentor = malloc(sizeof(iec_multi_rising_switch));
//	erdgGaragentor->input = malloc(sizeof(iec_bool_datapoint*));
//	erdgGaragentor->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgGaragentor->risingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgGaragentor->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
//	erdgGaragentor->inputcount = 1;
//	erdgGaragentor->input[0] = erdgtaster36;
//	btech_iec_bool_datapoint_initialize(&erdgGaragentor->oldrisingvalue[0]);
//	btech_iec_bool_datapoint_initialize(erdgGaragentor->risingvalue);
//	btech_iec_bool_datapoint_initialize(erdgGaragentor->oldtogglevalue);
//	erdgGaragentor->output = erdggaragentor41;

	/**
	 * aussenlicht
	 */
	erdgLichtAussenEingang = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtAussenEingang->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtAussenEingang->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint) * 2);
	erdgLichtAussenEingang->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenEingang->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenEingang->inputcount = 2;
	erdgLichtAussenEingang->input[0] = erdgtaster15;
	erdgLichtAussenEingang->input[1] = erdgtaster27;
	btech_iec_bool_datapoint_initialize(&erdgLichtAussenEingang->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtAussenEingang->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtAussenEingang->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtAussenEingang->oldtogglevalue);
	erdgLichtAussenEingang->output = erdglicht31;

	erdgLichtAussenPosch = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtAussenPosch->input = malloc(sizeof(iec_bool_datapoint*) * 1);
	erdgLichtAussenPosch->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 1);
	erdgLichtAussenPosch->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenPosch->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenPosch->inputcount = 1;
	erdgLichtAussenPosch->input[0] = erdgtaster26;
	btech_iec_bool_datapoint_initialize(&erdgLichtAussenPosch->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(erdgLichtAussenPosch->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtAussenPosch->oldtogglevalue);
	erdgLichtAussenPosch->output = erdglicht32;

	erdgLichtAussenHinten1 = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtAussenHinten1->input = malloc(sizeof(iec_bool_datapoint*));
	erdgLichtAussenHinten1->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenHinten1->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenHinten1->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenHinten1->inputcount = 1;
	erdgLichtAussenHinten1->input[0] = erdgtaster4;
	btech_iec_bool_datapoint_initialize(&erdgLichtAussenHinten1->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(erdgLichtAussenHinten1->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtAussenHinten1->oldtogglevalue);
	erdgLichtAussenHinten1->output = erdglicht33;

	erdgLichtAussenHinten2 = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtAussenHinten2->input = malloc(sizeof(iec_bool_datapoint*));
	erdgLichtAussenHinten2->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenHinten2->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenHinten2->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtAussenHinten2->inputcount = 1;
	erdgLichtAussenHinten2->input[0] = erdgtaster5;
	btech_iec_bool_datapoint_initialize(&erdgLichtAussenHinten2->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(erdgLichtAussenHinten2->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtAussenHinten2->oldtogglevalue);
	erdgLichtAussenHinten2->output = erdglicht34;

	erdgLichtGarageStiege = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtGarageStiege->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtGarageStiege->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint) * 2);
	erdgLichtGarageStiege->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtGarageStiege->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtGarageStiege->inputcount = 2;
	erdgLichtGarageStiege->input[0] = erdgtaster36;
	erdgLichtGarageStiege->input[1] = erdgtaster40;
	btech_iec_bool_datapoint_initialize(&erdgLichtGarageStiege->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtGarageStiege->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtGarageStiege->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtGarageStiege->oldtogglevalue);
	erdgLichtGarageStiege->output = erdglicht37;

	erdgLichtGarageVorne = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtGarageVorne->input = malloc(sizeof(iec_bool_datapoint*));
	erdgLichtGarageVorne->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtGarageVorne->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtGarageVorne->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtGarageVorne->inputcount = 1;
	erdgLichtGarageVorne->input[0] = erdgtaster38;
	btech_iec_bool_datapoint_initialize(&erdgLichtGarageVorne->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(erdgLichtGarageVorne->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtGarageVorne->oldtogglevalue);
	erdgLichtGarageVorne->output = erdglicht38;
	erdglicht39->value = erdglicht38->value;

	erdgLichtGarageHintenWinterg = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtGarageHintenWinterg->input = malloc(sizeof(iec_bool_datapoint*));
	erdgLichtGarageHintenWinterg->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint));
	erdgLichtGarageHintenWinterg->risingvalue = malloc(
			sizeof(iec_bool_datapoint));
	erdgLichtGarageHintenWinterg->oldtogglevalue = malloc(
			sizeof(iec_bool_datapoint));
	erdgLichtGarageHintenWinterg->inputcount = 1;
	erdgLichtGarageHintenWinterg->input[0] = erdgtaster41;
	btech_iec_bool_datapoint_initialize(
			&erdgLichtGarageHintenWinterg->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(erdgLichtGarageHintenWinterg->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtGarageHintenWinterg->oldtogglevalue);
	erdgLichtGarageHintenWinterg->output = erdglicht40;

//	erdgMarkiseAuf = malloc(sizeof(iec_multi_rising_switch));
//	erdgMarkiseAuf->input = malloc(sizeof(iec_bool_datapoint*));
//	erdgMarkiseAuf->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgMarkiseAuf->risingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgMarkiseAuf->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
//	erdgMarkiseAuf->inputcount = 1;
//	erdgMarkiseAuf->input[0] = erdgSoftTast1Auf;
//	btech_iec_bool_datapoint_initialize(&erdgMarkiseAuf->oldrisingvalue[0]);
//	btech_iec_bool_datapoint_initialize(erdgMarkiseAuf->risingvalue);
//	btech_iec_bool_datapoint_initialize(erdgMarkiseAuf->oldtogglevalue);
//	erdgMarkiseAuf->output = erdgmarkauf;
//
//	erdgMarkiseZu = malloc(sizeof(iec_multi_rising_switch));
//	erdgMarkiseZu->input = malloc(sizeof(iec_bool_datapoint*));
//	erdgMarkiseZu->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgMarkiseZu->risingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgMarkiseZu->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
//	erdgMarkiseZu->inputcount = 1;
//	erdgMarkiseAuf->input[0] = erdgSoftTast1Zu;
//	btech_iec_bool_datapoint_initialize(&erdgMarkiseZu->oldrisingvalue[0]);
//	btech_iec_bool_datapoint_initialize(erdgMarkiseZu->risingvalue);
//	btech_iec_bool_datapoint_initialize(erdgMarkiseZu->oldtogglevalue);
//	erdgMarkiseZu->output = erdgmarkzu;

	erdgMarkise = malloc(sizeof(iec_rollo_switch));
	erdgMarkise->inputup = malloc(sizeof(iec_bool_datapoint*));
	erdgMarkise->inputdown = malloc(sizeof(iec_bool_datapoint*));
	erdgMarkise->inputstop = malloc(sizeof(iec_bool_datapoint*));
	erdgMarkise->inputcountup = 2;
	erdgMarkise->inputcountstop = 1;
	erdgMarkise->inputcountdown = 2;
	erdgMarkise->inputup[0] = erdgtaster28;
	erdgMarkise->inputup[1] = erdgSoftTast1Auf;
	erdgMarkise->inputdown[0] = erdgtaster29;
	erdgMarkise->inputdown[1] = erdgSoftTast1Zu;
	erdgMarkise->inputstop[0] = erdgSoftTast1Stop;
	erdgMarkise->outputup = erdgmarkzu;
	erdgMarkise->outputdown = erdgmarkauf;

	erdgRollo2 = malloc(sizeof(iec_rollo_switch));
	erdgRollo2->inputup = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo2->inputdown = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo2->inputstop = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo2->inputcountup = 2;
	erdgRollo2->inputcountstop = 2;
	erdgRollo2->inputcountdown = 2;
	erdgRollo2->inputup[0] = erdgSoftTast2Auf;
	erdgRollo2->inputup[1] = erdgSoftTastAllWintAuf;
	erdgRollo2->inputdown[0] = erdgSoftTast2Zu;
	erdgRollo2->inputdown[1] = erdgSoftTastAllWintZu;
	erdgRollo2->inputstop[0] = erdgSoftTast2Stop;
	erdgRollo2->inputstop[1] = erdgSoftTastAllWintStop;
	erdgRollo2->outputup = erdgroll2up;
	erdgRollo2->outputdown = erdgroll2down;

	erdgRollo3 = malloc(sizeof(iec_rollo_switch));
	erdgRollo3->inputup = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo3->inputdown = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo3->inputstop = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo3->inputcountup = 2;
	erdgRollo3->inputcountstop = 2;
	erdgRollo3->inputcountdown = 2;
	erdgRollo3->inputup[0] = erdgSoftTast3Auf;
	erdgRollo3->inputup[1] = erdgSoftTastAllWintAuf;
	erdgRollo3->inputdown[0] = erdgSoftTast3Zu;
	erdgRollo3->inputdown[1] = erdgSoftTastAllWintZu;
	erdgRollo3->inputstop[0] = erdgSoftTast3Stop;
	erdgRollo3->inputstop[1] = erdgSoftTastAllWintStop;
	erdgRollo3->outputup = erdgroll3up;
	erdgRollo3->outputdown = erdgroll3down;

	erdgRollo4 = malloc(sizeof(iec_rollo_switch));
	erdgRollo4->inputup = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo4->inputdown = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo4->inputstop = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo4->inputcountup = 2;
	erdgRollo4->inputcountstop = 2;
	erdgRollo4->inputcountdown = 2;
	erdgRollo4->inputup[0] = erdgSoftTast4Auf;
	erdgRollo4->inputup[1] = erdgSoftTastAllWintAuf;
	erdgRollo4->inputdown[0] = erdgSoftTast4Zu;
	erdgRollo4->inputdown[1] = erdgSoftTastAllWintZu;
	erdgRollo4->inputstop[0] = erdgSoftTast4Stop;
	erdgRollo4->inputstop[1] = erdgSoftTastAllWintStop;
	erdgRollo4->outputup = erdgroll4up;
	erdgRollo4->outputdown = erdgroll4down;

	erdgRollo5 = malloc(sizeof(iec_rollo_switch));
	erdgRollo5->inputup = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo5->inputdown = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo5->inputstop = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo5->inputcountup = 2;
	erdgRollo5->inputcountstop = 2;
	erdgRollo5->inputcountdown = 2;
	erdgRollo5->inputup[0] = erdgSoftTast5Auf;
	erdgRollo5->inputup[1] = erdgSoftTastAllWintAuf;
	erdgRollo5->inputdown[0] = erdgSoftTast5Zu;
	erdgRollo5->inputdown[1] = erdgSoftTastAllWintZu;
	erdgRollo5->inputstop[0] = erdgSoftTast5Stop;
	erdgRollo5->inputstop[1] = erdgSoftTastAllWintStop;
	erdgRollo5->outputup = erdgroll5up;
	erdgRollo5->outputdown = erdgroll5down;

	erdgRollo6 = malloc(sizeof(iec_rollo_switch));
	erdgRollo6->inputup = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo6->inputdown = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo6->inputstop = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo6->inputcountup = 2;
	erdgRollo6->inputcountstop = 2;
	erdgRollo6->inputcountdown = 2;
	erdgRollo6->inputup[0] = erdgSoftTast6Auf;
	erdgRollo6->inputup[1] = erdgSoftTastAllWintAuf;
	erdgRollo6->inputdown[0] = erdgSoftTast6Zu;
	erdgRollo6->inputdown[1] = erdgSoftTastAllWintZu;
	erdgRollo6->inputstop[0] = erdgSoftTast6Stop;
	erdgRollo6->inputstop[1] = erdgSoftTastAllWintStop;
	erdgRollo6->outputup = erdgroll6up;
	erdgRollo6->outputdown = erdgroll6down;

	erdgRollo7 = malloc(sizeof(iec_rollo_switch));
	erdgRollo7->inputup = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo7->inputdown = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo7->inputstop = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo7->inputcountup = 1;
	erdgRollo7->inputcountstop = 1;
	erdgRollo7->inputcountdown = 1;
	erdgRollo7->inputup[0] = erdgSoftTast7Auf;
	erdgRollo7->inputdown[0] = erdgSoftTast7Zu;
	erdgRollo7->inputstop[0] = erdgSoftTast7Stop;
	erdgRollo7->outputup = erdgroll7up;
	erdgRollo7->outputdown = erdgroll7down;

	erdgRollo8 = malloc(sizeof(iec_rollo_switch));
	erdgRollo8->inputup = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo8->inputdown = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo8->inputstop = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo8->inputcountup = 1;
	erdgRollo8->inputcountstop = 1;
	erdgRollo8->inputcountdown = 1;
	erdgRollo8->inputup[0] = erdgSoftTast8Auf;
	erdgRollo8->inputdown[0] = erdgSoftTast8Zu;
	erdgRollo8->inputstop[0] = erdgSoftTast8Stop;
	erdgRollo8->outputup = erdgroll8up;
	erdgRollo8->outputdown = erdgroll8down;

	erdgRollo9 = malloc(sizeof(iec_rollo_switch));
	erdgRollo9->inputup = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo9->inputdown = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo9->inputstop = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo9->inputcountup = 1;
	erdgRollo9->inputcountstop = 1;
	erdgRollo9->inputcountdown = 1;
	erdgRollo9->inputup[0] = erdgSoftTast9Auf;
	erdgRollo9->inputdown[0] = erdgSoftTast9Zu;
	erdgRollo9->inputstop[0] = erdgSoftTast9Stop;
	erdgRollo9->outputup = erdgroll9up;
	erdgRollo9->outputdown = erdgroll9down;

	/**
	 * rollo kueche
	 */
	erdgRollo10 = malloc(sizeof(iec_rollo_switch));
	erdgRollo10->inputup = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo10->inputdown = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo10->inputstop = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo10->inputcountup = 2;
	erdgRollo10->inputcountstop = 2;
	erdgRollo10->inputcountdown = 2;
	erdgRollo10->inputup[0] = erdgSoftTastAllKuechAuf;
	erdgRollo10->inputup[1] = erdgSoftTast10Auf;
	erdgRollo10->inputdown[0] = erdgSoftTastAllKuechZu;
	erdgRollo10->inputdown[1] = erdgSoftTast10Zu;
	erdgRollo10->inputstop[0] = erdgSoftTast10Stop;
	erdgRollo10->inputstop[1] = erdgSoftTastAllKuechStop;
	erdgRollo10->outputup = erdgroll10up;
	erdgRollo10->outputdown = erdgroll10down;

	erdgRollo11 = malloc(sizeof(iec_rollo_switch));
	erdgRollo11->inputup = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo11->inputdown = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo11->inputstop = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo11->inputcountup = 2;
	erdgRollo11->inputcountstop = 2;
	erdgRollo11->inputcountdown = 2;
	erdgRollo11->inputup[0] = erdgSoftTast11Auf;
	erdgRollo11->inputup[1] = erdgSoftTastAllKuechAuf;
	erdgRollo11->inputdown[0] = erdgSoftTast11Zu;
	erdgRollo11->inputdown[1] = erdgSoftTastAllKuechZu;
	erdgRollo11->inputstop[0] = erdgSoftTast11Stop;
	erdgRollo11->inputstop[1] = erdgSoftTastAllKuechStop;
	erdgRollo11->outputup = erdgroll11up;
	erdgRollo11->outputdown = erdgroll11down;

	erdgRollo12 = malloc(sizeof(iec_rollo_switch));
	erdgRollo12->inputup = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo12->inputdown = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo12->inputstop = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo12->inputcountup = 2;
	erdgRollo12->inputcountstop = 2;
	erdgRollo12->inputcountdown = 2;
	erdgRollo12->inputup[0] = erdgSoftTast12Auf;
	erdgRollo12->inputup[1] = erdgSoftTastAllKuechAuf;
	erdgRollo12->inputdown[0] = erdgSoftTast12Zu;
	erdgRollo12->inputdown[1] = erdgSoftTastAllKuechZu;
	erdgRollo12->inputstop[0] = erdgSoftTast12Stop;
	erdgRollo12->inputstop[1] = erdgSoftTastAllKuechStop;
	erdgRollo12->outputup = erdgroll12up;
	erdgRollo12->outputdown = erdgroll12down;

	erdgRollo13 = malloc(sizeof(iec_rollo_switch));
	erdgRollo13->inputup = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo13->inputdown = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo13->inputstop = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgRollo13->inputcountup = 2;
	erdgRollo13->inputcountstop = 2;
	erdgRollo13->inputcountdown = 2;
	erdgRollo13->inputup[0] = erdgSoftTast13Auf;
	erdgRollo13->inputup[1] = erdgSoftTastAllKuechAuf;
	erdgRollo13->inputdown[0] = erdgSoftTast13Zu;
	erdgRollo13->inputdown[1] = erdgSoftTastAllKuechZu;
	erdgRollo13->inputstop[0] = erdgSoftTast13Stop;
	erdgRollo13->inputstop[1] = erdgSoftTastAllKuechStop;
	erdgRollo13->outputup = erdgroll13up;
	erdgRollo13->outputdown = erdgroll13down;

	erdgRollo14 = malloc(sizeof(iec_rollo_switch));
	erdgRollo14->inputup = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo14->inputdown = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo14->inputstop = malloc(sizeof(iec_bool_datapoint*));
	erdgRollo14->inputcountup = 1;
	erdgRollo14->inputcountstop = 1;
	erdgRollo14->inputcountdown = 1;
	erdgRollo14->inputup[0] = erdgSoftTast14Auf;
	erdgRollo14->inputdown[0] = erdgSoftTast14Zu;
	erdgRollo14->inputstop[0] = erdgSoftTast14Stop;
	erdgRollo14->outputup = erdgroll14up;
	erdgRollo14->outputdown = erdgroll14down;
//	erdgRollo2Auf = malloc(sizeof(iec_multi_rising_switch));
//	erdgRollo2Auf->input = malloc(sizeof(iec_bool_datapoint*));
//	erdgRollo2Auf->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgRollo2Auf->risingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgRollo2Auf->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
//	erdgRollo2Auf->inputcount = 1;
//	erdgRollo2Auf->input[0] = erdgSoftTast2Auf;
//	btech_iec_bool_datapoint_initialize(&erdgRollo2Auf->oldrisingvalue[0]);
//	btech_iec_bool_datapoint_initialize(erdgRollo2Auf->risingvalue);
//	btech_iec_bool_datapoint_initialize(erdgRollo2Auf->oldtogglevalue);
//	erdgRollo2Auf->output = erdgroll2up;

//	erdgRollo2Zu = malloc(sizeof(iec_multi_rising_switch));
//	erdgRollo2Zu->input = malloc(sizeof(iec_bool_datapoint*));
//	erdgRollo2Zu->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgRollo2Zu->risingvalue = malloc(sizeof(iec_bool_datapoint));
//	erdgRollo2Zu->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
//	erdgRollo2Zu->inputcount = 1;
//	erdgRollo2Zu->input[0] = erdgSoftTast2Zu;
//	btech_iec_bool_datapoint_initialize(&erdgRollo2Zu->oldrisingvalue[0]);
//	btech_iec_bool_datapoint_initialize(erdgRollo2Zu->risingvalue);
//	btech_iec_bool_datapoint_initialize(erdgRollo2Zu->oldtogglevalue);
//	erdgRollo2Zu->output = erdgroll2down;
	/**
	 * now connect to the device
	 *
#ifdef DEBUG_INITIALISE
	printf("try to connect %s device0\n", device->hostname);
#endif
	if (btech_ur20_connect(device) == -1)
	{
#ifdef DEBUG_INITIALISE
		printf("connect device0 failed\n");
#endif
	}
	else
	{
#ifdef DEBUG_INITIALISE
		printf("connect device0 successfully\n");
#endif
	}
	/******************************************************************
	 *
	 * initialize device1
	 *
	 ****************************************************************** *
	device = &devices[1];

	/**
	 * set address of u-remote coupler in cellar
	 *
//	device->hostname = "10.0.0.28";
	device->hostname = "172.17.0.203";
	device->portno = 502;
	/**
	 * set all input modules
	 *

	device->digitalInCount = 1;
	device->inmodules = malloc(sizeof(btech_ur20_module) * 1);

	/**
	 * set all output modules
	 *
	device->digitalOutCount = 1;
	device->outmodules = malloc(sizeof(btech_ur20_module) * 1);

	btech_ur20_16di_p_module_initialize(&device->inmodules[0]);
	btech_ur20_16do_p_module_initialize(&device->outmodules[0]);

	/******************************************************************
	 *
	 * create the read message for the device
	 *
	 ****************************************************************** *
	btech_ur20_create_read_message(device);

	kellertaster1 = (iec_bool_datapoint *) &device->inmodules[0].dps[0];
	kellertaster2 = (iec_bool_datapoint *) &device->inmodules[0].dps[1];
	kellertaster3 = (iec_bool_datapoint *) &device->inmodules[0].dps[2];
	kellertaster4 = (iec_bool_datapoint *) &device->inmodules[0].dps[3];
	kellertaster5 = (iec_bool_datapoint *) &device->inmodules[0].dps[4];
	kellertaster6 = (iec_bool_datapoint *) &device->inmodules[0].dps[5];
	kellertaster7 = (iec_bool_datapoint *) &device->inmodules[0].dps[6];
	kellertaster8 = (iec_bool_datapoint *) &device->inmodules[0].dps[7];
	kellertaster9 = (iec_bool_datapoint *) &device->inmodules[0].dps[8];
	kellertaster10 = (iec_bool_datapoint *) &device->inmodules[0].dps[9];
	kellertaster11 = (iec_bool_datapoint *) &device->inmodules[0].dps[10];
	kellertaster12 = (iec_bool_datapoint *) &device->inmodules[0].dps[11];
	kellertaster13 = (iec_bool_datapoint *) &device->inmodules[0].dps[12];
	kellerstaubsauger15 = (iec_bool_datapoint *) &device->inmodules[0].dps[14];
	kellerstaubsauger16 = (iec_bool_datapoint *) &device->inmodules[0].dps[15];

	btech_addGeneralVariable((iec_datapoint*) kellertaster1, "kellertaster1");
	btech_addGeneralVariable((iec_datapoint*) kellertaster2, "kellertaster2");
	btech_addGeneralVariable((iec_datapoint*) kellertaster3, "kellertaster3");
	btech_addGeneralVariable((iec_datapoint*) kellertaster4, "kellertaster4");
	btech_addGeneralVariable((iec_datapoint*) kellertaster5, "kellertaster5");
	btech_addGeneralVariable((iec_datapoint*) kellertaster6, "kellertaster6");
	btech_addGeneralVariable((iec_datapoint*) kellertaster7, "kellertaster7");
	btech_addGeneralVariable((iec_datapoint*) kellertaster8, "kellertaster8");
	btech_addGeneralVariable((iec_datapoint*) kellertaster9, "kellertaster9");
	btech_addGeneralVariable((iec_datapoint*) kellertaster10, "kellertaster10");
	btech_addGeneralVariable((iec_datapoint*) kellertaster11, "kellertaster11");
	btech_addGeneralVariable((iec_datapoint*) kellertaster12, "kellertaster12");
	btech_addGeneralVariable((iec_datapoint*) kellertaster13, "kellertaster13");
	btech_addGeneralVariable((iec_datapoint*) kellerstaubsauger15,
			"kellerstaubsauger15");
	btech_addGeneralVariable((iec_datapoint*) kellerstaubsauger16,
			"kellerstaubsauger16");

	staubsauger = (iec_bool_datapoint *) &device->outmodules[0].dps[0];
	kellerlicht1 = (iec_bool_datapoint *) &device->outmodules[0].dps[1];
	kellerlicht2 = (iec_bool_datapoint *) &device->outmodules[0].dps[2];
	kellerlicht3 = (iec_bool_datapoint *) &device->outmodules[0].dps[3];
	kellerlicht4 = (iec_bool_datapoint *) &device->outmodules[0].dps[4];
	kellerlicht5 = (iec_bool_datapoint *) &device->outmodules[0].dps[5];
	kellerlicht6 = (iec_bool_datapoint *) &device->outmodules[0].dps[6];
	kellerlicht7 = (iec_bool_datapoint *) &device->outmodules[0].dps[7];

	btech_addGeneralVariable((iec_datapoint*) staubsauger, "staubsauger");
	btech_addGeneralVariable((iec_datapoint*) kellerlicht1, "kellerlicht1");
	btech_addGeneralVariable((iec_datapoint*) kellerlicht2, "kellerlicht2");
	btech_addGeneralVariable((iec_datapoint*) kellerlicht3, "kellerlicht3");
	btech_addGeneralVariable((iec_datapoint*) kellerlicht4, "kellerlicht4");
	btech_addGeneralVariable((iec_datapoint*) kellerlicht5, "kellerlicht5");
	btech_addGeneralVariable((iec_datapoint*) kellerlicht6, "kellerlicht6");
	btech_addGeneralVariable((iec_datapoint*) kellerlicht7, "kellerlicht7");

	erdgLichtGarageHinten = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtGarageHinten->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	erdgLichtGarageHinten->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint) * 2);
	erdgLichtGarageHinten->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtGarageHinten->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtGarageHinten->inputcount = 2;
	erdgLichtGarageHinten->input[0] = erdgtaster42;
	erdgLichtGarageHinten->input[1] = kellertaster13;
	btech_iec_bool_datapoint_initialize(&erdgLichtGarageHinten->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtGarageHinten->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(erdgLichtGarageHinten->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtGarageHinten->oldtogglevalue);
	erdgLichtGarageHinten->output = erdglicht41;

	erdgLichtKellerStiege = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtKellerStiege->input = malloc(sizeof(iec_bool_datapoint*) * 3);
	erdgLichtKellerStiege->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint) * 3);
	erdgLichtKellerStiege->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtKellerStiege->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtKellerStiege->inputcount = 3;
	erdgLichtKellerStiege->input[0] = erdgtaster21;
	erdgLichtKellerStiege->input[1] = kellertaster3;
	erdgLichtKellerStiege->input[2] = kellertaster5;
	btech_iec_bool_datapoint_initialize(&erdgLichtKellerStiege->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtKellerStiege->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(&erdgLichtKellerStiege->oldrisingvalue[2]);
	btech_iec_bool_datapoint_initialize(erdgLichtKellerStiege->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtKellerStiege->oldtogglevalue);
	erdgLichtKellerStiege->output = erdglicht9;

	kellerLichtSpielzimmer = malloc(sizeof(iec_multi_rising_switch));
	kellerLichtSpielzimmer->input = malloc(sizeof(iec_bool_datapoint*));
	kellerLichtSpielzimmer->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtSpielzimmer->risingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtSpielzimmer->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtSpielzimmer->inputcount = 1;
	kellerLichtSpielzimmer->input[0] = kellertaster1;
	btech_iec_bool_datapoint_initialize(&kellerLichtSpielzimmer->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(kellerLichtSpielzimmer->risingvalue);
	btech_iec_bool_datapoint_initialize(kellerLichtSpielzimmer->oldtogglevalue);
	kellerLichtSpielzimmer->output = kellerlicht1;

	kellerLichtVorraum = malloc(sizeof(iec_multi_rising_switch));
	kellerLichtVorraum->input = malloc(sizeof(iec_bool_datapoint*) * 3);
	kellerLichtVorraum->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 3);
	kellerLichtVorraum->risingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtVorraum->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtVorraum->inputcount = 3;
	kellerLichtVorraum->input[0] = kellertaster2;
	kellerLichtVorraum->input[1] = kellertaster6;
	kellerLichtVorraum->input[2] = kellertaster8;
	btech_iec_bool_datapoint_initialize(&kellerLichtVorraum->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&kellerLichtVorraum->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(&kellerLichtVorraum->oldrisingvalue[2]);
	btech_iec_bool_datapoint_initialize(kellerLichtVorraum->risingvalue);
	btech_iec_bool_datapoint_initialize(kellerLichtVorraum->oldtogglevalue);
	kellerLichtVorraum->output = kellerlicht3;

	kellerLichtWC = malloc(sizeof(iec_multi_rising_switch));
	kellerLichtWC->input = malloc(sizeof(iec_bool_datapoint*));
	kellerLichtWC->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtWC->risingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtWC->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtWC->inputcount = 1;
	kellerLichtWC->input[0] = kellertaster4;
	btech_iec_bool_datapoint_initialize(&kellerLichtWC->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(kellerLichtWC->risingvalue);
	btech_iec_bool_datapoint_initialize(kellerLichtWC->oldtogglevalue);
	kellerLichtWC->output = kellerlicht4;

	kellerLichtBar = malloc(sizeof(iec_multi_rising_switch));
	kellerLichtBar->input = malloc(sizeof(iec_bool_datapoint*));
	kellerLichtBar->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtBar->risingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtBar->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtBar->inputcount = 1;
	kellerLichtBar->input[0] = kellertaster7;
	btech_iec_bool_datapoint_initialize(&kellerLichtBar->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(kellerLichtBar->risingvalue);
	btech_iec_bool_datapoint_initialize(kellerLichtBar->oldtogglevalue);
	kellerLichtBar->output = kellerlicht2;

	kellerLichtWaschk = malloc(sizeof(iec_multi_rising_switch));
	kellerLichtWaschk->input = malloc(sizeof(iec_bool_datapoint*));
	kellerLichtWaschk->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtWaschk->risingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtWaschk->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtWaschk->inputcount = 1;
	kellerLichtWaschk->input[0] = kellertaster9;
	btech_iec_bool_datapoint_initialize(&kellerLichtWaschk->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(kellerLichtWaschk->risingvalue);
	btech_iec_bool_datapoint_initialize(kellerLichtWaschk->oldtogglevalue);
	kellerLichtWaschk->output = kellerlicht5;

	kellerLichtKaltraum = malloc(sizeof(iec_multi_rising_switch));
	kellerLichtKaltraum->input = malloc(sizeof(iec_bool_datapoint*) * 2);
	kellerLichtKaltraum->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 2);
	kellerLichtKaltraum->risingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtKaltraum->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtKaltraum->inputcount = 2;
	kellerLichtKaltraum->input[0] = kellertaster11;
	kellerLichtKaltraum->input[1] = kellertaster12;
	btech_iec_bool_datapoint_initialize(&kellerLichtKaltraum->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&kellerLichtKaltraum->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(kellerLichtKaltraum->risingvalue);
	btech_iec_bool_datapoint_initialize(kellerLichtKaltraum->oldtogglevalue);
	kellerLichtKaltraum->output = kellerlicht6;

	kellerLichtStaubsauger = malloc(sizeof(iec_multi_rising_switch));
	kellerLichtStaubsauger->input = malloc(sizeof(iec_bool_datapoint*));
	kellerLichtStaubsauger->oldrisingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtStaubsauger->risingvalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtStaubsauger->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	kellerLichtStaubsauger->inputcount = 1;
	kellerLichtStaubsauger->input[0] = kellertaster10;
	btech_iec_bool_datapoint_initialize(&kellerLichtStaubsauger->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(kellerLichtStaubsauger->risingvalue);
	btech_iec_bool_datapoint_initialize(kellerLichtStaubsauger->oldtogglevalue);
	kellerLichtStaubsauger->output = kellerlicht7;

	/**
	 * now connect to the device
	 *
#ifdef DEBUG_INITIALISE
	printf("try to connect %s device1\n", device->hostname);
#endif
	if (btech_ur20_connect(device) == -1)
	{
#ifdef DEBUG_INITIALISE
		printf("connect device1 failed\n");
#endif
	}
	else
	{
#ifdef DEBUG_INITIALISE
		printf("connect device1 successfully\n");
#endif
	}
	/******************************************************************
	 *
	 * initialize device2
	 *
	 ****************************************************************** *
	device = &devices[2];
	/**
	 * set address of u-remote coupler in first floor
	 *
//	device->hostname = "10.0.0.27";
	device->hostname = "172.17.0.201";
	device->portno = 502;

	device->digitalInCount = 3;
	device->inmodules = malloc(sizeof(btech_ur20_module) * 3);

	/**
	 * set all output modules
	 *
	device->digitalOutCount = 1;
	device->outmodules = malloc(sizeof(btech_ur20_module) * 1);

	btech_ur20_16di_p_module_initialize(&device->inmodules[0]);
	btech_ur20_16di_p_module_initialize(&device->inmodules[1]);
	btech_ur20_16di_p_module_initialize(&device->inmodules[2]);
	btech_ur20_16do_p_module_initialize(&device->outmodules[0]);

	/******************************************************************
	 *
	 * create the read message for the device
	 *
	 ****************************************************************** *
	btech_ur20_create_read_message(device);

	stocktaster1 = (iec_bool_datapoint *) &device->inmodules[0].dps[0];
	stocktaster2 = (iec_bool_datapoint *) &device->inmodules[0].dps[1];
	stocktaster3 = (iec_bool_datapoint *) &device->inmodules[0].dps[2];
	stocktaster4 = (iec_bool_datapoint *) &device->inmodules[0].dps[3];
	stocktaster5 = (iec_bool_datapoint *) &device->inmodules[0].dps[4];
	stocktaster6 = (iec_bool_datapoint *) &device->inmodules[0].dps[5];
	stocktaster7 = (iec_bool_datapoint *) &device->inmodules[0].dps[6];
	stocktaster8 = (iec_bool_datapoint *) &device->inmodules[0].dps[7];
	stocktaster9 = (iec_bool_datapoint *) &device->inmodules[0].dps[8];
	stocktaster10 = (iec_bool_datapoint *) &device->inmodules[0].dps[9];
	stocktaster11 = (iec_bool_datapoint *) &device->inmodules[0].dps[10];
	stocktaster12 = (iec_bool_datapoint *) &device->inmodules[0].dps[11];
	stocktaster13 = (iec_bool_datapoint *) &device->inmodules[0].dps[12];
	stocktaster14 = (iec_bool_datapoint *) &device->inmodules[0].dps[13];
	stocktaster15 = (iec_bool_datapoint *) &device->inmodules[0].dps[14];
	stocktaster16 = (iec_bool_datapoint *) &device->inmodules[0].dps[15];
	stocktaster17 = (iec_bool_datapoint *) &device->inmodules[1].dps[1];
	stocktaster18 = (iec_bool_datapoint *) &device->inmodules[1].dps[2];
	stocktaster19 = (iec_bool_datapoint *) &device->inmodules[1].dps[3];

	stocklicht1 = (iec_bool_datapoint *) &device->outmodules[0].dps[0];
	stocklicht2 = (iec_bool_datapoint *) &device->outmodules[0].dps[1];
	stocklicht3 = (iec_bool_datapoint *) &device->outmodules[0].dps[2];
	stocklicht4 = (iec_bool_datapoint *) &device->outmodules[0].dps[3];
	stocklicht5 = (iec_bool_datapoint *) &device->outmodules[0].dps[4];
	stocklicht6 = (iec_bool_datapoint *) &device->outmodules[0].dps[5];
	stocklicht7 = (iec_bool_datapoint *) &device->outmodules[0].dps[6];
	stocklicht8 = (iec_bool_datapoint *) &device->outmodules[0].dps[7];
	stocklicht9 = (iec_bool_datapoint *) &device->outmodules[0].dps[8];
	stocklicht10 = (iec_bool_datapoint *) &device->outmodules[0].dps[9];

	btech_addGeneralVariable((iec_datapoint*) stocktaster1, "stocktaster1");
	btech_addGeneralVariable((iec_datapoint*) stocktaster2, "stocktaster2");
	btech_addGeneralVariable((iec_datapoint*) stocktaster3, "stocktaster3");
	btech_addGeneralVariable((iec_datapoint*) stocktaster4, "stocktaster4");
	btech_addGeneralVariable((iec_datapoint*) stocktaster5, "stocktaster5");
	btech_addGeneralVariable((iec_datapoint*) stocktaster6, "stocktaster6");
	btech_addGeneralVariable((iec_datapoint*) stocktaster7, "stocktaster7");
	btech_addGeneralVariable((iec_datapoint*) stocktaster8, "stocktaster8");
	btech_addGeneralVariable((iec_datapoint*) stocktaster9, "stocktaster9");
	btech_addGeneralVariable((iec_datapoint*) stocktaster10, "stocktaster10");
	btech_addGeneralVariable((iec_datapoint*) stocktaster11, "stocktaster11");
	btech_addGeneralVariable((iec_datapoint*) stocktaster12, "stocktaster12");
	btech_addGeneralVariable((iec_datapoint*) stocktaster13, "stocktaster13");
	btech_addGeneralVariable((iec_datapoint*) stocktaster14, "stocktaster14");
	btech_addGeneralVariable((iec_datapoint*) stocktaster15, "stocktaster15");
	btech_addGeneralVariable((iec_datapoint*) stocktaster16, "stocktaster16");
	btech_addGeneralVariable((iec_datapoint*) stocktaster17, "stocktaster17");
	btech_addGeneralVariable((iec_datapoint*) stocktaster18, "stocktaster18");
	btech_addGeneralVariable((iec_datapoint*) stocktaster19, "stocktaster19");

	btech_addGeneralVariable((iec_datapoint*) stocklicht1, "stocklicht1");
	btech_addGeneralVariable((iec_datapoint*) stocklicht2, "stocklicht2");
	btech_addGeneralVariable((iec_datapoint*) stocklicht3, "stocklicht3");
	btech_addGeneralVariable((iec_datapoint*) stocklicht4, "stocklicht4");
	btech_addGeneralVariable((iec_datapoint*) stocklicht5, "stocklicht5");
	btech_addGeneralVariable((iec_datapoint*) stocklicht6, "stocklicht6");
	btech_addGeneralVariable((iec_datapoint*) stocklicht7, "stocklicht7");
	btech_addGeneralVariable((iec_datapoint*) stocklicht8, "stocklicht8");
	btech_addGeneralVariable((iec_datapoint*) stocklicht9, "stocklicht9");
	btech_addGeneralVariable((iec_datapoint*) stocklicht10, "stocklicht10");

	stockLichtVorhaus = malloc(sizeof(iec_multi_rising_switch));
	stockLichtVorhaus->input = malloc(sizeof(iec_bool_datapoint*) * 4);
	stockLichtVorhaus->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 4);
	stockLichtVorhaus->risingvalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtVorhaus->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtVorhaus->inputcount = 4;
	stockLichtVorhaus->input[0] = stocktaster2;
	stockLichtVorhaus->input[1] = stocktaster13;
	stockLichtVorhaus->input[2] = stocktaster5;
	stockLichtVorhaus->input[3] = stocktaster7;
	btech_iec_bool_datapoint_initialize(&stockLichtVorhaus->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&stockLichtVorhaus->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(&stockLichtVorhaus->oldrisingvalue[2]);
	btech_iec_bool_datapoint_initialize(&stockLichtVorhaus->oldrisingvalue[3]);
	btech_iec_bool_datapoint_initialize(stockLichtVorhaus->risingvalue);
	btech_iec_bool_datapoint_initialize(stockLichtVorhaus->oldtogglevalue);
	stockLichtVorhaus->output = stocklicht6;

	stockLichtTimo = malloc(sizeof(iec_multi_rising_switch));
	stockLichtTimo->input = malloc(sizeof(iec_bool_datapoint*) * 1);
	stockLichtTimo->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 1);
	stockLichtTimo->risingvalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtTimo->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtTimo->inputcount = 1;
	stockLichtTimo->input[0] = stocktaster1;
	btech_iec_bool_datapoint_initialize(&stockLichtTimo->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(stockLichtTimo->risingvalue);
	btech_iec_bool_datapoint_initialize(stockLichtTimo->oldtogglevalue);
	stockLichtTimo->output = stocklicht8;

	stockLichtDenise1 = malloc(sizeof(iec_multi_rising_switch));
	stockLichtDenise1->input = malloc(sizeof(iec_bool_datapoint*) * 1);
	stockLichtDenise1->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 1);
	stockLichtDenise1->risingvalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtDenise1->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtDenise1->inputcount = 1;
	stockLichtDenise1->input[0] = stocktaster11;
	btech_iec_bool_datapoint_initialize(&stockLichtDenise1->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(stockLichtDenise1->risingvalue);
	btech_iec_bool_datapoint_initialize(stockLichtDenise1->oldtogglevalue);
	stockLichtDenise1->output = stocklicht1;

	stockLichtDenise2 = malloc(sizeof(iec_multi_rising_switch));
	stockLichtDenise2->input = malloc(sizeof(iec_bool_datapoint*) * 1);
	stockLichtDenise2->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 1);
	stockLichtDenise2->risingvalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtDenise2->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtDenise2->inputcount = 1;
	stockLichtDenise2->input[0] = stocktaster12;
	btech_iec_bool_datapoint_initialize(&stockLichtDenise2->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(stockLichtDenise2->risingvalue);
	btech_iec_bool_datapoint_initialize(stockLichtDenise2->oldtogglevalue);
	stockLichtDenise2->output = stocklicht2;

	stockLichtSchlafz = malloc(sizeof(iec_multi_rising_switch));
	stockLichtSchlafz->input = malloc(sizeof(iec_bool_datapoint*) * 1);
	stockLichtSchlafz->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 1);
	stockLichtSchlafz->risingvalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtSchlafz->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtSchlafz->inputcount = 1;
	stockLichtSchlafz->input[0] = stocktaster6;
	btech_iec_bool_datapoint_initialize(&stockLichtSchlafz->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(stockLichtSchlafz->risingvalue);
	btech_iec_bool_datapoint_initialize(stockLichtSchlafz->oldtogglevalue);
	stockLichtSchlafz->output = stocklicht3;

	stockLichtSchlafzRueck = malloc(sizeof(iec_multi_rising_switch));
	stockLichtSchlafzRueck->input = malloc(sizeof(iec_bool_datapoint*) * 1);
	stockLichtSchlafzRueck->oldrisingvalue = malloc(
			sizeof(iec_bool_datapoint) * 1);
	stockLichtSchlafzRueck->risingvalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtSchlafzRueck->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtSchlafzRueck->inputcount = 1;
	stockLichtSchlafzRueck->input[0] = stocktaster10;
	btech_iec_bool_datapoint_initialize(&stockLichtSchlafzRueck->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(stockLichtSchlafzRueck->risingvalue);
	btech_iec_bool_datapoint_initialize(stockLichtSchlafzRueck->oldtogglevalue);
	stockLichtSchlafzRueck->output = stocklicht10;

	stockLichtSchrankr = malloc(sizeof(iec_multi_rising_switch));
	stockLichtSchrankr->input = malloc(sizeof(iec_bool_datapoint*) * 1);
	stockLichtSchrankr->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 1);
	stockLichtSchrankr->risingvalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtSchrankr->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtSchrankr->inputcount = 1;
	stockLichtSchrankr->input[0] = stocktaster9;
	btech_iec_bool_datapoint_initialize(&stockLichtSchrankr->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(stockLichtSchrankr->risingvalue);
	btech_iec_bool_datapoint_initialize(stockLichtSchrankr->oldtogglevalue);
	stockLichtSchrankr->output = stocklicht4;

	stockLichtWC = malloc(sizeof(iec_multi_rising_switch));
	stockLichtWC->input = malloc(sizeof(iec_bool_datapoint*) * 1);
	stockLichtWC->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 1);
	stockLichtWC->risingvalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtWC->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	stockLichtWC->inputcount = 1;
	stockLichtWC->input[0] = stocktaster15;
	btech_iec_bool_datapoint_initialize(&stockLichtWC->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(stockLichtWC->risingvalue);
	btech_iec_bool_datapoint_initialize(stockLichtWC->oldtogglevalue);
	stockLichtWC->output = stocklicht9;

	erdgLichtStockStiege = malloc(sizeof(iec_multi_rising_switch));
	erdgLichtStockStiege->input = malloc(sizeof(iec_bool_datapoint*) * 3);
	erdgLichtStockStiege->oldrisingvalue = malloc(sizeof(iec_bool_datapoint) * 3);
	erdgLichtStockStiege->risingvalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtStockStiege->oldtogglevalue = malloc(sizeof(iec_bool_datapoint));
	erdgLichtStockStiege->inputcount = 3;
	erdgLichtStockStiege->input[0] = erdgtaster19;
	erdgLichtStockStiege->input[1] = stocktaster3;
	erdgLichtStockStiege->input[2] = stocktaster14;
	btech_iec_bool_datapoint_initialize(&erdgLichtStockStiege->oldrisingvalue[0]);
	btech_iec_bool_datapoint_initialize(&erdgLichtStockStiege->oldrisingvalue[1]);
	btech_iec_bool_datapoint_initialize(&erdgLichtStockStiege->oldrisingvalue[2]);
	btech_iec_bool_datapoint_initialize(erdgLichtStockStiege->risingvalue);
	btech_iec_bool_datapoint_initialize(erdgLichtStockStiege->oldtogglevalue);
	erdgLichtStockStiege->output = erdglicht43;

	staubsaugerOr = malloc(sizeof(iec_or));
	staubsaugerOr->input = malloc(sizeof(iec_bool_datapoint*) * 5);
	staubsaugerOr->inputcount = 5;
	staubsaugerOr->input[0] = stocktaster4;
	staubsaugerOr->input[1] = erdgtaster33;
	staubsaugerOr->input[2] = erdgtaster34;
	staubsaugerOr->input[3] = kellerstaubsauger15;
	staubsaugerOr->input[4] = kellerstaubsauger16;
	staubsaugerOr->output = staubsauger;

	/**
	 * now connect to the device
	 *
#ifdef DEBUG_INITIALISE
	printf("try to connect %s device2\n", device->hostname);
#endif
	if (btech_ur20_connect(device) == -1)
	{
#ifdef DEBUG_INITIALISE
		printf("connect device2 failed\n");
#endif
	}
	else
	{
#ifdef DEBUG_INITIALISE
		printf("connect device2 successfully\n");
#endif
	}
	/******************************************************************
	 *
	 * initialize helper variables
	 *
	 ****************************************************************** */

	return 0;

}

//// -----------------------------------------------------------------------------------
//// read all hardware inputs, if not possible, so we can not work correctly
//// -----------------------------------------------------------------------------------
//int btech_readHardwareInputs()
//{
//
//	for (int i = 0; i < deviceCount; i++)
//	{
//		if (devices[i].sockfd < 0)
//			btech_ur20_connect(&devices[i]);
//
//		if (btech_ur20_write(&devices[i], devices[i].readmessage) > 0)
//		{
//			btech_ur20_read(&devices[i]);
//		}
//	}
//	return 0;
//}

// -------------------------------------------------------------------------------------
// main execute function, which will scheduled every defined interval
// -------------------------------------------------------------------------------------
int btech_schedule_func1()
{
	iec_multi_rising_switch_func(erdgLichtFernseher);
	iec_multi_rising_switch_func(erdgLichtKachelofen);
	iec_multi_rising_switch_func(erdgLichtEsszimmer);
	iec_multi_rising_switch_func(erdgLichtEsszKueche);
	iec_multi_rising_switch_func(erdgLichtKueche);
	iec_multi_rising_switch_func(erdgLichtVorhaus);
	iec_multi_rising_switch_func(erdgLichtDurchgGarage);
	iec_multi_rising_switch_func(erdgLichtArbeitsz);
	iec_multi_rising_switch_func(erdgLichtKellerStiege);
	iec_multi_rising_switch_func(erdgLichtWintergWand);
	iec_multi_rising_switch_func(erdgLichtWC);
	iec_multi_rising_switch_func(erdgLichtWintergMitte);
	iec_multi_rising_switch_func(erdgLichtWintergHinten);
	iec_multi_rising_switch_func(erdgLichtFernseherWand);
	iec_multi_rising_switch_func(erdgLichtEsszWand);
	iec_multi_rising_switch_func(erdgLichtKuecheBoard);
	iec_multi_rising_switch_func(erdgLichtGarage);
	iec_multi_rising_switch_func(erdgLichtAussenEingang);
	iec_multi_rising_switch_func(erdgLichtAussenPosch);
	iec_multi_rising_switch_func(erdgLichtAussenHinten1);
	iec_multi_rising_switch_func(erdgLichtAussenHinten2);

	iec_multi_rising_switch_func(erdgLichtGarageStiege);
	iec_multi_rising_switch_func(erdgLichtGarageVorne);
	iec_multi_rising_switch_func(erdgLichtGarageHinten);
	iec_multi_rising_switch_func(erdgLichtGarageHintenWinterg);

//	iec_multi_rising_switch_func(erdgMarkiseAuf);
//	iec_multi_rising_switch_func(erdgMarkiseZu);

//	iec_multi_rising_switch_func(erdgRollo2Auf);
//	iec_multi_rising_switch_func(erdgRollo2Zu);
//	iec_multi_rising_switch_func(erdgRollo3Auf);
//	iec_multi_rising_switch_func(erdgRollo3Zu);

//	erdggaragentor41->setdpvalue(erdgtaster36->value,
//			(iec_datapoint *) erdggaragentor41);

	/**
	 * markise
	 */
	erdgmarkzu->setdpvalue(erdgtaster28->value, (iec_datapoint *) erdgmarkzu);
	erdgmarkzu->setdpvalue(erdgtaster29->value, (iec_datapoint *) erdgmarkauf);

	iec_or_func(staubsaugerOr);

	iec_multi_rising_switch_func(stockLichtVorhaus);
	iec_multi_rising_switch_func(stockLichtTimo);
	iec_multi_rising_switch_func(stockLichtDenise1);
	iec_multi_rising_switch_func(stockLichtDenise2);
	iec_multi_rising_switch_func(stockLichtSchlafz);
	iec_multi_rising_switch_func(stockLichtSchlafzRueck);
	iec_multi_rising_switch_func(stockLichtSchrankr);
	iec_multi_rising_switch_func(stockLichtWC);
	iec_multi_rising_switch_func(erdgLichtStockStiege);

	iec_multi_rising_switch_func(kellerLichtSpielzimmer);
	iec_multi_rising_switch_func(kellerLichtVorraum);
	iec_multi_rising_switch_func(kellerLichtBar);
	iec_multi_rising_switch_func(kellerLichtWC);
	iec_multi_rising_switch_func(kellerLichtWaschk);
	iec_multi_rising_switch_func(kellerLichtKaltraum);
	iec_multi_rising_switch_func(kellerLichtStaubsauger);

	iec_rollo_func(erdgMarkise);
	iec_rollo_func(erdgRollo2);
	iec_rollo_func(erdgRollo3);
	iec_rollo_func(erdgRollo4);
	iec_rollo_func(erdgRollo5);
	iec_rollo_func(erdgRollo6);
	iec_rollo_func(erdgRollo7);
	iec_rollo_func(erdgRollo8);
	iec_rollo_func(erdgRollo9);
	iec_rollo_func(erdgRollo10);
	iec_rollo_func(erdgRollo11);
	iec_rollo_func(erdgRollo12);
	iec_rollo_func(erdgRollo13);
	iec_rollo_func(erdgRollo14);
	// reset all software variables
	*erdgEsszSoftTast->value = 0;
	*erdgFernsehzSoftTast->value = 0;
	*erdgFernsehzRueckSoftTast->value = 0;
	*erdgWintergMitteSoftTast->value = 0;
	*erdgWintergHintenSoftTast->value = 0;
	*erdgWintergWandSoftTast->value = 0;
	*erdgEsszKuechSoftTast->value = 0;
	*erdgKuecheSoftTast->value = 0;
	*erdgKuecheBoardSoftTast->value = 0;

	*erdgSoftTast1Auf->value = 0;
	*erdgSoftTast1Zu->value = 0;
	*erdgSoftTast1Stop->value = 0;

	*erdgSoftTastAllWintAuf->value = 0;
	*erdgSoftTastAllWintZu->value = 0;
	*erdgSoftTastAllWintStop->value = 0;

	*erdgSoftTastAllKuechAuf->value = 0;
	*erdgSoftTastAllKuechZu->value = 0;
	*erdgSoftTastAllKuechStop->value = 0;

	*erdgSoftTast2Auf->value = 0;
	*erdgSoftTast2Zu->value = 0;
	*erdgSoftTast2Stop->value = 0;

	*erdgSoftTast3Auf->value = 0;
	*erdgSoftTast3Zu->value = 0;
	*erdgSoftTast3Stop->value = 0;

	*erdgSoftTast4Auf->value = 0;
	*erdgSoftTast4Zu->value = 0;
	*erdgSoftTast4Stop->value = 0;

	*erdgSoftTast5Auf->value = 0;
	*erdgSoftTast5Zu->value = 0;
	*erdgSoftTast5Stop->value = 0;

	*erdgSoftTast6Auf->value = 0;
	*erdgSoftTast6Zu->value = 0;
	*erdgSoftTast6Stop->value = 0;

	*erdgSoftTast7Auf->value = 0;
	*erdgSoftTast7Zu->value = 0;
	*erdgSoftTast7Stop->value = 0;

	*erdgSoftTast8Auf->value = 0;
	*erdgSoftTast8Zu->value = 0;
	*erdgSoftTast8Stop->value = 0;

	*erdgSoftTast9Auf->value = 0;
	*erdgSoftTast9Zu->value = 0;
	*erdgSoftTast9Stop->value = 0;

	*erdgSoftTast10Auf->value = 0;
	*erdgSoftTast10Zu->value = 0;
	*erdgSoftTast10Stop->value = 0;

	*erdgSoftTast11Auf->value = 0;
	*erdgSoftTast11Zu->value = 0;
	*erdgSoftTast11Stop->value = 0;

	*erdgSoftTast12Auf->value = 0;
	*erdgSoftTast12Zu->value = 0;
	*erdgSoftTast12Stop->value = 0;

	*erdgSoftTast13Auf->value = 0;
	*erdgSoftTast13Zu->value = 0;
	*erdgSoftTast13Stop->value = 0;

	*erdgSoftTast14Auf->value = 0;
	*erdgSoftTast14Zu->value = 0;
	*erdgSoftTast14Stop->value = 0;
	return 0;
}

//// -----------------------------------
//// write all hardware outputs
//// -----------------------------------
//int btech_writeHardwareOutputs()
//{
//	for (int i = 0; i < deviceCount; i++)
//	{
//		if (devices[i].sockfd < 0)
//			btech_ur20_connect(&devices[i]);
//
//		btech_ur20_write_values(&devices[i]);
//	}
//	return 0;
//}
