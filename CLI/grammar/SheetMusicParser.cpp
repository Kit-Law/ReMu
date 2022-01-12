
// Generated from SheetMusic.g4 by ANTLR 4.8


#include "SheetMusicListener.h"

#include "SheetMusicParser.h"


using namespace antlrcpp;
using namespace antlr4;

SheetMusicParser::SheetMusicParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SheetMusicParser::~SheetMusicParser() {
  delete _interpreter;
}

std::string SheetMusicParser::getGrammarFileName() const {
  return "SheetMusic.g4";
}

const std::vector<std::string>& SheetMusicParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SheetMusicParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ScriptContext ------------------------------------------------------------------

SheetMusicParser::ScriptContext::ScriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SheetMusicParser::RulesSectionContext* SheetMusicParser::ScriptContext::rulesSection() {
  return getRuleContext<SheetMusicParser::RulesSectionContext>(0);
}

std::vector<SheetMusicParser::SectionDefContext *> SheetMusicParser::ScriptContext::sectionDef() {
  return getRuleContexts<SheetMusicParser::SectionDefContext>();
}

SheetMusicParser::SectionDefContext* SheetMusicParser::ScriptContext::sectionDef(size_t i) {
  return getRuleContext<SheetMusicParser::SectionDefContext>(i);
}


size_t SheetMusicParser::ScriptContext::getRuleIndex() const {
  return SheetMusicParser::RuleScript;
}

void SheetMusicParser::ScriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScript(this);
}

void SheetMusicParser::ScriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScript(this);
}

SheetMusicParser::ScriptContext* SheetMusicParser::script() {
  ScriptContext *_localctx = _tracker.createInstance<ScriptContext>(_ctx, getState());
  enterRule(_localctx, 0, SheetMusicParser::RuleScript);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(33);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(30);
        sectionDef(); 
      }
      setState(35);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(36);
    rulesSection();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RulesSectionContext ------------------------------------------------------------------

SheetMusicParser::RulesSectionContext::RulesSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SheetMusicParser::SectionContext *> SheetMusicParser::RulesSectionContext::section() {
  return getRuleContexts<SheetMusicParser::SectionContext>();
}

SheetMusicParser::SectionContext* SheetMusicParser::RulesSectionContext::section(size_t i) {
  return getRuleContext<SheetMusicParser::SectionContext>(i);
}


size_t SheetMusicParser::RulesSectionContext::getRuleIndex() const {
  return SheetMusicParser::RuleRulesSection;
}

void SheetMusicParser::RulesSectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRulesSection(this);
}

void SheetMusicParser::RulesSectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRulesSection(this);
}

SheetMusicParser::RulesSectionContext* SheetMusicParser::rulesSection() {
  RulesSectionContext *_localctx = _tracker.createInstance<RulesSectionContext>(_ctx, getState());
  enterRule(_localctx, 2, SheetMusicParser::RuleRulesSection);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(39); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(38);
      section();
      setState(41); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SheetMusicParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SectionDefContext ------------------------------------------------------------------

SheetMusicParser::SectionDefContext::SectionDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SheetMusicParser::SectionIdentContext* SheetMusicParser::SectionDefContext::sectionIdent() {
  return getRuleContext<SheetMusicParser::SectionIdentContext>(0);
}

std::vector<tree::TerminalNode *> SheetMusicParser::SectionDefContext::NUMBER() {
  return getTokens(SheetMusicParser::NUMBER);
}

tree::TerminalNode* SheetMusicParser::SectionDefContext::NUMBER(size_t i) {
  return getToken(SheetMusicParser::NUMBER, i);
}


size_t SheetMusicParser::SectionDefContext::getRuleIndex() const {
  return SheetMusicParser::RuleSectionDef;
}

void SheetMusicParser::SectionDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSectionDef(this);
}

void SheetMusicParser::SectionDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSectionDef(this);
}

