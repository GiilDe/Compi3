%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "source.hpp"
#include "cmake-build-debug-cygwin/parser.tab.hpp"

#define TAB   0x09
#define LF    0x0A
#define CR    0x0D


static void error(char * c_name) {
  printf("Error %s\n", c_name);
  exit(0);
}

%}

%option yylineno
%option noyywrap

ws                              ([\r\n\t ])

%%

void                            { yylval = new stack_data(VOID, ""); return VOID; }
int                             return INT;
byte                            return BYTE;
b                               return B;
bool                            return BOOL;
and                             return AND;
or                              return OR;
not                             return NOT;
true                            return TRUE;
false                           return FALSE;
return                          return RETURN;
if                              return IF;
else                            return ELSE;
while                           return WHILE;
break                           return BREAK;
continue                        return CONTINUE;
@pre                            return PRECOND;
;                               return SC;
,                               return COMMA;
\(                              return LPAREN;
\)                              return RPAREN;
\{                              return LBRACE;
\}                              return RBRACE;
=                               return ASSIGN;
==|!=|<|>|<=|>=                 return RELOP;
\+|\-|\*|\/                     return BINOP;
[a-zA-Z][a-zA-Z0-9]*            { yylval = new stack_data(VOID, yytext); return ID; }
0|[1-9][0-9]*                   return NUM;
\"([^\n\r\"\\]|\\[rnt"\\])+\"   return STRING;

\/\/[^\r\n]*[\r|\n|\r\n]?       ;
{ws}                            ;

.                               error(yytext);

%%

