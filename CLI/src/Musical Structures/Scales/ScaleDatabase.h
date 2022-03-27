#pragma once

#include <map>
#include <string>

#include ".\ScaleInfo.h"

#include "..\..\Exceptions\ParseExceptions.h"

#define MAJOR_SCALE_INFO		new ScaleInfo(new int[7]{ 2,2,1,2,2,2,1 }, 7, 0)
#define DORIAN_SCALE_INFO		new ScaleInfo(new int[7]{ 2,1,2,2,2,1,2 }, 7, 6)
#define PHRYGIAN_SCALE_INFO		new ScaleInfo(new int[7]{ 1,2,2,2,1,2,2 }, 7, 5)
#define LYDIAN_SCALE_INFO		new ScaleInfo(new int[7]{ 2,2,2,1,2,2,1 }, 7, 4)
#define MIXOLYDIAN_SCALE_INFO	new ScaleInfo(new int[7]{ 2,2,1,2,2,1,2 }, 7, 3)
#define AEOLIAN_SCALE_INFO	    new ScaleInfo(new int[7]{ 2,1,2,2,1,2,2 }, 7, 2)
#define LOCRIAN_SCALE_INFO		new ScaleInfo(new int[7]{ 1,2,2,1,2,2,2 }, 7, 1)

namespace ReMu {

	class ScaleDatabase
	{
	private:
		static std::map<std::string, ScaleInfo*> database;
	public:
		static void initalize();
		static void destruct();

		static ScaleInfo* getScale(const char* scaleName, short line);
		static void addScale(const char* scaleName, ScaleInfo* scale, short line);
	};

}