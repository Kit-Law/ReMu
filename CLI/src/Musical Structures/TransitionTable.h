#pragma once

#include <vector>
#include <utility>
#include <iostream>

#include ".\Note\Pitch.h"

#include ".\Chord\Chord.h"

#include ".\Sequence\Sequence.h"

namespace ReMu {

	class TransitionTable
	{
	private:
		std::vector<std::pair<Pitch, Pitch>> noteTransitions;
		std::vector<std::pair<Sequence, Sequence>> sequenceTransitions;

		Pitch relativeMajorKey;
	public:
		void addTransition(Pitch inital, Pitch result);
		void addTransition(Sequence inital, Sequence result);

		std::vector<std::pair<Pitch, Pitch>>* const getNoteTransitions() { return &noteTransitions; }
		std::vector<std::pair<Sequence, Sequence>>* const getSequenceTransitions() { return &sequenceTransitions; }

		inline const void setRelativeMajorKey(Pitch relativeMajorKey) { this->relativeMajorKey = relativeMajorKey;  }
		inline const Pitch* getRelativeMajorKey() { return &relativeMajorKey; }

		friend std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable);
	};

}