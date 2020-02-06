#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llvm.h"
#include "symbol_table.h"

extern int yylineno;
extern char *yytext;

extern Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

extern LLVMcode *codehd; /* 命令列の先頭のアドレスを保持するポインタ */
extern LLVMcode *codetl; /* 命令列の末尾のアドレスを保持するポインタ */
extern unsigned int cntr;
extern unsigned int useRead;
extern unsigned int useWrite;

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
extern Fundecl *declhd;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
extern Fundecl *decltl;

extern LabelSyntaxStack lstack;

unsigned int arity = 0;
char args[10][256];

#line 37 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 65 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SBEGIN 257
#define DO 258
#define ELSE 259
#define SEND 260
#define FOR 261
#define FORWARD 262
#define FUNCTION 263
#define IF 264
#define PROCEDURE 265
#define PROGRAM 266
#define READ 267
#define THEN 268
#define TO 269
#define VAR 270
#define WHILE 271
#define WRITE 272
#define PLUS 273
#define MINUS 274
#define MULT 275
#define DIV 276
#define EQ 277
#define NEQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACE 285
#define RBRACE 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define INTERVAL 290
#define PERIOD 291
#define ASSIGN 292
#define NUMBER 293
#define IDENT 294
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    1,    0,    6,    2,    3,    3,    7,    7,    8,    4,
    4,   10,   10,   11,   15,   12,   17,   12,   19,   12,
   13,   18,   14,   20,   20,    5,    5,    5,    5,    5,
    5,    5,    5,    5,   30,   21,   33,   34,   36,   22,
   37,   35,   35,   38,   39,   40,   23,   41,   42,   24,
   25,   25,   43,   45,   46,   27,   28,   29,   26,   32,
   32,   32,   32,   32,   32,   31,   31,   31,   31,   31,
   47,   47,   47,   48,   48,   48,   48,   49,   44,   44,
    9,    9,   16,   16,
};
static const short yylen[] = {                            2,
    0,    6,    0,    4,    0,    2,    3,    1,    2,    2,
    0,    3,    1,    1,    0,    5,    0,    8,    0,    8,
    1,    1,    2,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    0,    4,    0,    0,    0,    8,
    0,    3,    0,    0,    0,    0,    7,    0,    0,   10,
    1,    4,    1,    4,    1,    3,    4,    4,    0,    3,
    3,    3,    3,    3,    3,    1,    2,    2,    3,    3,
    1,    3,    3,    1,    1,    3,    1,    1,    1,    3,
    1,    3,    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
   81,    0,    2,    0,    0,    3,    0,   13,   14,    0,
    0,   22,    0,   21,    0,    0,    0,    7,   82,    0,
    0,   15,    0,    0,    0,    0,   44,    0,    0,    4,
   26,   27,   28,   29,   30,   31,   32,   33,   34,    0,
   12,   83,    0,    0,    0,   25,    0,    0,    0,    0,
    0,   75,    0,    0,   37,   77,    0,    0,   71,   74,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   16,
   56,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   45,
    0,    0,    0,    0,   19,   84,   17,   23,   24,    0,
   76,    0,    0,    0,    0,    0,    0,    0,    0,   38,
    0,   72,   73,   57,    0,   58,    0,   52,    0,    0,
    0,    0,    0,   54,   46,    0,   20,   18,    0,   39,
    0,    0,    0,   47,    0,   41,   40,    0,    0,   50,
   42,
};
static const short yydgoto[] = {                          1,
    2,    7,   79,   16,   40,   26,    9,   10,   12,   17,
   18,   19,   25,   80,   55,   53,  131,   23,  130,   57,
   41,   42,   43,   44,   45,   46,   47,   48,   49,   74,
   64,   65,   95,  133,  147,  143,  149,   72,  125,  141,
  132,  145,   50,  104,   66,   67,   68,   69,   70,
};
static const short yysindex[] = {                         0,
    0, -246, -291, -249, -244, -247, -230,  -47, -222,    0,
    0, -173,    0, -205, -200,    0, -170,    0,    0, -244,
 -161,    0, -142,    0, -281, -144,  -47,    0,    0, -131,
 -131,    0, -144, -119, -106, -101,    0, -100,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -99,
    0,    0, -263, -262, -244,    0, -243,  -95, -221, -221,
 -106,    0,    0,   64,    0,    0,  -82, -193,    0,    0,
  -92, -106, -106,  -83, -106, -164,  -77,  -75, -144,    0,
    0, -144, -106, -193, -193, -268, -221, -221, -106, -106,
 -106, -106, -106, -106,  -56, -106, -221, -221,  -63,    0,
 -198, -106, -168, -158,    0,    0,    0,    0,    0, -168,
    0, -193, -193, -168, -168, -168, -168, -168, -168,    0,
 -152,    0,    0,    0,  -36,    0, -168,    0, -106, -144,
 -244,  -40, -144,    0,    0, -168,    0,    0, -106,    0,
 -144, -168,  -28,    0,  -26,    0,    0, -144, -144,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -213,    0,    0, -204,    0,    0,
    0,  -53,    0,    0,    0,    0,    0,    0,    0, -253,
    0,    0,    0,    0,    0,  -55, -187,    0,    0,    0,
    0,    0, -217,    0,    0,    0,    0,    0, -149,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -195,
    0,    0,    0,    0, -169,    0,    0,    0,    0,    0,
    0,    0, -122,    0,    0,    0,    0,  -88,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -46,    0,
    0, -217,    0,  -54,  -20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -89,    0,    0,    0,    0,    0,    0,  -25,
    0,   14,   48, -167, -159, -146, -137, -128,  -94,    0,
    0,    0,    0,    0,    0,    0, -115,    0,    0,  -46,
 -169,    0,  -81,    0,    0,  -76,    0,    0,    0,    0,
  -81,  -17, -251,    0,    0,    0,    0,  -81,  -81,    0,
    0,
};
static const short yygindex[] = {                         0,
    0,    0,  238,    0,  -33,    0,    0,  225,    0,    0,
  219,    0,    0,  116,    0,  220,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -60,  178,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  156,    0,    0,  -32,   51,    0,
};
#define YYTABLESIZE 346
static const short yytable[] = {                         56,
   86,   31,    4,    6,   87,   88,   32,    6,   43,    6,
    6,    6,  101,    6,  103,  111,   81,    6,    6,    3,
   76,   78,  110,   77,   77,    6,   84,   85,  114,  115,
  116,  117,  118,  119,    6,  103,   43,    6,    5,   43,
    6,  127,   59,    5,   82,  108,   11,    5,  109,    5,
    5,    5,   11,    5,  112,  113,   11,    5,    5,   11,
   13,   61,   11,   51,   51,   20,   11,   11,  136,   10,
   59,   62,   63,   10,   87,   88,   10,    5,  142,   10,
    5,   97,   98,   10,   10,  126,   11,    5,   22,   11,
   60,    5,   51,   24,    5,   51,  137,    5,   61,  140,
   60,    5,    5,   10,   87,   88,   10,  144,   61,   53,
   53,   63,   33,   21,  150,  151,   34,   27,    5,   35,
   62,   63,   36,  105,    5,  128,   37,   38,  129,   65,
   62,  134,   29,   53,  129,   78,   78,   78,   53,   65,
   30,   53,   35,   36,   36,   78,   78,  122,  123,   39,
   78,   78,   78,   78,   78,   78,   78,   78,   78,   78,
   55,   78,   52,   64,   78,   78,   59,   60,   78,   66,
   66,   66,   36,   64,   58,   36,   61,   59,   59,   66,
   66,   71,   73,   75,   66,   66,   62,   63,   66,   66,
   66,   66,   66,   66,   79,   66,   83,   79,   66,   66,
   96,   99,   66,   67,   67,   67,   59,   80,  102,   59,
   80,  120,  107,   67,   67,   14,  106,   15,   67,   67,
  124,  135,   67,   67,   67,   67,   67,   67,  139,   67,
  146,  148,   67,   67,    9,   59,   67,   68,   68,   68,
   49,   59,    8,   48,   28,   51,  138,   68,   68,  100,
   54,  121,   68,   68,    0,    0,   68,   68,   68,   68,
   68,   68,    0,   68,    0,    0,   68,   68,    0,    0,
   68,   69,   69,   69,    0,    0,    0,    0,    0,    0,
    0,   69,   69,    0,    0,    0,   69,   69,    0,    0,
   69,   69,   69,   69,   69,   69,    0,   69,    0,    0,
   69,   69,    0,    0,   69,   70,   70,   70,    0,    0,
    0,    0,    0,    0,    0,   70,   70,    0,    0,    0,
   70,   70,    0,    0,   70,   70,   70,   70,   70,   70,
    0,   70,    0,    0,   70,   70,   87,   88,   70,    0,
   89,   90,   91,   92,   93,   94,
};
static const short yycheck[] = {                         33,
   61,  283,  294,  257,  273,  274,  288,  261,  260,  263,
  264,  265,   73,  267,   75,  284,  260,  271,  272,  266,
  284,  284,   83,  287,  287,  270,   59,   60,   89,   90,
   91,   92,   93,   94,  288,   96,  288,  291,  288,  291,
  294,  102,  260,  257,  288,   79,  294,  261,   82,  263,
  264,  265,  257,  267,   87,   88,  261,  271,  272,  264,
  291,  283,  267,  259,  260,  288,  271,  272,  129,  257,
  288,  293,  294,  261,  273,  274,  264,  291,  139,  267,
  294,  275,  276,  271,  272,  284,  291,  257,  294,  294,
  258,  261,  288,  294,  264,  291,  130,  267,  258,  133,
  268,  271,  272,  291,  273,  274,  294,  141,  268,  259,
  260,  258,  257,  287,  148,  149,  261,  288,  288,  264,
  258,  268,  267,  288,  294,  284,  271,  272,  287,  258,
  268,  284,  294,  283,  287,  258,  259,  260,  288,  268,
  283,  291,  292,  259,  260,  268,  269,   97,   98,  294,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  294,  258,  287,  288,  273,  274,  291,  258,
  259,  260,  288,  268,  294,  291,  283,  259,  260,  268,
  269,  283,  283,  283,  273,  274,  293,  294,  277,  278,
  279,  280,  281,  282,  284,  284,  292,  287,  287,  288,
  283,  294,  291,  258,  259,  260,  288,  284,  292,  291,
  287,  268,  288,  268,  269,  263,  294,  265,  273,  274,
  284,  258,  277,  278,  279,  280,  281,  282,  269,  284,
  259,  258,  287,  288,  288,  291,  291,  258,  259,  260,
  258,  288,    5,  269,   20,   27,  131,  268,  269,   72,
   31,   96,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,   -1,  287,  288,   -1,   -1,
  291,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,   -1,   -1,
  287,  288,   -1,   -1,  291,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,   -1,   -1,  287,  288,  273,  274,  291,   -1,
  277,  278,  279,  280,  281,  282,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SBEGIN","DO","ELSE","SEND","FOR",
"FORWARD","FUNCTION","IF","PROCEDURE","PROGRAM","READ","THEN","TO","VAR",
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","EQ","NEQ","LE","LT","GE","GT",
"LPAREN","RPAREN","LBRACE","RBRACE","COMMA","SEMICOLON","COLON","INTERVAL",
"PERIOD","ASSIGN","NUMBER","IDENT",
};
static const char *yyrule[] = {
"$accept : program",
"$$1 :",
"program : $$1 PROGRAM IDENT SEMICOLON outblock PERIOD",
"$$2 :",
"outblock : var_decl_part subprog_decl_part $$2 statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"var_decl : VAR id_list",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_part :",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"$$3 :",
"proc_decl : PROCEDURE proc_name SEMICOLON $$3 inblock",
"$$4 :",
"proc_decl : PROCEDURE proc_name LPAREN did_list RPAREN SEMICOLON $$4 inblock",
"$$5 :",
"proc_decl : FUNCTION func_name LPAREN did_list RPAREN SEMICOLON $$5 statement",
"proc_name : IDENT",
"func_name : IDENT",
"inblock : var_decl_part statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"$$6 :",
"assignment_statement : IDENT $$6 ASSIGN expression",
"$$7 :",
"$$8 :",
"$$9 :",
"if_statement : IF condition $$7 THEN $$8 statement $$9 else_statement",
"$$10 :",
"else_statement : ELSE $$10 statement",
"else_statement :",
"$$11 :",
"$$12 :",
"$$13 :",
"while_statement : WHILE $$11 condition $$12 DO $$13 statement",
"$$14 :",
"$$15 :",
"for_statement : FOR IDENT ASSIGN expression $$14 TO expression $$15 DO statement",
"proc_call_statement : proc_call_name",
"proc_call_statement : proc_call_name LPAREN arg_list RPAREN",
"proc_call_name : IDENT",
"func_call : func_call_name LPAREN arg_list RPAREN",
"func_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"write_statement : WRITE LPAREN expression RPAREN",
"null_statement :",
"condition : expression EQ expression",
"condition : expression NEQ expression",
"condition : expression LT expression",
"condition : expression LE expression",
"condition : expression GT expression",
"condition : expression GE expression",
"expression : term",
"expression : PLUS term",
"expression : MINUS term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_name",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"factor : func_call",
"var_name : IDENT",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",
"did_list : IDENT",
"did_list : did_list COMMA IDENT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 496 "parser.y"
int yyerror(char *s)
{
  fprintf(stderr, "%s(%d: \'%s\')\n", s, yylineno, yytext);
  return 0;
}
#line 451 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 60 "parser.y"
	{
            fstack.top = 0;
            lstack.top = 0;
            useRead = 0;
            useWrite = 0;
          }
break;
case 2:
#line 65 "parser.y"
	{ outputCode(); }
break;
case 3:
#line 69 "parser.y"
	{ doMainProcedure(); }
break;
case 4:
#line 69 "parser.y"
	{ defineRet();delete(); }
break;
case 15:
#line 101 "parser.y"
	{
            Factor proc_name = factorpop();
            doProcedure(proc_name.vname, 0, args, VOID);
          }
break;
case 16:
#line 104 "parser.y"
	{
            defineRet();
            delete();
          }
break;
case 17:
#line 108 "parser.y"
	{
            Factor f = factorpop();
            doProcedure(f.vname, arity, args, VOID);
          }
break;
case 18:
#line 111 "parser.y"
	{
            defineRet();
            delete();
          }
break;
case 19:
#line 115 "parser.y"
	{
            Factor f = factorpop();
            doProcedure(f.vname, arity, args, INT32);
          }
break;
case 20:
#line 118 "parser.y"
	{
            Factor arg1;
            arg1 = (decltl->retval);
            defineLoad(arg1);
            (decltl->retval).val = cntr-1;
            defineRet();
            delete();
          }
break;
case 21:
#line 129 "parser.y"
	{ insert(yystack.l_mark[0].ident, PROC_NAME, 0, VOID); }
break;
case 22:
#line 133 "parser.y"
	{ insert(yystack.l_mark[0].ident, PROC_NAME, 0, INT32); }
break;
case 35:
#line 158 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 36:
#line 158 "parser.y"
	{
            Factor arg1, arg2;
            arg1 = factorpop();
            arg2 = factorpop();
            defineStore(arg1, arg2);
          }
break;
case 37:
#line 167 "parser.y"
	{
            /* if ~~~ BR1 then LABEL2 ~~~~~ BR2 else LABEL3 ~~~~~~ BR3 LABEL4*/
            LabelSyntax lsyntax;
            lsyntax.command = If;
            lsyntax.args.If.br1 = defineBrCondition(1, 1);
            lsyntax.args.If.br2 = NULL;
            lsyntax.args.If.br3 = NULL;
            pushLabelSyntax(lsyntax);
            displayLabelSyntax(lsyntax);
          }
break;
case 38:
#line 176 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg2 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          }
break;
case 39:
#line 180 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br2 = defineBr(1);
            pushLabelSyntax(lsyntax);
          }
