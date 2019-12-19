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

#line 19 "parser.y"
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
#line 47 "y.tab.c"

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
    0,    5,    1,    2,    2,    6,    6,    7,    3,    3,
    9,    9,   10,   11,   12,   13,   14,   14,    4,    4,
    4,    4,    4,    4,    4,    4,    4,   15,   16,   26,
   26,   17,   18,   19,   27,   21,   22,   23,   20,   25,
   25,   25,   25,   25,   25,   24,   24,   24,   24,   24,
   28,   28,   28,   29,   29,   29,   30,   31,   31,    8,
    8,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    2,    2,    0,
    3,    1,    1,    4,    1,    2,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    3,    5,    2,
    0,    4,    8,    1,    1,    3,    4,    4,    0,    3,
    3,    3,    3,    3,    3,    1,    2,    2,    3,    3,
    1,    3,    3,    1,    1,    3,    1,    1,    3,    1,
    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,   60,
    0,    1,    0,    2,    0,   12,   13,    0,    0,   15,
    0,    0,    0,    6,   61,    0,    0,    0,    0,    0,
    0,    0,    0,    3,   19,   20,   21,   22,   23,   24,
   25,   26,   27,   34,   11,    0,   14,   18,    0,    0,
    0,    0,    0,   55,   57,    0,    0,    0,   51,   54,
    0,    0,    0,    0,   16,   36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   17,    0,   56,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   52,   53,
   37,   32,   38,    0,    0,   29,    0,   30,    0,   33,
};
static const short yydgoto[] = {                          2,
    6,    7,   14,   34,   22,    8,    9,   11,   15,   16,
   17,   21,   47,   49,   35,   36,   37,   38,   39,   40,
   41,   42,   43,   56,   57,  106,   44,   58,   59,   60,
    0,
};
static const short yysindex[] = {                      -258,
 -274,    0, -243, -202, -222, -217, -190, -208,    0,    0,
 -182,    0, -178,    0, -165,    0,    0, -202, -170,    0,
 -156, -150, -190,    0,    0, -202, -150, -164, -154, -197,
 -154, -148, -149,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -150,    0,    0, -255, -135,
 -279, -279, -154,    0,    0,   -8, -130, -269,    0,    0,
 -136,  -98, -129, -154,    0,    0, -150, -154, -269, -269,
 -263, -279, -279, -154, -154, -154, -154, -154, -154, -150,
 -279, -279, -122, -150, -117, -226,    0, -103,    0, -269,
 -269, -226, -226, -226, -226, -226, -226,  -81,    0,    0,
    0,    0,    0, -154, -150,    0, -219,    0, -150,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -201,    0,    0, -188,    0,    0,    0,
 -104,    0,    0,    0,    0,    0,    0, -229,    0,    0,
    0, -106, -176,    0,    0, -163, -251,    0,    0,    0,
    0,    0, -257,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -101,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -132,    0,    0,
    0,    0,    0,    0,    0,    0, -251,    0, -105,  -78,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -242,
    0,    0,    0, -242,    0, -230,    0,    0,    0,  -51,
  -24, -191, -171, -169, -166, -158, -107, -247,    0,    0,
    0,    0,    0,    0, -242,    0,    0,    0, -242,    0,
};
static const short yygindex[] = {                         0,
    0,  162,    0,  -27,    0,    0,  171,    0,    0,  169,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -52,  163,    0,    0,   61,  -31,    0,
    0,
};
#define YYTABLESIZE 274
static const short yytable[] = {                         48,
   71,   35,   35,   53,   66,   81,   82,    1,   39,   72,
   73,   86,   31,   54,   55,   88,   39,   39,   65,    3,
   89,   92,   93,   94,   95,   96,   97,    5,   28,   28,
   35,    5,   67,   35,    5,    5,   39,    5,  109,   87,
   31,    5,    5,   31,    4,   39,   72,   73,   39,   99,
  100,  107,   98,   72,   73,    4,  102,   28,    5,    4,
   28,    5,    4,    4,    5,    4,   40,    5,   10,    4,
    4,   10,   10,   12,   13,   10,   40,  108,   10,   18,
    9,  110,   10,   10,    9,   61,   41,    9,   43,    4,
    9,   42,    4,    4,    9,    9,   41,    4,   43,   45,
    4,   42,   10,    4,   19,   10,   27,    4,    4,   45,
   28,   69,   70,   29,    9,   20,   30,    9,   51,   52,
   31,   32,   23,   25,    4,   46,   46,   46,   53,   50,
    4,   26,   90,   91,   63,   46,   46,   80,   54,   55,
   46,   46,   64,   33,   46,   46,   46,   46,   46,   46,
   44,   46,   47,   47,   47,   46,   68,   83,   46,   84,
   44,  101,   47,   47,   85,  104,  103,   47,   47,   72,
   73,   47,   47,   47,   47,   47,   47,  105,   47,   48,
   48,   48,   47,    8,   39,   47,   39,   46,   24,   48,
   48,   45,    0,   62,   48,   48,    0,    0,   48,   48,
   48,   48,   48,   48,    0,   48,   49,   49,   49,   48,
    0,    0,   48,    0,    0,    0,   49,   49,    0,    0,
    0,   49,   49,    0,    0,   49,   49,   49,   49,   49,
   49,    0,   49,   50,   50,   50,   49,    0,    0,   49,
    0,    0,    0,   50,   50,    0,    0,    0,   50,   50,
    0,    0,   50,   50,   50,   50,   50,   50,    0,   50,
    0,    0,    0,   50,   72,   73,   50,    0,   74,   75,
   76,   77,   78,   79,
};
static const short yycheck[] = {                         27,
   53,  259,  260,  283,  260,  275,  276,  266,  260,  273,
  274,   64,  260,  293,  294,   68,  259,  260,   46,  294,
  284,   74,   75,   76,   77,   78,   79,  257,  259,  260,
  288,  261,  288,  291,  264,  265,  288,  267,  258,   67,
  288,  271,  272,  291,  288,  288,  273,  274,  291,   81,
   82,  104,   80,  273,  274,  257,   84,  288,  288,  261,
  291,  291,  264,  265,  294,  267,  258,  270,  257,  271,
  272,  294,  261,  291,  265,  264,  268,  105,  267,  288,
  257,  109,  271,  272,  261,  283,  258,  264,  258,  291,
  267,  258,  294,  257,  271,  272,  268,  261,  268,  258,
  264,  268,  291,  267,  287,  294,  257,  271,  272,  268,
  261,   51,   52,  264,  291,  294,  267,  294,  273,  274,
  271,  272,  288,  294,  288,  258,  259,  260,  283,  294,
  294,  288,   72,   73,  283,  268,  269,  268,  293,  294,
  273,  274,  292,  294,  277,  278,  279,  280,  281,  282,
  258,  284,  258,  259,  260,  288,  292,  294,  291,  258,
  268,  284,  268,  269,  294,  269,  284,  273,  274,  273,
  274,  277,  278,  279,  280,  281,  282,  259,  284,  258,
  259,  260,  288,  288,  291,  291,  288,   26,   18,  268,
  269,   23,   -1,   31,  273,  274,   -1,   -1,  277,  278,
  279,  280,  281,  282,   -1,  284,  258,  259,  260,  288,
   -1,   -1,  291,   -1,   -1,   -1,  268,  269,   -1,   -1,
   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,
   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,   -1,   -1,  288,  273,  274,  291,   -1,  277,  278,
  279,  280,  281,  282,
};
#define YYFINAL 2
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
"program : PROGRAM IDENT SEMICOLON outblock PERIOD",
"$$1 :",
"outblock : var_decl_part subprog_decl_part $$1 statement",
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
"assignment_statement : IDENT ASSIGN expression",
"if_statement : IF condition THEN statement else_statement",
"else_statement : ELSE statement",
"else_statement :",
"while_statement : WHILE condition DO statement",
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
#line 193 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s(%d: \'%s\')\n", s, yylineno, yytext);
}
#line 375 "y.tab.c"

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
#line 42 "parser.y"
	{ outputCode(); }
break;
case 2:
#line 46 "parser.y"
	{ insert("main", PROC_NAME); }
break;
case 3:
#line 46 "parser.y"
	{ delete(); }
break;
case 14:
#line 78 "parser.y"
	{ delete(); }
break;
case 15:
#line 82 "parser.y"
	{ insert(yystack.l_mark[0].ident, PROC_NAME); }
break;
case 28:
#line 107 "parser.y"
	{ lookup(yystack.l_mark[-2].ident); }
break;
case 35:
#line 132 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 37:
#line 140 "parser.y"
	{ lookup(yystack.l_mark[-1].ident); }
break;
case 38:
#line 144 "parser.y"
	{ lookup(yystack.l_mark[-1].ident); }
break;
case 57:
#line 181 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 60:
#line 190 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR); }
break;
case 61:
#line 191 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR); }
break;
#line 629 "y.tab.c"
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
