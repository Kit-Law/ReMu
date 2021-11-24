// Generated from SheetMusic.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class SheetMusicParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, MEASURE=7, NATURAL=8, 
		MODIFIER=9, INTERVAL=10, QUALITY=11, STRING=12, COMMENT=13, SPACE=14, 
		OTHER=15;
	public static final int
		RULE_script = 0, RULE_rulesSection = 1, RULE_sectionDef = 2, RULE_section = 3, 
		RULE_sectionIdent = 4, RULE_transitionRules = 5, RULE_transitionRule = 6, 
		RULE_scaleRule = 7, RULE_chordRule = 8, RULE_noteRule = 9, RULE_scale = 10, 
		RULE_sequence = 11, RULE_chord = 12, RULE_symbol = 13, RULE_note = 14;
	private static String[] makeRuleNames() {
		return new String[] {
			"script", "rulesSection", "sectionDef", "section", "sectionIdent", "transitionRules", 
			"transitionRule", "scaleRule", "chordRule", "noteRule", "scale", "sequence", 
			"chord", "symbol", "note"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'='", "'-'", "','", "':'", "';'", "'->'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, "MEASURE", "NATURAL", "MODIFIER", 
			"INTERVAL", "QUALITY", "STRING", "COMMENT", "SPACE", "OTHER"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "SheetMusic.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public SheetMusicParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ScriptContext extends ParserRuleContext {
		public SectionDefContext sectionDef() {
			return getRuleContext(SectionDefContext.class,0);
		}
		public ScriptContext script() {
			return getRuleContext(ScriptContext.class,0);
		}
		public RulesSectionContext rulesSection() {
			return getRuleContext(RulesSectionContext.class,0);
		}
		public ScriptContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_script; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterScript(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitScript(this);
		}
	}

	public final ScriptContext script() throws RecognitionException {
		ScriptContext _localctx = new ScriptContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_script);
		try {
			setState(34);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(30);
				sectionDef();
				setState(31);
				script();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(33);
				rulesSection();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RulesSectionContext extends ParserRuleContext {
		public RulesSectionContext rulesSection() {
			return getRuleContext(RulesSectionContext.class,0);
		}
		public List<SectionContext> section() {
			return getRuleContexts(SectionContext.class);
		}
		public SectionContext section(int i) {
			return getRuleContext(SectionContext.class,i);
		}
		public RulesSectionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rulesSection; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterRulesSection(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitRulesSection(this);
		}
	}

	public final RulesSectionContext rulesSection() throws RecognitionException {
		RulesSectionContext _localctx = new RulesSectionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_rulesSection);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(37); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(36);
					section();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(39); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(41);
			rulesSection();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SectionDefContext extends ParserRuleContext {
		public SectionIdentContext sectionIdent() {
			return getRuleContext(SectionIdentContext.class,0);
		}
		public List<TerminalNode> MEASURE() { return getTokens(SheetMusicParser.MEASURE); }
		public TerminalNode MEASURE(int i) {
			return getToken(SheetMusicParser.MEASURE, i);
		}
		public SectionDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sectionDef; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterSectionDef(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitSectionDef(this);
		}
	}

	public final SectionDefContext sectionDef() throws RecognitionException {
		SectionDefContext _localctx = new SectionDefContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_sectionDef);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(43);
			sectionIdent();
			setState(44);
			match(T__0);
			setState(45);
			match(MEASURE);
			setState(46);
			match(T__1);
			setState(47);
			match(MEASURE);
			setState(48);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SectionContext extends ParserRuleContext {
		public SectionIdentContext sectionIdent() {
			return getRuleContext(SectionIdentContext.class,0);
		}
		public TransitionRulesContext transitionRules() {
			return getRuleContext(TransitionRulesContext.class,0);
		}
		public SectionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_section; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterSection(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitSection(this);
		}
	}

	public final SectionContext section() throws RecognitionException {
		SectionContext _localctx = new SectionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_section);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(50);
			sectionIdent();
			setState(51);
			match(T__3);
			setState(52);
			transitionRules();
			setState(53);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SectionIdentContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(SheetMusicParser.STRING, 0); }
		public SectionIdentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sectionIdent; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterSectionIdent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitSectionIdent(this);
		}
	}

	public final SectionIdentContext sectionIdent() throws RecognitionException {
		SectionIdentContext _localctx = new SectionIdentContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_sectionIdent);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(55);
			match(STRING);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TransitionRulesContext extends ParserRuleContext {
		public TransitionRulesContext transitionRules() {
			return getRuleContext(TransitionRulesContext.class,0);
		}
		public List<TransitionRuleContext> transitionRule() {
			return getRuleContexts(TransitionRuleContext.class);
		}
		public TransitionRuleContext transitionRule(int i) {
			return getRuleContext(TransitionRuleContext.class,i);
		}
		public TransitionRulesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_transitionRules; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterTransitionRules(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitTransitionRules(this);
		}
	}

	public final TransitionRulesContext transitionRules() throws RecognitionException {
		TransitionRulesContext _localctx = new TransitionRulesContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_transitionRules);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(58); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(57);
					transitionRule();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(60); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(62);
			transitionRules();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TransitionRuleContext extends ParserRuleContext {
		public ScaleRuleContext scaleRule() {
			return getRuleContext(ScaleRuleContext.class,0);
		}
		public ChordRuleContext chordRule() {
			return getRuleContext(ChordRuleContext.class,0);
		}
		public NoteRuleContext noteRule() {
			return getRuleContext(NoteRuleContext.class,0);
		}
		public TransitionRuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_transitionRule; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterTransitionRule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitTransitionRule(this);
		}
	}

	public final TransitionRuleContext transitionRule() throws RecognitionException {
		TransitionRuleContext _localctx = new TransitionRuleContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_transitionRule);
		try {
			setState(67);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(64);
				scaleRule();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(65);
				chordRule();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(66);
				noteRule();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ScaleRuleContext extends ParserRuleContext {
		public List<ScaleContext> scale() {
			return getRuleContexts(ScaleContext.class);
		}
		public ScaleContext scale(int i) {
			return getRuleContext(ScaleContext.class,i);
		}
		public ScaleRuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scaleRule; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterScaleRule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitScaleRule(this);
		}
	}

	public final ScaleRuleContext scaleRule() throws RecognitionException {
		ScaleRuleContext _localctx = new ScaleRuleContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_scaleRule);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			scale();
			setState(70);
			match(T__5);
			setState(71);
			scale();
			setState(72);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ChordRuleContext extends ParserRuleContext {
		public List<ChordContext> chord() {
			return getRuleContexts(ChordContext.class);
		}
		public ChordContext chord(int i) {
			return getRuleContext(ChordContext.class,i);
		}
		public ChordRuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_chordRule; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterChordRule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitChordRule(this);
		}
	}

	public final ChordRuleContext chordRule() throws RecognitionException {
		ChordRuleContext _localctx = new ChordRuleContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_chordRule);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(74);
			chord();
			setState(75);
			match(T__5);
			setState(76);
			chord();
			setState(77);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NoteRuleContext extends ParserRuleContext {
		public List<SequenceContext> sequence() {
			return getRuleContexts(SequenceContext.class);
		}
		public SequenceContext sequence(int i) {
			return getRuleContext(SequenceContext.class,i);
		}
		public NoteRuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_noteRule; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterNoteRule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitNoteRule(this);
		}
	}

	public final NoteRuleContext noteRule() throws RecognitionException {
		NoteRuleContext _localctx = new NoteRuleContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_noteRule);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(79);
			sequence();
			setState(80);
			match(T__5);
			setState(81);
			sequence();
			setState(82);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ScaleContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(SheetMusicParser.STRING, 0); }
		public ScaleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scale; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterScale(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitScale(this);
		}
	}

	public final ScaleContext scale() throws RecognitionException {
		ScaleContext _localctx = new ScaleContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_scale);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(84);
			match(STRING);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SequenceContext extends ParserRuleContext {
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public List<NoteContext> note() {
			return getRuleContexts(NoteContext.class);
		}
		public NoteContext note(int i) {
			return getRuleContext(NoteContext.class,i);
		}
		public SequenceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sequence; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterSequence(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitSequence(this);
		}
	}

	public final SequenceContext sequence() throws RecognitionException {
		SequenceContext _localctx = new SequenceContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_sequence);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(87); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(86);
					note(0);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(89); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(91);
			sequence();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ChordContext extends ParserRuleContext {
		public NoteContext note() {
			return getRuleContext(NoteContext.class,0);
		}
		public SymbolContext symbol() {
			return getRuleContext(SymbolContext.class,0);
		}
		public ChordContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_chord; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterChord(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitChord(this);
		}
	}

	public final ChordContext chord() throws RecognitionException {
		ChordContext _localctx = new ChordContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_chord);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			note(0);
			setState(94);
			symbol();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SymbolContext extends ParserRuleContext {
		public SymbolContext symbol() {
			return getRuleContext(SymbolContext.class,0);
		}
		public List<TerminalNode> QUALITY() { return getTokens(SheetMusicParser.QUALITY); }
		public TerminalNode QUALITY(int i) {
			return getToken(SheetMusicParser.QUALITY, i);
		}
		public List<TerminalNode> INTERVAL() { return getTokens(SheetMusicParser.INTERVAL); }
		public TerminalNode INTERVAL(int i) {
			return getToken(SheetMusicParser.INTERVAL, i);
		}
		public SymbolContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_symbol; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterSymbol(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitSymbol(this);
		}
	}

	public final SymbolContext symbol() throws RecognitionException {
		SymbolContext _localctx = new SymbolContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_symbol);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(98); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(96);
					match(QUALITY);
					setState(97);
					match(INTERVAL);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(100); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(102);
			symbol();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NoteContext extends ParserRuleContext {
		public TerminalNode NATURAL() { return getToken(SheetMusicParser.NATURAL, 0); }
		public NoteContext note() {
			return getRuleContext(NoteContext.class,0);
		}
		public TerminalNode MODIFIER() { return getToken(SheetMusicParser.MODIFIER, 0); }
		public NoteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_note; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).enterNote(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof SheetMusicListener ) ((SheetMusicListener)listener).exitNote(this);
		}
	}

	public final NoteContext note() throws RecognitionException {
		return note(0);
	}

	private NoteContext note(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		NoteContext _localctx = new NoteContext(_ctx, _parentState);
		NoteContext _prevctx = _localctx;
		int _startState = 28;
		enterRecursionRule(_localctx, 28, RULE_note, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(105);
			match(NATURAL);
			}
			_ctx.stop = _input.LT(-1);
			setState(111);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new NoteContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_note);
					setState(107);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(108);
					match(MODIFIER);
					}
					} 
				}
				setState(113);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 14:
			return note_sempred((NoteContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean note_sempred(NoteContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\21u\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4"+
		"\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\3\2\3\2\3\2\3\2\5\2%\n\2"+
		"\3\3\6\3(\n\3\r\3\16\3)\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3"+
		"\5\3\5\3\5\3\6\3\6\3\7\6\7=\n\7\r\7\16\7>\3\7\3\7\3\b\3\b\3\b\5\bF\n\b"+
		"\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\f"+
		"\3\f\3\r\6\rZ\n\r\r\r\16\r[\3\r\3\r\3\16\3\16\3\16\3\17\3\17\6\17e\n\17"+
		"\r\17\16\17f\3\17\3\17\3\20\3\20\3\20\3\20\3\20\7\20p\n\20\f\20\16\20"+
		"s\13\20\3\20\2\3\36\21\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36\2\2\2m\2"+
		"$\3\2\2\2\4\'\3\2\2\2\6-\3\2\2\2\b\64\3\2\2\2\n9\3\2\2\2\f<\3\2\2\2\16"+
		"E\3\2\2\2\20G\3\2\2\2\22L\3\2\2\2\24Q\3\2\2\2\26V\3\2\2\2\30Y\3\2\2\2"+
		"\32_\3\2\2\2\34d\3\2\2\2\36j\3\2\2\2 !\5\6\4\2!\"\5\2\2\2\"%\3\2\2\2#"+
		"%\5\4\3\2$ \3\2\2\2$#\3\2\2\2%\3\3\2\2\2&(\5\b\5\2\'&\3\2\2\2()\3\2\2"+
		"\2)\'\3\2\2\2)*\3\2\2\2*+\3\2\2\2+,\5\4\3\2,\5\3\2\2\2-.\5\n\6\2./\7\3"+
		"\2\2/\60\7\t\2\2\60\61\7\4\2\2\61\62\7\t\2\2\62\63\7\5\2\2\63\7\3\2\2"+
		"\2\64\65\5\n\6\2\65\66\7\6\2\2\66\67\5\f\7\2\678\7\7\2\28\t\3\2\2\29:"+
		"\7\16\2\2:\13\3\2\2\2;=\5\16\b\2<;\3\2\2\2=>\3\2\2\2><\3\2\2\2>?\3\2\2"+
		"\2?@\3\2\2\2@A\5\f\7\2A\r\3\2\2\2BF\5\20\t\2CF\5\22\n\2DF\5\24\13\2EB"+
		"\3\2\2\2EC\3\2\2\2ED\3\2\2\2F\17\3\2\2\2GH\5\26\f\2HI\7\b\2\2IJ\5\26\f"+
		"\2JK\7\5\2\2K\21\3\2\2\2LM\5\32\16\2MN\7\b\2\2NO\5\32\16\2OP\7\5\2\2P"+
		"\23\3\2\2\2QR\5\30\r\2RS\7\b\2\2ST\5\30\r\2TU\7\5\2\2U\25\3\2\2\2VW\7"+
		"\16\2\2W\27\3\2\2\2XZ\5\36\20\2YX\3\2\2\2Z[\3\2\2\2[Y\3\2\2\2[\\\3\2\2"+
		"\2\\]\3\2\2\2]^\5\30\r\2^\31\3\2\2\2_`\5\36\20\2`a\5\34\17\2a\33\3\2\2"+
		"\2bc\7\r\2\2ce\7\f\2\2db\3\2\2\2ef\3\2\2\2fd\3\2\2\2fg\3\2\2\2gh\3\2\2"+
		"\2hi\5\34\17\2i\35\3\2\2\2jk\b\20\1\2kl\7\n\2\2lq\3\2\2\2mn\f\3\2\2np"+
		"\7\13\2\2om\3\2\2\2ps\3\2\2\2qo\3\2\2\2qr\3\2\2\2r\37\3\2\2\2sq\3\2\2"+
		"\2\t$)>E[fq";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}