break;
case 40:
#line 184 "parser.y"
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
case 41:
#line 196 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg3 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          }
break;
case 42:
#line 200 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br3 = defineBr(1);
            pushLabelSyntax(lsyntax);
          }
break;
case 44:
#line 209 "parser.y"
	{
            /* BR1 LABEL1 while ~~~ BR2 do LABEL2 ~~~~~ BR3 LABEL3*/
            LabelSyntax lsyntax;
            lsyntax.command = While;
            lsyntax.args.While.br1 = defineBr(1); /* LABEL1へのジャンプ命令を定義して，LLVM命令の場所を記憶*/
            lsyntax.args.While.label1 = defineLabel()->args.label.l; /* LABEL1を定義して，LABEL1のレジスタ番号を代入*/
            lsyntax.args.While.br1->args.bruncond.arg1 = lsyntax.args.While.label1; /* BR1にLABEL1のレジスタ番号を代入*/
            lsyntax.args.While.br2 = NULL;
            /* displayLabelSyntax(lsyntax);*/
            pushLabelSyntax(lsyntax);
          }
break;
case 45:
#line 219 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2 = defineBrCondition(1, 1); /* LABEL2またはLABEL3へのジャンプ命令を定義して，LLVM命令の場所を記憶*/
            pushLabelSyntax(lsyntax);
            /* displayLabelSyntax(lsyntax);*/
          }
