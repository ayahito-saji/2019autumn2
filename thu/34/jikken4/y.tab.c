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
     SBEGIN = 258,
     DO = 259,
     ELSE = 260,
     SEND = 261,
     FOR = 262,
     FORWARD = 263,
     FUNCTION = 264,
     IF = 265,
     PROCEDURE = 266,
     PROGRAM = 267,
     READ = 268,
     THEN = 269,
     TO = 270,
     VAR = 271,
     WHILE = 272,
     WRITE = 273,
     MINUS = 274,
     PLUS = 275,
     DIV = 276,
     MULT = 277,
     EQ = 278,
     NEQ = 279,
     LE = 280,
     LT = 281,
     GE = 282,
     GT = 283,
     LPAREN = 284,
     RPAREN = 285,
     LBRACE = 286,
     RBRACE = 287,
     COMMA = 288,
     SEMICOLON = 289,
     COLON = 290,
     INTERVAL = 291,
     PERIOD = 292,
     ASSIGN = 293,
     NUMBER = 294,
     IDENT = 295
   };
#endif
/* Tokens.  */
#define SBEGIN 258
#define DO 259
#define ELSE 260
#define SEND 261
#define FOR 262
#define FORWARD 263
#define FUNCTION 264
#define IF 265
#define PROCEDURE 266
#define PROGRAM 267
#define READ 268
#define THEN 269
#define TO 270
#define VAR 271
#define WHILE 272
#define WRITE 273
#define MINUS 274
#define PLUS 275
#define DIV 276
#define MULT 277
#define EQ 278
#define NEQ 279
#define LE 280
#define LT 281
#define GE 282
#define GT 283
#define LPAREN 284
#define RPAREN 285
#define LBRACE 286
#define RBRACE 287
#define COMMA 288
#define SEMICOLON 289
#define COLON 290
#define INTERVAL 291
#define PERIOD 292
#define ASSIGN 293
#define NUMBER 294
#define IDENT 295




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "llvm.h"

extern int yylineno;
extern char *yytext;

extern Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

extern LLVMcode *codehd; /* 命令列の先頭のアドレスを保持するポインタ */
extern LLVMcode *codetl; /* 命令列の末尾のアドレスを保持するポインタ */
extern unsigned int cntr;

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
extern Fundecl *declhd;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
extern Fundecl *decltl;

