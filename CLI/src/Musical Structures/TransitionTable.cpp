#include ".\TransitionTable.h"

namespace ReMu {

	void TransitionTable::addTransition(Sequence inital, Sequence result, std::string instrument)
	{
		sequenceTransitions[instrument].push_back(std::pair<Sequence, Sequence>(inital, result));
	}

	void TransitionTable::addTransition(Pitch inital, Pitch result, std::string instrument)
	{ 
		noteTransitions[instrument].push_back(std::pair<Pitch, Pitch>(inital, result));
	}
	
	std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable)
	{
		if (transitionTable.noteTransitions.size() > 0) os << "Scale Transitions:" << std::endl;
		
		for (auto instrumnetNoteTransitions : transitionTable.noteTransitions)
		{
			if (instrumnetNoteTransitions.first != "")
				os << std::endl << "Instrument: " << instrumnetNoteTransitions.first << std::endl;

			for (auto notes : instrumnetNoteTransitions.second)
			{
				os << notes.first << " -> " << notes.second << std::endl;
			}
		}

		if (transitionTable.sequenceTransitions.size() > 0) os << "Sequence Transitions:" << std::endl;

		for (auto instrumnetSequenceTransitions : transitionTable.sequenceTransitions)
		{
			if (instrumnetSequenceTransitions.first != "")
				os << std::endl << "Instrument: " << instrumnetSequenceTransitions.first << std::endl;

			for (std::pair<Sequence, Sequence> sequence : instrumnetSequenceTransitions.second)
			{
				for (std::pair<void*, structType>& seq : *sequence.first.getStuctsToMapping())
				{
					if (seq.second == PITCH)
						os << *(Pitch*)seq.first << " ";
					else if (seq.second == CHORD)
						os << "(" << *(Chord*)seq.first << "\b) ";
				}

				os << "-> ";

				for (std::pair<void*, structType>& seq : *sequence.second.getStuctsToMapping())
				{
					if (seq.second == PITCH)
						os << *(Pitch*)seq.first << " ";
					else if (seq.second == CHORD)
						os << "(" << *(Chord*)seq.first << "\b) ";
				}

				os << std::endl;
			}
		}

		return os;
	}

}