break;
case 46:
#line 224 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2->args.brcond.arg2 = defineLabel()->args.label.l; /* LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入*/
            pushLabelSyntax(lsyntax);
            /* displayLabelSyntax(lsyntax);*/
          }
break;
case 47:
#line 229 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            defineBr(lsyntax.args.While.label1); /* LABEL1へジャンプするBR命令を定義*/
            lsyntax.args.While.br2->args.brcond.arg3 = defineLabel()->args.label.l; /* LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入*/
            /* displayLabelSyntax(lsyntax);*/
          }
break;
case 48:
#line 238 "parser.y"
	{
            LabelSyntax lsyntax;
            lsyntax.command = For;
            lookup(yystack.l_mark[-2].ident);

            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineStore(arg1, arg2);

            lsyntax.args.For.br1 = defineBr(1);

            lsyntax.args.For.var = arg2;

            lsyntax.args.For.label1 = defineLabel()->args.label.l;
            lsyntax.args.For.br1->args.bruncond.arg1 = lsyntax.args.For.label1;

            defineLoad(arg2);

            pushLabelSyntax(lsyntax);
          }
break;
case 49:
#line 259 "parser.y"
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
case 50:
#line 274 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();

            defineLoad(lsyntax.args.For.var);

            Factor arg1, arg2;
            pushNumber(1);
            arg2 = factorpop();
            arg1 = factorpop();

            defineAdd(arg1, arg2);

            defineStore(factorpop(), lsyntax.args.For.var);

            defineBr(lsyntax.args.For.label1);
            lsyntax.args.For.br2->args.brcond.arg3 = defineLabel()->args.label.l;
          }
