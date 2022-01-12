#include ".\Listener.h"

namespace ReMu {

	void Listener::enterSectionDef(SheetMusicParser::SectionDefContext* ctx)
	{
		sections[ctx->children[0]->getText()] = 
			new Section(ctx->children[0]->getText(), std::stoi(ctx->children[2]->getText()), std::stoi(ctx->children[4]->getText()));
	}

	void Listener::enterSectionIdent(SheetMusicParser::SectionIdentContext* ctx)
	{
		currentSection = sections[ctx->children[0]->getText()];
	}

	void Listener::exitChordRule(SheetMusicParser::ChordRuleContext* ctx)
	{
		Tokens::chordRule::evalChordRule();
	}

	void enterSection(SheetMusicParser::SectionContext* ctx)
	{
		if (ctx->children.size() > 1)
	}

	void Listener::enterScale(SheetMusicParser::ScaleContext* ctx)
	{
		if (onInital) initalScale = ctx->children[1]->getText();
		else resultScale = ctx->children[1]->getText();
	}

	void Listener::exitScaleRule(SheetMusicParser::ScaleRuleContext* ctx)
	{
		Tokens::scaleRule::evalScaleRule(initalNotes.front(), initalScale.c_str(), resultNotes.front(), resultScale.c_str(), currentSection->getTransitionTable());
	}

	void Listener::enterNote(SheetMusicParser::NoteContext* ctx)
	{
		std::vector<Note>* notes = onInital ? &initalNotes : &resultNotes;
		Note note;

		note.setStep(ctx->children[0]->getText()[0]);
		if (ctx->children.size() > 1) note.setAccidental(ctx->children[1]->getText()[0] == '#' ? Sharp : Flat);

		notes->push_back(note);
	}

	void Listener::exitNoteRule(SheetMusicParser::NoteRuleContext* ctx) 
	{
		currentSection->getTransitionTable()->addTransition(initalNotes, resultNotes);
	}

}