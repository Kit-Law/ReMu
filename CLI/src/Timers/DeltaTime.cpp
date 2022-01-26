#include ".\DeltaTime.h"

namespace Utils {

	Timer DeltaTime::m_Timer;
	double DeltaTime::m_DeltaTime = 1;

	void DeltaTime::calDeltaTime()
	{
		m_Timer.stop();
		std::chrono::duration<double> buff = m_Timer.elapsedTime;
		m_DeltaTime = buff.count();
		m_Timer.start();
	}

	void DeltaTime::resetDeltaTime()
	{
		m_Timer.stop();
		m_Timer.start();
	}

}