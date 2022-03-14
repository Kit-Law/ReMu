#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <tuple>

#include ".\Note\Pitch.h"

#include ".\Chord\Chord.h"

#include ".\Sequence\Sequence.h"

namespace ReMu {

	class TransitionTable
	{
	private:
		std::map<std::string, std::vector<std::pair<Pitch, Pitch>>> noteTransitions;
		std::map<std::string, std::vector<std::pair<Sequence, Sequence>>> sequenceTransitions;

		Pitch relativeMajorKey;
		std::tuple<const char*, Note, std::string> scaleBuffer;
	public:
		void addTransition(Pitch inital, Pitch result, std::string instrument);
		void addTransition(Sequence inital, Sequence result, std::string instrument);

		std::vector<std::pair<Pitch, Pitch>>* const getNoteTransitions(std::string instrument = "") { return &noteTransitions[instrument]; }
		std::vector<std::pair<Sequence, Sequence>>* const getSequenceTransitions(std::string instrument = "") { return &sequenceTransitions[instrument]; }

		inline const void setRelativeMajorKey(Pitch relativeMajorKey) { this->relativeMajorKey = relativeMajorKey;  }
		inline const Pitch* getRelativeMajorKey() { return &relativeMajorKey; }

		inline void setScaleBuffer(const Note& rootNote, const char* scale, std::string instrument) { scaleBuffer = std::tuple<const char*, Note, std::string>(scale, rootNote, instrument); }
		inline std::tuple<const char*, Note, std::string> getScaleBuffer() { return scaleBuffer; }

		friend std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable);
	};

}