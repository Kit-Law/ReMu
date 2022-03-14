grammar SheetMusic;

script
 : (sectionDef | userDef)* rulesSection
 ;

sectionDef
 : sectionIdent '=' NUMBER '-' NUMBER';'
 ;

userDef
 : (scaleDef | chordDef)+
 ;

scaleDef
 : '\\addScale' WORD '{' (NUMBER ',')* NUMBER '}'
 ;

chordDef
 : '\\addChord' WORD '{' (pitch ',')* pitch '}'
 ;

rulesSection
 : section+
 ;

section
 : sectionIdent':' (transitionRule | instrument)+
 ;

sectionIdent
 : STRING
 ;

instrument
 : WORD '{' transitionRule+ '}'
 ;

transitionRule
 : scaleRule
 | occurrenceRule
 | sequenceRule
 ;

scaleRule
 : 'Scale:' scale '->' scale','
 | 'Scale:' scale','
 ;

scale
 : pitch WORD
 ;

occurrenceRule
 : 'Occurrance' NUMBER ':' sequenceRule
 ;

sequenceRule
 : sequence '->' sequence','
 ;

sequence
 : (note | chord | '(' chord ')')+
 ;

chord
 : pitch symbol additions* ('[' NUMBER ']')?
 | '{' (pitch ',')* pitch '}'
 | pitch WORD
 ;

symbol
 : QUALITY NUMBER
 | QUALITY
 ;

additions
 : ADDITIONS pitch;

pitch
 : NATURAL
 | NATURAL ACCIDENTAL
 | NUMBER
 | NUMBER ACCIDENTAL
 ;

note
 : pitch NUMBER? ('[' NUMBER ']')?
 ;

NUMBER     : [0-9]+
           | [0-9]+ '.' [0-9]*
           | '.' [0-9]+ ;
NATURAL    : [A-G] | '_';
ACCIDENTAL : 'b' | 'bb' | 'bbb' | '###' | '##' | '#';
QUALITY    : 'maj' | 'min' | 'dim' | 'aug' | 'alt' | 'M' | 'm' | '+' | '-' | '/';
ADDITIONS  : 'sus' | 'add' | 'omit';

STRING
 : '"' (~["\r\n] | '""')* '"'
 ;

WORD
 : ([a-zA-Z])+
 ;

COMMENT
 : '//' ~[\r\n]* -> skip
 ;

SPACE
 : [ \t\r\n] -> skip
 ;

OTHER
 : .
 ;