extern LabelSyntaxStack lstack;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
typedef union YYSTYPE
#line 32 "parser.y"
{
    int num;
    char ident[MAXLENGTH+1];
}
/* Line 193 of yacc.c.  */
#line 212 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 225 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    11,    12,    17,    18,    21,    25,
      27,    30,    33,    34,    38,    40,    42,    47,    49,    52,
      56,    58,    60,    62,    64,    66,    68,    70,    72,    74,
      76,    77,    82,    83,    84,    85,    94,    95,    99,   100,
     101,   102,   103,   111,   112,   113,   124,   126,   128,   132,
     137,   142,   143,   147,   151,   155,   159,   163,   167,   169,
     172,   175,   179,   183,   185,   189,   193,   195,   197,   201,
     203,   205
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    43,    12,    40,    34,    44,    37,
      -1,    -1,    46,    49,    45,    56,    -1,    -1,    47,    34,
      -1,    47,    34,    48,    -1,    48,    -1,    16,    83,    -1,
      50,    34,    -1,    -1,    50,    34,    51,    -1,    51,    -1,
      52,    -1,    11,    53,    34,    54,    -1,    40,    -1,    46,
      56,    -1,    55,    34,    56,    -1,    56,    -1,    57,    -1,
      59,    -1,    65,    -1,    69,    -1,    72,    -1,    77,    -1,
      74,    -1,    75,    -1,    76,    -1,    -1,    40,    58,    38,
      79,    -1,    -1,    -1,    -1,    10,    78,    60,    14,    61,
      56,    62,    63,    -1,    -1,     5,    64,    56,    -1,    -1,
      -1,    -1,    -1,    17,    66,    78,    67,     4,    68,    56,
      -1,    -1,    -1,     7,    40,    38,    79,    70,    15,    79,
      71,     4,    56,    -1,    73,    -1,    40,    -1,     3,    55,
       6,    -1,    13,    29,    40,    30,    -1,    18,    29,    40,
      30,    -1,    -1,    79,    23,    79,    -1,    79,    24,    79,
      -1,    79,    26,    79,    -1,    79,    25,    79,    -1,    79,
      28,    79,    -1,    79,    27,    79,    -1,    80,    -1,    20,
      80,    -1,    19,    80,    -1,    79,    20,    80,    -1,    79,
      19,    80,    -1,    81,    -1,    80,    22,    81,    -1,    80,
      21,    81,    -1,    82,    -1,    39,    -1,    29,    79,    30,
      -1,    40,    -1,    40,    -1,    83,    33,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    55,    62,    62,    65,    67,    71,    72,
      76,    80,    81,    85,    86,    90,    94,    98,   102,   106,
     107,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     123,   123,   132,   141,   145,   132,   161,   161,   170,   174,
     184,   189,   174,   203,   224,   203,   259,   263,   267,   271,
     278,   281,   286,   292,   298,   304,   310,   316,   325,   326,
     327,   328,   335,   345,   346,   353,   363,   364,   365,   369,
     384,   385
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SBEGIN", "DO", "ELSE", "SEND", "FOR",
  "FORWARD", "FUNCTION", "IF", "PROCEDURE", "PROGRAM", "READ", "THEN",
  "TO", "VAR", "WHILE", "WRITE", "MINUS", "PLUS", "DIV", "MULT", "EQ",
  "NEQ", "LE", "LT", "GE", "GT", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "COMMA", "SEMICOLON", "COLON", "INTERVAL", "PERIOD", "ASSIGN", "NUMBER",
  "IDENT", "$accept", "program", "@1", "outblock", "@2", "var_decl_part",
  "var_decl_list", "var_decl", "subprog_decl_part", "subprog_decl_list",
  "subprog_decl", "proc_decl", "proc_name", "inblock", "statement_list",
  "statement", "assignment_statement", "@3", "if_statement", "@4", "@5",
  "@6", "else_statement", "@7", "while_statement", "@8", "@9", "@10",
  "for_statement", "@11", "@12", "proc_call_statement", "proc_call_name",
  "block_statement", "read_statement", "write_statement", "null_statement",
  "condition", "expression", "term", "factor", "var_name", "id_list", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    43,    42,    45,    44,    46,    46,    47,    47,
      48,    49,    49,    50,    50,    51,    52,    53,    54,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      58,    57,    60,    61,    62,    59,    64,    63,    63,    66,
      67,    68,    65,    70,    71,    69,    72,    73,    74,    75,
      76,    77,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    80,    80,    80,    81,    81,    81,    82,
      83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     0,     4,     0,     2,     3,     1,
       2,     2,     0,     3,     1,     1,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     0,     0,     8,     0,     3,     0,     0,
       0,     0,     7,     0,     0,    10,     1,     1,     3,     4,
       4,     0,     3,     3,     3,     3,     3,     3,     1,     2,
       2,     3,     3,     1,     3,     3,     1,     1,     3,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     6,     0,     0,    12,
       0,     9,    70,    10,     3,     0,     4,     0,    14,    15,
       7,     0,    17,     0,    51,    11,     8,    71,     6,    51,
       0,     0,     0,    39,     0,    47,     5,    21,    22,    23,
      24,    25,    46,    27,    28,    29,    26,    13,    51,    16,
       0,    20,     0,     0,     0,     0,    67,    69,    32,     0,
      58,    63,    66,     0,     0,     0,     0,    18,    48,    51,
       0,    60,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,     0,     0,    19,
      43,    68,    33,    62,    61,    52,    53,    55,    54,    57,
      56,    65,    64,    49,     0,    50,    31,     0,    51,    41,
       0,    34,    51,    44,    38,    42,     0,    36,    35,    51,
      51,    45,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,    24,     9,    10,    11,    16,    17,
      18,    19,    23,    49,    50,    36,    37,    66,    38,    74,
     108,   114,   118,   120,    39,    64,   104,   112,    40,   107,
     116,    41,    42,    43,    44,    45,    46,    58,    59,    60,
      61,    62,    13
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int8 yypact[] =
{
     -55,     3,    -6,   -55,   -32,   -16,    13,   -20,    -1,    28,
       9,   -55,   -55,     0,   -55,    10,   -55,    17,   -55,   -55,
      13,    12,   -55,    19,     4,    28,   -55,   -55,    13,     4,
      14,    18,    26,   -55,    32,    24,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,     4,   -55,
      -4,   -55,    31,     6,     6,    18,   -55,   -55,   -55,    40,
      -9,   -55,   -55,    30,    18,    33,    34,   -55,   -55,     4,
      18,    -9,    -9,   -15,    57,     6,     6,    18,    18,    18,
      18,    18,    18,     6,     6,    44,   -55,    45,    18,   -55,
      22,   -55,   -55,    -9,    -9,    22,    22,    22,    22,    22,
      22,   -55,   -55,   -55,    72,   -55,    22,    62,     4,   -55,
      18,   -55,     4,    22,    73,   -55,    76,   -55,   -55,     4,
       4,   -55,   -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,   -55,   -55,   -55,    53,   -55,    64,   -55,   -55,
      60,   -55,   -55,   -55,   -55,   -29,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,    23,   -54,   -44,
     -35,   -55,   -55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -31
static const yytype_int8 yytable[] =
{
      51,    73,    68,     3,    75,    76,     4,    29,     5,    71,
      72,    30,    83,    84,    31,    91,    90,    32,     6,    67,
      12,    33,    34,    95,    96,    97,    98,    99,   100,     7,
      69,    93,    94,    21,   106,    55,    14,    53,    54,    15,
      89,    75,    76,    20,    35,    56,    57,    55,   101,   102,
      22,    25,    27,    28,    52,    63,   113,    56,    57,    75,
      76,    65,   -30,    77,    78,    79,    80,    81,    82,    70,
      85,    92,    88,    87,   103,   105,   109,   110,   117,   111,
     119,    48,     0,   115,    26,    47,     0,    86,     0,     0,
     121,   122
};

static const yytype_int8 yycheck[] =
{
      29,    55,     6,     0,    19,    20,    12,     3,    40,    53,
      54,     7,    21,    22,    10,    30,    70,    13,    34,    48,
      40,    17,    18,    77,    78,    79,    80,    81,    82,    16,
      34,    75,    76,    33,    88,    29,    37,    19,    20,    11,
      69,    19,    20,    34,    40,    39,    40,    29,    83,    84,
      40,    34,    40,    34,    40,    29,   110,    39,    40,    19,
      20,    29,    38,    23,    24,    25,    26,    27,    28,    38,
      40,    14,    38,    40,    30,    30,     4,    15,     5,   108,
       4,    28,    -1,   112,    20,    25,    -1,    64,    -1,    -1,
     119,   120
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,    12,    40,    34,    16,    44,    46,
      47,    48,    40,    83,    37,    11,    49,    50,    51,    52,
      34,    33,    40,    53,    45,    34,    48,    40,    34,     3,
       7,    10,    13,    17,    18,    40,    56,    57,    59,    65,
      69,    72,    73,    74,    75,    76,    77,    51,    46,    54,
      55,    56,    40,    19,    20,    29,    39,    40,    78,    79,
      80,    81,    82,    29,    66,    29,    58,    56,     6,    34,
      38,    80,    80,    79,    60,    19,    20,    23,    24,    25,
      26,    27,    28,    21,    22,    40,    78,    40,    38,    56,
      79,    30,    14,    80,    80,    79,    79,    79,    79,    79,
      79,    81,    81,    30,    67,    30,    79,    70,    61,     4,
      15,    56,    68,    79,    62,    56,    71,     5,    63,     4,
      64,    56,    56
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
#line 55 "parser.y"
    {
            fstack.top = 0;
            lstack.top = 0;
          }
    break;

  case 3:
#line 58 "parser.y"
    { outputCode(); }
    break;

  case 4:
#line 62 "parser.y"
    { doMainProcedure(); }
    break;

  case 5:
#line 62 "parser.y"
    { defineRet();delete(); }
    break;

  case 16:
#line 94 "parser.y"
    { delete(); }
    break;

  case 17:
#line 98 "parser.y"
    { insert((yyvsp[(1) - (1)].ident), PROC_NAME); }
    break;

  case 30:
#line 123 "parser.y"
    { lookup((yyvsp[(1) - (1)].ident)); }
    break;

  case 31:
#line 123 "parser.y"
    {
            Factor arg1, arg2;
            arg1 = factorpop();
            arg2 = factorpop();
            defineStore(arg1, arg2);
          }
    break;

  case 32:
#line 132 "parser.y"
    {
            // if ~~~ BR1 then LABEL2 ~~~~~ BR2 else LABEL3 ~~~~~~ BR3 LABEL4
            LabelSyntax lsyntax;
            lsyntax.command = If;
            lsyntax.args.If.br1 = defineBrCondition(1, 1);
            lsyntax.args.If.br2 = NULL;
            lsyntax.args.If.br3 = NULL;
            pushLabelSyntax(lsyntax);
            displayLabelSyntax(lsyntax);
          }
    break;

  case 33:
#line 141 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg2 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          }
    break;

  case 34:
#line 145 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br2 = defineBr(1);
            pushLabelSyntax(lsyntax);
          }
    break;

  case 35:
#line 149 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();
            int label1 = defineLabel()->args.label.l;
            lsyntax.args.If.br2->args.bruncond.arg1 = label1;
            if (lsyntax.args.If.br3 != NULL)
              lsyntax.args.If.br3->args.bruncond.arg1 = label1;
            else
              lsyntax.args.If.br1->args.brcond.arg3 = label1;
          }
    break;

  case 36:
