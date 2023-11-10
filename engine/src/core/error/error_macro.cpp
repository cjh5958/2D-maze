#include "error_macro.h"
#include "../../utility/Debug_Logger.h"

void _err_print(const char* _func, const char* _file, int _line, const char* error) {
	Engine::Utility::Logger().Error("%\n	at: % (%:%)\n", error, _func, _file, _line);
}