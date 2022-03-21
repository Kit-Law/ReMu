#include "Symbol.h"

namespace ReMu {

	std::map<std::string, std::vector<Degree>> Symbol::userDef;

	std::vector<Degree> Symbol::eval()
	{
		switch (is(quality))
		{
		case major:
			return std::vector<Degree>{ Degree(3, None), Degree(5, None) };
		case minor:
			return std::vector<Degree>{ Degree(3, Flat), Degree(5, None) };
		case diminished:
			return std::vector<Degree>{ Degree(3, Flat), Degree(5, Flat) };
		case augmented:
			return std::vector<Degree>{ Degree(3, None), Degree(5, Sharp) };
		case altered:
			return std::vector<Degree>{ 3, 5 };
		case userDefined:
			if (userDef.count(quality) == 0)
				throw ChordNotFonud(quality);

			return userDef[quality];
		}
	}

	void Symbol::addSymbol(std::string name, std::vector<Pitch>* intervals)
	{
		if (userDef.count(name) > 0)
			throw RedefinedChord(name);

		std::vector<Degree> intervalBuffer;

		for (Pitch interval : *intervals)
			intervalBuffer.push_back(interval);

		userDef[name] = intervalBuffer;
	}

	Symbol::Quality Symbol::is(std::string const& quality)
	{
		if (quality == "maj" || quality == "M") return major;
		else if (quality == "min" || quality == "m") return minor;
		else if (quality == "dim" || quality == "o") return diminished;
		else if (quality == "aug" || quality == "+") return augmented;
		else if (quality == "alt") return altered;
		else return userDefined;
	}

}