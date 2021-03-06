#include ".\ChordRule.h"

namespace ReMu { namespace Tokens {

	Chord* ChordRule::genChord(std::vector<Pitch>* notes, Symbol* symbol, std::vector<std::string>* additions)
	{
		std::vector<Degree> initalComponents = symbol->eval();

		for (int i = 0; i < additions->size(); i++)
			Addition::evaluate(additions->at(i), notes->at(i + 1), &initalComponents);

		std::vector<Pitch> components;
		components.push_back(notes->front());

		for (int i = 0; i < initalComponents.size(); i++)
			components.push_back(initalComponents[i].evaluateNote(notes->front()));

		return new Chord(components);
	}

} }