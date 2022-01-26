#pragma once

#include ".\Timer.h"

namespace Utils {

	class DeltaTime
	{
	private:
		static Timer m_Timer;
		static double m_DeltaTime;
	public:
		static void calDeltaTime();
		static void resetDeltaTime();
		static inline double getDeltaTime() { return m_DeltaTime; }
	};

}