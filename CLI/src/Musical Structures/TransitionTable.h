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
		std::map<std::string, std::vector<std::pair<Pitch, Pitch>*>> noteTransitions;
		std::map<std::string, std::vector<std::tuple<Sequence, Sequence, int>>> sequenceTransitions;
		//std::vector<std::pair<Pitch, Pitch>*> noteTransitions;
		//std::vector<std::tuple<Sequence, Sequence, int>> sequenceTransitions;

		Pitch relativeMajorKey;
		std::tuple<const char*, Note, std::string, short> scaleBuffer;
	public:
		~TransitionTable()
		{
			for (auto& intrtumentNoteTran : noteTransitions)
				for (auto& transition : intrtumentNoteTran.second)
				{
					delete transition;
					transition = nullptr;
				}

			noteTransitions.clear();
		}

		void addTransition(Pitch inital, Pitch result, std::string instrument);
		void addTransition(Sequence inital, Sequence result, int occurance, std::string instrument);

		std::vector<std::pair<Pitch, Pitch>*>* const getNoteTransitions(std::string instrument = "") { return &noteTransitions[instrument]; }
		std::vector<std::tuple<Sequence, Sequence, int>>* const getSequenceTransitions(std::string instrument = "") { return &sequenceTransitions[instrument]; }

		inline const void setRelativeMajorKey(Pitch relativeMajorKey) { this->relativeMajorKey = relativeMajorKey; }
		inline const Pitch* getRelativeMajorKey() { return &relativeMajorKey; }

		inline void setScaleBuffer(const Note& rootNote, const char* scale, std::string instrument, short line) { scaleBuffer = std::tuple<const char*, Note, std::string, short>(scale, rootNote, instrument, line); }
		inline std::tuple<const char*, Note, std::string, short> getScaleBuffer() { return scaleBuffer; }

		friend std::ostream& operator<<(std::ostream& os, const TransitionTable& transitionTable);
	};

}