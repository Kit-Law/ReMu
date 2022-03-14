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

	void Listener::exitChord(SheetMusicParser::ChordContext* ctx)
	{
		std::vector<Pitch>* notes; Symbol* symbol; std::vector<std::string>* additions; Sequence* sequence;

		if (onInital)
		{	notes = &initalNotes; symbol = &initalSymbol; additions = &initalAdditions; sequence = &initalSequence; }
		else
		{	notes = &resultNotes; symbol = &resultSymbol; additions = &resultAdditions; sequence = &resultSequence; }

		sequence->pushBack(Tokens::ChordRule::genChord(notes, symbol, additions));
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

	void Listener::enterPitch(SheetMusicParser::PitchContext* ctx)
	{
		std::vector<Pitch>* notes = onInital ? &initalNotes : &resultNotes;
		Pitch note;

		note.setStep(ctx->children[0]->getText()[0]);
		if (ctx->children.size() > 1) note.setAccidental(Accidental(ctx->children[1]->getText().size() * (ctx->children[1]->getText()[0] == '#' ? 1 : -1)));

		notes->push_back(note);
	}

	void Listener::exitSequenceRule(SheetMusicParser::SequenceRuleContext* ctx)
	{
		currentSection->getTransitionTable()->addTransition(initalSequence, resultSequence);
	}

}