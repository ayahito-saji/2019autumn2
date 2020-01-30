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
#include "symbol_table.h"
#include "llvm.h"

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
    4,   10,   10,   11,   15,   12,   17,   12,   13,   14,
   18,   18,    5,    5,    5,    5,    5,    5,    5,    5,
    5,   28,   19,   31,   32,   34,   20,   35,   33,   33,
   36,   37,   38,   21,   39,   40,   22,   23,   23,   41,
   25,   26,   27,   24,   30,   30,   30,   30,   30,   30,
   29,   29,   29,   29,   29,   43,   43,   43,   44,   44,
   44,   45,   42,   42,    9,    9,   16,   16,
};
static const short yylen[] = {                            2,
    0,    6,    0,    4,    0,    2,    3,    1,    2,    2,
    0,    3,    1,    1,    0,    5,    0,    8,    1,    2,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    0,    4,    0,    0,    0,    8,    0,    3,    0,
    0,    0,    0,    7,    0,    0,   10,    1,    4,    1,
    3,    4,    4,    0,    3,    3,    3,    3,    3,    3,
    1,    2,    2,    3,    3,    1,    3,    3,    1,    1,
    3,    1,    1,    3,    1,    3,    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
   75,    0,    2,    0,    3,    0,   13,   14,    0,    0,
   19,    0,    0,    0,    7,   76,    0,   15,    0,    0,
    0,    0,   41,    0,    0,    4,   23,   24,   25,   26,
   27,   28,   29,   30,   31,    0,   12,   77,    0,    0,
   22,    0,    0,    0,    0,    0,   70,   72,    0,   34,
    0,   66,   69,    0,    0,    0,    0,    0,    0,    0,
    0,   16,   51,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   42,    0,    0,    0,    0,   17,   78,   20,   21,    0,
   71,    0,    0,    0,    0,    0,    0,    0,    0,   35,
   67,   68,   52,    0,   53,    0,   49,    0,    0,    0,
    0,   43,    0,   18,    0,   36,    0,    0,    0,   44,
    0,   38,   37,    0,    0,   47,   39,
};
static const short yydgoto[] = {                          1,
    2,    7,   71,   15,   36,   23,    9,   10,   12,   16,
   17,   18,   22,   72,   50,   49,  119,   52,   37,   38,
   39,   40,   41,   42,   43,   44,   45,   67,   59,   60,
   87,  121,  133,  129,  135,   65,  114,  127,  120,  131,
   46,   95,   61,   62,   63,
};
static const short yysindex[] = {                         0,
    0, -261, -287, -251, -229, -241, -227, -189, -177,    0,
    0, -168,    0, -154,    0, -162,    0,    0, -229, -134,
    0, -163, -164, -189,    0,    0, -122,    0, -164, -119,
 -109, -152,    0, -139,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -93,    0,    0, -262, -229,
    0, -239,  -97, -275, -275, -109,    0,    0,    7,    0,
  -89,    0,    0,  -88, -109, -109,  -84, -109,  -76,  -85,
 -164,    0,    0, -164, -109,  -89,  -89, -213, -275, -275,
 -109, -109, -109, -109, -109, -109,  -50, -275, -275,  -71,
    0, -157, -109,  -75, -197,    0,    0,    0,    0,  -75,
    0,  -89,  -89,  -75,  -75,  -75,  -75,  -75,  -75,    0,
    0,    0,    0,  -39,    0,  -75,    0, -109, -229,  -49,
 -164,    0,  -75,    0, -109,    0, -164,  -75,  -38,    0,
  -36,    0,    0, -164, -164,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -217,    0,    0, -205,    0,    0,
    0,  -65,    0,    0,    0,    0,    0,    0, -255,    0,
    0,    0,  -67, -192,    0,    0,    0,    0, -237,    0,
    0,    0,    0,    0, -138,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -256,    0,    0,    0, -176,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -145,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -61,    0,    0, -237,    0, -111,  -77,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -132,    0,    0,    0,    0,    0,  -41,
    0,  -43,   -9, -234, -190, -174, -107,  -80,  -79,    0,
    0,    0,    0,    0,    0, -245,    0,    0, -176,    0,
 -150,    0, -128,    0,    0,    0, -150,  -26, -187,    0,
    0,    0,    0, -150, -150,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  224,    0,  -29,    0,    0,  214,    0,    0,
  216,    0,    0,  123,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -55,  178,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    3,  105,    0,
};
#define YYTABLESIZE 289
static const short yytable[] = {                         51,
   78,    6,   48,   48,    3,    6,    4,   56,    6,    6,
   92,    6,   94,   33,   33,    6,    6,   57,   58,  100,
   73,   69,   54,   55,   70,  104,  105,  106,  107,  108,
  109,   48,    6,   55,   48,    6,    5,  116,    6,    5,
    6,   98,   33,    5,   99,   33,    5,    5,   74,    5,
   54,   11,   11,    5,    5,   11,   76,   77,   11,   79,
   80,   11,  123,   13,   10,   11,   11,   56,   10,  128,
  101,   10,   40,    5,   10,   14,    5,   56,   10,   10,
    5,  102,  103,   58,    5,   11,  117,    5,   11,  118,
    5,  126,   29,   58,    5,    5,   30,  130,   10,   31,
   40,   10,   32,   40,  136,  137,   33,   34,   54,   54,
   19,    5,   61,   61,   61,   79,   80,    5,   20,   27,
   50,   50,   61,   61,   28,   24,  115,   61,   61,   35,
   64,   61,   61,   61,   61,   61,   61,   54,   61,   21,
   54,   61,   61,   66,   50,   61,   62,   62,   62,   50,
   57,   73,   50,   32,   73,   74,   62,   62,   74,   26,
   57,   62,   62,   54,   55,   62,   62,   62,   62,   62,
   62,   48,   62,   56,   53,   62,   62,   60,   59,   62,
   63,   63,   63,   57,   58,   88,   89,   60,   59,   68,
   63,   63,  111,  112,   75,   63,   63,   79,   80,   63,
   63,   63,   63,   63,   63,   90,   63,   93,   97,   63,
   63,   96,  113,   63,   64,   64,   64,  110,  122,  125,
  132,  134,    9,   54,   64,   64,   54,   45,    8,   64,
   64,   46,   25,   64,   64,   64,   64,   64,   64,   47,
   64,  124,   91,   64,   64,    0,    0,   64,   65,   65,
   65,    0,    0,    0,    0,    0,    0,    0,   65,   65,
    0,    0,    0,   65,   65,    0,    0,   65,   65,   65,
   65,   65,   65,    0,   65,    0,    0,   65,   65,   79,
   80,   65,    0,   81,   82,   83,   84,   85,   86,
};
static const short yycheck[] = {                         29,
   56,  257,  259,  260,  266,  261,  294,  283,  264,  265,
   66,  267,   68,  259,  260,  271,  272,  293,  294,   75,
  260,  284,  260,  258,  287,   81,   82,   83,   84,   85,
   86,  288,  288,  268,  291,  291,  288,   93,  294,  257,
  270,   71,  288,  261,   74,  291,  264,  265,  288,  267,
  288,  257,  294,  271,  272,  261,   54,   55,  264,  273,
  274,  267,  118,  291,  257,  271,  272,  258,  261,  125,
  284,  264,  260,  291,  267,  265,  294,  268,  271,  272,
  257,   79,   80,  258,  261,  291,  284,  264,  294,  287,
  267,  121,  257,  268,  271,  272,  261,  127,  291,  264,
  288,  294,  267,  291,  134,  135,  271,  272,  259,  260,
  288,  288,  258,  259,  260,  273,  274,  294,  287,  283,
  259,  260,  268,  269,  288,  288,  284,  273,  274,  294,
  283,  277,  278,  279,  280,  281,  282,  288,  284,  294,
  291,  287,  288,  283,  283,  291,  258,  259,  260,  288,
  258,  284,  291,  292,  287,  284,  268,  269,  287,  294,
  268,  273,  274,  273,  274,  277,  278,  279,  280,  281,
  282,  294,  284,  283,  294,  287,  288,  258,  258,  291,
  258,  259,  260,  293,  294,  275,  276,  268,  268,  283,
  268,  269,   88,   89,  292,  273,  274,  273,  274,  277,
  278,  279,  280,  281,  282,  294,  284,  292,  294,  287,
  288,  288,  284,  291,  258,  259,  260,  268,  258,  269,
  259,  258,  288,  291,  268,  269,  288,  269,    5,  273,
  274,  258,   19,  277,  278,  279,  280,  281,  282,   24,
  284,  119,   65,  287,  288,   -1,   -1,  291,  258,  259,
  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,
   -1,   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,   -1,   -1,  287,  288,  273,
  274,  291,   -1,  277,  278,  279,  280,  281,  282,
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
"proc_name : IDENT",
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
"$$5 :",
"assignment_statement : IDENT $$5 ASSIGN expression",
"$$6 :",
"$$7 :",
"$$8 :",
"if_statement : IF condition $$6 THEN $$7 statement $$8 else_statement",
"$$9 :",
"else_statement : ELSE $$9 statement",
"else_statement :",
"$$10 :",
"$$11 :",
"$$12 :",
"while_statement : WHILE $$10 condition $$11 DO $$12 statement",
"$$13 :",
"$$14 :",
"for_statement : FOR IDENT ASSIGN expression $$13 TO expression $$14 DO statement",
"proc_call_statement : proc_call_name",
"proc_call_statement : proc_call_name LPAREN arg_list RPAREN",
"proc_call_name : IDENT",
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
#line 438 "parser.y"
int yyerror(char *s)
{
  fprintf(stderr, "%s(%d: \'%s\')\n", s, yylineno, yytext);
  return 0;
}
#line 425 "y.tab.c"

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
	{ defineRet(INT32);delete(); }
break;
case 15:
#line 101 "parser.y"
	{
            Factor proc_name = factorpop();
            doProcedure(proc_name.vname, 0, args);
          }
break;
case 16:
#line 104 "parser.y"
	{
            defineRet(VOID);
            delete();
          }
break;
case 17:
#line 108 "parser.y"
	{
            Factor f = factorpop();
            doProcedure(f.vname, arity, args);
          }
break;
case 18:
#line 111 "parser.y"
	{
            defineRet(VOID);
            delete();
          }
break;
case 19:
#line 118 "parser.y"
	{ insert(yystack.l_mark[0].ident, PROC_NAME, 0); }
break;
case 32:
#line 143 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 33:
#line 143 "parser.y"
	{
            Factor arg1, arg2;
            arg1 = factorpop();
            arg2 = factorpop();
            defineStore(arg1, arg2);
          }
break;
case 34:
#line 152 "parser.y"
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
case 35:
#line 161 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg2 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          }
break;
case 36:
#line 165 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br2 = defineBr(1);
            pushLabelSyntax(lsyntax);
          }
