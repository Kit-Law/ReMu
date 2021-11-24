grammar SheetMusic;

script
 : sectionDef script
 | rulesSection
 ;

rulesSection
 : section+ rulesSection
 ;

sectionDef 
 : sectionIdent '=' MEASURE '-' MEASURE','
 ;

section 
 : sectionIdent':' transitionRules';'
 ;

sectionIdent
 : STRING
 ;

transitionRules
 : transitionRule+ transitionRules
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
 : STRING
 ;

sequence
 : note+ sequence
 ;

chord
 : note symbol
 ;

symbol
 : (QUALITY INTERVAL)+ symbol
 ;

note
 : NATURAL
 | note MODIFIER
 ;

MEASURE    : STRING;
NATURAL    : [A-G];
MODIFIER   : 'b' | '#';
INTERVAL   : [1-9][1-3];
QUALITY    : 'maj' | 'min' | 'dim' | 'aug' | 'sus' | 'alt' | 'M' | 'm' | '+' | '-' | '/';

STRING
 : '"' (~["\r\n] | '""')* '"'
 ;

COMMENT
 : '#' ~[\r\n]* -> skip
 ;

SPACE
 : [ \t\r\n] -> skip
 ;

OTHER
 : . 
 ;