SheetMusicParser::SectionDefContext* SheetMusicParser::sectionDef() {
  SectionDefContext *_localctx = _tracker.createInstance<SectionDefContext>(_ctx, getState());
  enterRule(_localctx, 4, SheetMusicParser::RuleSectionDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    sectionIdent();
    setState(44);
    match(SheetMusicParser::T__0);
    setState(45);
    match(SheetMusicParser::NUMBER);
    setState(46);
    match(SheetMusicParser::T__1);
    setState(47);
    match(SheetMusicParser::NUMBER);
    setState(48);
    match(SheetMusicParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SectionContext ------------------------------------------------------------------

SheetMusicParser::SectionContext::SectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SheetMusicParser::SectionIdentContext* SheetMusicParser::SectionContext::sectionIdent() {
  return getRuleContext<SheetMusicParser::SectionIdentContext>(0);
}

std::vector<SheetMusicParser::TransitionRuleContext *> SheetMusicParser::SectionContext::transitionRule() {
  return getRuleContexts<SheetMusicParser::TransitionRuleContext>();
}

SheetMusicParser::TransitionRuleContext* SheetMusicParser::SectionContext::transitionRule(size_t i) {
  return getRuleContext<SheetMusicParser::TransitionRuleContext>(i);
}


size_t SheetMusicParser::SectionContext::getRuleIndex() const {
  return SheetMusicParser::RuleSection;
}

void SheetMusicParser::SectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection(this);
}

void SheetMusicParser::SectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection(this);
}

SheetMusicParser::SectionContext* SheetMusicParser::section() {
  SectionContext *_localctx = _tracker.createInstance<SectionContext>(_ctx, getState());
  enterRule(_localctx, 6, SheetMusicParser::RuleSection);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    sectionIdent();
    setState(51);
    match(SheetMusicParser::T__3);
    setState(53); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(52);
      transitionRule();
      setState(55); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SheetMusicParser::NUMBER

    || _la == SheetMusicParser::NATURAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SectionIdentContext ------------------------------------------------------------------

SheetMusicParser::SectionIdentContext::SectionIdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::SectionIdentContext::STRING() {
  return getToken(SheetMusicParser::STRING, 0);
}


size_t SheetMusicParser::SectionIdentContext::getRuleIndex() const {
  return SheetMusicParser::RuleSectionIdent;
}

void SheetMusicParser::SectionIdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSectionIdent(this);
}

void SheetMusicParser::SectionIdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSectionIdent(this);
}

