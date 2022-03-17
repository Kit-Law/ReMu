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

			for (int i = 1; i < notes->size(); i++)
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
		}
	};

} }