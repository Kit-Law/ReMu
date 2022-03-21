#include "./Evaluator.h"

namespace ReMu { namespace Evaluator {

	Evaluator::Evaluator(std::map<std::string, Section*> sections, const char* input, const char* output)
	{
		pugi::xml_document doc = openDoc(input);

		for (auto const& section : sections)
		{
			changeKey(section.second->getTransitionTable()->getRelativeMajorKey(), section.second, doc);

			evaluateSection(doc, section.second);
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

	void Evaluator::evaluateSection(pugi::xml_document& doc, Section* section)
	{
		pugi::xpath_node_set notes = doc.select_nodes(("/score-partwise/part/measure[@number >= " + std::to_string(section->getStartingMessure()) + " and @number < " + std::to_string(section->getEndingMessure()) + "] /note/pitch").c_str());
		ReMu::TransitionTable* transitionTable = section->getTransitionTable();
		
		//TODO: Clean this block up
		std::vector<SequenceEvaluator*> sequenceBuffers;
		for (auto& sequence : *transitionTable->getSequenceTransitions())
			sequenceBuffers.push_back(new SequenceEvaluator(sequence));

		//TODO: Clean this block up
		std::unordered_map<ReMu::Pitch, ReMu::Pitch, ReMu::Pitch> noteTransitions;
		for (auto transition : *transitionTable->getNoteTransitions())
			noteTransitions[transition.first] = transition.second;

		for (int i = 0; i < notes.size(); i++)// pugi::xpath_node node : notes)
		{
			std::pair<std::vector<Pitch>, std::vector<pugi::xml_node>> notesBuffers;
			
			notesBuffers.second.push_back(notes[i].node());
			notesBuffers.first.push_back(NoteEvaluator::parseNote(notes[i].node()));

			for (int j = i + 1; j < notes.size(); j++)
			{
				if (notes[j].node().parent().child("chord"))
				{
					notesBuffers.second.push_back(notes[j].node());
					notesBuffers.first.push_back(NoteEvaluator::parseNote(notes[j].node()));
				}
				else
				{
					i = j - 1;
					break;
				}
			}

			for (auto sequence : sequenceBuffers)
				sequence->evaluate(notesBuffers, notesBuffers.second.front().parent().child("duration").text().as_float());

			if (notesBuffers.first.size() == 1 && noteTransitions.count(notesBuffers.first.at(0)) > 0)
				NoteEvaluator::setNote(&notesBuffers.second.at(0), &noteTransitions.at(notesBuffers.first.at(0)));
		}
	}

} }