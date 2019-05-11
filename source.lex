%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "source.hpp"

#define TAB   0x09
#define LF    0x0A
#define CR    0x0D

int comment_lines = 1;
char * curr_str = NULL;

static void error(char * c_name) {
  printf("Error %s\n", c_name);
  exit(0);
}

%}

%option yylineno
%option noyywrap


ws                          ([\r\n\t ])
digit                       ([0-9])
letter                      ([a-zA-Z])
hex_digit                   ([0-9a-fA-F])
hex_num                     ([\+\-]?0x{hex_digit}+)
printable_char              ([\x20-\x7E\x09\x0A\x0D])
identifier_char             ({digit}|{letter}|[\-_])
ascii_escape_seq            (\\({hex_digit}){1,6})
num                         ({digit}+)
s_num                       ([\+\-]?{num})
rgb_num                     ({ws}*{s_num}{ws}*)
printable_in_comment        ([\x20-\x29\x2B-\x2E\x30-\x7E\t\r])
printable_str_c             ([\x20-\x21\x23-\x5B\x5D-\x7E\x09])
printable_str_c_f           ([\x20-\x26\x28-\x5B\x5D-\x7E\x09])
esc_seq_no_lf               ((\\r)|(\\t)|(\\\\)|{ascii_escape_seq})
esc_seq                     ((\\n)|{esc_seq_no_lf})

%%

void                        return VOID;
int                         return INT;
byte                        return BYTE;
b                           return B;
bool                        return BOOL;
and                         return AND;
or                          return OR;
not                         return NOT;
true                        return TRUE;
false                       return FALSE;
return                      return RETURN;
if                          return IF;
else                        return ELSE;
while                       return WHILE;
break                       return BREAK;
continue                    return CONTINUE;
@pre                        return PRECOND;
;                           return SC;
,                           return COMMA;
(                           return LPAREN;
)                           return RPAREN;
{                           return LBRACE;
}                           return RBRACE;
=                           return ASSIGN;
==|!=|<|>|<=|>=             return RELOP;
+|-|*|/                     return BINOP;
[a-zA-Z][a-zA-Z0-9]*        return ID;
0|[1-9][1-9]*               return NUM;
"([^\n\r\"\\]|\\[rnt"\\])+" return STRING;

?[n\r|\n|\r]*[ \n\r//[^\    ;
{ws}                        ;
<<EOF>> {return EF;}

.                           error(yytext);

%%
