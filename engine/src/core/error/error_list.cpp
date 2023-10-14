#include "error_list.h"


const char* Engine::error_strings[] = {
	"OK",
	"Failed",
	"Out of memory",
	"No such file",
	"File no permission",
	"File read failed",
	"File_EOF",
	"Timeout",
	"Out of range",
	"Create failed",
	"Delete failed",
	"Unavailable",
	"Unconfigured",
	"Unknown"
};

static_assert(
	sizeof(Engine::error_strings) / sizeof(*Engine::error_strings) == Engine::Error::ERR_COUNT-1 ,
	"the size of error_strings doesn't match the size of Error"
);