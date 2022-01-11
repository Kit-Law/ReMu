#pragma once

#include "..\Musical Structures\Note\Note.h"
#include "..\Musical Structures\Scales\ScaleInfo.h"
#include "..\Musical Structures\Scales\ScaleDatabase.h"
#include "..\Musical Structures\TransitionTable.h"

namespace ReMu { namespace Tokens {

	class scaleRule
	{
	public: //Cahnge this
		static TransitionTable* transitionTable;
	public:
		static void evalScaleRule(const Note& initalRootNote, const char* initalScale, const Note& resultRootNote, const char* resultScale);
	private:
		static inline Notes genNotes(ScaleInfo* scaleInfo, const Note& rootNote);
	};

} }