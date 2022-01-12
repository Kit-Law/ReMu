#pragma once

#include <string>
#include <vector>

#include "..\Note\Degree.h"

namespace ReMu {

	class Symbol
	{
	private:
		std::string quality;
		int interval;

		enum Quality
		{
			major,
			minor,
			diminished,
			augmented,
			altered
		};
	public:
		Symbol() { }
		Symbol(std::string __quality, int __interval = 0) { quality = __quality, interval = __interval; }

		inline std::vector<Degree> eval()
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
			}
		}

		Quality is(std::string const& quality)
		{
			if (quality == "maj" || quality == "M") return major;
			else if (quality == "min" || quality == "m") return minor;
			else if (quality == "dim" || quality == "o") return diminished;
			else if (quality == "aug" || quality == "+") return augmented;
			else if (quality == "alt") return altered;
			else throw;
		}
	};

}