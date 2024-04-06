#ifndef INC_FLARM_H
#define INC_FLARM_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef enum {
	AIRCRAFT_RESERVED = 0x0,
	AIRCRAFT_GLIDER,
	AIRCRAFT_TOW_PLANE,
	AIRCRAFT_HELICOPTER,
	AIRCRAFT_SKYDIVER,
	AIRCRAFT_DROP_PLANE,
	AIRCRAFT_HANG_GLIDER,
	AIRCRAFT_PARAGLIDER,
	AIRCRAFT_PISTON_ENGINE,
	AIRCRAFT_TURBO_JET_ENGINE,
	AIRCRAFT_UNKNOWN,
	AIRCRAFT_BALLOON,
	AIRCRAFT_AIRSHIP,
	AIRCRAFT_UNMANNED_AERIAL_VEHICLE,
	AIRCRAFT_RESERVED_2,
	AIRCRAFT_STATIC_OBSTACLE
} flarm_aircraft_t;

typedef enum {
	SOURCE_FLARM,
	SOURCE_ADS_B,
	SOURCE_ADS_R,
	SOURCE_TIS_B,
	SOURCE_MODE_S
} flarm_source_t;

typedef enum {
	ALARM_LEVEL_NO_ALARM,
	ALARM_LEVEL_15_TO_20_SEC_TO_IMPCT,
	ALARM_LEVEL_10_TO_15_SEC_TO_IMPCT,
	ALARM_LEVEL_0_TO_10_SEC_TO_IMPCT
} flarm_alarm_level_t;

#endif  /* INC_FLARM_H */