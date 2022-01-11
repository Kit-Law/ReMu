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
		std::vector<std::pair<std::vector<Note>, std::vector<Note>>> sequenceTransitions;
	public:
		void addTransition(Note inital, Note result);
		void addTransition(std::vector<Note> inital, std::vector<Note> result);

		friend std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable);
	};

}