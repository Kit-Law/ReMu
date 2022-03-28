#pragma once

#include "../Musical Structures/Note/Pitch.h"
#include "../Musical Structures/Note/Note.h"
#include "../Musical Structures/Note/Accidental.h"

#include "pugixml.hpp"

#include <map>
#include <unordered_map>
#include <string>

namespace ReMu { namespace Evaluator {

	class NoteEvaluator
	{
	public:	
		inline static Pitch parseNote(pugi::xml_node note)
		{
			return Pitch(note.child_value("step")[0], note.child("alter") ? Accidental(std::stoi(note.child_value("alter"))) : Accidental::None);
		}

		inline static void setNotes(std::vector<pugi::xml_node>* notes, Pitch* resultNote)
		{
			setNote(&notes->front(), resultNote);

			for (size_t i = 1; i < notes->size(); i++)
				notes->at(i).parent().parent().remove_child(notes->at(i).parent());
		}

		inline static void setNote(pugi::xml_node* note, Pitch* resultNote)
		{
			pugi::char_t noteStep[2] = { resultNote->getStep() };
			note->child("step").text() = noteStep;

			if (note->child("alter"))
			{
				if (resultNote->getAccidental() == ReMu::Accidental::None)
					note->remove_child("alter");
				else
					note->child("alter").text() = resultNote->getAccidental();
			}
			else if (!resultNote->getAccidental() == ReMu::Accidental::None)
				note->insert_child_after("alter", note->child("step")).text().set(std::to_string(resultNote->getAccidental()).c_str());

			if (resultNote->getDuration() > 0)
			{
				//if notes can fit in devisions then fair enough 
				//Otherwise change them and thusly change all of the notes in that measure
				//caculate the correct conversion from devisions and duration to actual note value
				//proceed
				note->parent().child("duration").text() = resultNote->getDuration();

				if (resultNote->getDuration() == 1)
					note->parent().child("type").text() = "whole";
				else if (resultNote->getDuration() == 2)
					note->parent().child("type").text() = "half";
				else if (resultNote->getDuration() == 4)
					note->parent().child("type").text() = "quarter";
				else if (resultNote->getDuration() == 8)
					note->parent().child("type").text() = "eighth";
				else if (resultNote->getDuration() == 16)
					note->parent().child("type").text() = "16th";
				else if (resultNote->getDuration() == 32)
					note->parent().child("type").text() = "32nd";
				else if (resultNote->getDuration() == 64)
					note->parent().child("type").text() = "64th";
				else if (resultNote->getDuration() == 128)
					note->parent().child("type").text() = "128th";
				else if (resultNote->getDuration() == 256)
					note->parent().child("type").text() = "256th";
			}
		}
	};

} }