#line 161 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg3 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          }
    break;

  case 37:
#line 165 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br3 = defineBr(1);
            pushLabelSyntax(lsyntax);
          }
    break;

  case 39:
#line 174 "parser.y"
    {
            // BR1 LABEL1 while ~~~ BR2 do LABEL2 ~~~~~ BR3 LABEL3
            LabelSyntax lsyntax;
            lsyntax.command = While;
            lsyntax.args.While.br1 = defineBr(1); // LABEL1へのジャンプ命令を定義して，LLVM命令の場所を記憶
            lsyntax.args.While.label1 = defineLabel()->args.label.l; // LABEL1を定義して，LABEL1のレジスタ番号を代入
            lsyntax.args.While.br1->args.bruncond.arg1 = lsyntax.args.While.label1; // BR1にLABEL1のレジスタ番号を代入
            lsyntax.args.While.br2 = NULL;
            // displayLabelSyntax(lsyntax);
            pushLabelSyntax(lsyntax);
          }
    break;

  case 40:
#line 184 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2 = defineBrCondition(1, 1); // LABEL2またはLABEL3へのジャンプ命令を定義して，LLVM命令の場所を記憶
            pushLabelSyntax(lsyntax);
            // displayLabelSyntax(lsyntax);
          }
    break;

  case 41:
