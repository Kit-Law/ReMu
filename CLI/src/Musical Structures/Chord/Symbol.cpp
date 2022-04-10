#include "Symbol.h"

namespace ReMu {

	std::map<std::string, std::vector<Degree>> Symbol::userDef;

	std::vector<Degree> Symbol::eval()
	{
		switch (is(quality))
		{
		case major:
			return std::vector<Degree>{ Degree(3, None), Degree(5, None) };
		case major6:
			return std::vector<Degree>{ Degree(3, None), Degree(5, None), Degree(6, None) };
		case major7:
			return std::vector<Degree>{ Degree(3, None), Degree(5, None), Degree(7, None) };
		case minor:
			return std::vector<Degree>{ Degree(3, Flat), Degree(5, None) };
		case minor6:
			return std::vector<Degree>{ Degree(3, Flat), Degree(5, None), Degree(5, DoubleSharp) };
		case minor7:
			return std::vector<Degree>{ Degree(3, Flat), Degree(5, None), Degree(7, Flat) };
		case diminished:
			return std::vector<Degree>{ Degree(3, Flat), Degree(5, Flat) };
		case diminished7:
			return std::vector<Degree>{ Degree(3, Flat), Degree(5, Flat), Degree(7, DoubleFlat) };
		case dominant7:
			return std::vector<Degree>{ Degree(3, None), Degree(5, None), Degree(7, Flat) };
		case suspended2:
			return std::vector<Degree>{ Degree(2, None), Degree(5, None) };
		case suspended4:
			return std::vector<Degree>{ Degree(4, None), Degree(5, None) };
		case augmented:
			return std::vector<Degree>{ Degree(3, None), Degree(5, Sharp) };
		case altered:
			return std::vector<Degree>{ 3, 5 };
		case userDefined:
			if (userDef.count(quality) <= 0)
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
		else if (quality == "maj6" || quality == "M6") return major6;
		else if (quality == "maj7" || quality == "M7") return major7;
		else if (quality == "min" || quality == "m") return minor;
		else if (quality == "min6" || quality == "m6") return minor6;
		else if (quality == "min7" || quality == "m7") return minor7;
		else if (quality == "dim" || quality == "°") return diminished;
		else if (quality == "dim7" || quality == "°7") return diminished7;
		else if (quality == "dom7") return dominant7;
		else if (quality == "sus2") return suspended2;
		else if (quality == "sus4") return suspended4;
		else if (quality == "aug") return augmented;
		else if (quality == "alt") return altered;
		else return userDefined;
	}

}