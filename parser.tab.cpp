/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     STRING = 286
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




/* Copy the first part of user declarations.  */
#line 1 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"

    #include "parser.h"


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 172 "/Users/miki/Desktop/Compilation/hw3/cmake-build-debug/parser.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    10,    21,    23,    25,
      26,    28,    30,    34,    37,    38,    41,    46,    48,    51,
      53,    55,    61,    62,    69,    77,    78,    79,    87,    89,
      97,    98,    99,   107,   108,   113,   117,   123,   128,   131,
     134,   138,   141,   144,   149,   153,   155,   159,   161,   163,
     165,   169,   173,   175,   177,   179,   182,   184,   186,   188,
     191,   195,   199
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    34,    -1,    -1,    35,    34,    -1,    -1,
      37,    29,    22,    36,    38,    23,    41,    24,    43,    25,
      -1,    56,    -1,     3,    -1,    -1,    39,    -1,    40,    -1,
      40,    21,    39,    -1,    56,    29,    -1,    -1,    41,    42,
      -1,    19,    22,    57,    23,    -1,    44,    -1,    43,    44,
      -1,    45,    -1,    49,    -1,    14,    22,    57,    23,    52,
      -1,    -1,    14,    46,    22,    57,    23,    45,    -1,    14,
      22,    57,    23,    49,    15,    45,    -1,    -1,    -1,    16,
      47,    22,    57,    23,    48,    45,    -1,    52,    -1,    14,
      22,    57,    23,    49,    15,    49,    -1,    -1,    -1,    16,
      22,    50,    57,    23,    51,    49,    -1,    -1,    24,    53,
      43,    25,    -1,    56,    29,    20,    -1,    56,    29,    26,
      57,    20,    -1,    29,    26,    57,    20,    -1,    54,    20,
      -1,    13,    20,    -1,    13,    57,    20,    -1,    17,    20,
      -1,    18,    20,    -1,    29,    22,    55,    23,    -1,    29,
      22,    23,    -1,    57,    -1,    57,    21,    55,    -1,     4,
      -1,     5,    -1,     7,    -1,    22,    57,    23,    -1,    57,
      28,    57,    -1,    29,    -1,    54,    -1,    30,    -1,    30,
       6,    -1,    31,    -1,    11,    -1,    12,    -1,    10,    57,
      -1,    57,     9,    57,    -1,    57,     8,    57,    -1,    57,
      27,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    41,    42,    45,    45,    56,    59,    64,
      66,    75,    81,    91,    97,    98,   101,   105,   106,   109,
     110,   113,   116,   116,   119,   122,   122,   122,   126,   127,
     130,   130,   130,   134,   134,   136,   139,   142,   143,   144,
     148,   152,   158,   166,   169,   173,   174,   177,   180,   183,
     187,   190,   200,   206,   207,   210,   216,   219,   222,   225,
     230,   236,   242
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL", "OR",
  "AND", "NOT", "TRUE", "FALSE", "RETURN", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "PRECOND", "SC", "COMMA", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "ASSIGN", "RELOP", "BINOP", "ID", "NUM", "STRING", "$accept",
  "Program", "Funcs", "FuncDecl", "@1", "RetType", "Formals",
  "FormalsList", "FormalDecl", "PreConditions", "PreCondition",
  "Statements", "Statement", "Open_statement", "@2", "@3", "@4",
  "Closed_statement", "@5", "@6", "Simple_statement", "@7", "Call",
  "ExpList", "Type", "Exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    36,    35,    37,    37,    38,
      38,    39,    39,    40,    41,    41,    42,    43,    43,    44,
      44,    45,    46,    45,    45,    47,    48,    45,    49,    49,
      50,    51,    49,    53,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    54,    54,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,    10,     1,     1,     0,
       1,     1,     3,     2,     0,     2,     4,     1,     2,     1,
       1,     5,     0,     6,     7,     0,     0,     7,     1,     7,
       0,     0,     7,     0,     4,     3,     5,     4,     2,     2,
       3,     2,     2,     4,     3,     1,     3,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     1,     1,     1,     2,
       3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     8,    47,    48,    49,     0,     2,     3,     0,     7,
       1,     4,     0,     5,     9,     0,    10,    11,     0,    14,
       0,    13,     0,    12,     0,     0,    15,     0,     0,     0,
       0,     0,     0,    33,     0,     0,    17,    19,    20,    28,
       0,     0,     0,    57,    58,     0,    52,    54,    56,    53,
       0,    39,     0,     0,     0,    30,     0,    41,    42,     0,
       0,     0,     6,    18,    38,     0,    59,     0,    55,     0,
       0,    16,     0,     0,    40,     0,     0,     0,     0,     0,
      44,     0,    45,     0,    35,     0,    50,    61,    60,    62,
      51,     0,     0,     0,     0,    34,    43,     0,    37,     0,
       0,     0,     0,    21,     0,    31,    26,    46,    36,     0,
       0,     0,    25,    23,     0,     0,     0,    24,    29,     0,
      32,    27,     0,     0,     0,     0,     0,     0,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    14,     8,    15,    16,    17,    22,
      26,    35,    36,    37,    54,    56,   115,    38,    77,   114,
      39,    59,    49,    81,    41,    82
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
      67,   -99,   -99,   -99,   -99,     8,   -99,    67,    -8,   -99,
     -99,   -99,     4,   -99,   228,    15,   -99,    10,     0,   -99,
     228,   -99,    -1,   -99,    23,   100,   -99,   155,   128,    27,
      55,    37,    53,   -99,   -15,    51,   -99,   -99,   -99,   -99,
      62,    57,   155,   -99,   -99,   155,    72,    78,   -99,   -99,
     145,   -99,     5,   155,    84,   -99,    88,   -99,   -99,   100,
     133,   155,   -99,   -99,   -99,   -11,    35,   152,   -99,   155,
     155,   -99,   155,   155,   -99,   173,   155,   155,   155,    74,
     -99,    73,   162,    33,   -99,   155,   -99,    99,    35,    83,
     -99,   118,   179,   185,   195,   -99,   -99,   155,   -99,   189,
      90,    55,   104,   105,     6,   -99,   -99,   -99,   -99,   155,
     100,   106,   -99,   -99,   118,     6,   202,   -99,   -99,   155,
     -99,   -99,   118,   211,   115,   118,   118,   122,     6
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   114,   -99,   -99,   -99,   -99,   113,   -99,   -99,
     -99,    82,   -31,   -98,   -99,   -99,   -99,   -86,   -99,   -99,
     -88,   -99,   -25,    49,    95,   -26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -29
