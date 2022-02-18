#pragma once

#include "../Musical Structures/Note/Pitch.h"
#include "../Musical Structures/Note/Note.h"
#include "../Musical Structures/Note/Accidental.h"

#include "./SequenceBuffer.h"

#include "pugixml.hpp"

#include <map>
#include <unordered_map>
#include <string>

namespace ReMu { namespace Evaluator {

	class NoteTransitionEvaluator
	{
	public:	
		inline static void evaluate(pugi::xml_document &doc, Section* section)
		{
			pugi::xpath_node_set notes = doc.select_nodes(("/score-partwise/part/measure[@number >= " + std::to_string(section->getStartingMessure()) + " and @number < " + std::to_string(section->getEndingMessure()) + " and not(note/chord)] /note/pitch").c_str());
			ReMu::TransitionTable* transitionTable = section->getTransitionTable();

			//TODO: Clean this block up
			std::vector<SequenceBuffer*> sequenceBuffers;
			for (auto const& sequence : *transitionTable->getSequenceTransitions())
				sequenceBuffers.push_back(new SequenceBuffer(sequence));

			//TODO: Clean this block up
			std::unordered_map<ReMu::Pitch, ReMu::Pitch, ReMu::Pitch> noteTransitions;
			for (auto transition : *transitionTable->getNoteTransitions())
				noteTransitions[transition.first] = transition.second;

			for (pugi::xpath_node node : notes)
			{
				pugi::xml_node note = node.node();
				ReMu::Pitch intialNote = NoteEvaluator::parseNote(note);

				for (auto sequence : sequenceBuffers)
					sequence->evaluate(note);

				if (noteTransitions.count(intialNote) > 0)
					NoteEvaluator::setNote(note, noteTransitions.at(intialNote));
			}
		}
	};

} }