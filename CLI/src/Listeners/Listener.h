#pragma once

#include "antlr4-runtime.h"
#include "SheetMusicLexer.h"
#include "SheetMusicParser.h"
#include "SheetMusicBaseListener.h"

#include "..\Tokens\chordRule.h"
#include "..\Tokens\noteRule.h"
#include "..\Tokens\scaleRule.h"
#include "..\Tokens\section.h"
#include "..\Tokens\sectionDef.h"

#include "..\Musical Structures\Section.h"

#include <string>

namespace ReMu {

	enum RuleState
	{
		ScaleRule,
		ChordRule,
		SequenceRule
	};

	class Listener : public SheetMusicBaseListener
	{
	private:
		RuleState ruleState;
		bool onInital = true;
		std::vector<Note> initalNotes;
		std::vector<Note> resultNotes;
		std::string initalScale;
		std::string resultScale;

		std::map<std::string, Section*> sections;
		Section* currentSection;
	public:
		void enterSectionDef(SheetMusicParser::SectionDefContext* ctx) override;
		void enterSection(SheetMusicParser::SectionContext* ctx) override;

		void enterSectionIdent(SheetMusicParser::SectionIdentContext* ctx) override;

		void enterChordRule(SheetMusicParser::ChordRuleContext* ctx) override;

		inline void enterTransitionRule(SheetMusicParser::TransitionRuleContext* ctx) override { initalNotes.clear(); resultNotes.clear(); }

		inline void enterNoteRule(SheetMusicParser::NoteRuleContext* ctx) override { ruleState = SequenceRule; }
		void exitNoteRule(SheetMusicParser::NoteRuleContext* ctx) override;

		inline void exitSequence(SheetMusicParser::SequenceContext* ctx) override { onInital = !onInital; }

		inline void enterScaleRule(SheetMusicParser::ScaleRuleContext* ctx) override { ruleState = ScaleRule; }
		void exitScaleRule(SheetMusicParser::ScaleRuleContext* ctx) override;

		void enterScale(SheetMusicParser::ScaleContext* ctx) override;
		inline void exitScale(SheetMusicParser::ScaleContext* ctx) override { onInital = !onInital; }
		
		void enterNote(SheetMusicParser::NoteContext* ctx) override;

		void exitScript(SheetMusicParser::ScriptContext* ctx) override { std::cout << *currentSection; }
	};

}