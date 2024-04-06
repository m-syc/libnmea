#ifndef INC_NMEA_PFLAU_H
#define INC_NMEA_PFLAU_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

#define NMEA_PFLAU_ID_LEN 6

typedef struct {
	nmea_s base;
	unsigned int rx;
	unsigned int tx;
	unsigned int gps;
	unsigned int power;
	unsigned int alarm_level;
	int relative_bearing;
	unsigned int alarm_type;
	int relative_vertical;
	unsigned int relative_distance;
	char id[NMEA_PFLAU_ID_LEN];
} nmea_pflau_s;

/* Value indexes */
#define NMEA_PFLAU_RX		0
#define NMEA_PFLAU_TX		1
#define NMEA_PFLAU_GPS		2
#define NMEA_PFLAU_POWER		3
#define NMEA_PFLAU_ALARM_LEVEL		4
#define NMEA_PFLAU_RELATIVE_BEARING		5
#define NMEA_PFLAU_ALARM_TYPE			6
#define NMEA_PFLAU_RELATIVE_VERTICAL	7
#define NMEA_PFLAU_RELATIVE_DISTANCE	8
#define NMEA_PFLAU_ID		9

#endif  /* INC_NMEA_PFLAU_H */