break;
case 37:
#line 169 "parser.y"
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
case 38:
#line 181 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg3 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          }
break;
case 39:
#line 185 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br3 = defineBr(1);
            pushLabelSyntax(lsyntax);
          }
break;
case 41:
#line 194 "parser.y"
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
case 42:
#line 204 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2 = defineBrCondition(1, 1); /* LABEL2またはLABEL3へのジャンプ命令を定義して，LLVM命令の場所を記憶*/
            pushLabelSyntax(lsyntax);
            /* displayLabelSyntax(lsyntax);*/
          }
break;
case 43:
#line 209 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2->args.brcond.arg2 = defineLabel()->args.label.l; /* LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入*/
            pushLabelSyntax(lsyntax);
            /* displayLabelSyntax(lsyntax);*/
          }
break;
case 44:
#line 214 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            defineBr(lsyntax.args.While.label1); /* LABEL1へジャンプするBR命令を定義*/
            lsyntax.args.While.br2->args.brcond.arg3 = defineLabel()->args.label.l; /* LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入*/
            /* displayLabelSyntax(lsyntax);*/
          }
break;
case 45:
#line 223 "parser.y"
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
case 46:
#line 244 "parser.y"
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
case 47:
#line 259 "parser.y"
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
case 48:
#line 279 "parser.y"
	{
            Factor f, args[10];
            f = factorpop();
            defineCall(f, 0, args);
          }
