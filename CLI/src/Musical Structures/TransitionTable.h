#pragma once

#include <vector>
#include <utility>
#include <iostream>

#include ".\Note\Pitch.h"

#include ".\Chord\Chord.h"

namespace ReMu {

	class TransitionTable
	{
	private:
		std::vector<std::pair<Pitch, Pitch>> noteTransitions;
		std::vector<std::pair<std::vector<Pitch>, std::vector<Pitch>>> sequenceTransitions;
		std::vector<std::pair<Chord, Chord>> chordTransitions;
	public:
		void addTransition(Pitch inital, Pitch result);
		void addTransition(std::vector<Pitch> inital, std::vector<Pitch> result);
		void addTransition(Chord inital, Chord result);

		friend std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable);
	};

}