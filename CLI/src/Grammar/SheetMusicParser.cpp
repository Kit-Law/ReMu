
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

std::vector<SheetMusicParser::UserDefContext *> SheetMusicParser::ScriptContext::userDef() {
  return getRuleContexts<SheetMusicParser::UserDefContext>();
}

SheetMusicParser::UserDefContext* SheetMusicParser::ScriptContext::userDef(size_t i) {
  return getRuleContext<SheetMusicParser::UserDefContext>(i);
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
    setState(48);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(46);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SheetMusicParser::STRING: {
            setState(44);
            sectionDef();
            break;
          }

          case SheetMusicParser::T__3:
          case SheetMusicParser::T__7: {
            setState(45);
            userDef();
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(50);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(51);
    rulesSection();
   
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
  enterRule(_localctx, 2, SheetMusicParser::RuleSectionDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    sectionIdent();
    setState(54);
    match(SheetMusicParser::T__0);
    setState(55);
    match(SheetMusicParser::NUMBER);
    setState(56);
    match(SheetMusicParser::T__1);
    setState(57);
    match(SheetMusicParser::NUMBER);
    setState(58);
    match(SheetMusicParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UserDefContext ------------------------------------------------------------------

SheetMusicParser::UserDefContext::UserDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SheetMusicParser::ScaleDefContext *> SheetMusicParser::UserDefContext::scaleDef() {
  return getRuleContexts<SheetMusicParser::ScaleDefContext>();
}

SheetMusicParser::ScaleDefContext* SheetMusicParser::UserDefContext::scaleDef(size_t i) {
  return getRuleContext<SheetMusicParser::ScaleDefContext>(i);
}

std::vector<SheetMusicParser::ChordDefContext *> SheetMusicParser::UserDefContext::chordDef() {
  return getRuleContexts<SheetMusicParser::ChordDefContext>();
}

SheetMusicParser::ChordDefContext* SheetMusicParser::UserDefContext::chordDef(size_t i) {
  return getRuleContext<SheetMusicParser::ChordDefContext>(i);
}


size_t SheetMusicParser::UserDefContext::getRuleIndex() const {
  return SheetMusicParser::RuleUserDef;
}

void SheetMusicParser::UserDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUserDef(this);
}

void SheetMusicParser::UserDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUserDef(this);
}

SheetMusicParser::UserDefContext* SheetMusicParser::userDef() {
  UserDefContext *_localctx = _tracker.createInstance<UserDefContext>(_ctx, getState());
  enterRule(_localctx, 4, SheetMusicParser::RuleUserDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(62); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(62);
              _errHandler->sync(this);
              switch (_input->LA(1)) {
                case SheetMusicParser::T__3: {
                  setState(60);
                  scaleDef();
                  break;
                }

                case SheetMusicParser::T__7: {
                  setState(61);
                  chordDef();
                  break;
                }

              default:
                throw NoViableAltException(this);
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(64); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScaleDefContext ------------------------------------------------------------------

SheetMusicParser::ScaleDefContext::ScaleDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::ScaleDefContext::WORD() {
  return getToken(SheetMusicParser::WORD, 0);
}

std::vector<tree::TerminalNode *> SheetMusicParser::ScaleDefContext::NUMBER() {
  return getTokens(SheetMusicParser::NUMBER);
}

tree::TerminalNode* SheetMusicParser::ScaleDefContext::NUMBER(size_t i) {
  return getToken(SheetMusicParser::NUMBER, i);
}


size_t SheetMusicParser::ScaleDefContext::getRuleIndex() const {
  return SheetMusicParser::RuleScaleDef;
}

void SheetMusicParser::ScaleDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScaleDef(this);
}

void SheetMusicParser::ScaleDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScaleDef(this);
}

SheetMusicParser::ScaleDefContext* SheetMusicParser::scaleDef() {
  ScaleDefContext *_localctx = _tracker.createInstance<ScaleDefContext>(_ctx, getState());
  enterRule(_localctx, 6, SheetMusicParser::RuleScaleDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(SheetMusicParser::T__3);
    setState(67);
    match(SheetMusicParser::WORD);
    setState(68);
    match(SheetMusicParser::T__4);
    setState(73);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(69);
        match(SheetMusicParser::NUMBER);
        setState(70);
        match(SheetMusicParser::T__5); 
      }
      setState(75);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(76);
    match(SheetMusicParser::NUMBER);
    setState(77);
    match(SheetMusicParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChordDefContext ------------------------------------------------------------------

SheetMusicParser::ChordDefContext::ChordDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::ChordDefContext::WORD() {
  return getToken(SheetMusicParser::WORD, 0);
}

std::vector<SheetMusicParser::PitchContext *> SheetMusicParser::ChordDefContext::pitch() {
  return getRuleContexts<SheetMusicParser::PitchContext>();
}

SheetMusicParser::PitchContext* SheetMusicParser::ChordDefContext::pitch(size_t i) {
  return getRuleContext<SheetMusicParser::PitchContext>(i);
}


size_t SheetMusicParser::ChordDefContext::getRuleIndex() const {
  return SheetMusicParser::RuleChordDef;
}

void SheetMusicParser::ChordDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChordDef(this);
}

void SheetMusicParser::ChordDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChordDef(this);
}

SheetMusicParser::ChordDefContext* SheetMusicParser::chordDef() {
  ChordDefContext *_localctx = _tracker.createInstance<ChordDefContext>(_ctx, getState());
  enterRule(_localctx, 8, SheetMusicParser::RuleChordDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(SheetMusicParser::T__7);
    setState(80);
    match(SheetMusicParser::WORD);
    setState(81);
    match(SheetMusicParser::T__4);
    setState(87);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(82);
        pitch();
        setState(83);
        match(SheetMusicParser::T__5); 
      }
      setState(89);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(90);
    pitch();
    setState(91);
    match(SheetMusicParser::T__6);
   
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
  enterRule(_localctx, 10, SheetMusicParser::RuleRulesSection);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(93);
      section();
      setState(96); 
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

std::vector<SheetMusicParser::InstrumentContext *> SheetMusicParser::SectionContext::instrument() {
  return getRuleContexts<SheetMusicParser::InstrumentContext>();
}

SheetMusicParser::InstrumentContext* SheetMusicParser::SectionContext::instrument(size_t i) {
  return getRuleContext<SheetMusicParser::InstrumentContext>(i);
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
  enterRule(_localctx, 12, SheetMusicParser::RuleSection);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    sectionIdent();
    setState(99);
    match(SheetMusicParser::T__8);
    setState(102); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(102);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SheetMusicParser::T__9:
        case SheetMusicParser::T__11:
        case SheetMusicParser::T__12:
        case SheetMusicParser::T__14:
        case SheetMusicParser::T__16:
        case SheetMusicParser::NUMBER:
        case SheetMusicParser::NATURAL: {
          setState(100);
          transitionRule();
          break;
        }

        case SheetMusicParser::WORD: {
          setState(101);
          instrument();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(104); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SheetMusicParser::T__9)
      | (1ULL << SheetMusicParser::T__11)
      | (1ULL << SheetMusicParser::T__12)
      | (1ULL << SheetMusicParser::T__14)
      | (1ULL << SheetMusicParser::T__16)
      | (1ULL << SheetMusicParser::NUMBER)
      | (1ULL << SheetMusicParser::NATURAL)
      | (1ULL << SheetMusicParser::WORD))) != 0));
   
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
  enterRule(_localctx, 14, SheetMusicParser::RuleSectionIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(SheetMusicParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstrumentContext ------------------------------------------------------------------

SheetMusicParser::InstrumentContext::InstrumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::InstrumentContext::WORD() {
  return getToken(SheetMusicParser::WORD, 0);
}

std::vector<SheetMusicParser::TransitionRuleContext *> SheetMusicParser::InstrumentContext::transitionRule() {
  return getRuleContexts<SheetMusicParser::TransitionRuleContext>();
}

SheetMusicParser::TransitionRuleContext* SheetMusicParser::InstrumentContext::transitionRule(size_t i) {
  return getRuleContext<SheetMusicParser::TransitionRuleContext>(i);
}


size_t SheetMusicParser::InstrumentContext::getRuleIndex() const {
  return SheetMusicParser::RuleInstrument;
}

void SheetMusicParser::InstrumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstrument(this);
}

void SheetMusicParser::InstrumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstrument(this);
}

SheetMusicParser::InstrumentContext* SheetMusicParser::instrument() {
  InstrumentContext *_localctx = _tracker.createInstance<InstrumentContext>(_ctx, getState());
  enterRule(_localctx, 16, SheetMusicParser::RuleInstrument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(SheetMusicParser::WORD);
    setState(109);
    match(SheetMusicParser::T__4);
    setState(111); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(110);
      transitionRule();
      setState(113); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SheetMusicParser::T__9)
      | (1ULL << SheetMusicParser::T__11)
      | (1ULL << SheetMusicParser::T__12)
      | (1ULL << SheetMusicParser::T__14)
      | (1ULL << SheetMusicParser::T__16)
      | (1ULL << SheetMusicParser::NUMBER)
      | (1ULL << SheetMusicParser::NATURAL))) != 0));
    setState(115);
    match(SheetMusicParser::T__6);
   
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