static const yytype_int16 yytable[] =
{
      40,    50,    52,   103,    63,   102,   113,    60,    10,    84,
      40,    61,   117,    69,    70,    85,    66,   121,    24,    67,
     111,    12,   112,    25,   118,    74,    13,    75,   120,    21,
     117,    20,    72,    73,    40,    83,   124,   103,    19,   127,
     118,    69,    70,    87,    88,    27,    89,    90,    63,    53,
      92,    93,    94,    98,    40,     2,     3,    57,     4,    99,
      72,    73,    72,    73,    28,    29,    40,    30,    31,    32,
       1,     2,     3,    58,     4,    33,    62,    55,     2,     3,
      34,     4,    64,   116,    68,    40,    65,    28,    29,    40,
      30,    31,    32,   123,    60,     9,    96,    40,    33,    95,
      40,    40,     9,    34,     2,     3,    76,     4,    70,    18,
      78,    73,   109,    28,    29,    18,    30,    31,    32,   110,
     -28,    11,     2,     3,    33,     4,    72,    73,   119,    34,
     126,    28,   100,    23,   101,    31,    32,   128,    42,    43,
      44,    79,    33,    42,    43,    44,   107,    34,    51,     0,
      45,     0,     0,    69,    70,    45,    80,    46,    47,    48,
      69,    70,    46,    47,    48,    42,    43,    44,    71,     0,
      69,    70,    72,    73,     0,    86,     0,    45,     0,    72,
      73,    69,    70,    97,    46,    47,    48,    69,    70,    72,
      73,     0,     0,    69,    70,     0,    91,    69,    70,     0,
      72,    73,   104,    69,    70,     0,    72,    73,   105,   108,
      69,    70,    72,    73,     0,     0,    72,    73,   106,    69,
      70,     0,    72,    73,     0,   122,     0,     0,     0,    72,
      73,     0,     2,     3,   125,     4,     0,     0,    72,    73
};

