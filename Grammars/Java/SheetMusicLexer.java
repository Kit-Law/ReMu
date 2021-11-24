// Generated from SheetMusic.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class SheetMusicLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, MEASURE=7, NATURAL=8, 
		MODIFIER=9, INTERVAL=10, QUALITY=11, STRING=12, COMMENT=13, SPACE=14, 
		OTHER=15;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "MEASURE", "NATURAL", 
			"MODIFIER", "INTERVAL", "QUALITY", "STRING", "COMMENT", "SPACE", "OTHER"
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


	public SheetMusicLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "SheetMusic.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\21f\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\3\2\3\2\3\3\3\3\3\4"+
		"\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\13"+
		"\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3"+
		"\f\3\f\5\fK\n\f\3\r\3\r\3\r\3\r\7\rQ\n\r\f\r\16\rT\13\r\3\r\3\r\3\16\3"+
		"\16\7\16Z\n\16\f\16\16\16]\13\16\3\16\3\16\3\17\3\17\3\17\3\17\3\20\3"+
		"\20\2\2\21\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33"+
		"\17\35\20\37\21\3\2\n\3\2CI\4\2%%dd\3\2\63;\3\2\63\65\7\2--//\61\61OO"+
		"oo\5\2\f\f\17\17$$\4\2\f\f\17\17\5\2\13\f\17\17\"\"\2n\2\3\3\2\2\2\2\5"+
		"\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2"+
		"\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33"+
		"\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\3!\3\2\2\2\5#\3\2\2\2\7%\3\2\2\2\t"+
		"\'\3\2\2\2\13)\3\2\2\2\r+\3\2\2\2\17.\3\2\2\2\21\60\3\2\2\2\23\62\3\2"+
		"\2\2\25\64\3\2\2\2\27J\3\2\2\2\31L\3\2\2\2\33W\3\2\2\2\35`\3\2\2\2\37"+
		"d\3\2\2\2!\"\7?\2\2\"\4\3\2\2\2#$\7/\2\2$\6\3\2\2\2%&\7.\2\2&\b\3\2\2"+
		"\2\'(\7<\2\2(\n\3\2\2\2)*\7=\2\2*\f\3\2\2\2+,\7/\2\2,-\7@\2\2-\16\3\2"+
		"\2\2./\5\31\r\2/\20\3\2\2\2\60\61\t\2\2\2\61\22\3\2\2\2\62\63\t\3\2\2"+
		"\63\24\3\2\2\2\64\65\t\4\2\2\65\66\t\5\2\2\66\26\3\2\2\2\678\7o\2\289"+
		"\7c\2\29K\7l\2\2:;\7o\2\2;<\7k\2\2<K\7p\2\2=>\7f\2\2>?\7k\2\2?K\7o\2\2"+
		"@A\7c\2\2AB\7w\2\2BK\7i\2\2CD\7u\2\2DE\7w\2\2EK\7u\2\2FG\7c\2\2GH\7n\2"+
		"\2HK\7v\2\2IK\t\6\2\2J\67\3\2\2\2J:\3\2\2\2J=\3\2\2\2J@\3\2\2\2JC\3\2"+
		"\2\2JF\3\2\2\2JI\3\2\2\2K\30\3\2\2\2LR\7$\2\2MQ\n\7\2\2NO\7$\2\2OQ\7$"+
		"\2\2PM\3\2\2\2PN\3\2\2\2QT\3\2\2\2RP\3\2\2\2RS\3\2\2\2SU\3\2\2\2TR\3\2"+
		"\2\2UV\7$\2\2V\32\3\2\2\2W[\7%\2\2XZ\n\b\2\2YX\3\2\2\2Z]\3\2\2\2[Y\3\2"+
		"\2\2[\\\3\2\2\2\\^\3\2\2\2][\3\2\2\2^_\b\16\2\2_\34\3\2\2\2`a\t\t\2\2"+
		"ab\3\2\2\2bc\b\17\2\2c\36\3\2\2\2de\13\2\2\2e \3\2\2\2\7\2JPR[\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}