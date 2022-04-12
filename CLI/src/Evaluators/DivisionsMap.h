#pragma once

#include <vector>

#include "pugixml.hpp"

namespace ReMu {

	class DivisionsMap
	{
	private:
		struct DivisionEntry
		{
			int startingMessure;
			int endingMessure;

			float division;

			DivisionEntry(int __startingMessure, int __endingMessure, float __division) : startingMessure(__startingMessure), endingMessure(__endingMessure), division(__division) {}
		};

		std::vector<DivisionEntry> divisionsVector;
	public:
		DivisionsMap(pugi::xml_document& doc)
		{
			pugi::xpath_node_set divisions = doc.select_nodes("/score-partwise/part/measure/attributes/divisions");

			for (int i = 0; i < divisions.size(); i++)
				divisionsVector.push_back(DivisionEntry(divisions[i].node().parent().parent().attribute("number").as_int(),
					(i + 1 < divisions.size() ? divisions[i + 1].node().parent().parent().attribute("number").as_int() : INT_MAX),
					divisions[i].node().text().as_float()));
		}

		inline float getDivision(int messure)
		{
			for (DivisionEntry division : divisionsVector)
			{
				if (division.startingMessure <= messure && division.endingMessure >= messure)
					return division.division;
			}

			throw;
		}
	};

}

/*
pugi::xpath_node_set divisions = testDoc.select_nodes(("/score-partwise/part/measure[@number >= " + std::to_string(section->getStartingMessure()) + " and @number < " + std::to_string(section->getEndingMessure()) + "]/attributes/divisions").c_str());
	
for (int i = 0; i < divisions.size(); i++)
{
	pugi::xml_node division = divisions[i].node();
	division.text() = division.text().as_int() * factor;

	pugi::xpath_node_set notes = testDoc.select_nodes(("/score-partwise/part/measure[@number >= " + std::string(division.parent().parent().attribute("number").value()) + " and @number < " + (i + 1 < divisions.size() ? std::string(division.parent().parent().attribute("number").value()) : std::to_string(section->getEndingMessure())) + "]/note/duration").c_str());

	for (pugi::xpath_node note : notes)
		note.node().text() = note.node().text().as_int() * factor;
}
*/