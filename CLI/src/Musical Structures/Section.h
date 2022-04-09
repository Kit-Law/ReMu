#pragma once

#include ".\TransitionTable.h"

#include <map>
#include <string>

namespace ReMu {

	class Section
	{
	private:
		std::string label;
		std::pair<int, int> duration;

		std::map<std::string, TransitionTable> transitionTables;
	public:
		Section(std::string __label, int start, int end) : label(__label), duration(std::pair<int, int>(start, end)) {  }

		inline TransitionTable* getTransitionTable(std::string instrument = "") { return &transitionTables[instrument]; }
		inline std::map<std::string, TransitionTable>* getTransitionTableMap() { return &transitionTables; }

		inline int getStartingMessure() { return duration.first; }
		inline int getEndingMessure() { return duration.second; }

		friend std::ostream& operator<<(std::ostream& os, const Section& section);
	};
	
	inline std::ostream& operator<<(std::ostream& os, const Section& section)
	{
		os << std::endl << "Section: " << section.label << ", " << section.duration.first << " - " << section.duration.second << std::endl;

		for (const auto& instrumentTrans : section.transitionTables)
		{
			if (instrumentTrans.first != "")
				os << std::endl << "Instrument: " << instrumentTrans.first << std::endl;

			os << std::endl << instrumentTrans.second;
		}
		
		return os;
	}

}