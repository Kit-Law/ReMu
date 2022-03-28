#pragma once

#include "../Musical Structures/Note/Pitch.h"
#include "../Musical Structures/Sequence/Sequence.h"

#include "./NoteEvaluator.h"
#include "./ChordEvaluator.h"

#include "pugixml.hpp"

#include <vector>

namespace ReMu { namespace Evaluator {

	class SequenceEvaluator
	{
	private:
		std::tuple<Sequence, Sequence, int> sequenceTransitions;
		std::vector<pugi::xml_node>* nodeBuffer;
		int nextNode = 0;
		int occurance = 1;
	public:
		SequenceEvaluator(std::tuple<Sequence, Sequence, int> __sequenceTransitions)
		{
			sequenceTransitions = __sequenceTransitions;
			nodeBuffer = new std::vector<pugi::xml_node>[std::get<0>(__sequenceTransitions).size()];
		}

		~SequenceEvaluator()
		{
			delete nodeBuffer;
		}

		void evaluate(std::pair<std::vector<ReMu::Pitch>, std::vector<pugi::xml_node>>& intialNotes, float duration)
		{
			std::pair<void*, structType>* next = &std::get<0>(sequenceTransitions).getStuctsToMapping()->at(nextNode);
			std::pair<void*, structType>* first = &std::get<0>(sequenceTransitions).getStuctsToMapping()->at(0);
			bool hasDuration = std::get<0>(sequenceTransitions).hasDuration();
			bool currentMatch = false;
			bool firstMatch = false;

			if (next->second == PITCH)
			{
				if ((intialNotes.first.front() == *(Pitch*)next->first || ((Pitch*)next->first)->getStep() == '_')
					&& (!hasDuration || ((Pitch*)next->first)->getDuration() == duration))
					currentMatch = true;
			}
			else if (next->second == CHORD)
			{
				if (intialNotes.first == *(Chord*)next->first
					&& (!hasDuration || ((Chord*)first->first)->getDuration() == duration))
					currentMatch = true;
			}

			if (!currentMatch)
			{
				if (first->second == PITCH)
				{
					if ((nextNode > 0 && intialNotes.first.front() == *(Pitch*)first->first || ((Pitch*)first->first)->getStep() == '_')
						&& (!hasDuration || ((Pitch*)first->first)->getDuration() == duration))
						firstMatch = true;
				}
				else if (first->second == CHORD)
				{
					if ((nextNode > 0 && intialNotes.first == *(Chord*)first->first)
						&& (!hasDuration || ((Chord*)first->first)->getDuration() == duration))
						firstMatch = true;
				}
			}

			if (currentMatch)
			{
				nodeBuffer[nextNode] = intialNotes.second;
				nextNode++;
			}
			else if (firstMatch)
			{
				nodeBuffer[0] = intialNotes.second;
				nextNode = 1;
			}
			else
				nextNode = 0;

			if (nextNode == std::get<0>(sequenceTransitions).size())
			{
				if (occurance == std::get<2>(sequenceTransitions))
				{
					colapse();
					nextNode = 0;
					occurance = 1;
				}
				else
				{
					occurance++;
					nextNode = 0;
				}
			}		
		}
	private:
		void colapse()
		{
			for (size_t j = 0; j < std::get<1>(sequenceTransitions).size(); j++)
			{
				std::pair<void*, structType>* next = &std::get<1>(sequenceTransitions).getStuctsToMapping()->at(j);

				if (next->second == PITCH)
					NoteEvaluator::setNotes(&nodeBuffer[j], (Pitch*)next->first);
				else if (next->second == CHORD)
					ChordEvaluator::setChord(&nodeBuffer[j], (Chord*)next->first);
			}
		}
	};

} }