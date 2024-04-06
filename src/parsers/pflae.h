#ifndef INC_NMEA_PFLAE_H
#define INC_NMEA_PFLAE_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

#define FLARM_PFLAE_MESSAGE_LEN 40

typedef struct {
	nmea_s base;
	char query_type;
	unsigned char severity;
	unsigned short error_code;
	char message[FLARM_PFLAE_MESSAGE_LEN];
} nmea_pflae_s;

/* Value indexes */
#define NMEA_PFLAE_QUERY_TYPE	0
#define NMEA_PFLAE_SEVERITY		1
#define NMEA_PFLAE_ERROR_CODE	2
#define NMEA_PFLAE_MESSAGE		3

#endif  /* INC_NMEA_PFLAE_H */
