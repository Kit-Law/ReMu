#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <tuple>

#include ".\Note\Pitch.h"

#include ".\Chord\Chord.h"

#include ".\Sequence\Sequence.h"

#include "..\Exceptions\ParseExceptions.h"

namespace ReMu {

	class TransitionTable
	{
	private:
		std::vector<std::pair<Pitch, Pitch>*> noteTransitions;
		std::vector<std::tuple<Sequence, Sequence, int>> sequenceTransitions;

		Pitch relativeMajorKey;
		std::tuple<const char*, Note, std::string, short> scaleBuffer;
	public:
		~TransitionTable()
		{
			for (auto& transition : noteTransitions)
			{
				delete transition;
				transition = nullptr;
			}

			noteTransitions.clear();
		}

		void addTransition(Pitch inital, Pitch result, std::string instrument);
		void addTransition(Sequence inital, Sequence result, int occurance, std::string instrument);

		std::vector<std::pair<Pitch, Pitch>*>* const getNoteTransitions() { return &noteTransitions; }
		std::vector<std::tuple<Sequence, Sequence, int>>* const getSequenceTransitions() { return &sequenceTransitions; }

		inline const void setRelativeMajorKey(Pitch relativeMajorKey) { this->relativeMajorKey = relativeMajorKey; }
		inline const Pitch* getRelativeMajorKey() { return &relativeMajorKey; }

		inline void setScaleBuffer(const Note& rootNote, const char* scale, std::string instrument, short line) { scaleBuffer = std::tuple<const char*, Note, std::string, short>(scale, rootNote, instrument, line); }
		inline std::tuple<const char*, Note, std::string, short> getScaleBuffer() { return scaleBuffer; }

		friend std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable);
	};

}