#pragma once

#include "../Musical Structures/Note/Pitch.h"
#include "../Musical Structures/Note/Note.h"
#include "../Musical Structures/Chord/Chord.h"

#include "../Musical Structures/Section.h"

#include "./NoteEvaluator.h"

#include "pugixml.hpp"

#include <map>
#include <unordered_map>
#include <string>

namespace ReMu { namespace Evaluator {

	class ChordTransitionEvaluator
	{
	public:	
		inline static void evaluate(pugi::xml_document &doc, Section* section)
		{
			pugi::xpath_node_set messures = doc.select_nodes(("/score-partwise/part/measure[@number >= " + std::to_string(section->getStartingMessure()) + " and @number < " + std::to_string(section->getEndingMessure()) + " and note/chord]").c_str());
			for (pugi::xpath_node node : messures)
			{
				pugi::xml_node messure = node.node();

				Chord initalChord = parseChord(messure);

				for (std::pair<Chord, Chord> transition : *section->getTransitionTable()->getChordTransitions())
				{
					if (initalChord == transition.first)
					{
						setChord(messure, transition.second);

						break;
					}
				}
			}
		}
	private:
		inline static Chord parseChord(pugi::xml_node messure)
		{
			std::vector<Note> components;

			for (pugi::xml_node note : messure.children("note"))
			{
				Pitch component = NoteEvaluator::parseNote(note.child("pitch"));

				components.push_back(component);
			}

			return Chord(components);
		}

		inline static void setChord(pugi::xml_node messure, Chord chord)
		{
			short i = 0;
			pugi::xml_node* lastNote = nullptr;
			for (pugi::xml_node note : messure.children("note"))
			{
				if (i < chord.getComponents()->size())
					NoteEvaluator::setNote(note.child("pitch"), chord.getComponents()->at(i));
				else
					note.parent().remove_child(note);

				i++;
				lastNote = &note;
			}

			for (; i < chord.getComponents()->size(); i++)
				NoteEvaluator::setNote(messure.append_copy(*lastNote).child("pitch"), chord.getComponents()->at(i));
		}
	};

} }