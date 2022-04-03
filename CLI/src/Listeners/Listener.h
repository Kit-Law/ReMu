#pragma once

#include "antlr4-runtime.h"
#include "..\Grammar\SheetMusicLexer.h"
#include "..\Grammar\SheetMusicParser.h"
#include "..\Grammar\SheetMusicBaseListener.h"

#include "..\Tokens\ChordRule.h"
#include "..\Tokens\ScaleRule.h"

#include "..\Musical Structures\Section.h"

#include "..\Musical Structures\Chord\Symbol.h"

#include "..\Exceptions\ParseExceptions.h"

#include "..\Logger\Logger.h"

#include <string>

namespace ReMu {

	class Listener : public SheetMusicBaseListener
	{
	private:
		bool onInital = true;

		std::vector<Pitch> notes;
		Symbol symbol;
		std::vector<std::string> additions;

		std::string initalScale;
		std::string resultScale;

		Sequence initalSequence;
		Sequence resultSequence;

		int occurance = 1;

		std::map<std::string, Section*> sections;
		Section* currentSection;

		std::string currentIntstument = "";

		std::string chordName;
	public:
		~Listener() { for (auto section : sections) delete section.second; }

		void enterSectionDef(SheetMusicParser::SectionDefContext* ctx) override;
		void enterSectionIdent(SheetMusicParser::SectionIdentContext* ctx) override;

		void enterScaleDef(SheetMusicParser::ScaleDefContext* ctx) override;
		void enterChordDef(SheetMusicParser::ChordDefContext* ctx) override;
		void exitChordDef(SheetMusicParser::ChordDefContext* ctx) override;

		inline void enterInstrument(SheetMusicParser::InstrumentContext* ctx) override { currentIntstument = ctx->WORD()->getText(); }
		inline void exitInstrument(SheetMusicParser::InstrumentContext* ctx) override { currentIntstument = ""; }

		inline void enterOccurrenceRule(SheetMusicParser::OccurrenceRuleContext* ctx) override { occurance = std::stoi(ctx->NUMBER()->getText()); }
		inline void exitOccurrenceRule(SheetMusicParser::OccurrenceRuleContext* ctx) override { occurance = 1; }

		inline void enterTransitionRule(SheetMusicParser::TransitionRuleContext* ctx) override { notes.clear(); initalSequence.getStuctsToMapping()->clear(); resultSequence.getStuctsToMapping()->clear(); }

		void enterSymbol(SheetMusicParser::SymbolContext* ctx) override;
		void enterAdditions(SheetMusicParser::AdditionsContext* ctx) override;
		void exitChord(SheetMusicParser::ChordContext* ctx) override;

		void exitNote(SheetMusicParser::NoteContext* ctx) override;

		inline void exitSequence(SheetMusicParser::SequenceContext* ctx) override { onInital = !onInital; }

		void exitScaleRule(SheetMusicParser::ScaleRuleContext* ctx) override;

		void enterScale(SheetMusicParser::ScaleContext* ctx) override;
		inline void exitScale(SheetMusicParser::ScaleContext* ctx) override { onInital = !onInital; }

		void enterPitch(SheetMusicParser::PitchContext* ctx) override;

		void exitSequenceRule(SheetMusicParser::SequenceRuleContext* ctx) override;

		void exitScript(SheetMusicParser::ScriptContext* ctx) override 
		{ 
			Logger logger;

			logger << std::string("==================================") << std::endl;
			for(auto const& section : sections) 
				logger << *section.second << std::endl << "==================================" << std::endl; 
		}

		inline std::map<std::string, Section*> getSections() { return sections; }
	};

}