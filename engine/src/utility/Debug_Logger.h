#pragma once
#include <iostream>
#include <fstream>

namespace Engine{

	/*
	* @brief Write log in terminal and save into assigned file
	* (For default it's log.txt).
	* 
	* If there is no any assigned file exists, here will create
	* one and store in the same place of `maze.exe`.
	*/
	class Debug_Logger
	{

	static const int BUFFER_MAX_SIZE = 1024;

	private:
		char const* filename;
		char buffer[BUFFER_MAX_SIZE];
		std::ofstream out;

	public:
		void log(char const*);

		/* 
		* @brief 
		*/
		template<typename T, typename... Targs>
		void log(char const* _Format, T const &_value, Targs const &...args)
		{
			using std::cout;

			while (*_Format != '\0')
			{
				if (*_Format == '%')
				{
					cout << _value;
					out << _value;
					this->log(_Format + 1, args...);
					return;
				}

				cout << *_Format;
				out << *_Format;
				_Format++;
			}
		}


		Debug_Logger(char const*);
		Debug_Logger();
		~Debug_Logger() noexcept;

	};	//class Debug_Logger


	inline Debug_Logger& Logger(void)
	{
		static Debug_Logger logger;
		return logger;
	}
}
