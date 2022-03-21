#include "ScaleRule.h"

namespace ReMu { namespace Tokens {

	void ScaleRule::evalScaleRule(const Note& initalRootNote, const char* initalScale, const Note& resultRootNote, const char* resultScale, std::string instrument, TransitionTable* transitionTable, short line)
	{
		ScaleInfo* initalScaleInfo = ScaleDatabase::getScale(initalScale, line);
		ScaleInfo* resultScaleInfo = ScaleDatabase::getScale(resultScale, line);

		Notes initalNotes = genNotes(initalScaleInfo, initalRootNote);
		Notes resultNotes = genNotes(resultScaleInfo, resultRootNote);

		for (int i = 0; i < initalScaleInfo->getScaleLength(); i++)
		{
			if (initalNotes[i] == resultNotes[i])
				continue;
		
			transitionTable->addTransition(initalNotes[i], resultNotes[i], instrument);
		}

		transitionTable->setRelativeMajorKey(resultScaleInfo->getRelativeMajorKey(resultRootNote));
	}
	
	void ScaleRule::evalScaleRule(const Note& rootNote, const char* scale, std::string instrument, TransitionTable* transitionTable, short line)
	{
		transitionTable->setScaleBuffer(rootNote, scale, instrument, line);
	}

	void ScaleRule::evalScaleBuffer(const Note& rootNote, const char* scale, TransitionTable* transitionTable)
	{
		evalScaleRule(rootNote, scale, std::get<1>(transitionTable->getScaleBuffer()), std::get<0>(transitionTable->getScaleBuffer()), std::get<2>(transitionTable->getScaleBuffer()), transitionTable, std::get<3>(transitionTable->getScaleBuffer()));
	}

	Notes ScaleRule::genNotes(ScaleInfo* scaleInfo, const Note& rootNote)
	{
		Notes notes = new Note[scaleInfo->getScaleLength()];
		notes[0] = rootNote;

		for (int i = 1; i < scaleInfo->getScaleLength() + 1; i++)
			notes[i] = notes[i - 1].incrementNote(scaleInfo->getIntervales()[i - 1]);

		return notes;
	}

} }