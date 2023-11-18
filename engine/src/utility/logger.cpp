#include "logger.h"
using Engine::Utility::Debug_Logger;


#if defined(_WIN64)

void Debug_Logger::set_text(C_Color color)
{
	UINT16 c = 0x0u;

	switch (color)
	{
	case C_White:
		c |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		break;
	case C_Blue:
		c |= FOREGROUND_BLUE;
		break;
	case C_Green:
		c |= FOREGROUND_GREEN;
		break;
	case C_Red:
		c |= FOREGROUND_RED;
		break;
	case C_Yellow:
		c |= FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
		break;
	case C_Purple:
		c |= FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		break;
	case C_Cyan:
		c |= FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		break;
	case C_Gray:
		c |= FOREGROUND_INTENSITY;
		break;
	}

	SetConsoleTextAttribute(hConsole, c);
}

#endif

inline void Debug_Logger::log(char const* _Format)
{
	std::cout << _Format;
	out << _Format;
}

void Debug_Logger::Warn(char const* _Format)
{
#if defined(_WIN64)
	set_text(C_Purple);
#endif
	this->log("[WARN] ");
#if defined(_WIN64)
	set_text(C_White);
#endif
	this->log(_Format);
}

void Debug_Logger::Info(char const* _Format)
{
#if defined(_WIN64)
	set_text(C_Cyan);
#endif
	this->log("[INFO] ");
#if defined(_WIN64)
	set_text(C_White);
#endif
	this->log(_Format);
}

void Debug_Logger::Error(char const* _Format)
{
#if defined(_WIN64)
	set_text(C_Red);
#endif
	this->log("[ERROR] ");
#if defined(_WIN64)
	set_text(C_White);
#endif
	this->log(_Format);
}

void Debug_Logger::System(char const* _Format)
{
#if defined(_WIN64)
	set_text(C_Gray);
#endif
	this->log("[SYSTEM] ");
#if defined(_WIN64)
	set_text(C_White);
#endif
	this->log(_Format);
}

void Debug_Logger::Success(char const* _Format)
{
#if defined(_WIN64)
	set_text(C_Yellow);
#endif
	this->log("[SUCCESS] ");
#if defined(_WIN64)
	set_text(C_White);
#endif
	this->log(_Format);
}


Debug_Logger::Debug_Logger(char const* _filename) :
	filename(_filename){

#if defined(_WIN64)
	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

	this->out.open(this->filename, std::fstream::out | std::fstream::trunc);
}


Debug_Logger::Debug_Logger() :
	filename("log.txt"){

#if defined(_WIN64)
	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

	this->out.open(this->filename, std::fstream::out | std::fstream::trunc);
}


Debug_Logger::~Debug_Logger()
{
	this->out.close();
}

