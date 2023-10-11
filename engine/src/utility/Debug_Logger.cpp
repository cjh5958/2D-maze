#include <exception>

#include "Debug_Logger.h"
using Engine::Debug_Logger;



void Debug_Logger::log(char const* _Format)
{
	std::cout << _Format;
	out << _Format;
}

Debug_Logger::Debug_Logger(char const* _filename) :
	filename(_filename),
	buffer("") {
	this->out.open(this->filename);
}


Debug_Logger::Debug_Logger() :
	filename("log.txt"),
	buffer("") {
	this->out.open(this->filename);
}


Debug_Logger::~Debug_Logger()
{
	this->out.close();
}

