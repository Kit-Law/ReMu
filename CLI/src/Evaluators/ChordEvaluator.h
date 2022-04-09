#pragma once

#include "../Musical Structures/Note/Pitch.h"
#include "../Musical Structures/Chord/Chord.h"

#include "../Musical Structures/Section.h"

#include "./NoteEvaluator.h"

#include "pugixml.hpp"

#include <map>
#include <unordered_map>
#include <string>

namespace ReMu { namespace Evaluator {

	class ChordEvaluator
	{
	public:	
		inline static Chord parseChord(pugi::xml_node messure)
		{
			std::vector<Pitch> components;

			for (pugi::xml_node note : messure.children("note"))
			{
				Pitch component = NoteEvaluator::parseNote(note.child("pitch"));

				components.push_back(component);
			}

			return Chord(components);
		}

		inline static void setChord(std::vector<pugi::xml_node>* notes, Chord* chord)
		{
			size_t i = 0;
			pugi::xml_node* lastNote = nullptr;
			for (pugi::xml_node note : *notes)
			{
				if (i < chord->getComponents()->size())
				{
					auto pitchBuffer = static_cast<Pitch>(chord->getComponents()->at(i));
					pitchBuffer.setDuration(chord->getDuration());

					NoteEvaluator::setNote(&note, &pitchBuffer);
				}
					
				else
					note.parent().parent().remove_child(note.parent());

				i++;
				lastNote = &note;
			}

			//TODO: add chord tag here
			for (; i < chord->getComponents()->size(); i++)
			{
				auto noteBuffer = notes->at(0).parent().parent().append_copy(lastNote->parent()).child("pitch");//.append_child("chord");
				auto pitchBuffer = static_cast<Pitch>(chord->getComponents()->at(i));

				if (!noteBuffer.parent().child("chord"))
					noteBuffer.parent().prepend_child("chord");

				NoteEvaluator::setNote(&noteBuffer, &pitchBuffer);
			}
		}
	};

} }