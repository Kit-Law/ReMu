#include ".\ScaleDatabase.h"

#include <iostream>
#include <string.h>

namespace ReMu {

	std::map<std::string, ScaleInfo*> ScaleDatabase::database;

	void ScaleDatabase::initalize()
	{
		database["Major"] = MAJOR_SCALE_INFO;
		database["Dorian"] = DORIAN_SCALE_INFO;
		database["Phrygian"] = PHRYGIAN_SCALE_INFO;
		database["Lydian"] = LYDIAN_SCALE_INFO;
		database["Mixolydian"] = MIXOLYDIAN_SCALE_INFO;
		database["Aeolian"] = AEOLIAN_SCALE_INFO;
		database["Minor"] = AEOLIAN_SCALE_INFO;
		database["Locrian"] = LOCRIAN_SCALE_INFO;
	}

	void ScaleDatabase::destruct()
	{
		for (std::map<std::string, ScaleInfo*>::iterator itr = database.begin(); itr != database.end(); itr++)
			delete (itr->second);

		database.clear();
	}

	ScaleInfo* ScaleDatabase::getScale(const char* scaleName, short line)
	{ 
		if (database.count(scaleName) <= 0)
			throw ScaleNotFonud(scaleName, line);

		return database.at(scaleName); 
	}

	void ScaleDatabase::addScale(const char* scaleName, ScaleInfo* scale, short line)
	{
		if (database.count(scaleName) > 0)
			throw RedefinedScale(scaleName, line);

		database[scaleName] = scale;
	}

}