#include "../nmea/parser_types.h"
#include "pflar.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_PFLAR);
	NMEA_PARSER_PREFIX(parser, "PFLAR");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_pflar_s));
	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_pflar_s));
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
	nmea_pflar_s *data = (nmea_pflar_s *) parser->data;

	switch (val_index) {
	case NMEA_PFLAR_VALUE:
		if(*value == 0 || *value == 33 || *value == 99) {
			data->value = *value;
		}
		break;
	default:
		break;
	}

	return 0;
}
