#pragma once

#include <vector>
#include <string>

#include "..\Musical Structures\Note\Pitch.h"

#include "..\Musical Structures\Chord\Symbol.h"
#include "..\Musical Structures\Chord\Addition.h"
#include "..\Musical Structures\Chord\Chord.h"
#include "..\Musical Structures\TransitionTable.h"

namespace ReMu { namespace Tokens {

	class ChordRule
	{
	public:
		static Chord* genChord(std::vector<Pitch>* notes, Symbol* symbol, std::vector<std::string>* additions);
	};

} }