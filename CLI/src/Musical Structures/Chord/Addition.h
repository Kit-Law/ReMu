#pragma once

#include <vector>
#include <string>

#include "..\Note\Degree.h"

namespace ReMu {

	class Addition
	{
	public:
		static void evaluate(std::string const& addition, Degree interval, std::vector<Degree>* components)
		{
			if (addition == "add") components->push_back(interval);
			else if (addition == "omit" || addition == "sus")
			{
				auto iterator = std::remove_if(components->begin(), components->end(), [interval](Degree& component) { return component == interval; });
				components->erase(iterator, components->end());
			}
			else if (addition == "sus") //TODO: fix this
			{
				auto iterator = std::remove_if(components->begin(), components->end(), [interval](Degree& component) { return component == interval; });
				components->erase(iterator, components->end());
				components->push_back(interval);
			}
			else throw;
		}
	};

}