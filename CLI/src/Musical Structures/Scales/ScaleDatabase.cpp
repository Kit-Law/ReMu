#include ".\ScaleDatabase.h"

#include <iostream>
#include <string.h>

namespace ReMu {

	std::map<std::string, ScaleInfo*> ScaleDatabase::database;

	void ScaleDatabase::initalize() //TODO::fix the space issue
	{
		database["Major scale"] = MAJOR_SCALE_INFO;
		database["Dorian scale"] = DORIAN_SCALE_INFO;
		database["Phrygian scale"] = PHRYGIAN_SCALE_INFO;
		database["Lydian scale"] = LYDIAN_SCALE_INFO;
		database["Mixolydian scale"] = MIXOLYDIAN_SCALE_INFO;
		database["Aeolianand scale"] = AEOLIANAND_SCALE_INFO;
		database["Locrian scale"] = LOCRIAN_SCALE_INFO;
	}

	ScaleInfo* ScaleDatabase::getScale(const char* scaleName)
	{ 
		return database.at(scaleName); 
	} //TODO: make this secure

}