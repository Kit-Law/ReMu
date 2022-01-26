// Generated from SheetMusic.g4 by ANTLR 4.8

#pragma once

#include "antlr4-runtime.h"




class  SheetMusicParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, NUMBER = 7, 
    NATURAL = 8, ACCIDENTAL = 9, QUALITY = 10, ADDITIONS = 11, STRING = 12, 
    SCALE = 13, COMMENT = 14, SPACE = 15, OTHER = 16
  };

  enum {
    RuleScript = 0, RuleRulesSection = 1, RuleSectionDef = 2, RuleSection = 3, 
    RuleSectionIdent = 4, RuleTransitionRule = 5, RuleScaleRule = 6, RuleChordRule = 7, 
    RuleNoteRule = 8, RuleScale = 9, RuleSequence = 10, RuleChord = 11, 
    RuleSymbol = 12, RuleAdditions = 13, RuleNote = 14
  };

  SheetMusicParser(antlr4::TokenStream *input);
  ~SheetMusicParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ScriptContext;
  class RulesSectionContext;
  class SectionDefContext;
  class SectionContext;
  class SectionIdentContext;
  class TransitionRuleContext;
  class ScaleRuleContext;
  class ChordRuleContext;
  class NoteRuleContext;
  class ScaleContext;
  class SequenceContext;
  class ChordContext;
  class SymbolContext;
  class AdditionsContext;
  class NoteContext; 

  class  ScriptContext : public antlr4::ParserRuleContext {
  public:
    ScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RulesSectionContext *rulesSection();
    std::vector<SectionDefContext *> sectionDef();
    SectionDefContext* sectionDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScriptContext* script();

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

  class  SectionContext : public antlr4::ParserRuleContext {
  public:
    SectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SectionIdentContext *sectionIdent();
    std::vector<TransitionRuleContext *> transitionRule();
    TransitionRuleContext* transitionRule(size_t i);

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

  class  TransitionRuleContext : public antlr4::ParserRuleContext {
  public:
    TransitionRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScaleRuleContext *scaleRule();
    ChordRuleContext *chordRule();
    NoteRuleContext *noteRule();

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

  class  ChordRuleContext : public antlr4::ParserRuleContext {
  public:
    ChordRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ChordContext *> chord();
    ChordContext* chord(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ChordRuleContext* chordRule();

  class  NoteRuleContext : public antlr4::ParserRuleContext {
  public:
    NoteRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SequenceContext *> sequence();
    SequenceContext* sequence(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NoteRuleContext* noteRule();

  class  ScaleContext : public antlr4::ParserRuleContext {
  public:
    ScaleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NoteContext *note();
    antlr4::tree::TerminalNode *SCALE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScaleContext* scale();

  class  SequenceContext : public antlr4::ParserRuleContext {
  public:
    SequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NoteContext *> note();
    NoteContext* note(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SequenceContext* sequence();

  class  ChordContext : public antlr4::ParserRuleContext {
  public:
    ChordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NoteContext *note();
    SymbolContext *symbol();
    std::vector<AdditionsContext *> additions();
    AdditionsContext* additions(size_t i);

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
    NoteContext *note();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AdditionsContext* additions();

  class  NoteContext : public antlr4::ParserRuleContext {
  public:
    NoteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NATURAL();
    antlr4::tree::TerminalNode *ACCIDENTAL();
    antlr4::tree::TerminalNode *NUMBER();

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

