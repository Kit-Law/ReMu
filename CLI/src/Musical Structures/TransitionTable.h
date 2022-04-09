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
		std::tuple<const char*, Pitch, short> scaleBuffer;
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

		void addTransition(Pitch inital, Pitch result);
		void addTransition(Sequence inital, Sequence result, int occurance);

		std::vector<std::pair<Pitch, Pitch>*>* const getNoteTransitions() { return &noteTransitions; }
		std::vector<std::tuple<Sequence, Sequence, int>>* const getSequenceTransitions() { return &sequenceTransitions; }

		inline const void setRelativeMajorKey(Pitch relativeMajorKey) { this->relativeMajorKey = relativeMajorKey; }
		inline const Pitch* getRelativeMajorKey() { return &relativeMajorKey; }

		inline void setScaleBuffer(const Pitch& rootNote, const char* scale, short line) { scaleBuffer = std::tuple<const char*, Pitch, short>(scale, rootNote, line); }
		inline std::tuple<const char*, Pitch, short> getScaleBuffer() { return scaleBuffer; }

		friend std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable);
	};

}