break;
case 51:
#line 294 "parser.y"
	{
            Factor f, args[10];
            f = factorpop();
            defineCall(f, 0, args, VOID);
          }
break;
case 52:
#line 299 "parser.y"
	{
            Factor f, args[10];
            unsigned int arity = 0;
            while (1){
              f = factorpop();
              if (f.type == PROC_NAME) break;
              else {
                args[arity] = f;
                arity ++;
              }
            }
            defineCall(f, arity, args, VOID);
          }
break;
case 53:
#line 315 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 54:
#line 320 "parser.y"
	{
            Factor f, args[10];
            unsigned int arity = 0;
            while (1){
              f = factorpop();
              if (f.type == PROC_NAME) break;
              else {
                args[arity] = f;
                arity ++;
              }
            }
            defineCall(f, arity, args, INT32);
          }
break;
case 55:
#line 336 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 57:
#line 345 "parser.y"
	{
            useRead = 1;
            lookup(yystack.l_mark[-1].ident);
            defineScanf();
          }
break;
case 58:
#line 353 "parser.y"
	{
            useWrite = 1;

            Factor arg1;
            arg1 = factorpop();
            definePrintf(arg1);
          }
break;
case 60:
#line 367 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(EQUAL, arg1, arg2);
          }
break;
case 61:
#line 373 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(NE, arg1, arg2);
          }
