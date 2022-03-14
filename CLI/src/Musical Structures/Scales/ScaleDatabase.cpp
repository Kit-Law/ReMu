#include ".\ScaleDatabase.h"

#include <iostream>
#include <string.h>

namespace ReMu {

	std::map<std::string, ScaleInfo*> ScaleDatabase::database;

	void ScaleDatabase::initalize() //TODO::fix the space issue
	{
		database["Major"] = MAJOR_SCALE_INFO;
		database["Dorian"] = DORIAN_SCALE_INFO;
		database["Phrygian"] = PHRYGIAN_SCALE_INFO;
		database["Lydian"] = LYDIAN_SCALE_INFO;
		database["Mixolydian"] = MIXOLYDIAN_SCALE_INFO;
		database["Aeolian"] = AEOLIAN_SCALE_INFO;
		database["Locrian"] = LOCRIAN_SCALE_INFO;
	}

	ScaleInfo* ScaleDatabase::getScale(const char* scaleName)
	{ 
		return database.at(scaleName); 
	} //TODO: make this secure

	void ScaleDatabase::addScale(const char* scaleName, ScaleInfo* scale)
	{
		database[scaleName] = scale;
	}

}