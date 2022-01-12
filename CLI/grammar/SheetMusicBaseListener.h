
// Generated from SheetMusic.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "SheetMusicListener.h"


/**
 * This class provides an empty implementation of SheetMusicListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SheetMusicBaseListener : public SheetMusicListener {
public:

  virtual void enterScript(SheetMusicParser::ScriptContext * /*ctx*/) override { }
  virtual void exitScript(SheetMusicParser::ScriptContext * /*ctx*/) override { }

  virtual void enterRulesSection(SheetMusicParser::RulesSectionContext * /*ctx*/) override { }
  virtual void exitRulesSection(SheetMusicParser::RulesSectionContext * /*ctx*/) override { }

  virtual void enterSectionDef(SheetMusicParser::SectionDefContext * /*ctx*/) override { }
  virtual void exitSectionDef(SheetMusicParser::SectionDefContext * /*ctx*/) override { }

  virtual void enterSection(SheetMusicParser::SectionContext * /*ctx*/) override { }
  virtual void exitSection(SheetMusicParser::SectionContext * /*ctx*/) override { }

  virtual void enterSectionIdent(SheetMusicParser::SectionIdentContext * /*ctx*/) override { }
  virtual void exitSectionIdent(SheetMusicParser::SectionIdentContext * /*ctx*/) override { }

  virtual void enterTransitionRule(SheetMusicParser::TransitionRuleContext * /*ctx*/) override { }
  virtual void exitTransitionRule(SheetMusicParser::TransitionRuleContext * /*ctx*/) override { }

  virtual void enterScaleRule(SheetMusicParser::ScaleRuleContext * /*ctx*/) override { }
  virtual void exitScaleRule(SheetMusicParser::ScaleRuleContext * /*ctx*/) override { }

  virtual void enterChordRule(SheetMusicParser::ChordRuleContext * /*ctx*/) override { }
  virtual void exitChordRule(SheetMusicParser::ChordRuleContext * /*ctx*/) override { }

  virtual void enterNoteRule(SheetMusicParser::NoteRuleContext * /*ctx*/) override { }
  virtual void exitNoteRule(SheetMusicParser::NoteRuleContext * /*ctx*/) override { }

  virtual void enterScale(SheetMusicParser::ScaleContext * /*ctx*/) override { }
  virtual void exitScale(SheetMusicParser::ScaleContext * /*ctx*/) override { }

  virtual void enterSequence(SheetMusicParser::SequenceContext * /*ctx*/) override { }
  virtual void exitSequence(SheetMusicParser::SequenceContext * /*ctx*/) override { }

  virtual void enterChord(SheetMusicParser::ChordContext * /*ctx*/) override { }
  virtual void exitChord(SheetMusicParser::ChordContext * /*ctx*/) override { }

  virtual void enterSymbol(SheetMusicParser::SymbolContext * /*ctx*/) override { }
  virtual void exitSymbol(SheetMusicParser::SymbolContext * /*ctx*/) override { }

  virtual void enterAdditions(SheetMusicParser::AdditionsContext * /*ctx*/) override { }
  virtual void exitAdditions(SheetMusicParser::AdditionsContext * /*ctx*/) override { }

  virtual void enterNote(SheetMusicParser::NoteContext * /*ctx*/) override { }
  virtual void exitNote(SheetMusicParser::NoteContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

