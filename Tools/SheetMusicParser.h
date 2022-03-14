
// Generated from SheetMusic.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  SheetMusicParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, NUMBER = 17, NATURAL = 18, ACCIDENTAL = 19, 
    QUALITY = 20, ADDITIONS = 21, STRING = 22, WORD = 23, COMMENT = 24, 
    SPACE = 25, OTHER = 26
  };

  enum {
    RuleScript = 0, RuleSectionDef = 1, RuleUserDef = 2, RuleScaleDef = 3, 
    RuleChordDef = 4, RuleRulesSection = 5, RuleSection = 6, RuleSectionIdent = 7, 
    RuleInstrument = 8, RuleTransitionRule = 9, RuleScaleRule = 10, RuleScale = 11, 
    RuleOccurrenceRule = 12, RuleSequenceRule = 13, RuleSequence = 14, RuleChord = 15, 
    RuleSymbol = 16, RuleAdditions = 17, RulePitch = 18, RuleNote = 19
  };

  SheetMusicParser(antlr4::TokenStream *input);
  ~SheetMusicParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ScriptContext;
  class SectionDefContext;
  class UserDefContext;
  class ScaleDefContext;
  class ChordDefContext;
  class RulesSectionContext;
  class SectionContext;
  class SectionIdentContext;
  class InstrumentContext;
  class TransitionRuleContext;
  class ScaleRuleContext;
  class ScaleContext;
  class OccurrenceRuleContext;
  class SequenceRuleContext;
  class SequenceContext;
  class ChordContext;
  class SymbolContext;
  class AdditionsContext;
  class PitchContext;
  class NoteContext; 

  class  ScriptContext : public antlr4::ParserRuleContext {
  public:
    ScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RulesSectionContext *rulesSection();
    std::vector<SectionDefContext *> sectionDef();
    SectionDefContext* sectionDef(size_t i);
    std::vector<UserDefContext *> userDef();
    UserDefContext* userDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScriptContext* script();

  class  SectionDefContext : public antlr4::ParserRuleContext {
  public:
    SectionDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SectionIdentContext *sectionIdent();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SectionDefContext* sectionDef();

  class  UserDefContext : public antlr4::ParserRuleContext {
  public:
    UserDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ScaleDefContext *> scaleDef();
    ScaleDefContext* scaleDef(size_t i);
    std::vector<ChordDefContext *> chordDef();
    ChordDefContext* chordDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UserDefContext* userDef();

  class  ScaleDefContext : public antlr4::ParserRuleContext {
  public:
    ScaleDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScaleDefContext* scaleDef();

  class  ChordDefContext : public antlr4::ParserRuleContext {
  public:
    ChordDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();
    std::vector<PitchContext *> pitch();
    PitchContext* pitch(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ChordDefContext* chordDef();

  class  RulesSectionContext : public antlr4::ParserRuleContext {
  public:
    RulesSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SectionContext *> section();
    SectionContext* section(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RulesSectionContext* rulesSection();

  class  SectionContext : public antlr4::ParserRuleContext {
  public:
    SectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SectionIdentContext *sectionIdent();
    std::vector<TransitionRuleContext *> transitionRule();
    TransitionRuleContext* transitionRule(size_t i);
    std::vector<InstrumentContext *> instrument();
    InstrumentContext* instrument(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SectionContext* section();

  class  SectionIdentContext : public antlr4::ParserRuleContext {
  public:
    SectionIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SectionIdentContext* sectionIdent();

  class  InstrumentContext : public antlr4::ParserRuleContext {
  public:
    InstrumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();
    std::vector<TransitionRuleContext *> transitionRule();
    TransitionRuleContext* transitionRule(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InstrumentContext* instrument();

  class  TransitionRuleContext : public antlr4::ParserRuleContext {
  public:
    TransitionRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScaleRuleContext *scaleRule();
    OccurrenceRuleContext *occurrenceRule();
    SequenceRuleContext *sequenceRule();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TransitionRuleContext* transitionRule();

  class  ScaleRuleContext : public antlr4::ParserRuleContext {
  public:
    ScaleRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ScaleContext *> scale();
    ScaleContext* scale(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScaleRuleContext* scaleRule();

  class  ScaleContext : public antlr4::ParserRuleContext {
  public:
    ScaleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PitchContext *pitch();
    antlr4::tree::TerminalNode *WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScaleContext* scale();

  class  OccurrenceRuleContext : public antlr4::ParserRuleContext {
  public:
    OccurrenceRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    SequenceRuleContext *sequenceRule();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OccurrenceRuleContext* occurrenceRule();

  class  SequenceRuleContext : public antlr4::ParserRuleContext {
  public:
    SequenceRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SequenceContext *> sequence();
    SequenceContext* sequence(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SequenceRuleContext* sequenceRule();

  class  SequenceContext : public antlr4::ParserRuleContext {
  public:
    SequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NoteContext *> note();
    NoteContext* note(size_t i);
    std::vector<ChordContext *> chord();
    ChordContext* chord(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SequenceContext* sequence();

  class  ChordContext : public antlr4::ParserRuleContext {
  public:
    ChordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PitchContext *> pitch();
    PitchContext* pitch(size_t i);
    SymbolContext *symbol();
    std::vector<AdditionsContext *> additions();
    AdditionsContext* additions(size_t i);
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ChordContext* chord();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUALITY();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SymbolContext* symbol();

  class  AdditionsContext : public antlr4::ParserRuleContext {
  public:
    AdditionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDITIONS();
    PitchContext *pitch();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AdditionsContext* additions();

  class  PitchContext : public antlr4::ParserRuleContext {
  public:
    PitchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NATURAL();
    antlr4::tree::TerminalNode *ACCIDENTAL();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PitchContext* pitch();

  class  NoteContext : public antlr4::ParserRuleContext {
  public:
    NoteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PitchContext *pitch();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NoteContext* note();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

