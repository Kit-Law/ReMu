#include ".\TransitionTable.h"

namespace ReMu {

	void TransitionTable::addTransition(std::vector<Note> inital, std::vector<Note> result)
	{
		sequenceTransitions.push_back(std::pair<std::vector<Note>, std::vector<Note>>(inital, result));
	}

	void TransitionTable::addTransition(Note inital, Note result) 
	{ 
		noteTransitions.push_back(std::pair<Note, Note>(inital, result)); 
	}
	
	std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable)
	{
		os << "Scale Transitions:" << std::endl;

		for (auto notes : transitionTable.noteTransitions)
		{
			os << notes.first << " -> " << notes.second << std::endl;
		}

		os << "Sequence Transitions:" << std::endl;

		for (auto sequence : transitionTable.sequenceTransitions)
		{
			for (Note& note : sequence.first)
				os << note << " ";

			os << "-> ";

			for (Note& note : sequence.second)
				os << note << " ";

			os << std::endl;
		}

		return os;
	}

}