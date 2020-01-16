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

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
extern Fundecl *declhd;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
extern Fundecl *decltl;

extern LabelSyntaxStack lstack;

#line 32 "parser.y"
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
#line 60 "y.tab.c"

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
    4,   10,   10,   11,   12,   13,   14,   15,   15,    5,
    5,    5,    5,    5,    5,    5,    5,    5,   25,   16,
   28,   29,   31,   17,   32,   30,   30,   33,   34,   35,
   18,   19,   20,   36,   22,   23,   24,   21,   27,   27,
   27,   27,   27,   27,   26,   26,   26,   26,   26,   37,
   37,   37,   38,   38,   38,   39,   40,   40,    9,    9,
};
static const short yylen[] = {                            2,
    0,    6,    0,    4,    0,    2,    3,    1,    2,    2,
    0,    3,    1,    1,    4,    1,    2,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    0,    4,
    0,    0,    0,    8,    0,    3,    0,    0,    0,    0,
    7,    8,    1,    1,    3,    4,    4,    0,    3,    3,
    3,    3,    3,    3,    1,    2,    2,    3,    3,    1,
    3,    3,    1,    1,    3,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
   69,    0,    2,    0,    3,    0,   13,   14,    0,    0,
   16,    0,    0,    0,    7,   70,    0,    0,    0,    0,
    0,   38,    0,    0,    4,   20,   21,   22,   23,   24,
   25,   26,   27,   28,   43,   12,    0,   15,   19,    0,
    0,    0,    0,    0,   64,   66,    0,   31,    0,   60,
   63,    0,    0,    0,    0,   17,   45,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   39,    0,    0,   18,    0,   65,
    0,    0,    0,    0,    0,    0,    0,    0,   32,   61,
   62,   46,    0,   47,    0,    0,    0,   40,    0,   33,
    0,    0,    0,   41,   42,   35,   34,    0,   36,
};
static const short yydgoto[] = {                          1,
    2,    7,    8,   15,   35,   23,    9,   10,   12,   16,
   17,   18,   22,   48,   50,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   65,   57,   58,   81,  107,  117,
  113,  118,   63,  103,  111,   45,   59,   60,   61,    0,
};
static const short yysindex[] = {                         0,
    0, -237, -246, -231, -210, -214, -204, -184, -196,    0,
    0, -193,    0, -199,    0, -179,    0,    0, -210, -180,
    0, -178, -159, -184,    0,    0, -210, -159, -172,  -41,
 -167,    0, -160,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -159,    0,    0, -257,
 -177, -279, -279,  -41,    0,    0,  -17,    0, -269,    0,
    0, -146,  -41, -145, -158,    0,    0, -159,  -41, -269,
 -269, -218, -279, -279,  -41,  -41,  -41,  -41,  -41,  -41,
 -117, -279, -279, -127,    0, -122,  -41,    0, -261,    0,
 -269, -269, -264, -264, -264, -264, -264, -264,    0,    0,
    0,    0,  -82,    0, -264,  -41, -159,    0, -253,    0,
 -159, -159,  -81,    0,    0,    0,    0, -159,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -220,    0,    0, -203,    0,    0,
    0, -108,    0,    0,    0,    0,    0,    0, -229,    0,
    0,    0, -107, -194,    0,    0, -168, -249,    0,    0,
    0,    0,    0, -242,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -105,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -141,    0,
    0,    0,    0,    0,    0,    0,    0, -249,    0, -114,
  -87,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -60,  -33, -186, -157, -137, -116,  -89,  -83,    0,    0,
    0,    0,    0,    0, -135,    0, -130,    0,    0,    0,
 -130, -130, -258,    0,    0,    0,    0, -130,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  161,    0,  -28,    0,    0,  170,    0,    0,
  172,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -53,  139,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   33,   -7,    0,    0,
};
#define YYTABLESIZE 265
static const short yytable[] = {                         49,
   72,   37,   67,   54,  112,   82,   83,  106,   73,   74,
   48,   73,   74,   55,   56,   89,   44,   44,   66,   73,
   74,   93,   94,   95,   96,   97,   98,    6,    3,   37,
   68,    6,   37,  105,    6,    6,    5,    6,   48,   88,
    5,    6,    6,    5,    5,   44,    5,    4,   44,   29,
    5,    5,  109,   11,   73,   74,    5,   11,    6,    6,
   11,    6,   10,   11,    6,   90,   10,   11,   11,   10,
    5,   49,   10,    5,  100,  101,   10,   10,  110,   11,
   14,   49,  114,  115,   70,   71,   13,   11,    5,  119,
   11,   19,    5,   20,   21,    5,   10,   28,    5,   10,
   50,   29,    5,    5,   30,   91,   92,   31,   24,   27,
   50,   32,   33,   26,   69,   62,   55,   55,   55,    5,
   52,   51,   64,   30,   30,    5,   55,   55,   48,   48,
   52,   55,   55,   87,   34,   55,   55,   55,   55,   55,
   55,   51,   55,   56,   56,   56,   55,   84,   86,   55,
   99,   51,   30,   56,   56,   30,  102,   48,   56,   56,
   48,  104,   56,   56,   56,   56,   56,   56,   54,   56,
   57,   57,   57,   56,   53,  108,   56,  116,   54,    9,
   57,   57,   48,   48,   53,   57,   57,   47,   25,   57,
   57,   57,   57,   57,   57,   46,   57,   58,   58,   58,
   57,   85,    0,   57,    0,    0,    0,   58,   58,    0,
    0,    0,   58,   58,    0,    0,   58,   58,   58,   58,
   58,   58,    0,   58,   59,   59,   59,   58,    0,    0,
   58,   52,   53,    0,   59,   59,    0,    0,    0,   59,
   59,   54,    0,   59,   59,   59,   59,   59,   59,    0,
   59,   55,   56,    0,   59,   73,   74,   59,    0,   75,
   76,   77,   78,   79,   80,
};
static const short yycheck[] = {                         28,
   54,  260,  260,  283,  258,  275,  276,  269,  273,  274,
  260,  273,  274,  293,  294,   69,  259,  260,   47,  273,
  274,   75,   76,   77,   78,   79,   80,  257,  266,  288,
  288,  261,  291,   87,  264,  265,  257,  267,  288,   68,
  261,  271,  272,  264,  265,  288,  267,  294,  291,  292,
  271,  272,  106,  257,  273,  274,  288,  261,  288,  270,
  264,  291,  257,  267,  294,  284,  261,  271,  272,  264,
  291,  258,  267,  294,   82,   83,  271,  272,  107,  294,
  265,  268,  111,  112,   52,   53,  291,  291,  257,  118,
  294,  288,  261,  287,  294,  264,  291,  257,  267,  294,
  258,  261,  271,  272,  264,   73,   74,  267,  288,  288,
  268,  271,  272,  294,  292,  283,  258,  259,  260,  288,
  258,  294,  283,  259,  260,  294,  268,  269,  259,  260,
  268,  273,  274,  292,  294,  277,  278,  279,  280,  281,
  282,  258,  284,  258,  259,  260,  288,  294,  294,  291,
  268,  268,  288,  268,  269,  291,  284,  288,  273,  274,
  291,  284,  277,  278,  279,  280,  281,  282,  258,  284,
  258,  259,  260,  288,  258,  258,  291,  259,  268,  288,
  268,  269,  288,  291,  268,  273,  274,   27,   19,  277,
  278,  279,  280,  281,  282,   24,  284,  258,  259,  260,
  288,   63,   -1,  291,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,
  291,  273,  274,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,  283,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,  293,  294,   -1,  288,  273,  274,  291,   -1,  277,
  278,  279,  280,  281,  282,
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
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
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
"$$3 :",
"assignment_statement : IDENT $$3 ASSIGN expression",
"$$4 :",
"$$5 :",
"$$6 :",
"if_statement : IF condition $$4 THEN $$5 statement $$6 else_statement",
"$$7 :",
"else_statement : ELSE $$7 statement",
"else_statement :",
"$$8 :",
"$$9 :",
"$$10 :",
"while_statement : WHILE $$8 condition $$9 DO $$10 statement",
"for_statement : FOR IDENT ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"write_statement : WRITE LPAREN IDENT RPAREN",
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
#line 332 "parser.y"
int yyerror(char *s)
{
  fprintf(stderr, "%s(%d: \'%s\')\n", s, yylineno, yytext);
  return 0;
}
#line 398 "y.tab.c"

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
#line 55 "parser.y"
	{
            fstack.top = 0;
            lstack.top = 0;
          }
break;
case 2:
#line 58 "parser.y"
	{ outputCode(); }
break;
case 3:
#line 62 "parser.y"
	{ doProcedure("main"); }
break;
case 4:
#line 62 "parser.y"
	{ delete(); }
break;
case 15:
#line 94 "parser.y"
	{ delete(); }
break;
case 16:
#line 98 "parser.y"
	{ insert(yystack.l_mark[0].ident, PROC_NAME); }
break;
case 29:
#line 123 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 30:
#line 123 "parser.y"
	{
            Factor arg1, arg2;
            arg1 = factorpop();
            arg2 = factorpop();
            defineStore(arg1, arg2);
          }
break;
case 31:
#line 132 "parser.y"
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
case 32:
#line 141 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg2 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          }
break;
case 33:
#line 145 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br2 = defineBr(1);
            pushLabelSyntax(lsyntax);
          }