static const yytype_int16 yycheck[] =
{
      25,    27,    28,    91,    35,    91,   104,    22,     0,    20,
      35,    26,   110,     8,     9,    26,    42,   115,    19,    45,
      14,    29,    16,    24,   110,    20,    22,    53,   114,    29,
     128,    21,    27,    28,    59,    61,   122,   125,    23,   125,
     126,     8,     9,    69,    70,    22,    72,    73,    79,    22,
      76,    77,    78,    20,    79,     4,     5,    20,     7,    85,
      27,    28,    27,    28,    13,    14,    91,    16,    17,    18,
       3,     4,     5,    20,     7,    24,    25,    22,     4,     5,
      29,     7,    20,   109,     6,   110,    29,    13,    14,   114,
      16,    17,    18,   119,    22,     0,    23,   122,    24,    25,
     125,   126,     7,    29,     4,     5,    22,     7,     9,    14,
      22,    28,    22,    13,    14,    20,    16,    17,    18,    15,
      15,     7,     4,     5,    24,     7,    27,    28,    22,    29,
      15,    13,    14,    20,    16,    17,    18,    15,    10,    11,
      12,    59,    24,    10,    11,    12,    97,    29,    20,    -1,
      22,    -1,    -1,     8,     9,    22,    23,    29,    30,    31,
       8,     9,    29,    30,    31,    10,    11,    12,    23,    -1,
       8,     9,    27,    28,    -1,    23,    -1,    22,    -1,    27,
      28,     8,     9,    21,    29,    30,    31,     8,     9,    27,
      28,    -1,    -1,     8,     9,    -1,    23,     8,     9,    -1,
      27,    28,    23,     8,     9,    -1,    27,    28,    23,    20,
       8,     9,    27,    28,    -1,    -1,    27,    28,    23,     8,
       9,    -1,    27,    28,    -1,    23,    -1,    -1,    -1,    27,
      28,    -1,     4,     5,    23,     7,    -1,    -1,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,    33,    34,    35,    37,    56,
       0,    34,    29,    22,    36,    38,    39,    40,    56,    23,
      21,    29,    41,    39,    19,    24,    42,    22,    13,    14,
      16,    17,    18,    24,    29,    43,    44,    45,    49,    52,
      54,    56,    10,    11,    12,    22,    29,    30,    31,    54,
      57,    20,    57,    22,    46,    22,    47,    20,    20,    53,
      22,    26,    25,    44,    20,    29,    57,    57,     6,     8,
       9,    23,    27,    28,    20,    57,    22,    50,    22,    43,
      23,    55,    57,    57,    20,    26,    23,    57,    57,    57,
      57,    23,    57,    57,    57,    25,    23,    21,    20,    57,
      14,    16,    49,    52,    23,    23,    23,    55,    20,    22,
      15,    14,    16,    45,    51,    48,    57,    45,    49,    22,
      49,    45,    23,    57,    49,    23,    15,    49,    15
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 38 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyMainFunction(); ;}
    break;

  case 5:
#line 45 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {new_scope();;}
    break;

  case 6:
#line 46 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
                tokens ret_type = static_cast<tokens>(static_cast<Type*>((yyvsp[(1) - (10)]))->type);
                // tokens actual_ret_type = static_cast<tokens>(static_cast<Type*>($8)->type)

                string id = static_cast<Id*>((yyvsp[(2) - (10)]))->id;
                ParamsList* l = static_cast<ParamsList*>((yyvsp[(5) - (10)]));
                add_func(l->params, ret_type, id);
            ;}
    break;

  case 7:
#line 57 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(static_cast<Type*>((yyvsp[(1) - (1)]))->type); ;}
    break;

  case 8:
#line 60 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(VOID); ;}
    break;

  case 9:
#line 64 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new ParamsList(); ;}
    break;

  case 10:
#line 67 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
            (yyval) = new ParamsList();
            vector<int>& params = static_cast<ParamsList*>((yyval))->params;
            vector<int>& params_other = static_cast<ParamsList*>((yyvsp[(1) - (1)]))->params;
            params = params_other;
		;}
    break;

  case 11:
#line 76 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
                (yyval) = new ParamsList();
                Type* t = static_cast<Type*>((yyvsp[(1) - (1)]));
                static_cast<ParamsList*>((yyval))->params.push_back(t->type);
            ;}
    break;

  case 12:
#line 82 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
                (yyval) = new ParamsList();
                vector<int>& params = static_cast<ParamsList*>((yyval))->params;
                vector<int>& params_other = static_cast<ParamsList*>((yyvsp[(3) - (3)]))->params;
                params.push_back(static_cast<Type*>((yyvsp[(1) - (3)]))->type);
                params.insert(params.end(), params_other.begin(), params_other.end());
			;}
    break;

  case 13:
#line 92 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
                tryAddVariable((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), true);
                (yyval) = new Type(static_cast<Type*>((yyvsp[(1) - (2)]))->type);
	        ;}
    break;

  case 16:
