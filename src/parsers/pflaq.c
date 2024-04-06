#include "../nmea/parser_types.h"
#include "pflaq.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_PFLAQ);
	NMEA_PARSER_PREFIX(parser, "PFLAQ");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_pflaq_s));
	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_pflaq_s));
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
	nmea_pflaq_s *data = (nmea_pflaq_s *) parser->data;

	switch (val_index) {
	case NMEA_PFLAQ_OPERATION:
		strncpy(data->operation, value, FLARM_PFLAQ_OPERATION_LEN);
		break;
	case NMEA_PFLAQ_INFO:
		strncpy(data->info, value, FLARM_PFLAQ_INFO_LEN);
		break;
	case NMEA_PFLAQ_PROGRESS:
		unsigned int progress = atoi(value);
		if(progress < 101) {
			data->progress = progress;
		}
		break;
	default:
		break;
	}

	return 0;
}
