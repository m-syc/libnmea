#include "../nmea/parser_types.h"
#include "pflav.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_PFLAV);
	NMEA_PARSER_PREFIX(parser, "PFLAV");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_pflav_s));
	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_pflav_s));
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
	nmea_pflav_s *data = (nmea_pflav_s *) parser->data;

	switch (val_index) {
	case NMEA_PFLAV_QUERY_TYPE:
		data->query_type = *value;
		break;
	case NMEA_PFLAV_HW_VERSION:
		data->hw_version = strtof(value, NULL);
		break;
	case NMEA_PFLAV_SW_VERSION:
		data->sw_version = strtof(value, NULL);
		break;
	case NMEA_PFLAV_OBST_VERSION:
		strncpy(data->obst_version, value, FLARM_PFLAV_OBST_VERSION_LEN);
		break;
	default:
		break;
	}

	return 0;
}
