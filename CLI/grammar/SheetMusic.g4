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
 : note symbol
 ;

symbol
 : (QUALITY NUMBER)+
 | QUALITY
 ;

note
 : NATURAL
 | NATURAL MODIFIER
 ;

NUMBER    : [0-9]+;
NATURAL    : [A-G];
MODIFIER   : 'b' | '#';
INTERVAL   : [1-9][1-3];
QUALITY    : 'maj' | 'min' | 'dim' | 'aug' | 'sus' | 'alt' | 'M' | 'm' | '+' | '-' | '/';

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