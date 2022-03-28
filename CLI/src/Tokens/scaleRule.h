#pragma once

#include "..\Musical Structures\Note\Note.h"
#include "..\Musical Structures\Scales\ScaleInfo.h"
#include "..\Musical Structures\Scales\ScaleDatabase.h"
#include "..\Musical Structures\TransitionTable.h"

namespace ReMu { namespace Tokens {

	class ScaleRule
	{
	public:
		static void evalScaleRule(const Note& initalRootNote, const char* initalScale, const Note& resultRootNote, const char* resultScale, TransitionTable* transitionTable, short line);
		static void evalScaleRule(const Note& rootNote, const char* scale, TransitionTable* transitionTable, short line);
		
		static void evalScaleBuffer(const Note& rootNote, const char* scale, TransitionTable* transitionTable);
	private:
		static inline std::vector<Note> genNotes(ScaleInfo* scaleInfo, const Note& rootNote);
	};

} }