#line 189 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2->args.brcond.arg2 = defineLabel()->args.label.l; // LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入
            pushLabelSyntax(lsyntax);
            // displayLabelSyntax(lsyntax);
          }
    break;

  case 42:
#line 194 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();
            defineBr(lsyntax.args.While.label1); // LABEL1へジャンプするBR命令を定義
            lsyntax.args.While.br2->args.brcond.arg3 = defineLabel()->args.label.l; // LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入
            // displayLabelSyntax(lsyntax);
          }
    break;

  case 43:
#line 203 "parser.y"
    {
            LabelSyntax lsyntax;
            lsyntax.command = For;
            lookup((yyvsp[(2) - (4)].ident));

            Factor arg1, arg2;
            arg1 = factorpop();
            arg2 = factorpop();

            defineStore(arg1, arg2);

            lsyntax.args.For.br1 = defineBr(1);

            lsyntax.args.For.var = arg1;

            lsyntax.args.For.label1 = defineLabel()->args.label.l;
            lsyntax.args.For.br1->args.bruncond.arg1 = lsyntax.args.For.label1;

            defineLoad(arg1);

            pushLabelSyntax(lsyntax);
          }
    break;

  case 44:
#line 224 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();

            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLE, arg1, arg2);

            lsyntax.args.For.br2 = defineBrCondition(1, 1);

            lsyntax.args.For.br2->args.brcond.arg2 = defineLabel()->args.label.l;

            pushLabelSyntax(lsyntax);


          }
    break;

  case 45:
