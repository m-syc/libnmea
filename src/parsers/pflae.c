#include "../nmea/parser_types.h"
#include "pflae.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_PFLAE);
	NMEA_PARSER_PREFIX(parser, "PFLAE");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_pflae_s));
	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_pflae_s));
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
	nmea_pflae_s *data = (nmea_pflae_s *) parser->data;

	switch (val_index) {
	case NMEA_PFLAE_QUERY_TYPE:
		data->query_type = *value;
		break;
	case NMEA_PFLAE_SEVERITY:
		unsigned int severity = atoi(value);
		if(severity < 4) {
			data->severity = (unsigned char)severity;
		}
		break;
	case NMEA_PFLAE_ERROR_CODE:
		unsigned int error_code = atoi(value);
		if(error_code < 0xFFF) {
			data->error_code = (unsigned short)error_code;
		}
		break;
	case NMEA_PFLAE_MESSAGE:
		strncpy(data->message, value, FLARM_PFLAE_MESSAGE_LEN);
		break;
	default:
		break;
	}

	return 0;
}
