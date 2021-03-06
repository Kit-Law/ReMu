#include ".\Listener.h"

namespace ReMu {

	void Listener::enterSectionDef(SheetMusicParser::SectionDefContext* ctx)
	{
		int startMesure = std::stoi(ctx->children[2]->getText());
		int endMesure = std::stoi(ctx->children[4]->getText());

		if (startMesure > endMesure || startMesure < 0 || endMesure < 0)
			throw SectionDefOutOfBounds(ctx->children[0]->getText(), ctx->start->getLine());

		if (sections.count(ctx->children[0]->getText()) > 0)
			throw RedefinedSection(ctx->children[0]->getText(), ctx->start->getLine());

		for (auto section : sections)
		{
			if (section.second->getStartingMessure() > startMesure &&
				section.second->getStartingMessure() < endMesure ||
				section.second->getEndingMessure() > startMesure &&
				section.second->getEndingMessure() < endMesure)
				throw OverlappingSections(section.first, ctx->children[0]->getText(), ctx->start->getLine());
		}

		sections[ctx->children[0]->getText()] = 
			new Section(ctx->children[0]->getText(), startMesure, endMesure);
	}

	void Listener::enterSectionIdent(SheetMusicParser::SectionIdentContext* ctx)
	{
		if (sections.count(ctx->children[0]->getText()) == 0)
			throw UndefinedSection(ctx->children[0]->getText(), ctx->start->getLine());

		currentSection = sections[ctx->children[0]->getText()];
	}

	void Listener::enterScaleDef(SheetMusicParser::ScaleDefContext* ctx)
	{
		std::string scaleName = ctx->WORD()->getText();
		size_t size = (ctx->children.size() - 3) / 2;
		int* intervals = new int[size];

		for (size_t i = 0; i < size; i++)
			intervals[i] = std::stoi(ctx->NUMBER(i)->getText());

		ScaleDatabase::addScale(scaleName.c_str(), new ScaleInfo(intervals, size, 0), ctx->start->getLine());
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

		Chord* chordBuffer = Tokens::ChordRule::genChord(&notes, &symbol, &additions);
		
		if (sequence->size() == 0 && ctx->NUMBER() != nullptr)
			sequence->setDurationFlag(true);

		if (ctx->NUMBER() != nullptr)
		{
			if (!sequence->hasDuration())
				throw IncompleteTranstionrhythm(ctx->start->getLine());
				
			chordBuffer->setDuration(std::stof(ctx->NUMBER()->toString()));
		}
		else if (sequence->hasDuration())
			throw IncompleteTranstionrhythm(ctx->start->getLine());

		sequence->pushBack(chordBuffer);

		notes.clear();
		additions.clear();
	}

	void Listener::exitNote(SheetMusicParser::NoteContext* ctx)
	{
		Sequence* sequence;

		if (onInital)
			sequence = &initalSequence;
		else
			sequence = &resultSequence;

		if (sequence->size() == 0 && ctx->NUMBER(0) != nullptr)
			sequence->setDurationFlag(true);

		if (ctx->NUMBER(0) != nullptr)
		{
			if (!sequence->hasDuration())
				throw IncompleteTranstionrhythm(ctx->start->getLine());

			notes.back().setDuration(std::stoi(ctx->NUMBER(0)->toString()));
		}
		else if (sequence->hasDuration())
			throw IncompleteTranstionrhythm(ctx->start->getLine());

		sequence->pushBack(notes.at(0));
		notes.clear();
	}

	void Listener::enterSymbol(SheetMusicParser::SymbolContext* ctx)
	{
		symbol = Symbol(ctx->children[0]->getText());
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
			Tokens::ScaleRule::evalScaleRule(notes.at(0), initalScale.c_str(), currentSection->getTransitionTable(currentIntstument), ctx->start->getLine());
		if (notes.size() == 2)
			Tokens::ScaleRule::evalScaleRule(notes.at(0), initalScale.c_str(), notes.at(1), resultScale.c_str(), currentSection->getTransitionTable(currentIntstument), ctx->start->getLine());
	}

	void Listener::enterPitch(SheetMusicParser::PitchContext* ctx)
	{
		Pitch note;
		
		note.setStep(ctx->children[0]->getText().size() > 1 ? '0' + (char)std::stoi(ctx->children[0]->getText()) : ctx->children[0]->getText()[0]);
		if (ctx->children.size() > 1) note.setAccidental(Accidental(ctx->children[1]->getText().size() * (ctx->children[1]->getText()[0] == '#' ? 1 : -1)));

		notes.push_back(note);
	}

	void Listener::enterRest(SheetMusicParser::RestContext* ctx)
	{
		Sequence* sequence;

		if (onInital)
			sequence = &initalSequence;
		else
			sequence = &resultSequence;

		if (sequence->size() == 0 && ctx->NUMBER() != nullptr)
			sequence->setDurationFlag(true);

		if (!sequence->hasDuration())
			throw IncompleteTranstionrhythm(ctx->start->getLine());

		Pitch rest = Pitch('-', std::stoi(ctx->NUMBER()->toString()), Accidental::None);
		sequence->pushBack(rest);
	}

	void Listener::exitSequenceRule(SheetMusicParser::SequenceRuleContext* ctx)
	{
		currentSection->getTransitionTable(currentIntstument)->addTransition(initalSequence, resultSequence, occurance);
	}

}