#line 239 "parser.y"
    {
            LabelSyntax lsyntax = popLabelSyntax();

            defineLoad(lsyntax.args.For.var);

            Factor arg1, arg2;
            pushNumber(1);
            arg2 = factorpop();
            arg1 = factorpop();

            defineAdd(arg1, arg2);

            defineStore(lsyntax.args.For.var, factorpop());

            defineBr(lsyntax.args.For.label1);
            lsyntax.args.For.br2->args.brcond.arg3 = defineLabel()->args.label.l;
          }
    break;

  case 47:
#line 263 "parser.y"
    { lookup((yyvsp[(1) - (1)].ident)); }
    break;

  case 49:
#line 271 "parser.y"
    {
            lookup((yyvsp[(3) - (4)].ident));
            defineAlloca();
          }
    break;

  case 50:
#line 278 "parser.y"
    { lookup((yyvsp[(3) - (4)].ident)); }
    break;

  case 52:
#line 286 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(EQUAL, arg1, arg2);
          }
    break;

  case 53:
#line 292 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(NE, arg1, arg2);
          }
    break;

  case 54:
#line 298 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLE, arg1, arg2);
          }
    break;

  case 55:
#line 304 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLE, arg1, arg2);
          }
    break;

  case 56:
#line 310 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGT, arg1, arg2);
          }
    break;

  case 57:
#line 316 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGE, arg1, arg2);
          }
    break;

  case 61:
#line 328 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineAdd(arg1, arg2);
          }
    break;

  case 62:
#line 335 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineSub(arg1, arg2);
          }
    break;

  case 64:
#line 346 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineMul(arg1, arg2);
          }
    break;

  case 65:
#line 353 "parser.y"
    {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineDiv(arg1, arg2);
          }
    break;

  case 67:
#line 364 "parser.y"
    { pushNumber((yyvsp[(1) - (1)].num)); }
    break;

  case 69:
#line 369 "parser.y"
    { lookup((yyvsp[(1) - (1)].ident));
            Factor arg1;
            arg1 = factorpop();

            if (arg1.type == GLOBAL_VAR) defineLoad(arg1);
            else factorpush(arg1);
          }
    break;

  case 70:
#line 384 "parser.y"
    { insert((yyvsp[(1) - (1)].ident), UNDEFINED_VAR); }
    break;

  case 71:
#line 385 "parser.y"
    { insert((yyvsp[(3) - (3)].ident), UNDEFINED_VAR); }
    break;


/* Line 1267 of yacc.c.  */
#line 1904 "y.tab.c"
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


#line 387 "parser.y"

int yyerror(char *s)
{
  fprintf(stderr, "%s(%d: \'%s\')\n", s, yylineno, yytext);
  return 0;
}

