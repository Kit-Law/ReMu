#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#endif

#define LOG_LEVEL_INFO		ReMu::logLevel::info
#define LOG_LEVEL_WARNING	ReMu::logLevel::warning
#define LOG_LEVEL_ERROR		ReMu::logLevel::error

namespace ReMu {

	enum logLevel : short
	{
		info, warning, error
	};

	static const char* levelName[3] = { "INFO", "WARNING", "ERROR" };

	class Logger
	{
	private:
		short m_LogLevel = LOG_LEVEL_INFO;
		static std::ofstream file;
		std::stringstream m_BufferStream;
	public:
		Logger() {}

		Logger(const char* logFile, logLevel level = LOG_LEVEL_INFO)
		{
			m_LogLevel = level;

			file.open(logFile, std::ofstream::trunc);
		}

		Logger(const char* subSystem, short _logLevel, const char* logFile = "")
		{
			m_LogLevel = _logLevel;
			file.open(logFile, std::ofstream::trunc);

			m_BufferStream << '[' << subSystem << "][" << levelName[_logLevel] << ']';
		}

		~Logger()
		{
			logThis();
		}

		inline int get() { return std::cin.get(); }
		inline void setLogLevel(logLevel level) { this->m_LogLevel = level; }

		template <typename T>
		Logger& operator<<(const T& input)
		{
			m_BufferStream << input;
			return *this;
		}

		Logger& operator<<(std::ostream& (*endl) (std::ostream&))
		{
			m_BufferStream << endl;
			return *this;
		}

		void logThis();
	};

}