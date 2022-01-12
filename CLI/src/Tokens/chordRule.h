#pragma once

#include <vector>
#include <string>

#include "..\Musical Structures\Note\Note.h"

#include "..\Musical Structures\Chord\Symbol.h"
#include "..\Musical Structures\Chord\Addition.h"
#include "..\Musical Structures\Chord\Chord.h"
#include "..\Musical Structures\TransitionTable.h"

namespace ReMu { namespace Tokens {

	class ChordRule
	{
	public:
		static void evalChordRule(std::vector<Pitch> initalNotes, Symbol initalSymbol, std::vector<std::string> initalAdditions,
								  std::vector<Pitch> resultNotes, Symbol resultSymbol, std::vector<std::string> resultAdditions, TransitionTable* transitionTable);
	private:
		static Chord genChord(std::vector<Pitch> notes, Symbol symbol, std::vector<std::string> additions);
	};

} }