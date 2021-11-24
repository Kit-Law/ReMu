// Generated from SheetMusic.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link SheetMusicParser}.
 */
public interface SheetMusicListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#script}.
	 * @param ctx the parse tree
	 */
	void enterScript(SheetMusicParser.ScriptContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#script}.
	 * @param ctx the parse tree
	 */
	void exitScript(SheetMusicParser.ScriptContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#rulesSection}.
	 * @param ctx the parse tree
	 */
	void enterRulesSection(SheetMusicParser.RulesSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#rulesSection}.
	 * @param ctx the parse tree
	 */
	void exitRulesSection(SheetMusicParser.RulesSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#sectionDef}.
	 * @param ctx the parse tree
	 */
	void enterSectionDef(SheetMusicParser.SectionDefContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#sectionDef}.
	 * @param ctx the parse tree
	 */
	void exitSectionDef(SheetMusicParser.SectionDefContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#section}.
	 * @param ctx the parse tree
	 */
	void enterSection(SheetMusicParser.SectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#section}.
	 * @param ctx the parse tree
	 */
	void exitSection(SheetMusicParser.SectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#sectionIdent}.
	 * @param ctx the parse tree
	 */
	void enterSectionIdent(SheetMusicParser.SectionIdentContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#sectionIdent}.
	 * @param ctx the parse tree
	 */
	void exitSectionIdent(SheetMusicParser.SectionIdentContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#transitionRules}.
	 * @param ctx the parse tree
	 */
	void enterTransitionRules(SheetMusicParser.TransitionRulesContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#transitionRules}.
	 * @param ctx the parse tree
	 */
	void exitTransitionRules(SheetMusicParser.TransitionRulesContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#transitionRule}.
	 * @param ctx the parse tree
	 */
	void enterTransitionRule(SheetMusicParser.TransitionRuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#transitionRule}.
	 * @param ctx the parse tree
	 */
	void exitTransitionRule(SheetMusicParser.TransitionRuleContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#scaleRule}.
	 * @param ctx the parse tree
	 */
	void enterScaleRule(SheetMusicParser.ScaleRuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#scaleRule}.
	 * @param ctx the parse tree
	 */
	void exitScaleRule(SheetMusicParser.ScaleRuleContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#chordRule}.
	 * @param ctx the parse tree
	 */
	void enterChordRule(SheetMusicParser.ChordRuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#chordRule}.
	 * @param ctx the parse tree
	 */
	void exitChordRule(SheetMusicParser.ChordRuleContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#noteRule}.
	 * @param ctx the parse tree
	 */
	void enterNoteRule(SheetMusicParser.NoteRuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#noteRule}.
	 * @param ctx the parse tree
	 */
	void exitNoteRule(SheetMusicParser.NoteRuleContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#scale}.
	 * @param ctx the parse tree
	 */
	void enterScale(SheetMusicParser.ScaleContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#scale}.
	 * @param ctx the parse tree
	 */
	void exitScale(SheetMusicParser.ScaleContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#sequence}.
	 * @param ctx the parse tree
	 */
	void enterSequence(SheetMusicParser.SequenceContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#sequence}.
	 * @param ctx the parse tree
	 */
	void exitSequence(SheetMusicParser.SequenceContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#chord}.
	 * @param ctx the parse tree
	 */
	void enterChord(SheetMusicParser.ChordContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#chord}.
	 * @param ctx the parse tree
	 */
	void exitChord(SheetMusicParser.ChordContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#symbol}.
	 * @param ctx the parse tree
	 */
	void enterSymbol(SheetMusicParser.SymbolContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#symbol}.
	 * @param ctx the parse tree
	 */
	void exitSymbol(SheetMusicParser.SymbolContext ctx);
	/**
	 * Enter a parse tree produced by {@link SheetMusicParser#note}.
	 * @param ctx the parse tree
	 */
	void enterNote(SheetMusicParser.NoteContext ctx);
	/**
	 * Exit a parse tree produced by {@link SheetMusicParser#note}.
	 * @param ctx the parse tree
	 */
	void exitNote(SheetMusicParser.NoteContext ctx);
}