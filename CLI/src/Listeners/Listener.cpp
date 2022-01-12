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
		Tokens::ChordRule::evalChordRule(initalNotes, initalSymbol, initalAdditions, resultNotes, resultSymbol, resultAdditions, currentSection->getTransitionTable());
	}

	void Listener::enterSymbol(SheetMusicParser::SymbolContext* ctx)
	{
		Symbol symbol(ctx->children[0]->getText(), (ctx->children.size() > 1) ? std::stoi(ctx->children[1]->getText()) : 0);

		if (onInital) initalSymbol = symbol;
		else resultSymbol = symbol;
	}

	void Listener::enterAdditions(SheetMusicParser::AdditionsContext* ctx)
	{
		if (onInital) initalAdditions.push_back(ctx->children[0]->getText());
		else resultAdditions.push_back(ctx->children[0]->getText());
	}

	void Listener::enterScale(SheetMusicParser::ScaleContext* ctx)
	{
		if (onInital) initalScale = ctx->children[1]->getText();
		else resultScale = ctx->children[1]->getText();
	}

	void Listener::exitScaleRule(SheetMusicParser::ScaleRuleContext* ctx)
	{
		Tokens::ScaleRule::evalScaleRule(static_cast<Note&>(initalNotes.front()), initalScale.c_str(), static_cast<Note&>(resultNotes.front()), resultScale.c_str(), currentSection->getTransitionTable());
	}

	void Listener::enterNote(SheetMusicParser::NoteContext* ctx)
	{
		std::vector<Pitch>* notes = onInital ? &initalNotes : &resultNotes;
		Pitch note;

		note.setStep(ctx->children[0]->getText()[0]);
		if (ctx->children.size() > 1) note.setAccidental(ctx->children[1]->getText()[0] == '#' ? Sharp : Flat);

		notes->push_back(note);
	}

	void Listener::exitNoteRule(SheetMusicParser::NoteRuleContext* ctx) 
	{
		currentSection->getTransitionTable()->addTransition(initalNotes, resultNotes);
	}

}