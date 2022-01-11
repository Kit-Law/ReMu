#include "scaleRule.h"

namespace ReMu { namespace Tokens {

	TransitionTable* scaleRule::transitionTable = new TransitionTable();

	void scaleRule::evalScaleRule(const Note& initalRootNote, const char* initalScale, const Note& resultRootNote, const char* resultScale)
	{
		ScaleInfo* initalScaleInfo = ScaleDatabase::getScale(initalScale);
		ScaleInfo* resultScaleInfo = ScaleDatabase::getScale(resultScale);

		Notes initalNotes = genNotes(initalScaleInfo, initalRootNote);
		Notes resultNotes = genNotes(initalScaleInfo, resultRootNote);

		for (int i = 0; i < initalScaleInfo->getScaleLength(); i++)
		{
			if (initalNotes[i] == resultNotes[i])
				continue;
		
			transitionTable->addTransition(initalNotes[i], resultNotes[i]);
		}
	}

	Notes scaleRule::genNotes(ScaleInfo* scaleInfo, const Note& rootNote)
	{
		Notes notes = new Note[scaleInfo->getScaleLength()];
		notes[0] = rootNote;

		for (int i = 1; i < scaleInfo->getScaleLength() + 1; i++)
			notes[i] = notes[i - 1].incrementNote(scaleInfo->getIntervales()[i - 1]);

		return notes;
	}

} }