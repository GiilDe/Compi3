%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "output.hpp"
#include "source.hpp"
#include "parser.tab.hpp"

using namespace output;

static void error(char * c_name) {
  printf("Error %s\n", c_name);
  exit(0);
}

%}

%option yylineno
%option noyywrap

ws                              ([\r\n\t ])

%%


void                            {
                                    yylval = new Type(VOID);
                                    return VOID;
                                }
int                             {
                                    yylval = new Type(INT);
                                    return INT;
                                }
byte                            {
                                    yylval = new Type(BYTE);
                                    return BYTE;
                                }
b                               return B;
bool                            {
                                    yylval = new Type(BOOL);
                                    return BOOL;
                                }
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
[a-zA-Z][a-zA-Z0-9]*            {
                                    yylval = new Id(yytext);
                                    return ID;
                                }
0|[1-9][0-9]*                   {
                                    yylval = new Id(yytext);
                                    return NUM;
                                }
\"([^\n\r\"\\]|\\[rnt"\\])+\"   {
                                    yylval = new Type(STRING);
                                    return STRING;
                                }

\/\/[^\r\n]*[\r|\n|\r\n]?       ;
{ws}                            ;
<<EOF>> {return EF;}
.                               errorLex(yylineno);

%%

