#ifndef INC_NMEA_PFLAQ_H
#define INC_NMEA_PFLAQ_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

#define FLARM_PFLAQ_OPERATION_LEN 10
#define FLARM_PFLAQ_INFO_LEN 32

typedef struct {
	nmea_s base;
	char operation[FLARM_PFLAQ_OPERATION_LEN];
	char info[FLARM_PFLAQ_INFO_LEN];
	unsigned char progress;
} nmea_pflaq_s;

/* Value indexes */
#define NMEA_PFLAQ_OPERATION	0
#define NMEA_PFLAQ_INFO			1
#define NMEA_PFLAQ_PROGRESS		2

#endif  /* INC_NMEA_PFLAQ_H */
