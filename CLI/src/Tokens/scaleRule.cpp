#include "ScaleRule.h"

namespace ReMu { namespace Tokens {

	void ScaleRule::evalScaleRule(const Pitch& initalRootNote, const char* initalScale, const Pitch& resultRootNote, const char* resultScale, TransitionTable* transitionTable, short line)
	{
		ScaleInfo* initalScaleInfo = ScaleDatabase::getScale(initalScale, line);
		ScaleInfo* resultScaleInfo = ScaleDatabase::getScale(resultScale, line);

		std::vector<Pitch> initalNotes = genNotes(initalScaleInfo, initalRootNote);
		std::vector<Pitch> resultNotes = genNotes(resultScaleInfo, resultRootNote);

		for (int i = 0; i < initalScaleInfo->getScaleLength(); i++)
		{
			if (initalNotes[i] == resultNotes[i])
				continue;
		
			transitionTable->addTransition(initalNotes[i], resultNotes[i]);
		}

		transitionTable->setRelativeMajorKey(resultScaleInfo->getRelativeMajorKey(resultRootNote));
	}
	
	void ScaleRule::evalScaleRule(const Pitch& rootNote, const char* scale, TransitionTable* transitionTable, short line)
	{
		transitionTable->setScaleBuffer(rootNote, scale, line);
	}

	void ScaleRule::evalScaleBuffer(const Pitch& rootNote, const char* scale, TransitionTable* transitionTable)
	{
		evalScaleRule(rootNote, scale, std::get<1>(transitionTable->getScaleBuffer()), std::get<0>(transitionTable->getScaleBuffer()), transitionTable, std::get<2>(transitionTable->getScaleBuffer()));
	}

	std::vector<Pitch> ScaleRule::genNotes(ScaleInfo* scaleInfo, const Pitch& rootNote)
	{
		std::vector<Pitch> notes;
		notes.push_back(rootNote);

		for (int i = 1; i < scaleInfo->getScaleLength() + 1; i++)
			notes.push_back(notes[i - 1].incrementNote(scaleInfo->getIntervales()[i - 1]));
			
		return notes;
	}

} }