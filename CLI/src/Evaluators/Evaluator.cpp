#include "./Evaluator.h"
/*
namespace ReMu { namespace Evaluator {

	Evaluator::Evaluator(std::map<std::string, Section*> sections, const char* input, const char* output)
	{
		pugi::xml_document doc = openDoc(input);

		for (auto const& section : sections)
		{
			changeKey(section.second->getTransitionTable()->getRelativeMajorKey(), section.second, doc);

			NoteTransitionEvaluator::evaluate(doc, section.second);

			ChordTransitionEvaluator::evaluate(doc, section.second);
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

} }*/