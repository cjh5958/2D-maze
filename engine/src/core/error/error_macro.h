#pragma once

#ifndef ERROR_MACRO_H
#define ERROR_MACRO_H

#include "../typedef.h"

void _err_print(const char* _func, const char* _file, int _line, const char* error);

#define ERR_HANDLE_PRINT(EX)

#define ERR_INDEX_OUT_OF_RANGE(m_idx, m_size)				\
	if( unlikely((m_idx) < 0 || (m_idx) >= (m_size)) ) {	\
		return;												\
	} else {												\
		(void)0;											\
	}

#define CRASH_INSTANTLY()									\
	if(true) {												\
		__debugbreak();										\
	} else {												\
		(void)0;											\
	}

#ifdef STRICT_DEV_ENABLED
#define DEV_ASSERTION(x)																							\
	if(unlikely(!(x)))	{																							\
		_err_print(__FUNCTION__, __FILE__, __LINE__, "Fatal: DEV_ASSERTION failed.\"" _STR(x) "\" is false.");		\
		CRASH_INSTANTLY();																							\
	} else {																										\
		((void)0);																									\
	}
#else
#define DEV_ASSERTION(x)
#endif

#endif
