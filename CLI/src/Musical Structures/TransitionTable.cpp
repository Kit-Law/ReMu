#include ".\TransitionTable.h"

namespace ReMu {

	void TransitionTable::addTransition(Sequence inital, Sequence result, int occurance, std::string instrument)
	{
		if (inital.calDuration() != result.calDuration())
			throw UnbalancedTranstion(inital, result);

		//if (noteTransitions.count(instrument) == 0)
		//	sequenceTransitions[instrument] = std::vector<std::tuple<Sequence, Sequence, int>*>();

		//sequenceTransitions[instrument].push_back(new std::tuple<Sequence, Sequence, int>(inital, result, occurance));
		sequenceTransitions.push_back(std::tuple<Sequence, Sequence, int>(inital, result, occurance));
	}

	void TransitionTable::addTransition(Pitch inital, Pitch result, std::string instrument)
	{ 
		//if (noteTransitions.count(instrument) == 0)
		//	noteTransitions[instrument] = std::vector<std::pair<Pitch, Pitch>*>();

		//noteTransitions[instrument].push_back(new std::pair<Pitch, Pitch>(inital, result));

		noteTransitions.push_back(new std::pair<Pitch, Pitch>(inital, result));
	}
	
	std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable)
	{
		if (transitionTable.noteTransitions.size() > 0) os << "Scale Transitions:" << std::endl;
		
		for (auto notes : transitionTable.noteTransitions)
		{
			os << notes->first << " -> " << notes->second << std::endl;
		}

		/*for (auto instrumnetNoteTransitions : transitionTable.noteTransitions)
		{
			if (instrumnetNoteTransitions.first != "")
				os << std::endl << "Instrument: " << instrumnetNoteTransitions.first << std::endl;

			for (auto notes : instrumnetNoteTransitions.second)
			{
				os << notes->first << " -> " << notes->second << std::endl;
			}
		}*/

		if (transitionTable.sequenceTransitions.size() > 0) os << "----------------------------------" << std::endl << "Sequence Transitions:" << std::endl;

		/*for (auto instrumnetSequenceTransitions : transitionTable.sequenceTransitions)
		{
			if (instrumnetSequenceTransitions.first != "")
				os << std::endl << "Instrument: " << instrumnetSequenceTransitions.first << std::endl;

			for (std::tuple<Sequence, Sequence, int>* sequence : instrumnetSequenceTransitions.second)
			{
				if (std::get<2>(*sequence) > 0)
					os << "Every " << std::get<2>(*sequence) << " occurance: ";

				os << std::get<0>(*sequence) << "-> " << std::get<1>(*sequence) << std::endl;
			}
		}*/

		for (std::tuple<Sequence, Sequence, int> sequence : transitionTable.sequenceTransitions)
		{
			if (std::get<2>(sequence) > 0)
				os << "Every " << std::get<2>(sequence) << " occurance: ";

			os << std::get<0>(sequence) << "-> " << std::get<1>(sequence) << std::endl;
		}

		return os;
	}

}