#pragma once

#include "antlr4-runtime.h"
#include "SheetMusicLexer.h"
#include "SheetMusicParser.h"
#include "SheetMusicBaseListener.h"

#include "..\Tokens\chordRule.h"
#include "..\Tokens\scaleRule.h"

#include "..\Musical Structures\Section.h"

#include "..\Musical Structures\Chord\Symbol.h"

#include <string>

namespace ReMu {

	class Listener : public SheetMusicBaseListener
	{
	private:
		bool onInital = true;

		std::vector<Note> initalNotes;
		std::vector<Note> resultNotes;

		std::string initalScale;
		std::string resultScale;

		std::vector<Symbol> initalSymbols;
		std::vector<Symbol> resultSymbols;

		std::map<std::string, Section*> sections;
		Section* currentSection;
	public:
		void enterSectionDef(SheetMusicParser::SectionDefContext* ctx) override;
		void enterSectionIdent(SheetMusicParser::SectionIdentContext* ctx) override;

		inline void enterTransitionRule(SheetMusicParser::TransitionRuleContext* ctx) override { initalNotes.clear(); resultNotes.clear(); }
		
		void exitChordRule(SheetMusicParser::ChordRuleContext* ctx) override;

		inline void exitChord(SheetMusicParser::ChordContext* ctx) override { onInital = !onInital; }

		void enterSection(SheetMusicParser::SectionContext* ctx) override;

		inline void exitSequence(SheetMusicParser::SequenceContext* ctx) override { onInital = !onInital; }

		void exitScaleRule(SheetMusicParser::ScaleRuleContext* ctx) override;

		void enterScale(SheetMusicParser::ScaleContext* ctx) override;
		inline void exitScale(SheetMusicParser::ScaleContext* ctx) override { onInital = !onInital; }

		void exitNoteRule(SheetMusicParser::NoteRuleContext* ctx) override;

		void enterNote(SheetMusicParser::NoteContext* ctx) override;

		void exitScript(SheetMusicParser::ScriptContext* ctx) override { std::cout << *currentSection; }
	};

}