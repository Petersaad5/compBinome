grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' declaration* affectation* '{' return_stmt '}' ;

declaration : 'int' ID ('=' CONST)? ';' ;
affectation : ID '=' CONST ';' ;

ID : [a-zA-Z_][a-zA-Z_0-9]* ;

return_stmt: RETURN CONST ';' ;

RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
