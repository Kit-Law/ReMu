#include ".\TransitionTable.h"

namespace ReMu {

	void TransitionTable::addTransition(Note inital, Note result) 
	{ 
		noteTransitions.push_back(std::pair<Note, Note>(inital, result)); 
	}
	
	void TransitionTable::printTrans()
	{
		for (int i = 0; i < noteTransitions.size(); i++)
		{
			std::cout << noteTransitions.at(i).first << " -> " << noteTransitions.at(i).second << std::endl;
		}
	}

}