#include "../nmea/parser_types.h"
#include "pflao.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_PFLAO);
	NMEA_PARSER_PREFIX(parser, "PFLAO");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_pflao_s));
	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_pflao_s));
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
	nmea_pflao_s *data = (nmea_pflao_s *) parser->data;

	switch (val_index) {
	case NMEA_PFLAO_ALARM_LEVEL:
		unsigned int alarm_level = atoi(value);
		if(alarm_level < 4) {
			data->alarm_level = (flarm_alarm_level_t)alarm_level;
		}
		break;
	case NMEA_PFLAO_INSIDE:
		unsigned int inside = atoi(value);
		if(inside < 2) {
			data->inside = (flarm_alarm_level_t)inside;
		}
		break;
	case NMEA_PFLAO_LATITUDE:
		int latitude = atoi(value);
		if(-900000001 < latitude && latitude < 900000001) {
			data->latitude = latitude;
		}
		break;
	case NMEA_PFLAO_LONGTITUDE:
		int longtitude = atoi(value);
		if(-1800000001 < longtitude && longtitude < 1800000001) {
			data->longtitude = longtitude;
		}
		break;
	case NMEA_PFLAO_RADIUS:
		unsigned int radius = atoi(value);
		if(radius < 2001) {
			data->radius = radius;
		}
		break;
	case NMEA_PFLAO_BOTTOM:
		int bottom = atoi(value);
		if(-1001 < bottom && bottom < 6001) {
			data->bottom = bottom;
		}
		break;
	case NMEA_PFLAO_TOP:
		unsigned int top = atoi(value);
		if(top < 6001) {
			data->top = top;
		}
		break;
	case NMEA_PFLAO_ACTIVITY_LIMIT:
		data->activity_limit = atoi(value);
		break;
	case NMEA_PFLAO_ID:
		strncpy(data->id, value, FLARM_PFLAO_ID_LEN);
		break;
	case NMEA_PFLAO_ID_TYPE:
		unsigned int id_type = atoi(value);
		if(id_type < 3) {
			data->id_type = (unsigned char)id_type;
		}
		break;
	case NMEA_PFLAO_ZONE_TYPE:
		unsigned int zone_type = strtoul(value, NULL, 16);
		if(0x09 < zone_type && zone_type < 0x100) {
			data->zone_type = zone_type;
		}
		break;
	default:
		break;
	}

	return 0;
}
