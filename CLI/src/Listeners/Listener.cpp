#include ".\Listener.h"

namespace ReMu {

	void Listener::enterSectionDef(SheetMusicParser::SectionDefContext* ctx)
	{
		//std::cout << "Section def: " << ctx->getText() << std::endl;

		Tokens::sectionDef::evalSectionDefRule();
	}

	void Listener::enterSection(SheetMusicParser::SectionContext* ctx)
	{
		Tokens::section::evalSectionRule();
	}

	void Listener::enterChordRule(SheetMusicParser::ChordRuleContext* ctx)
	{
		Tokens::chordRule::evalChordRule();
	}

	void Listener::enterNoteRule(SheetMusicParser::NoteRuleContext* ctx)
	{
		Tokens::noteRule::evalNoteRule();
	}

	void Listener::enterScaleRule(SheetMusicParser::ScaleRuleContext* ctx)
	{
		ruleState = ScaleRule;
	}

	void Listener::enterNote(SheetMusicParser::NoteContext* ctx)
	{
		Note* rootNote = onInital ? &initalRootNote : &resultRootNote;

		rootNote->setNote(ctx->children[0]->getText()[0]);
		if (ctx->children.size() > 1) rootNote->setModifier(ctx->children[1]->getText()[0] == '#' ? Sharp : Flat);
	}

	void Listener::enterScale(SheetMusicParser::ScaleContext* ctx)
	{
		if (onInital) initalScale = ctx->children[1]->getText();
		else resultScale = ctx->children[1]->getText();
	}

	void Listener::exitScale(SheetMusicParser::ScaleContext* ctx) { onInital = !onInital; }

	void Listener::exitScaleRule(SheetMusicParser::ScaleRuleContext* ctx)
	{
		Tokens::scaleRule::evalScaleRule(initalRootNote, initalScale.c_str(), resultRootNote, resultScale.c_str());

		Tokens::scaleRule::transitionTable->printTrans();
	}

}