#include ".\TransitionTable.h"

namespace ReMu {

	void TransitionTable::addTransition(Sequence inital, Sequence result, int occurance, std::string instrument)
	{
		sequenceTransitions[instrument].push_back(std::tuple<Sequence, Sequence, int>(inital, result, occurance));
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

		if (transitionTable.sequenceTransitions.size() > 0) os << "----------------------------------" << std::endl << "Sequence Transitions:" << std::endl;

		for (auto instrumnetSequenceTransitions : transitionTable.sequenceTransitions)
		{
			if (instrumnetSequenceTransitions.first != "")
				os << std::endl << "Instrument: " << instrumnetSequenceTransitions.first << std::endl;

			for (std::tuple<Sequence, Sequence, int> sequence : instrumnetSequenceTransitions.second)
			{
				if (std::get<2>(sequence) > 0)
					os << "Every " << std::get<2>(sequence) << " occurance: ";

				for (std::pair<void*, structType>& seq : *std::get<0>(sequence).getStuctsToMapping())
				{
					if (seq.second == PITCH)
						os << *(Pitch*)seq.first << " ";
					else if (seq.second == CHORD)
						os << "(" << *(Chord*)seq.first << "\b) ";
				}

				os << "-> ";

				for (std::pair<void*, structType>& seq : *std::get<1>(sequence).getStuctsToMapping())
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