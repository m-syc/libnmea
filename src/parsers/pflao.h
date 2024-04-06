#ifndef INC_NMEA_PFLAO_H
#define INC_NMEA_PFLAO_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

#define FLARM_PFLAO_ID_LEN 6

typedef struct {
	nmea_s base;
	unsigned char alarm_level;
	unsigned char inside;
	int latitude;
	int longtitude;
	unsigned short radius;
	int bottom;
	unsigned int top;
	unsigned int activity_limit;
	char id[FLARM_PFLAO_ID_LEN];
	unsigned char id_type;
	unsigned char zone_type;
} nmea_pflao_s;

/* Value indexes */
#define NMEA_PFLAO_ALARM_LEVEL	0
#define NMEA_PFLAO_INSIDE		1
#define NMEA_PFLAO_LATITUDE		2
#define NMEA_PFLAO_LONGTITUDE	3
#define NMEA_PFLAO_RADIUS		4
#define NMEA_PFLAO_BOTTOM		5
#define NMEA_PFLAO_TOP			6
#define NMEA_PFLAO_ACTIVITY_LIMIT	7
#define NMEA_PFLAO_ID			8
#define NMEA_PFLAO_ID_TYPE		9
#define NMEA_PFLAO_ZONE_TYPE	10

#endif  /* INC_NMEA_PFLAO_H */
