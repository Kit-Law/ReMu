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
 | flags
 ;

scaleRule
 : 'Scale:' scale '->' scale','
 | 'Scale:' scale','
 ;

scale
 : pitch WORD
 ;

occurrenceRule
 : 'Occurrence' NUMBER ':' sequenceRule
 ;

sequenceRule
 : sequence '->' sequence','
 ;

sequence
 : (note | chord | '(' chord ')' | rest)+
 ;

chord
 : pitch symbol additions* ('[' NUMBER ']')?
// | '{' (pitch ',')* pitch '}'
 ;

symbol
 : WORD
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
 
rest
 : '[' NUMBER ']'
 ;

flags
 : '\\ScaleEffectsChords'
 ;

NUMBER     : [0-9]+;
NATURAL    : [A-G] | '_';
ACCIDENTAL : 'b' | 'bb' | 'bbb' | '###' | '##' | '#';
//QUALITY    : 'maj' | 'M' | 'maj7' | 'M7' | 'maj6' | 'M6' | 'min' | 'm' | 'min7' | 'm7' | 'min6' | 'm6' | 'dim' | '°' | 'dim7' | '°7' | 'dom7' | 'aug' | 'alt' | 'sus4' | 'sus2';
ADDITIONS  : 'add' | 'omit';

STRING
 : '"' (~["\r\n] | '""')* '"'
 ;

WORD
 : ([a-zA-Z])+([a-zA-Z0-9])+
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