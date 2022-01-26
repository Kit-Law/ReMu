#pragma once

#include "antlr4-runtime.h"
#include "SheetMusicLexer.h"
#include "SheetMusicParser.h"
#include "SheetMusicBaseListener.h"

#include "..\Tokens\ChordRule.h"
#include "..\Tokens\ScaleRule.h"

#include "..\Musical Structures\Section.h"

#include "..\Musical Structures\Chord\Symbol.h"

#include <string>

namespace ReMu {

	class Listener : public SheetMusicBaseListener
	{
	private:
		bool onInital = true;

		std::vector<Pitch> initalNotes;
		std::vector<Pitch> resultNotes;

		std::string initalScale;
		std::string resultScale;

		std::vector<std::string> initalAdditions;
		std::vector<std::string> resultAdditions;

		Symbol initalSymbol;
		Symbol resultSymbol;

		std::map<std::string, Section*> sections;
		Section* currentSection;
	public:
		void enterSectionDef(SheetMusicParser::SectionDefContext* ctx) override;
		void enterSectionIdent(SheetMusicParser::SectionIdentContext* ctx) override;

		inline void enterTransitionRule(SheetMusicParser::TransitionRuleContext* ctx) override { initalNotes.clear(); resultNotes.clear(); }
		
		void exitChordRule(SheetMusicParser::ChordRuleContext* ctx) override;

		void enterSymbol(SheetMusicParser::SymbolContext* ctx) override;
		void enterAdditions(SheetMusicParser::AdditionsContext* ctx) override;
		inline void exitChord(SheetMusicParser::ChordContext* ctx) override { onInital = !onInital; }

		inline void exitSequence(SheetMusicParser::SequenceContext* ctx) override { onInital = !onInital; }

		void exitScaleRule(SheetMusicParser::ScaleRuleContext* ctx) override;

		void enterScale(SheetMusicParser::ScaleContext* ctx) override;
		inline void exitScale(SheetMusicParser::ScaleContext* ctx) override { onInital = !onInital; }

		void exitNoteRule(SheetMusicParser::NoteRuleContext* ctx) override;

		void enterNote(SheetMusicParser::NoteContext* ctx) override;

		void exitScript(SheetMusicParser::ScriptContext* ctx) override 
		{ 
			std::cout << "==================================" << std::endl;
			for(auto const& section : sections) 
				std::cout << *section.second << std::endl << "==================================" << std::endl; 
		}

		inline std::map<std::string, Section*> getSections() { return sections; }
	};

}