break;
case 62:
#line 379 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLT, arg1, arg2);
          }
break;
case 63:
#line 385 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLE, arg1, arg2);
          }
break;
case 64:
#line 391 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGT, arg1, arg2);
          }
break;
case 65:
#line 397 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGE, arg1, arg2);
          }
break;
case 69:
#line 409 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            if (arg1.type == CONSTANT && arg2.type == CONSTANT) {
              arg1.val = arg1.val + arg2.val;
              factorpush(arg1);
            } else {
              defineAdd(arg1, arg2);
            }
          }
break;
case 70:
#line 421 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            if (arg1.type == CONSTANT && arg2.type == CONSTANT) {
              arg1.val = arg1.val - arg2.val;
              factorpush(arg1);
            } else {
              defineSub(arg1, arg2);
            }
          }
break;
case 72:
#line 437 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            if (arg1.type == CONSTANT && arg2.type == CONSTANT) {
              arg1.val = arg1.val * arg2.val;
              factorpush(arg1);
            } else {
              defineMul(arg1, arg2);
            }
          }
break;
case 73:
#line 449 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            if (arg1.type == CONSTANT && arg2.type == CONSTANT) {
              arg1.val = arg1.val / arg2.val;
              factorpush(arg1);
            } else {
              defineDiv(arg1, arg2);
            }
          }
break;
case 75:
#line 465 "parser.y"
	{ pushNumber(yystack.l_mark[0].num); }
break;
case 78:
#line 471 "parser.y"
	{ lookup(yystack.l_mark[0].ident);
            Factor arg1;
            arg1 = factorpop();

            if (arg1.type == GLOBAL_VAR) defineLoad(arg1);
            else if (arg1.type == LOCAL_VAR) defineLoad(arg1);
            else factorpush(arg1);
          }
break;
case 81:
#line 487 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR, 0, VOID); }
break;
case 82:
#line 488 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR, 0, VOID); }
break;
case 83:
#line 492 "parser.y"
	{ strcpy(args[0], yystack.l_mark[0].ident);arity = 1; }
break;
case 84:
#line 493 "parser.y"
	{ strcpy(args[arity], yystack.l_mark[0].ident);arity++; }
break;
#line 1118 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
