
// Generated from SheetMusic.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  SheetMusicParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, MEASURE = 7, 
    NATURAL = 8, MODIFIER = 9, INTERVAL = 10, QUALITY = 11, STRING = 12, 
    COMMENT = 13, SPACE = 14, OTHER = 15
  };

  enum {
    RuleScript = 0, RuleRulesSection = 1, RuleSectionDef = 2, RuleSection = 3, 
    RuleSectionIdent = 4, RuleTransitionRules = 5, RuleTransitionRule = 6, 
    RuleScaleRule = 7, RuleChordRule = 8, RuleNoteRule = 9, RuleScale = 10, 
    RuleSequence = 11, RuleChord = 12, RuleSymbol = 13, RuleNote = 14
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
  class TransitionRulesContext;
  class TransitionRuleContext;
  class ScaleRuleContext;
  class ChordRuleContext;
  class NoteRuleContext;
  class ScaleContext;
  class SequenceContext;
  class ChordContext;
  class SymbolContext;
  class NoteContext; 

  class  ScriptContext : public antlr4::ParserRuleContext {
  public:
    ScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SectionDefContext *sectionDef();
    ScriptContext *script();
    RulesSectionContext *rulesSection();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScriptContext* script();

  class  RulesSectionContext : public antlr4::ParserRuleContext {
  public:
    RulesSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RulesSectionContext *rulesSection();
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
    std::vector<antlr4::tree::TerminalNode *> MEASURE();
    antlr4::tree::TerminalNode* MEASURE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SectionDefContext* sectionDef();

  class  SectionContext : public antlr4::ParserRuleContext {
  public:
    SectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SectionIdentContext *sectionIdent();
    TransitionRulesContext *transitionRules();

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

  class  TransitionRulesContext : public antlr4::ParserRuleContext {
  public:
    TransitionRulesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TransitionRulesContext *transitionRules();
    std::vector<TransitionRuleContext *> transitionRule();
    TransitionRuleContext* transitionRule(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TransitionRulesContext* transitionRules();

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
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScaleContext* scale();

  class  SequenceContext : public antlr4::ParserRuleContext {
  public:
    SequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SequenceContext *sequence();
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ChordContext* chord();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolContext *symbol();
    std::vector<antlr4::tree::TerminalNode *> QUALITY();
    antlr4::tree::TerminalNode* QUALITY(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INTERVAL();
    antlr4::tree::TerminalNode* INTERVAL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SymbolContext* symbol();

  class  NoteContext : public antlr4::ParserRuleContext {
  public:
    NoteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NATURAL();
    NoteContext *note();
    antlr4::tree::TerminalNode *MODIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NoteContext* note();
  NoteContext* note(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool noteSempred(NoteContext *_localctx, size_t predicateIndex);

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