break;
case 49:
#line 284 "parser.y"
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
            defineCall(f, arity, args);
          }
break;
case 50:
#line 300 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 52:
#line 308 "parser.y"
	{
            useRead = 1;
            lookup(yystack.l_mark[-1].ident);
            defineScanf();
          }
break;
case 53:
#line 316 "parser.y"
	{
            useWrite = 1;

            Factor arg1;
            arg1 = factorpop();
            definePrintf(arg1);
          }
break;
case 55:
#line 330 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(EQUAL, arg1, arg2);
          }
break;
case 56:
#line 336 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(NE, arg1, arg2);
          }
break;
case 57:
#line 342 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLT, arg1, arg2);
          }
break;
case 58:
#line 348 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLE, arg1, arg2);
          }
break;
case 59:
#line 354 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGT, arg1, arg2);
          }
break;
case 60:
#line 360 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGE, arg1, arg2);
          }
break;
case 64:
#line 372 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineAdd(arg1, arg2);
          }
break;
case 65:
#line 379 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineSub(arg1, arg2);
          }
break;
case 67:
#line 390 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineMul(arg1, arg2);
          }
break;
case 68:
#line 397 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineDiv(arg1, arg2);
          }
break;
case 70:
#line 408 "parser.y"
	{ pushNumber(yystack.l_mark[0].num); }
break;
case 72:
#line 413 "parser.y"
	{ lookup(yystack.l_mark[0].ident);
            Factor arg1;
            arg1 = factorpop();

            if (arg1.type == GLOBAL_VAR) defineLoad(arg1);
            else if (arg1.type == LOCAL_VAR) defineLoad(arg1);
            else factorpush(arg1);
          }
break;
case 75:
#line 429 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR, 0); }
break;
case 76:
#line 430 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR, 0); }
break;
case 77:
#line 434 "parser.y"
	{ strcpy(args[0], yystack.l_mark[0].ident);arity = 1; }
break;
case 78:
#line 435 "parser.y"
	{ strcpy(args[arity], yystack.l_mark[0].ident);arity++; }
break;
#line 1030 "y.tab.c"
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
