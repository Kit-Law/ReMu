#pragma once

#include <chrono>

namespace Utils {

	class Timer
	{
	protected:
		std::chrono::high_resolution_clock::time_point m_Buff;
	public:
		std::chrono::duration<double> elapsedTime;
	public:
		inline void start()
		{
			m_Buff = std::chrono::high_resolution_clock::now();
		}
		inline void stop()
		{
			std::chrono::high_resolution_clock::time_point buff = std::chrono::high_resolution_clock::now();
			elapsedTime = std::chrono::duration_cast<std::chrono::duration<double>>(buff - m_Buff);
		}
	};

}