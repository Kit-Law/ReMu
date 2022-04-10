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

		static std::map<std::string, std::vector<Degree>> userDef;

		enum Quality
		{
			major,
			major6,
			major7,
			minor,
			minor6,
			minor7,
			diminished,
			diminished7,
			dominant7,
			augmented,
			suspended2,
			suspended4,
			altered,
			userDefined
		};
	public:
		Symbol() { }
		Symbol(std::string __quality) :  quality(__quality) { }

		std::vector<Degree> eval();

		static void addSymbol(std::string name, std::vector<Pitch>* intervals);
	private:
		Quality is(std::string const& quality);
	};

}