#include "./Evaluator.h"

namespace ReMu { namespace Evaluator {

	Evaluator::Evaluator(std::map<std::string, Section*> sections, const char* input, const char* output)
	{
		pugi::xml_document doc = openDoc(input);

		for (auto const& section : sections)
		{
			for (auto instrumentTransition : *section.second->getTransitionTableMap())
			{
				changeKey(instrumentTransition.second.getRelativeMajorKey(), section.second, instrumentTransition.first, doc);

				evaluateSection(doc, section.second, &instrumentTransition.second, instrumentTransition.first);//section.second);
			}
		}

		closeDoc(doc, output);
	}

	void Evaluator::changeKey(const ReMu::Pitch* relativeMajorKey, Section* section, std::string instrument, pugi::xml_document& doc)
	{
		pugi::xpath_node_set keys = doc.select_nodes(("/score-partwise" + (instrument != "" ? "[part-list/score-part/part-name/text() = '" + instrument + "']" : "") + " /part/measure[@number >= " + std::to_string(section->getStartingMessure()) + " and @number < " + std::to_string(section->getEndingMessure()) + "] /attributes/key/fifths").c_str());

		for (pugi::xpath_node key : keys) //Let key change notes in sections
			key.node().first_child().set_value(std::to_string(ReMu::KeySig::getFiths(relativeMajorKey)).c_str());
	}

	void Evaluator::evaluateSection(pugi::xml_document& doc, Section* section, TransitionTable* transitionTable, std::string instrument)
	{
		pugi::xpath_node_set notes = doc.select_nodes(("/score-partwise" + (instrument != "" ? "[part-list/score-part/part-name/text() = '" + instrument + "']" : "") + " / part / measure[@number >= " + std::to_string(section->getStartingMessure()) + " and @number < " + std::to_string(section->getEndingMessure()) + "] / note / pitch").c_str());
		
		std::vector<SequenceEvaluator*> sequenceBuffers;
		for (auto sequence : *transitionTable->getSequenceTransitions())
			sequenceBuffers.push_back(new SequenceEvaluator(sequence));

		std::unordered_map<ReMu::Pitch, ReMu::Pitch, ReMu::Pitch> noteTransitions;
		for (auto transition : *transitionTable->getNoteTransitions())
			noteTransitions[transition->first] = transition->second;

		for (int i = 0; i < notes.size(); i++)
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

			if (notesBuffers.first.size() == 1)
			{
				if (noteTransitions.count(notesBuffers.first.at(0)) > 0)
					NoteEvaluator::setNote(&notesBuffers.second.at(0), &noteTransitions.at(notesBuffers.first.at(0)));
			}
			else if (section->getFlag("\\ScaleEffectsChords"))
				for (int j = 0; j < notesBuffers.first.size(); j++)
					if (noteTransitions.count(notesBuffers.first.at(j)) > 0)
						NoteEvaluator::setNote(&notesBuffers.second.at(j), &noteTransitions.at(notesBuffers.first.at(j)));
		}
	}

} }