SheetMusicParser::OccurrenceRuleContext* SheetMusicParser::TransitionRuleContext::occurrenceRule() {
  return getRuleContext<SheetMusicParser::OccurrenceRuleContext>(0);
}

SheetMusicParser::SequenceRuleContext* SheetMusicParser::TransitionRuleContext::sequenceRule() {
  return getRuleContext<SheetMusicParser::SequenceRuleContext>(0);
}

SheetMusicParser::FlagsContext* SheetMusicParser::TransitionRuleContext::flags() {
  return getRuleContext<SheetMusicParser::FlagsContext>(0);
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
  enterRule(_localctx, 18, SheetMusicParser::RuleTransitionRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SheetMusicParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(117);
        scaleRule();
        break;
      }

      case SheetMusicParser::T__11: {
        enterOuterAlt(_localctx, 2);
        setState(118);
        occurrenceRule();
        break;
      }

      case SheetMusicParser::T__12:
      case SheetMusicParser::T__14:
      case SheetMusicParser::NUMBER:
      case SheetMusicParser::NATURAL: {
        enterOuterAlt(_localctx, 3);
        setState(119);
        sequenceRule();
        break;
      }

      case SheetMusicParser::T__16: {
        enterOuterAlt(_localctx, 4);
        setState(120);
        flags();
        break;
      }

    default:
      throw NoViableAltException(this);
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
  enterRule(_localctx, 20, SheetMusicParser::RuleScaleRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(123);
      match(SheetMusicParser::T__9);
      setState(124);
      scale();
      setState(125);
      match(SheetMusicParser::T__10);
      setState(126);
      scale();
      setState(127);
      match(SheetMusicParser::T__5);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(129);
      match(SheetMusicParser::T__9);
      setState(130);
      scale();
      setState(131);
      match(SheetMusicParser::T__5);
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

//----------------- ScaleContext ------------------------------------------------------------------

SheetMusicParser::ScaleContext::ScaleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SheetMusicParser::PitchContext* SheetMusicParser::ScaleContext::pitch() {
  return getRuleContext<SheetMusicParser::PitchContext>(0);
}

tree::TerminalNode* SheetMusicParser::ScaleContext::WORD() {
  return getToken(SheetMusicParser::WORD, 0);
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
  enterRule(_localctx, 22, SheetMusicParser::RuleScale);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    pitch();
    setState(136);
    match(SheetMusicParser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OccurrenceRuleContext ------------------------------------------------------------------

SheetMusicParser::OccurrenceRuleContext::OccurrenceRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::OccurrenceRuleContext::NUMBER() {
  return getToken(SheetMusicParser::NUMBER, 0);
}

SheetMusicParser::SequenceRuleContext* SheetMusicParser::OccurrenceRuleContext::sequenceRule() {
  return getRuleContext<SheetMusicParser::SequenceRuleContext>(0);
}


size_t SheetMusicParser::OccurrenceRuleContext::getRuleIndex() const {
  return SheetMusicParser::RuleOccurrenceRule;
}

void SheetMusicParser::OccurrenceRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOccurrenceRule(this);
}

void SheetMusicParser::OccurrenceRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOccurrenceRule(this);
}

SheetMusicParser::OccurrenceRuleContext* SheetMusicParser::occurrenceRule() {
  OccurrenceRuleContext *_localctx = _tracker.createInstance<OccurrenceRuleContext>(_ctx, getState());
  enterRule(_localctx, 24, SheetMusicParser::RuleOccurrenceRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(SheetMusicParser::T__11);
    setState(139);
    match(SheetMusicParser::NUMBER);
    setState(140);
    match(SheetMusicParser::T__8);
    setState(141);
    sequenceRule();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequenceRuleContext ------------------------------------------------------------------

SheetMusicParser::SequenceRuleContext::SequenceRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SheetMusicParser::SequenceContext *> SheetMusicParser::SequenceRuleContext::sequence() {
  return getRuleContexts<SheetMusicParser::SequenceContext>();
}

SheetMusicParser::SequenceContext* SheetMusicParser::SequenceRuleContext::sequence(size_t i) {
  return getRuleContext<SheetMusicParser::SequenceContext>(i);
}


size_t SheetMusicParser::SequenceRuleContext::getRuleIndex() const {
  return SheetMusicParser::RuleSequenceRule;
}

void SheetMusicParser::SequenceRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequenceRule(this);
}

void SheetMusicParser::SequenceRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequenceRule(this);
}

SheetMusicParser::SequenceRuleContext* SheetMusicParser::sequenceRule() {
  SequenceRuleContext *_localctx = _tracker.createInstance<SequenceRuleContext>(_ctx, getState());
  enterRule(_localctx, 26, SheetMusicParser::RuleSequenceRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    sequence();
    setState(144);
    match(SheetMusicParser::T__10);
    setState(145);
    sequence();
    setState(146);
    match(SheetMusicParser::T__5);
   
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

std::vector<SheetMusicParser::ChordContext *> SheetMusicParser::SequenceContext::chord() {
  return getRuleContexts<SheetMusicParser::ChordContext>();
}

SheetMusicParser::ChordContext* SheetMusicParser::SequenceContext::chord(size_t i) {
  return getRuleContext<SheetMusicParser::ChordContext>(i);
}

std::vector<SheetMusicParser::RestContext *> SheetMusicParser::SequenceContext::rest() {
  return getRuleContexts<SheetMusicParser::RestContext>();
}

SheetMusicParser::RestContext* SheetMusicParser::SequenceContext::rest(size_t i) {
  return getRuleContext<SheetMusicParser::RestContext>(i);
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
  enterRule(_localctx, 28, SheetMusicParser::RuleSequence);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(155);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(148);
        note();
        break;
      }

      case 2: {
        setState(149);
        chord();
        break;
      }

      case 3: {
        setState(150);
        match(SheetMusicParser::T__12);
        setState(151);
        chord();
        setState(152);
        match(SheetMusicParser::T__13);
        break;
      }

      case 4: {
        setState(154);
        rest();
        break;
      }

      }
      setState(157); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SheetMusicParser::T__12)
      | (1ULL << SheetMusicParser::T__14)
      | (1ULL << SheetMusicParser::NUMBER)
      | (1ULL << SheetMusicParser::NATURAL))) != 0));
   
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

