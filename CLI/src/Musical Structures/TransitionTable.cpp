#include ".\TransitionTable.h"

namespace ReMu {

	void TransitionTable::addTransition(Sequence inital, Sequence result)
	{
		sequenceTransitions.push_back(std::pair<Sequence, Sequence>(inital, result));
	}

	void TransitionTable::addTransition(Pitch inital, Pitch result) 
	{ 
		noteTransitions.push_back(std::pair<Pitch, Pitch>(inital, result)); 
	}
	
	std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable)
	{
		if (transitionTable.noteTransitions.size() > 0) os << "Scale Transitions:" << std::endl;

		for (auto notes : transitionTable.noteTransitions)
		{
			os << notes.first << " -> " << notes.second << std::endl;
		}

		if (transitionTable.sequenceTransitions.size() > 0) os << "Sequence Transitions:" << std::endl;

		for (std::pair<Sequence, Sequence> sequence : transitionTable.sequenceTransitions)
		{
			for (std::pair<void*, structType>& seq : *sequence.first.getStuctsToMapping())
			{
				if (seq.second == PITCH)
					os << *(Pitch*)seq.first << " ";
				else if (seq.second == CHORD)
					os << *(Chord*)seq.first << " ";
			}

			os << "-> ";

			for (std::pair<void*, structType>& seq : *sequence.second.getStuctsToMapping())
			{
				if (seq.second == PITCH)
					os << *(Pitch*)seq.first << " ";
				else if (seq.second == CHORD)
					os << *(Chord*)seq.first << " ";
			}

			os << std::endl;
		}

		return os;
	}

}