#include ".\TransitionTable.h"

namespace ReMu {

	void TransitionTable::addTransition(std::vector<Pitch> inital, std::vector<Pitch> result)
	{
		sequenceTransitions.push_back(std::pair<std::vector<Pitch>, std::vector<Pitch>>(inital, result));
	}

	void TransitionTable::addTransition(Pitch inital, Pitch result) 
	{ 
		noteTransitions.push_back(std::pair<Pitch, Pitch>(inital, result)); 
	}

	void TransitionTable::addTransition(Chord inital, Chord result)
	{
		chordTransitions.push_back(std::pair<Chord, Chord>(inital, result));
	}
	
	std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable)
	{
		if (transitionTable.noteTransitions.size() > 0) os << "Scale Transitions:" << std::endl;

		for (auto notes : transitionTable.noteTransitions)
		{
			os << notes.first << " -> " << notes.second << std::endl;
		}

		if (transitionTable.chordTransitions.size() > 0) os << "Chord Transitions:" << std::endl;

		for (auto chords : transitionTable.chordTransitions)
		{
			os << chords.first << " -> " << chords.second << std::endl;
		}

		if (transitionTable.sequenceTransitions.size() > 0) os << "Sequence Transitions:" << std::endl;

		for (auto sequence : transitionTable.sequenceTransitions)
		{
			for (Pitch& note : sequence.first)
				os << note << " ";

			os << "-> ";

			for (Pitch& note : sequence.second)
				os << note << " ";

			os << std::endl;
		}

		return os;
	}

}