SheetMusicParser::SectionIdentContext* SheetMusicParser::sectionIdent() {
  SectionIdentContext *_localctx = _tracker.createInstance<SectionIdentContext>(_ctx, getState());
  enterRule(_localctx, 8, SheetMusicParser::RuleSectionIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(SheetMusicParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransitionRuleContext ------------------------------------------------------------------

SheetMusicParser::TransitionRuleContext::TransitionRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SheetMusicParser::ScaleRuleContext* SheetMusicParser::TransitionRuleContext::scaleRule() {
  return getRuleContext<SheetMusicParser::ScaleRuleContext>(0);
}

SheetMusicParser::ChordRuleContext* SheetMusicParser::TransitionRuleContext::chordRule() {
  return getRuleContext<SheetMusicParser::ChordRuleContext>(0);
}

SheetMusicParser::NoteRuleContext* SheetMusicParser::TransitionRuleContext::noteRule() {
  return getRuleContext<SheetMusicParser::NoteRuleContext>(0);
}


size_t SheetMusicParser::TransitionRuleContext::getRuleIndex() const {
  return SheetMusicParser::RuleTransitionRule;
}

void SheetMusicParser::TransitionRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransitionRule(this);
}

void SheetMusicParser::TransitionRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransitionRule(this);
}

SheetMusicParser::TransitionRuleContext* SheetMusicParser::transitionRule() {
  TransitionRuleContext *_localctx = _tracker.createInstance<TransitionRuleContext>(_ctx, getState());
  enterRule(_localctx, 10, SheetMusicParser::RuleTransitionRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(59);
      scaleRule();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(60);
      chordRule();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(61);
      noteRule();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScaleRuleContext ------------------------------------------------------------------

SheetMusicParser::ScaleRuleContext::ScaleRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SheetMusicParser::ScaleContext *> SheetMusicParser::ScaleRuleContext::scale() {
  return getRuleContexts<SheetMusicParser::ScaleContext>();
}

SheetMusicParser::ScaleContext* SheetMusicParser::ScaleRuleContext::scale(size_t i) {
  return getRuleContext<SheetMusicParser::ScaleContext>(i);
}


size_t SheetMusicParser::ScaleRuleContext::getRuleIndex() const {
  return SheetMusicParser::RuleScaleRule;
}

void SheetMusicParser::ScaleRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScaleRule(this);
}

void SheetMusicParser::ScaleRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScaleRule(this);
}

SheetMusicParser::ScaleRuleContext* SheetMusicParser::scaleRule() {
  ScaleRuleContext *_localctx = _tracker.createInstance<ScaleRuleContext>(_ctx, getState());
  enterRule(_localctx, 12, SheetMusicParser::RuleScaleRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    scale();
    setState(65);
    match(SheetMusicParser::T__4);
    setState(66);
    scale();
    setState(67);
    match(SheetMusicParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChordRuleContext ------------------------------------------------------------------

SheetMusicParser::ChordRuleContext::ChordRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SheetMusicParser::ChordContext *> SheetMusicParser::ChordRuleContext::chord() {
  return getRuleContexts<SheetMusicParser::ChordContext>();
}

SheetMusicParser::ChordContext* SheetMusicParser::ChordRuleContext::chord(size_t i) {
  return getRuleContext<SheetMusicParser::ChordContext>(i);
}


size_t SheetMusicParser::ChordRuleContext::getRuleIndex() const {
  return SheetMusicParser::RuleChordRule;
}

void SheetMusicParser::ChordRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChordRule(this);
}

void SheetMusicParser::ChordRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChordRule(this);
}

SheetMusicParser::ChordRuleContext* SheetMusicParser::chordRule() {
  ChordRuleContext *_localctx = _tracker.createInstance<ChordRuleContext>(_ctx, getState());
  enterRule(_localctx, 14, SheetMusicParser::RuleChordRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    chord();
    setState(70);
    match(SheetMusicParser::T__4);
    setState(71);
    chord();
    setState(72);
    match(SheetMusicParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoteRuleContext ------------------------------------------------------------------

SheetMusicParser::NoteRuleContext::NoteRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SheetMusicParser::SequenceContext *> SheetMusicParser::NoteRuleContext::sequence() {
  return getRuleContexts<SheetMusicParser::SequenceContext>();
}

SheetMusicParser::SequenceContext* SheetMusicParser::NoteRuleContext::sequence(size_t i) {
  return getRuleContext<SheetMusicParser::SequenceContext>(i);
}


size_t SheetMusicParser::NoteRuleContext::getRuleIndex() const {
  return SheetMusicParser::RuleNoteRule;
}

void SheetMusicParser::NoteRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoteRule(this);
}

void SheetMusicParser::NoteRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoteRule(this);
}

SheetMusicParser::NoteRuleContext* SheetMusicParser::noteRule() {
  NoteRuleContext *_localctx = _tracker.createInstance<NoteRuleContext>(_ctx, getState());
  enterRule(_localctx, 16, SheetMusicParser::RuleNoteRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    sequence();
    setState(75);
    match(SheetMusicParser::T__4);
    setState(76);
    sequence();
    setState(77);
    match(SheetMusicParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScaleContext ------------------------------------------------------------------

SheetMusicParser::ScaleContext::ScaleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SheetMusicParser::NoteContext* SheetMusicParser::ScaleContext::note() {
  return getRuleContext<SheetMusicParser::NoteContext>(0);
}

tree::TerminalNode* SheetMusicParser::ScaleContext::SCALE() {
  return getToken(SheetMusicParser::SCALE, 0);
}


size_t SheetMusicParser::ScaleContext::getRuleIndex() const {
  return SheetMusicParser::RuleScale;
}

void SheetMusicParser::ScaleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScale(this);
}

void SheetMusicParser::ScaleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScale(this);
}

SheetMusicParser::ScaleContext* SheetMusicParser::scale() {
  ScaleContext *_localctx = _tracker.createInstance<ScaleContext>(_ctx, getState());
  enterRule(_localctx, 18, SheetMusicParser::RuleScale);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    note();
    setState(80);
    match(SheetMusicParser::SCALE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequenceContext ------------------------------------------------------------------

SheetMusicParser::SequenceContext::SequenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SheetMusicParser::NoteContext *> SheetMusicParser::SequenceContext::note() {
  return getRuleContexts<SheetMusicParser::NoteContext>();
}

SheetMusicParser::NoteContext* SheetMusicParser::SequenceContext::note(size_t i) {
  return getRuleContext<SheetMusicParser::NoteContext>(i);
}


size_t SheetMusicParser::SequenceContext::getRuleIndex() const {
  return SheetMusicParser::RuleSequence;
}

void SheetMusicParser::SequenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequence(this);
}

void SheetMusicParser::SequenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequence(this);
}

SheetMusicParser::SequenceContext* SheetMusicParser::sequence() {
  SequenceContext *_localctx = _tracker.createInstance<SequenceContext>(_ctx, getState());
  enterRule(_localctx, 20, SheetMusicParser::RuleSequence);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(82);
      note();
      setState(85); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SheetMusicParser::NUMBER

    || _la == SheetMusicParser::NATURAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChordContext ------------------------------------------------------------------

SheetMusicParser::ChordContext::ChordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SheetMusicParser::NoteContext* SheetMusicParser::ChordContext::note() {
  return getRuleContext<SheetMusicParser::NoteContext>(0);
}

SheetMusicParser::SymbolContext* SheetMusicParser::ChordContext::symbol() {
  return getRuleContext<SheetMusicParser::SymbolContext>(0);
}

std::vector<SheetMusicParser::AdditionsContext *> SheetMusicParser::ChordContext::additions() {
  return getRuleContexts<SheetMusicParser::AdditionsContext>();
}

SheetMusicParser::AdditionsContext* SheetMusicParser::ChordContext::additions(size_t i) {
  return getRuleContext<SheetMusicParser::AdditionsContext>(i);
}


size_t SheetMusicParser::ChordContext::getRuleIndex() const {
  return SheetMusicParser::RuleChord;
}

void SheetMusicParser::ChordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChord(this);
}

void SheetMusicParser::ChordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChord(this);
}

SheetMusicParser::ChordContext* SheetMusicParser::chord() {
  ChordContext *_localctx = _tracker.createInstance<ChordContext>(_ctx, getState());
  enterRule(_localctx, 22, SheetMusicParser::RuleChord);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    note();
    setState(88);
    symbol();
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SheetMusicParser::ADDITIONS) {
      setState(89);
      additions();
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolContext ------------------------------------------------------------------

SheetMusicParser::SymbolContext::SymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::SymbolContext::QUALITY() {
  return getToken(SheetMusicParser::QUALITY, 0);
}

tree::TerminalNode* SheetMusicParser::SymbolContext::NUMBER() {
  return getToken(SheetMusicParser::NUMBER, 0);
}


size_t SheetMusicParser::SymbolContext::getRuleIndex() const {
  return SheetMusicParser::RuleSymbol;
}

void SheetMusicParser::SymbolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbol(this);
}

void SheetMusicParser::SymbolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbol(this);
}

SheetMusicParser::SymbolContext* SheetMusicParser::symbol() {
  SymbolContext *_localctx = _tracker.createInstance<SymbolContext>(_ctx, getState());
  enterRule(_localctx, 24, SheetMusicParser::RuleSymbol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(95);
      match(SheetMusicParser::QUALITY);
      setState(96);
      match(SheetMusicParser::NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(97);
      match(SheetMusicParser::QUALITY);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditionsContext ------------------------------------------------------------------

SheetMusicParser::AdditionsContext::AdditionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::AdditionsContext::ADDITIONS() {
  return getToken(SheetMusicParser::ADDITIONS, 0);
}

SheetMusicParser::NoteContext* SheetMusicParser::AdditionsContext::note() {
  return getRuleContext<SheetMusicParser::NoteContext>(0);
}


size_t SheetMusicParser::AdditionsContext::getRuleIndex() const {
  return SheetMusicParser::RuleAdditions;
}

void SheetMusicParser::AdditionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditions(this);
}

void SheetMusicParser::AdditionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditions(this);
}

SheetMusicParser::AdditionsContext* SheetMusicParser::additions() {
  AdditionsContext *_localctx = _tracker.createInstance<AdditionsContext>(_ctx, getState());
  enterRule(_localctx, 26, SheetMusicParser::RuleAdditions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(SheetMusicParser::ADDITIONS);
    setState(101);
    note();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoteContext ------------------------------------------------------------------

SheetMusicParser::NoteContext::NoteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::NoteContext::NATURAL() {
  return getToken(SheetMusicParser::NATURAL, 0);
}

tree::TerminalNode* SheetMusicParser::NoteContext::ACCIDENTAL() {
  return getToken(SheetMusicParser::ACCIDENTAL, 0);
}

tree::TerminalNode* SheetMusicParser::NoteContext::NUMBER() {
  return getToken(SheetMusicParser::NUMBER, 0);
}


size_t SheetMusicParser::NoteContext::getRuleIndex() const {
  return SheetMusicParser::RuleNote;
}

void SheetMusicParser::NoteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNote(this);
}

void SheetMusicParser::NoteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNote(this);
}

SheetMusicParser::NoteContext* SheetMusicParser::note() {
  NoteContext *_localctx = _tracker.createInstance<NoteContext>(_ctx, getState());
  enterRule(_localctx, 28, SheetMusicParser::RuleNote);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(103);
      match(SheetMusicParser::NATURAL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(104);
      match(SheetMusicParser::NATURAL);
      setState(105);
      match(SheetMusicParser::ACCIDENTAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(106);
      match(SheetMusicParser::NUMBER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(107);
      match(SheetMusicParser::NUMBER);
      setState(108);
      match(SheetMusicParser::ACCIDENTAL);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> SheetMusicParser::_decisionToDFA;
atn::PredictionContextCache SheetMusicParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SheetMusicParser::_atn;
std::vector<uint16_t> SheetMusicParser::_serializedATN;

std::vector<std::string> SheetMusicParser::_ruleNames = {
  "script", "rulesSection", "sectionDef", "section", "sectionIdent", "transitionRule", 
  "scaleRule", "chordRule", "noteRule", "scale", "sequence", "chord", "symbol", 
  "additions", "note"
};

std::vector<std::string> SheetMusicParser::_literalNames = {
  "", "'='", "'-'", "';'", "':'", "'->'", "','"
};

std::vector<std::string> SheetMusicParser::_symbolicNames = {
  "", "", "", "", "", "", "", "NUMBER", "NATURAL", "ACCIDENTAL", "QUALITY", 
  "ADDITIONS", "STRING", "SCALE", "COMMENT", "SPACE", "OTHER"
};

dfa::Vocabulary SheetMusicParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SheetMusicParser::_tokenNames;

SheetMusicParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x12, 0x72, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x7, 0x2, 0x22, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x25, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x6, 0x3, 0x2a, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x2b, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x6, 0x5, 0x38, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x39, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x41, 0xa, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x6, 0xc, 0x56, 0xa, 0xc, 
    0xd, 0xc, 0xe, 0xc, 0x57, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x5d, 
    0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x60, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x5, 0xe, 0x65, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x70, 
    0xa, 0x10, 0x3, 0x10, 0x2, 0x2, 0x11, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x2, 0x2, 0x2, 
    0x6d, 0x2, 0x23, 0x3, 0x2, 0x2, 0x2, 0x4, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x34, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x40, 0x3, 0x2, 0x2, 0x2, 0xe, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x47, 0x3, 0x2, 0x2, 0x2, 0x12, 0x4c, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x51, 0x3, 0x2, 0x2, 0x2, 0x16, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x64, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x20, 0x22, 
    0x5, 0x6, 0x4, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0x24, 0x26, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x27, 0x5, 0x4, 0x3, 0x2, 0x27, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x2a, 0x5, 0x8, 0x5, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x5, 
    0xa, 0x6, 0x2, 0x2e, 0x2f, 0x7, 0x3, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x9, 
    0x2, 0x2, 0x30, 0x31, 0x7, 0x4, 0x2, 0x2, 0x31, 0x32, 0x7, 0x9, 0x2, 
    0x2, 0x32, 0x33, 0x7, 0x5, 0x2, 0x2, 0x33, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x35, 0x5, 0xa, 0x6, 0x2, 0x35, 0x37, 0x7, 0x6, 0x2, 0x2, 0x36, 
    0x38, 0x5, 0xc, 0x7, 0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0xe, 
    0x2, 0x2, 0x3c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x41, 0x5, 0xe, 0x8, 
    0x2, 0x3e, 0x41, 0x5, 0x10, 0x9, 0x2, 0x3f, 0x41, 0x5, 0x12, 0xa, 0x2, 
    0x40, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0xd, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 
    0x5, 0x14, 0xb, 0x2, 0x43, 0x44, 0x7, 0x7, 0x2, 0x2, 0x44, 0x45, 0x5, 
    0x14, 0xb, 0x2, 0x45, 0x46, 0x7, 0x8, 0x2, 0x2, 0x46, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x48, 0x5, 0x18, 0xd, 0x2, 0x48, 0x49, 0x7, 0x7, 0x2, 
    0x2, 0x49, 0x4a, 0x5, 0x18, 0xd, 0x2, 0x4a, 0x4b, 0x7, 0x8, 0x2, 0x2, 
    0x4b, 0x11, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x5, 0x16, 0xc, 0x2, 0x4d, 
    0x4e, 0x7, 0x7, 0x2, 0x2, 0x4e, 0x4f, 0x5, 0x16, 0xc, 0x2, 0x4f, 0x50, 
    0x7, 0x8, 0x2, 0x2, 0x50, 0x13, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x5, 
    0x1e, 0x10, 0x2, 0x52, 0x53, 0x7, 0xf, 0x2, 0x2, 0x53, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x56, 0x5, 0x1e, 0x10, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x17, 0x3, 0x2, 0x2, 0x2, 0x59, 
    0x5a, 0x5, 0x1e, 0x10, 0x2, 0x5a, 0x5e, 0x5, 0x1a, 0xe, 0x2, 0x5b, 0x5d, 
    0x5, 0x1c, 0xf, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x19, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x7, 0xc, 0x2, 0x2, 0x62, 0x65, 0x7, 0x9, 0x2, 0x2, 
    0x63, 0x65, 0x7, 0xc, 0x2, 0x2, 0x64, 0x61, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 
    0x7, 0xd, 0x2, 0x2, 0x67, 0x68, 0x5, 0x1e, 0x10, 0x2, 0x68, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x70, 0x7, 0xa, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0xa, 
    0x2, 0x2, 0x6b, 0x70, 0x7, 0xb, 0x2, 0x2, 0x6c, 0x70, 0x7, 0x9, 0x2, 
    0x2, 0x6d, 0x6e, 0x7, 0x9, 0x2, 0x2, 0x6e, 0x70, 0x7, 0xb, 0x2, 0x2, 
    0x6f, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6f, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x70, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x23, 0x2b, 0x39, 0x40, 0x57, 0x5e, 0x64, 0x6f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SheetMusicParser::Initializer SheetMusicParser::_init;
