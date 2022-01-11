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
		Note initalRootNote;
		Note resultRootNote;
		std::string initalScale;
		std::string resultScale;
	public:
		void enterSectionDef(SheetMusicParser::SectionDefContext* ctx) override;
		void enterSection(SheetMusicParser::SectionContext* ctx) override;

		void enterChordRule(SheetMusicParser::ChordRuleContext* ctx) override;
		void enterNoteRule(SheetMusicParser::NoteRuleContext* ctx) override;
		void enterScaleRule(SheetMusicParser::ScaleRuleContext* ctx) override;

		void enterNote(SheetMusicParser::NoteContext* ctx) override;

		void enterScale(SheetMusicParser::ScaleContext* ctx) override;
		void exitScale(SheetMusicParser::ScaleContext* ctx) override;

		void exitScaleRule(SheetMusicParser::ScaleRuleContext* ctx) override;
	};

}