#line 102 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyType((yyvsp[(3) - (4)]), BOOL); ;}
    break;

  case 21:
#line 114 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyType((yyvsp[(3) - (5)]), BOOL); ;}
    break;

  case 22:
#line 116 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {new_scope();;}
    break;

  case 23:
#line 117 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyType((yyvsp[(3) - (6)]), BOOL); ;}
    break;

  case 24:
#line 120 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyType((yyvsp[(3) - (7)]), BOOL); ;}
    break;

  case 25:
#line 122 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {in_while = true;;}
    break;

  case 26:
#line 122 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {in_while = false;;}
    break;

  case 27:
#line 123 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyType((yyvsp[(3) - (7)]), BOOL); ;}
    break;

  case 29:
#line 128 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyType((yyvsp[(3) - (7)]), BOOL); ;}
    break;

  case 30:
#line 130 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {in_while = true;;}
    break;

  case 31:
#line 130 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {in_while = false;;}
    break;

  case 32:
#line 131 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyType((yyvsp[(3) - (7)]), BOOL); ;}
    break;

  case 33:
#line 134 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {new_scope();;}
    break;

  case 35:
#line 137 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { tryAddVariable((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), false); ;}
    break;

  case 36:
#line 140 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { tryAddVariable((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), false); ;}
    break;

  case 39:
#line 145 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {

                ;}
    break;

  case 40:
#line 149 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {

                ;}
    break;

  case 41:
#line 153 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
                    if (!in_while) {
                        errorUnexpectedBreak(yylineno);
                    }
                ;}
    break;

  case 42:
#line 159 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
                    if (!in_while) {
                        errorUnexpectedContinue(yylineno);
                    }
                ;}
    break;

  case 43:
#line 167 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyFunctionDefined((yyvsp[(1) - (4)])); ;}
    break;

  case 44:
#line 170 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { verifyFunctionDefined((yyvsp[(1) - (3)])); ;}
    break;

  case 47:
#line 178 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(NUM); ;}
    break;

  case 48:
#line 181 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(BYTE); ;}
    break;

  case 49:
#line 184 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(BOOL); ;}
    break;

  case 50:
#line 188 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(static_cast<Type*>((yyvsp[(2) - (3)]))->type); ;}
    break;

  case 51:
#line 191 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
        int t1 = verifyTypes((yyvsp[(1) - (3)]), 2, NUM, BYTE);
        int t2 = verifyTypes((yyvsp[(3) - (3)]), 2, NUM, BYTE);

        // Try NUM precision first, retreat to byte if both are BYTE
        int preciseType = t1 == NUM ? NUM : (t2 == NUM ? NUM : BYTE);
        (yyval) = new Type(preciseType);
    ;}
    break;

  case 52:
#line 201 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
        verifyVariableDefined((yyvsp[(1) - (1)]));
        (yyval) = new Type(getVariableType((yyvsp[(1) - (1)])));
    ;}
    break;

  case 54:
#line 208 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(NUM); ;}
    break;

  case 55:
#line 211 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
	    verifyByteSize((yyvsp[(1) - (2)]));
	    (yyval) = new Type(BYTE);
	;}
    break;

  case 56:
#line 217 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(STRING); ;}
    break;

  case 57:
#line 220 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(BOOL); ;}
    break;

  case 58:
#line 223 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    { (yyval) = new Type(BOOL); ;}
    break;

  case 59:
#line 226 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
    	verifyType((yyvsp[(2) - (2)]), BOOL);
        (yyval) = new Type(BOOL);
    ;}
    break;

  case 60:
#line 231 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
	    verifyType((yyvsp[(1) - (3)]), BOOL);
	    verifyType((yyvsp[(3) - (3)]), BOOL);
        (yyval) = new Type(BOOL);
    ;}
    break;

  case 61:
#line 237 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
	    verifyType((yyvsp[(1) - (3)]), BOOL);
     	verifyType((yyvsp[(3) - (3)]), BOOL);
        (yyval) = new Type(BOOL);
    ;}
    break;

  case 62:
#line 243 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"
    {
	    verifyTypes((yyvsp[(1) - (3)]), 2, NUM, BYTE);
	    verifyTypes((yyvsp[(3) - (3)]), 2, NUM, BYTE);
	    (yyval) = new Type(BOOL);
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 1789 "/Users/miki/Desktop/Compilation/hw3/cmake-build-debug/parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 250 "/Users/miki/Desktop/Compilation/hw3/parser.ypp"


