#pragma once

#include <string>
#include <vector>
#include <map>

#include "..\Note\Degree.h"

#include "..\..\Exceptions\ParseExceptions.h"

namespace ReMu {

	class Symbol
	{
	private:
		std::string quality;
		int interval;

		static std::map<std::string, std::vector<Degree>> userDef;

		enum Quality
		{
			major,
			minor,
			diminished,
			augmented,
			altered,
			userDefined
		};
	public:
		Symbol() { }
		Symbol(std::string __quality, int __interval = 0) :  quality(__quality), interval(__interval) { }

		std::vector<Degree> eval();

		static void addSymbol(std::string name, std::vector<Pitch>* intervals);
	private:
		Quality is(std::string const& quality);
	};

}