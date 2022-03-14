
// Generated from SheetMusic.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "SheetMusicParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SheetMusicParser.
 */
class  SheetMusicListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterScript(SheetMusicParser::ScriptContext *ctx) = 0;
  virtual void exitScript(SheetMusicParser::ScriptContext *ctx) = 0;

  virtual void enterSectionDef(SheetMusicParser::SectionDefContext *ctx) = 0;
  virtual void exitSectionDef(SheetMusicParser::SectionDefContext *ctx) = 0;

  virtual void enterUserDef(SheetMusicParser::UserDefContext *ctx) = 0;
  virtual void exitUserDef(SheetMusicParser::UserDefContext *ctx) = 0;

  virtual void enterScaleDef(SheetMusicParser::ScaleDefContext *ctx) = 0;
  virtual void exitScaleDef(SheetMusicParser::ScaleDefContext *ctx) = 0;

  virtual void enterChordDef(SheetMusicParser::ChordDefContext *ctx) = 0;
  virtual void exitChordDef(SheetMusicParser::ChordDefContext *ctx) = 0;

  virtual void enterRulesSection(SheetMusicParser::RulesSectionContext *ctx) = 0;
  virtual void exitRulesSection(SheetMusicParser::RulesSectionContext *ctx) = 0;

  virtual void enterSection(SheetMusicParser::SectionContext *ctx) = 0;
  virtual void exitSection(SheetMusicParser::SectionContext *ctx) = 0;

  virtual void enterSectionIdent(SheetMusicParser::SectionIdentContext *ctx) = 0;
  virtual void exitSectionIdent(SheetMusicParser::SectionIdentContext *ctx) = 0;

  virtual void enterInstrument(SheetMusicParser::InstrumentContext *ctx) = 0;
  virtual void exitInstrument(SheetMusicParser::InstrumentContext *ctx) = 0;

  virtual void enterTransitionRule(SheetMusicParser::TransitionRuleContext *ctx) = 0;
  virtual void exitTransitionRule(SheetMusicParser::TransitionRuleContext *ctx) = 0;

  virtual void enterScaleRule(SheetMusicParser::ScaleRuleContext *ctx) = 0;
  virtual void exitScaleRule(SheetMusicParser::ScaleRuleContext *ctx) = 0;

  virtual void enterScale(SheetMusicParser::ScaleContext *ctx) = 0;
  virtual void exitScale(SheetMusicParser::ScaleContext *ctx) = 0;

  virtual void enterOccurrenceRule(SheetMusicParser::OccurrenceRuleContext *ctx) = 0;
  virtual void exitOccurrenceRule(SheetMusicParser::OccurrenceRuleContext *ctx) = 0;

  virtual void enterSequenceRule(SheetMusicParser::SequenceRuleContext *ctx) = 0;
  virtual void exitSequenceRule(SheetMusicParser::SequenceRuleContext *ctx) = 0;

  virtual void enterSequence(SheetMusicParser::SequenceContext *ctx) = 0;
  virtual void exitSequence(SheetMusicParser::SequenceContext *ctx) = 0;

  virtual void enterChord(SheetMusicParser::ChordContext *ctx) = 0;
  virtual void exitChord(SheetMusicParser::ChordContext *ctx) = 0;

  virtual void enterSymbol(SheetMusicParser::SymbolContext *ctx) = 0;
  virtual void exitSymbol(SheetMusicParser::SymbolContext *ctx) = 0;

  virtual void enterAdditions(SheetMusicParser::AdditionsContext *ctx) = 0;
  virtual void exitAdditions(SheetMusicParser::AdditionsContext *ctx) = 0;

  virtual void enterPitch(SheetMusicParser::PitchContext *ctx) = 0;
  virtual void exitPitch(SheetMusicParser::PitchContext *ctx) = 0;

  virtual void enterNote(SheetMusicParser::NoteContext *ctx) = 0;
  virtual void exitNote(SheetMusicParser::NoteContext *ctx) = 0;


};

