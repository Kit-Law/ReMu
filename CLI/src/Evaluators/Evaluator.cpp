#include "./Evaluator.h"

namespace ReMu { namespace Evaluator {

	Evaluator::Evaluator(std::map<std::string, Section*> sections, const char* input, const char* output)
	{
		pugi::xml_document doc = openDoc(input);

		for (auto const& section : sections)
		{
			pugi::xpath_node_set notes = doc.select_nodes(("/score-partwise/part/measure[@number >= " + std::to_string(section.second->getStartingMessure()) + " and @number < " + std::to_string(section.second->getEndingMessure()) + " and not(note/chord)] /note/pitch").c_str());
			ReMu::TransitionTable* transitionTable = section.second->getTransitionTable();

			changeKey(transitionTable->getRelativeMajorKey(), section.second, doc);

			//TODO: Clean this block up
			std::vector<SequenceBuffer*> sequenceBuffers;
			for (auto const& sequence : *section.second->getTransitionTable()->getSequenceTransitions())
				sequenceBuffers.push_back(new SequenceBuffer(sequence));

			//TODO: Clean this block up
			std::unordered_map<ReMu::Pitch, ReMu::Pitch, ReMu::Pitch> noteTransitions;
			for (auto transition : *(transitionTable->getNoteTransitions()))
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

			pugi::xpath_node_set messures = doc.select_nodes(("/score-partwise/part/measure[@number >= " + std::to_string(section.second->getStartingMessure()) + " and @number < " + std::to_string(section.second->getEndingMessure()) + " and note/chord]").c_str());
			for (pugi::xpath_node node : messures)
			{
				std::vector<Note> components;
				pugi::xml_node messure = node.node();

				for (pugi::xml_node note : messure.children("note"))
				{
					Pitch initalNote = NoteEvaluator::parseNote(note.child("pitch"));

					components.push_back(initalNote);
				}

			 	Chord initalChord(components);

				for (std::pair<Chord, Chord> transition : *transitionTable->getChordTransitions())
				{
					if (initalChord == transition.first)
					{
						short i = 0;
						pugi::xml_node* lastNote = nullptr;
						for (pugi::xml_node note : messure.children("note"))
						{
							if (i < transition.second.getComponents()->size())
								NoteEvaluator::setNote(note.child("pitch"), transition.second.getComponents()->at(i));
							else
								note.parent().remove_child(note);

							i++;
							lastNote = &note;
						}

						for (; i < transition.second.getComponents()->size(); i++)
							NoteEvaluator::setNote(messure.append_copy(*lastNote).child("pitch"), transition.second.getComponents()->at(i));

						break;
					}
				}
			}
		}

		closeDoc(doc, output);
	}

	void Evaluator::changeKey(const ReMu::Pitch* relativeMajorKey, Section* section, pugi::xml_document& doc)
	{
		//Use text() rather than set whatever tf
		pugi::xpath_node_set keys = doc.select_nodes(("/score-partwise/part/measure[@number >= " + std::to_string(section->getStartingMessure()) + " and @number < " + std::to_string(section->getEndingMessure()) + "] /attributes/key/fifths").c_str());

		for (pugi::xpath_node key : keys) //Let key change notes in sections
			key.node().first_child().set_value(std::to_string(ReMu::KeySig::getFiths(relativeMajorKey)).c_str());
	}

} }