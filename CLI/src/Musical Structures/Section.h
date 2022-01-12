#pragma once

#include ".\TransitionTable.h"

namespace ReMu {

	class Section
	{
	private:
		std::string label;
		std::pair<int, int> duration;

		TransitionTable transitionTable;
	public:
		Section(std::string __label, int start, int end) { label = __label; duration.first = start, duration.second = end; }

		inline TransitionTable* getTransitionTable() { return &transitionTable; }

		friend std::ostream& operator<<(std::ostream& os, const Section& section);
	};
	
	inline std::ostream& operator<<(std::ostream& os, const Section& section)
	{
		os << std::endl << "Section: " << section.label << ", " << section.duration.first << " - " << section.duration.second << std::endl;
		os << std::endl << section.transitionTable;
		return os;
	}

}