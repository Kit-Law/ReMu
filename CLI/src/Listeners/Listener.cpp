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

	void Listener::enterScaleDef(SheetMusicParser::ScaleDefContext* ctx)
	{
		std::string scaleName = ctx->WORD()->getText();
		int size = (ctx->children.size() - 3) / 2;
		int* intervals = new int[size];

		for (int i = 0; i < size; i++)
			intervals[i] = std::stoi(ctx->NUMBER(i)->getText());

		ScaleDatabase::addScale(scaleName.c_str(), new ScaleInfo(intervals, size, 0));
	}

	void Listener::enterChordDef(SheetMusicParser::ChordDefContext* ctx)
	{
		chordName = ctx->WORD()->getText();
	}

	void Listener::exitChordDef(SheetMusicParser::ChordDefContext* ctx)
	{
		Symbol::addSymbol(chordName, &notes);

		notes.clear();
	}

	void Listener::exitChord(SheetMusicParser::ChordContext* ctx)
	{
		Sequence* sequence;

		if (onInital)
			sequence = &initalSequence;
		else
			sequence = &resultSequence;

		sequence->pushBack(Tokens::ChordRule::genChord(&notes, &symbol, &additions));

		notes.clear();
		additions.clear();
	}

	void Listener::exitNote(SheetMusicParser::NoteContext* ctx)
	{
		if (ctx->NUMBER(0) != nullptr)
			notes.back().setDuration(std::stof(ctx->NUMBER(0)->toString()));

		if (onInital)
			initalSequence.pushBack(notes.at(0));
		else
			resultSequence.pushBack(notes.at(0));

		notes.clear();
	}

	void Listener::enterSymbol(SheetMusicParser::SymbolContext* ctx)
	{
		symbol = Symbol(ctx->children[0]->getText(), (ctx->children.size() > 1) ? std::stoi(ctx->children[1]->getText()) : 0);
	}

	void Listener::enterAdditions(SheetMusicParser::AdditionsContext* ctx)
	{
		additions.push_back(ctx->children[0]->getText());
	}

	void Listener::enterScale(SheetMusicParser::ScaleContext* ctx)
	{
		if (onInital) initalScale = ctx->children[1]->getText();
		else resultScale = ctx->children[1]->getText();
	}

	void Listener::exitScaleRule(SheetMusicParser::ScaleRuleContext* ctx)
	{
		if (notes.size() == 1)
			Tokens::ScaleRule::evalScaleRule(static_cast<Note&>(notes.at(0)), initalScale.c_str(), currentIntstument, currentSection->getTransitionTable());
		if (notes.size() == 2)
			Tokens::ScaleRule::evalScaleRule(static_cast<Note&>(notes.at(0)), initalScale.c_str(), static_cast<Note&>(notes.at(1)), resultScale.c_str(), currentIntstument, currentSection->getTransitionTable());
	}

	void Listener::enterPitch(SheetMusicParser::PitchContext* ctx)
	{
		Pitch note;
		
		note.setStep(ctx->children[0]->getText()[0]);
		if (ctx->children.size() > 1) note.setAccidental(Accidental(ctx->children[1]->getText().size() * (ctx->children[1]->getText()[0] == '#' ? 1 : -1)));

		notes.push_back(note);
	}

	void Listener::exitSequenceRule(SheetMusicParser::SequenceRuleContext* ctx)
	{
		currentSection->getTransitionTable()->addTransition(initalSequence, resultSequence, occurance, currentIntstument);
	}

}