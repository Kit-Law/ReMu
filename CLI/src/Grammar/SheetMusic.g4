grammar SheetMusic;

script
 : sectionDef* rulesSection
 ;

rulesSection
 : section+
 ;

sectionDef
 : sectionIdent '=' NUMBER '-' NUMBER';'
 ;

section
 : sectionIdent':' transitionRule+
 ;

sectionIdent
 : STRING
 ;

transitionRule
 : scaleRule
 | chordRule
 | noteRule
 ;

scaleRule
 : scale '->' scale','
 ;

chordRule
 : chord '->' chord','
 ;

noteRule
 : sequence '->' sequence','
 ;

scale
 : note SCALE
 ;

sequence
 : note+
 ;

chord
 : note symbol additions*
 ;

symbol
 : QUALITY NUMBER
 | QUALITY
 ;

additions
 : ADDITIONS note;

note
 : NATURAL
 | NATURAL ACCIDENTAL
 | NUMBER
 | NUMBER ACCIDENTAL
 ;

NUMBER     : [0-9]+;
NATURAL    : [A-G];
ACCIDENTAL : 'b' | 'bb' | 'bbb' | '###' | '##' | '#';
QUALITY    : 'maj' | 'min' | 'dim' | 'aug' | 'alt' | 'M' | 'm' | '+' | '-' | '/';
ADDITIONS  : 'sus' | 'add' | 'omit';

STRING
 : '"' (~["\r\n] | '""')* '"'
 ;

SCALE
 : ([a-zA-Z])+ ' scale'
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