break;
case 34:
#line 149 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            int label1 = defineLabel()->args.label.l;
            lsyntax.args.If.br2->args.bruncond.arg1 = label1;
            if (lsyntax.args.If.br3 != NULL) {
              lsyntax.args.If.br3->args.bruncond.arg1 = label1;
              lsyntax.args.If.br1->args.brcond.arg3 = label1;
            }
          }
break;
case 35:
#line 161 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg3 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          }
break;
case 36:
#line 165 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br3 = defineBr(1);
            pushLabelSyntax(lsyntax);
          }
break;
case 38:
#line 174 "parser.y"
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
case 39:
#line 184 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2 = defineBrCondition(1, 1); /* LABEL2またはLABEL3へのジャンプ命令を定義して，LLVM命令の場所を記憶*/
            pushLabelSyntax(lsyntax);
            /* displayLabelSyntax(lsyntax);*/
          }
break;
case 40:
#line 189 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2->args.brcond.arg2 = defineLabel()->args.label.l; /* LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入*/
            pushLabelSyntax(lsyntax);
            /* displayLabelSyntax(lsyntax);*/
          }
break;
case 41:
#line 194 "parser.y"
	{
            LabelSyntax lsyntax = popLabelSyntax();
            defineBr(lsyntax.args.While.label1); /* LABEL1へジャンプするBR命令を定義*/
            lsyntax.args.While.br2->args.brcond.arg3 = defineLabel()->args.label.l; /* LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入*/
            /* displayLabelSyntax(lsyntax);*/
          }
