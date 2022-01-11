#pragma once

#include ".\Note\Note.h"

#include <vector>
#include <utility>
#include <iostream>

namespace ReMu {

	class TransitionTable
	{
	private:
		std::vector<std::pair<Note, Note>> noteTransitions;
	public:
		void addTransition(Note inital, Note result);
		void printTrans();
	};

}