#include ".\ChordRule.h"

namespace ReMu { namespace Tokens {

	/*void ChordRule::evalChordRule(std::vector<Pitch> initalNotes, Symbol initalSymbol, std::vector<std::string> initalAdditions,
					              std::vector<Pitch> resultNotes, Symbol resultSymbol, std::vector<std::string> resultAdditions, TransitionTable* transitionTable)
	{
		transitionTable->addTransition(genChord(initalNotes, initalSymbol, initalAdditions), genChord(resultNotes, resultSymbol, resultAdditions));
	}*/

	Chord* ChordRule::genChord(std::vector<Pitch>* notes, Symbol* symbol, std::vector<std::string>* additions)
	{
		std::vector<Degree> initalComponents = symbol->eval();

		for (int i = 0; i < additions->size(); i++)
			Addition::evaluate(additions->at(i), notes->at(i + 1), &initalComponents);

		std::vector<Note> components;
		components.push_back(static_cast<Note&>(notes->front()));

		for (int i = 0; i < initalComponents.size(); i++)
			components.push_back(initalComponents[i].evaluateNote(static_cast<Note&>(notes->front())));

		return new Chord(components);
	}

} }