break;
case 44:
#line 211 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 46:
#line 219 "parser.y"
	{ lookup(yystack.l_mark[-1].ident); }
break;
case 47:
#line 223 "parser.y"
	{ lookup(yystack.l_mark[-1].ident); }
break;
case 49:
#line 231 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(EQUAL, arg1, arg2);
          }
break;
case 50:
#line 237 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(NE, arg1, arg2);
          }
break;
case 51:
#line 243 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLE, arg1, arg2);
          }
break;
case 52:
#line 249 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLE, arg1, arg2);
          }
break;
case 53:
#line 255 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGT, arg1, arg2);
          }
break;
case 54:
#line 261 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGE, arg1, arg2);
          }
break;
case 58:
#line 273 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineAdd(arg1, arg2);
          }
break;
case 59:
#line 280 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineSub(arg1, arg2);
          }
break;
case 61:
#line 291 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineMul(arg1, arg2);
          }
break;
case 62:
#line 298 "parser.y"
	{
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineDiv(arg1, arg2);
          }
break;
case 64:
#line 309 "parser.y"
	{ pushNumber(yystack.l_mark[0].num); }
break;
case 66:
#line 314 "parser.y"
	{ lookup(yystack.l_mark[0].ident);
            Factor arg1;
            arg1 = factorpop();

            defineLoad(arg1);
          }
break;
case 69:
#line 328 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR); }
break;
case 70:
#line 329 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR); }
break;
#line 869 "y.tab.c"
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