SheetMusicParser::PitchContext* SheetMusicParser::ChordContext::pitch() {
  return getRuleContext<SheetMusicParser::PitchContext>(0);
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

tree::TerminalNode* SheetMusicParser::ChordContext::NUMBER() {
  return getToken(SheetMusicParser::NUMBER, 0);
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
  enterRule(_localctx, 30, SheetMusicParser::RuleChord);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    pitch();
    setState(160);
    symbol();
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SheetMusicParser::ADDITIONS) {
      setState(161);
      additions();
      setState(166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(170);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(167);
      match(SheetMusicParser::T__14);
      setState(168);
      match(SheetMusicParser::NUMBER);
      setState(169);
      match(SheetMusicParser::T__15);
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

//----------------- SymbolContext ------------------------------------------------------------------

SheetMusicParser::SymbolContext::SymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::SymbolContext::WORD() {
  return getToken(SheetMusicParser::WORD, 0);
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
  enterRule(_localctx, 32, SheetMusicParser::RuleSymbol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(SheetMusicParser::WORD);
   
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

SheetMusicParser::PitchContext* SheetMusicParser::AdditionsContext::pitch() {
  return getRuleContext<SheetMusicParser::PitchContext>(0);
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
  enterRule(_localctx, 34, SheetMusicParser::RuleAdditions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(SheetMusicParser::ADDITIONS);
    setState(175);
    pitch();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PitchContext ------------------------------------------------------------------

SheetMusicParser::PitchContext::PitchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::PitchContext::NATURAL() {
  return getToken(SheetMusicParser::NATURAL, 0);
}

tree::TerminalNode* SheetMusicParser::PitchContext::ACCIDENTAL() {
  return getToken(SheetMusicParser::ACCIDENTAL, 0);
}

tree::TerminalNode* SheetMusicParser::PitchContext::NUMBER() {
  return getToken(SheetMusicParser::NUMBER, 0);
}


size_t SheetMusicParser::PitchContext::getRuleIndex() const {
  return SheetMusicParser::RulePitch;
}

void SheetMusicParser::PitchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPitch(this);
}

void SheetMusicParser::PitchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPitch(this);
}

SheetMusicParser::PitchContext* SheetMusicParser::pitch() {
  PitchContext *_localctx = _tracker.createInstance<PitchContext>(_ctx, getState());
  enterRule(_localctx, 36, SheetMusicParser::RulePitch);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(177);
      match(SheetMusicParser::NATURAL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(178);
      match(SheetMusicParser::NATURAL);
      setState(179);
      match(SheetMusicParser::ACCIDENTAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(180);
      match(SheetMusicParser::NUMBER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(181);
      match(SheetMusicParser::NUMBER);
      setState(182);
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

//----------------- NoteContext ------------------------------------------------------------------

SheetMusicParser::NoteContext::NoteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SheetMusicParser::PitchContext* SheetMusicParser::NoteContext::pitch() {
  return getRuleContext<SheetMusicParser::PitchContext>(0);
}

std::vector<tree::TerminalNode *> SheetMusicParser::NoteContext::NUMBER() {
  return getTokens(SheetMusicParser::NUMBER);
}

tree::TerminalNode* SheetMusicParser::NoteContext::NUMBER(size_t i) {
  return getToken(SheetMusicParser::NUMBER, i);
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
  enterRule(_localctx, 38, SheetMusicParser::RuleNote);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    pitch();
    setState(187);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(186);
      match(SheetMusicParser::NUMBER);
      break;
    }

    }
    setState(192);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(189);
      match(SheetMusicParser::T__14);
      setState(190);
      match(SheetMusicParser::NUMBER);
      setState(191);
      match(SheetMusicParser::T__15);
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

//----------------- RestContext ------------------------------------------------------------------

SheetMusicParser::RestContext::RestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SheetMusicParser::RestContext::NUMBER() {
  return getToken(SheetMusicParser::NUMBER, 0);
}


size_t SheetMusicParser::RestContext::getRuleIndex() const {
  return SheetMusicParser::RuleRest;
}

void SheetMusicParser::RestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRest(this);
}

void SheetMusicParser::RestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRest(this);
}

SheetMusicParser::RestContext* SheetMusicParser::rest() {
  RestContext *_localctx = _tracker.createInstance<RestContext>(_ctx, getState());
  enterRule(_localctx, 40, SheetMusicParser::RuleRest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(SheetMusicParser::T__14);
    setState(195);
    match(SheetMusicParser::NUMBER);
    setState(196);
    match(SheetMusicParser::T__15);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlagsContext ------------------------------------------------------------------

SheetMusicParser::FlagsContext::FlagsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SheetMusicParser::FlagsContext::getRuleIndex() const {
  return SheetMusicParser::RuleFlags;
}

void SheetMusicParser::FlagsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFlags(this);
}

void SheetMusicParser::FlagsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SheetMusicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFlags(this);
}

SheetMusicParser::FlagsContext* SheetMusicParser::flags() {
  FlagsContext *_localctx = _tracker.createInstance<FlagsContext>(_ctx, getState());
  enterRule(_localctx, 42, SheetMusicParser::RuleFlags);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(SheetMusicParser::T__16);
   
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
  "script", "sectionDef", "userDef", "scaleDef", "chordDef", "rulesSection", 
  "section", "sectionIdent", "instrument", "transitionRule", "scaleRule", 
  "scale", "occurrenceRule", "sequenceRule", "sequence", "chord", "symbol", 
  "additions", "pitch", "note", "rest", "flags"
};

std::vector<std::string> SheetMusicParser::_literalNames = {
  "", "'='", "'-'", "';'", "'\\addScale'", "'{'", "','", "'}'", "'\\addChord'", 
  "':'", "'Scale:'", "'->'", "'Occurrence'", "'('", "')'", "'['", "']'", 
  "'\\ScaleEffectsChords'"
};

std::vector<std::string> SheetMusicParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "NUMBER", "NATURAL", "ACCIDENTAL", "ADDITIONS", "STRING", "WORD", "COMMENT", 
  "SPACE", "OTHER"
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
    0x3, 0x1c, 0xcb, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x3, 0x2, 
    0x7, 0x2, 0x31, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x34, 0xb, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0x41, 0xa, 0x4, 0xd, 0x4, 0xe, 
    0x4, 0x42, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x4a, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4d, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x7, 0x6, 0x58, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x5b, 0xb, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x6, 0x7, 0x61, 0xa, 0x7, 0xd, 0x7, 0xe, 
    0x7, 0x62, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0x69, 0xa, 
    0x8, 0xd, 0x8, 0xe, 0x8, 0x6a, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x6, 0xa, 0x72, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0x73, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x7c, 0xa, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x88, 0xa, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x6, 0x10, 0x9e, 
    0xa, 0x10, 0xd, 0x10, 0xe, 0x10, 0x9f, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x7, 0x11, 0xa5, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xa8, 0xb, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xad, 0xa, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xba, 0xa, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0xbe, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0xc3, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x2, 0x2, 0x18, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2, 0x2, 0x2, 0xcd, 0x2, 0x32, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x37, 0x3, 0x2, 0x2, 0x2, 0x6, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x44, 0x3, 0x2, 0x2, 0x2, 0xa, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x60, 0x3, 0x2, 0x2, 0x2, 0xe, 0x64, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x14, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x87, 0x3, 0x2, 0x2, 0x2, 0x18, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x20, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xae, 0x3, 0x2, 0x2, 0x2, 0x24, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x28, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x31, 
    0x5, 0x4, 0x3, 0x2, 0x2f, 0x31, 0x5, 0x6, 0x4, 0x2, 0x30, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x34, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x35, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x36, 0x5, 0xc, 0x7, 0x2, 0x36, 0x3, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x38, 0x5, 0x10, 0x9, 0x2, 0x38, 0x39, 0x7, 0x3, 0x2, 0x2, 0x39, 0x3a, 
    0x7, 0x14, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x4, 0x2, 0x2, 0x3b, 0x3c, 0x7, 
    0x14, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x5, 0x2, 0x2, 0x3d, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x41, 0x5, 0x8, 0x5, 0x2, 0x3f, 0x41, 0x5, 0xa, 0x6, 
    0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x7, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 
    0x7, 0x6, 0x2, 0x2, 0x45, 0x46, 0x7, 0x19, 0x2, 0x2, 0x46, 0x4b, 0x7, 
    0x7, 0x2, 0x2, 0x47, 0x48, 0x7, 0x14, 0x2, 0x2, 0x48, 0x4a, 0x7, 0x8, 
    0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x4f, 0x7, 0x14, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x9, 0x2, 0x2, 0x50, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0xa, 0x2, 0x2, 0x52, 0x53, 0x7, 
    0x19, 0x2, 0x2, 0x53, 0x59, 0x7, 0x7, 0x2, 0x2, 0x54, 0x55, 0x5, 0x26, 
    0x14, 0x2, 0x55, 0x56, 0x7, 0x8, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x54, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 
    0x5, 0x26, 0x14, 0x2, 0x5d, 0x5e, 0x7, 0x9, 0x2, 0x2, 0x5e, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x61, 0x5, 0xe, 0x8, 0x2, 0x60, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x65, 0x5, 0x10, 0x9, 0x2, 0x65, 0x68, 0x7, 0xb, 0x2, 0x2, 0x66, 
    0x69, 0x5, 0x14, 0xb, 0x2, 0x67, 0x69, 0x5, 0x12, 0xa, 0x2, 0x68, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x18, 0x2, 
    0x2, 0x6d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x19, 0x2, 0x2, 
    0x6f, 0x71, 0x7, 0x7, 0x2, 0x2, 0x70, 0x72, 0x5, 0x14, 0xb, 0x2, 0x71, 
    0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0x9, 0x2, 0x2, 0x76, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0x7c, 0x5, 0x16, 0xc, 0x2, 0x78, 0x7c, 0x5, 0x1a, 0xe, 
    0x2, 0x79, 0x7c, 0x5, 0x1c, 0xf, 0x2, 0x7a, 0x7c, 0x5, 0x2c, 0x17, 0x2, 
    0x7b, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0xc, 0x2, 0x2, 0x7e, 0x7f, 0x5, 
    0x18, 0xd, 0x2, 0x7f, 0x80, 0x7, 0xd, 0x2, 0x2, 0x80, 0x81, 0x5, 0x18, 
    0xd, 0x2, 0x81, 0x82, 0x7, 0x8, 0x2, 0x2, 0x82, 0x88, 0x3, 0x2, 0x2, 
    0x2, 0x83, 0x84, 0x7, 0xc, 0x2, 0x2, 0x84, 0x85, 0x5, 0x18, 0xd, 0x2, 
    0x85, 0x86, 0x7, 0x8, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x87, 0x83, 0x3, 0x2, 0x2, 0x2, 0x88, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x5, 0x26, 0x14, 0x2, 0x8a, 0x8b, 0x7, 
    0x19, 0x2, 0x2, 0x8b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0xe, 
    0x2, 0x2, 0x8d, 0x8e, 0x7, 0x14, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0xb, 0x2, 
    0x2, 0x8f, 0x90, 0x5, 0x1c, 0xf, 0x2, 0x90, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x92, 0x5, 0x1e, 0x10, 0x2, 0x92, 0x93, 0x7, 0xd, 0x2, 0x2, 0x93, 
    0x94, 0x5, 0x1e, 0x10, 0x2, 0x94, 0x95, 0x7, 0x8, 0x2, 0x2, 0x95, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x96, 0x9e, 0x5, 0x28, 0x15, 0x2, 0x97, 0x9e, 0x5, 
    0x20, 0x11, 0x2, 0x98, 0x99, 0x7, 0xf, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x20, 
    0x11, 0x2, 0x9a, 0x9b, 0x7, 0x10, 0x2, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x9e, 0x5, 0x2a, 0x16, 0x2, 0x9d, 0x96, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x26, 0x14, 0x2, 0xa2, 0xa6, 0x5, 0x22, 
    0x12, 0x2, 0xa3, 0xa5, 0x5, 0x24, 0x13, 0x2, 0xa4, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xac, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa6, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x11, 0x2, 0x2, 0xaa, 0xab, 
    0x7, 0x14, 0x2, 0x2, 0xab, 0xad, 0x7, 0x12, 0x2, 0x2, 0xac, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xaf, 0x7, 0x19, 0x2, 0x2, 0xaf, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xb1, 0x7, 0x17, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x26, 0x14, 0x2, 
    0xb2, 0x25, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xba, 0x7, 0x15, 0x2, 0x2, 0xb4, 
    0xb5, 0x7, 0x15, 0x2, 0x2, 0xb5, 0xba, 0x7, 0x16, 0x2, 0x2, 0xb6, 0xba, 
    0x7, 0x14, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x14, 0x2, 0x2, 0xb8, 0xba, 0x7, 
    0x16, 0x2, 0x2, 0xb9, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0x27, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x26, 0x14, 0x2, 
    0xbc, 0xbe, 0x7, 0x14, 0x2, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 
    0x7, 0x11, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x14, 0x2, 0x2, 0xc1, 0xc3, 0x7, 
    0x12, 0x2, 0x2, 0xc2, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xc3, 0x29, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x11, 0x2, 
    0x2, 0xc5, 0xc6, 0x7, 0x14, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x12, 0x2, 0x2, 
    0xc7, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x13, 0x2, 0x2, 0xc9, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x15, 0x30, 0x32, 0x40, 0x42, 0x4b, 0x59, 
    0x62, 0x68, 0x6a, 0x73, 0x7b, 0x87, 0x9d, 0x9f, 0xa6, 0xac, 0xb9, 0xbd, 
    0xc2, 
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
