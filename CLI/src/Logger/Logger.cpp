#include ".\Logger.h"

namespace ReMu {

	std::ofstream Logger::file;

	void Logger::logThis()
	{
		if (file.is_open())
			file << m_BufferStream.str();

#ifdef _WIN32
		int settings = 0;

		if (m_LogLevel == LOG_LEVEL_INFO)
			settings = (FOREGROUND_GREEN | FOREGROUND_BLUE);
		else if (m_LogLevel == LOG_LEVEL_WARNING)
			settings = (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE);
		else if (m_LogLevel == LOG_LEVEL_ERROR)
			settings = (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED);

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, settings);
#endif

		std::string m_buff = m_BufferStream.str();
		std::cout << m_buff;

		m_BufferStream.clear();

#ifdef _WIN32
		SetConsoleTextAttribute(hStdOut, 15);
#endif
	}

}