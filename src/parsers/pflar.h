#ifndef INC_NMEA_PFLAR_H
#define INC_NMEA_PFLAR_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	unsigned int value;
} nmea_pflar_s;

/* Value indexes */
#define NMEA_PFLAR_VALUE	0

#endif  /* INC_NMEA_PFLAR_H */
