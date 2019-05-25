/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     INT = 259,
     BYTE = 260,
     B = 261,
     BOOL = 262,
     OR = 263,
     AND = 264,
     NOT = 265,
     TRUE = 266,
     FALSE = 267,
     RETURN = 268,
     IF = 269,
     ELSE = 270,
     WHILE = 271,
     BREAK = 272,
     CONTINUE = 273,
     PRECOND = 274,
     SC = 275,
     COMMA = 276,
     LPAREN = 277,
     RPAREN = 278,
     LBRACE = 279,
     RBRACE = 280,
     ASSIGN = 281,
     RELOP = 282,
     BINOP = 283,
     ID = 284,
     NUM = 285,
     STRING = 286,
     EF = 287
   };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define BYTE 260
#define B 261
#define BOOL 262
#define OR 263
#define AND 264
#define NOT 265
#define TRUE 266
#define FALSE 267
#define RETURN 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define BREAK 272
#define CONTINUE 273
#define PRECOND 274
#define SC 275
#define COMMA 276
#define LPAREN 277
#define RPAREN 278
#define LBRACE 279
#define RBRACE 280
#define ASSIGN 281
#define RELOP 282
#define BINOP 283
#define ID 284
#define NUM 285
#define STRING 286
#define EF 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

