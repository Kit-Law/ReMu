#pragma once

#include "..\Note\Note.h"

namespace ReMu {

	class ScaleInfo
	{
	private:
		const int* intervales;
		const int scaleLength;
	public:
		ScaleInfo(int* __intervales, int __scaleLength) : intervales(__intervales), scaleLength(__scaleLength) { }
		~ScaleInfo() { delete intervales; }

		inline const int* getIntervales() { return intervales; }
		inline const int getScaleLength() { return scaleLength; }
	};

}