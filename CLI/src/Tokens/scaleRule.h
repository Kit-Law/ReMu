#pragma once

#include "..\Musical Structures\Note\Pitch.h"
#include "..\Musical Structures\Scales\ScaleInfo.h"
#include "..\Musical Structures\Scales\ScaleDatabase.h"
#include "..\Musical Structures\TransitionTable.h"

namespace ReMu { namespace Tokens {

	class ScaleRule
	{
	public:
		static void evalScaleRule(const Pitch& initalRootNote, const char* initalScale, const Pitch& resultRootNote, const char* resultScale, TransitionTable* transitionTable, short line);
		static void evalScaleRule(const Pitch& rootNote, const char* scale, TransitionTable* transitionTable, short line);
		
		static void evalScaleBuffer(const Pitch& rootNote, const char* scale, TransitionTable* transitionTable);
	private:
		static inline std::vector<Pitch> genNotes(ScaleInfo* scaleInfo, const Pitch& rootNote);
	};

} }