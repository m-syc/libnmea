#ifndef INC_NMEA_PFLAA_H
#define INC_NMEA_PFLAA_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

#define FLARM_PFLAA_ID_LEN 6

typedef struct {
	nmea_s base;
	flarm_alarm_level_t alarm_level;
	int relative_north;
	int relative_east;
	short relative_vertical;
	unsigned char id_type;
	char id[FLARM_PFLAA_ID_LEN];
	unsigned char track;
	char turn_rate;
	unsigned short ground_speed;
	float climb_rate;
	flarm_aircraft_t aircraft_type;
	unsigned char no_track;
	flarm_source_t source;
	float rssi;
} nmea_pflaa_s;

/* Value indexes */
#define NMEA_PFLAA_ALARM_LEVEL			0
#define NMEA_PFLAA_RELATIVE_NORTH		1
#define NMEA_PFLAA_RELATIVE_EAST		2
#define NMEA_PFLAA_RELATIVE_VERTICAL	3
#define NMEA_PFLAA_IT_TYPE		4
#define NMEA_PFLAA_ID			5
#define NMEA_PFLAA_TRACK		6
#define NMEA_PFLAA_TURN_RATE		7
#define NMEA_PFLAA_GROUND_SPEED		8
#define NMEA_PFLAA_CLIMB_RATE		9
#define NMEA_PFLAA_ACFT_TYPE		10
#define NMEA_PFLAA_NO_TRACK		11
#define NMEA_PFLAA_SOURCE		12
#define NMEA_PFLAA_RSSI			13

#endif  /* INC_NMEA_PFLAA_H */
