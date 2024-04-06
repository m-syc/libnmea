#include "../nmea/parser_types.h"
#include "pflaa.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_PFLAA);
	NMEA_PARSER_PREFIX(parser, "PFLAA");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_pflaa_s));
	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_pflaa_s));
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
	nmea_pflaa_s *data = (nmea_pflaa_s *) parser->data;

	switch (val_index) {
	case NMEA_PFLAA_ALARM_LEVEL:
		unsigned int alarm_level = atoi(value);
		if(alarm_level < 4) {
			data->alarm_level = (flarm_alarm_level_t)alarm_level;
		}
		break;
	case NMEA_PFLAA_RELATIVE_NORTH:
		int relative_north = atoi(value);
		if(-20000001 < relative_north && relative_north < 20000001) {
			data->relative_north = relative_north;
		}
		break;
	case NMEA_PFLAA_RELATIVE_EAST:
		int relative_east = atoi(value);
		if(-20000001 < relative_east && relative_east < 20000001) {
			data->relative_east = relative_east;
		}
		break;
	case NMEA_PFLAA_RELATIVE_VERTICAL:
		int relative_vertical = atoi(value);
		if(-32769 < relative_vertical && relative_vertical < 32768) {
			data->relative_vertical = (short)relative_vertical;
		}
		break;
	case NMEA_PFLAA_IT_TYPE:
		unsigned int id_type = atoi(value);
		if(id_type < 3) {
			data->id_type = (unsigned char)id_type;
		}
		break;
	case NMEA_PFLAA_ID:
		strncpy(data->id, value, FLARM_PFLAA_ID_LEN);
		break;
	case NMEA_PFLAA_TRACK:
		unsigned int track = atoi(value);
		if(track < 360) {
			data->track = (unsigned short)track;
		}
		break;
	case NMEA_PFLAA_TURN_RATE:
		// unsupported
		break;
	case NMEA_PFLAA_GROUND_SPEED:
		unsigned int ground_speed = atoi(value);
		if(ground_speed < 32768) {
			data->ground_speed = (unsigned short)ground_speed;
		}
		break;
	case NMEA_PFLAA_CLIMB_RATE:
		float climb_rate = strtof(value, NULL);
		if(-32.8 < climb_rate && climb_rate < 32.8) {
			data->climb_rate = climb_rate;
		}
		break;
	case NMEA_PFLAA_ACFT_TYPE:
		unsigned int acft_type = atoi(value);
		if(acft_type < 0x10) {
			data->aircraft_type = (flarm_aircraft_t)acft_type;
		}
		break;
	case NMEA_PFLAA_NO_TRACK:
		unsigned int no_track = atoi(value);
		if(no_track < 2) {
			data->no_track = (unsigned char)no_track;
		}
		break;
	case NMEA_PFLAA_SOURCE:
		unsigned int source = atoi(value);
		if(source < 7) {
			data->source = (flarm_source_t)source;
		}
		break;
	case NMEA_PFLAA_RSSI:
		data->rssi = strtof(value, NULL);
		break;
	default:
		break;
	}

	return 0;
}
