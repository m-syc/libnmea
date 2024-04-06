#include "../nmea/parser_types.h"
#include "pflau.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_PFLAU);
	NMEA_PARSER_PREFIX(parser, "PFLAU");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_pflau_s));
	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_pflau_s));
	return 0;
}

int
free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int
parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_pflau_s *data = (nmea_pflau_s *) parser->data;

	switch (val_index) {
	case NMEA_PFLAU_RX:
		unsigned int rx = atoi(value);
		if(rx < 100) {
			data->rx = rx;
		}
		break;
	case NMEA_PFLAU_TX:
		unsigned int tx = atoi(value);
		if(tx < 2) {
			data->tx = tx;
		}
		break;
	case NMEA_PFLAU_GPS:
		unsigned int gps = atoi(value);
		if(gps < 3) {
			data->gps = gps;
		}
		break;
	case NMEA_PFLAU_POWER:
		unsigned int power = atoi(value);
		if(power < 2) {
			data->power = power;
		}
		break;
	case NMEA_PFLAU_ALARM_LEVEL:
		unsigned int alarm_level = atoi(value);
		if(alarm_level < 4) {
			data->alarm_level = alarm_level;
		}
		break;
	case NMEA_PFLAU_RELATIVE_BEARING:
		int relative_bearing = atoi(value);
		if(relative_bearing > -181 && relative_bearing < 181) {
			data->relative_bearing = relative_bearing;
		}
		break;
	case NMEA_PFLAU_ALARM_TYPE:
		unsigned int alarm_type = strtol(value, NULL, 16);
		if(alarm_type < 0x100) {
			data->alarm_type = alarm_type;
		}
		break;
	case NMEA_PFLAU_RELATIVE_VERTICAL:
		int relative_vertical = atoi(value);
		if(relative_vertical > -32769 && relative_vertical < 32768) { // 0x8000
			data->relative_vertical = relative_vertical;
		}
		break;
	case NMEA_PFLAU_RELATIVE_DISTANCE:
		unsigned int relative_distance = atoi(value);
		if(relative_distance < 0x80000000) {
			data->relative_distance = relative_distance;
		}
		break;
	case NMEA_PFLAU_ID:
		strncpy(data->id, value, NMEA_PFLAU_ID_LEN);
		break;
	default:
		break;
	}

	return 0;
}
