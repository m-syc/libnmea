#ifndef INC_NMEA_PFLAV_H
#define INC_NMEA_PFLAV_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

#define FLARM_PFLAV_OBST_VERSION_LEN 18

typedef struct {
	nmea_s base;
	char query_type;
	float hw_version;
	float sw_version;
	char obst_version[FLARM_PFLAV_OBST_VERSION_LEN];
} nmea_pflav_s;

/* Value indexes */
#define NMEA_PFLAV_QUERY_TYPE		0
#define NMEA_PFLAV_HW_VERSION		1
#define NMEA_PFLAV_SW_VERSION		2
#define NMEA_PFLAV_OBST_VERSION		3

#endif  /* INC_NMEA_PFLAV_H */
