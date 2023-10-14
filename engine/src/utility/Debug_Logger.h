#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>

namespace Engine{
	namespace Utility{

		/*
		* @brief Write log into assigned file, for default it's `log.txt`
		* ,and print the message automatically on terminal simultaneously.
		* 
		* @see 5 methods offered to write debug messages or log. 
		* 
		* For WIN64, it's possible to use colorful mode to print
		* debug messages on the terminal.
		* 
		* Use Logger() to get the instance of Debug_Logger.
		* 
		* @sa Warn
		* @sa System
		* @sa Info
		* @sa Error
		* @sa Success
		*/
		class Debug_Logger
		{

#if defined(_WIN64)
			enum C_Color {
				C_White,
				C_Green,
				C_Blue,
				C_Red,
				C_Yellow,
				C_Purple,
				C_Cyan,
				C_Gray
			};
#endif

		private:

			inline void log(char const*);

			template<typename T, typename... Targs>
			void log(char const* _Format, T const& _value, Targs const &...args)
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

		private:
			char const* filename;
			std::ofstream out;

#if defined(_WIN64)
			/* 
			* @brief To control terminal in WIN64
			*/
			HANDLE hConsole;

			/*
			* @brief Set color of text that would be print on the terminal.
			*/
			void set_text(C_Color);
#endif

		public:
			void Warn(char const*);

			template<typename T, typename... Targs>
			void Warn(char const* _Format, T const& _value, Targs const &...args)
			{

#if defined(_WIN64)
				set_text(C_Purple);
#endif
				this->log("[WARN] ");

#if defined(_WIN64)
				set_text(C_White);
#endif

				this->log(_Format, _value, args...);
			}

			void Info(char const*);

			template<typename T, typename... Targs>
			void Info(char const* _Format, T const& _value, Targs const &...args)
			{

#if defined(_WIN64)
				set_text(C_Cyan);
#endif
				this->log("[INFO] ");

#if defined(_WIN64)
				set_text(C_White);
#endif

				this->log(_Format, _value, args...);
			}

			void System(char const*);

			template<typename T, typename... Targs>
			void System(char const* _Format, T const& _value, Targs const &...args)
			{

#if defined(_WIN64)
				set_text(C_Gray);
#endif

				this->log("[SYSTEM] ");

#if defined(_WIN64)
				set_text(C_White);
#endif

				this->log(_Format, _value, args...);
			}

			void Error(char const*);

			template<typename T, typename... Targs>
			void Error(char const* _Format, T const& _value, Targs const &...args)
			{

#if defined(_WIN64)
				set_text(C_Red);
#endif
				this->log("[ERROR] ");

				this->log(_Format, _value, args...);

#if defined(_WIN64)
				set_text(C_White);
#endif
			}

			void Success(char const*);

			template<typename T, typename... Targs>
			void Success(char const* _Format, T const& _value, Targs const &...args)
			{

#if defined(_WIN64)
				set_text(C_Yellow);
#endif
				this->log("[SUCCESS] ");

#if defined(_WIN64)
				set_text(C_White);
#endif

				this->log(_Format, _value, args...);
			}


		public:

			Debug_Logger(char const*);
			Debug_Logger();
			~Debug_Logger() noexcept;

		};	//class Debug_Logger

		/**
		 * @brief Instance of Debug_Logger
		 * 
		 * @return Debug_Logger
		*/
		inline Debug_Logger &Logger(void)
		{
			static Debug_Logger logger;
			return logger;
		}

	}	//namespace Utility

}	//namespace Engine
