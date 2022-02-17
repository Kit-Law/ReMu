#pragma once

#include "../Musical Structures/Note/Pitch.h"

#include "./NoteEvaluator.h"

#include "pugixml.hpp"

#include <vector>

namespace ReMu { namespace Evaluator {

	class SequenceBuffer
	{
	private:
		std::pair<std::vector<Pitch>, std::vector<Pitch>> sequenceTransitions;
		pugi::xml_node* nodeBuffer;
		int nextNode = 0;
	public:
		SequenceBuffer(std::pair<std::vector<Pitch>, std::vector<Pitch>> __sequenceTransitions)
		{
			sequenceTransitions = __sequenceTransitions;
			nodeBuffer = new pugi::xml_node[__sequenceTransitions.first.size()];
		}

		void evaluate(pugi::xml_node &note)
		{
			ReMu::Pitch intialNote = NoteEvaluator::parseNote(note);
			
			if (intialNote == sequenceTransitions.first[nextNode])
			{
				nodeBuffer[nextNode] = note;
				nextNode++;
			}
			else if (nextNode > 0 && intialNote == sequenceTransitions.first[0])
			{
				nodeBuffer[0] = note;
				nextNode = 1;
			}
			else
				nextNode = 0;

			if (nextNode == sequenceTransitions.first.size())
			{
				colapse();
				nextNode = 0;
			}		
		}
	private:
		void colapse()
		{
			for (int j = 0; j < sequenceTransitions.first.size(); j++)
				NoteEvaluator::setNote(nodeBuffer[j], sequenceTransitions.second[j]);
		}
	};

} }