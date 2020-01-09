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
    1,    0,    6,    2,    3,    3,    7,    7,    8,    4,
    4,   10,   10,   11,   12,   13,   14,   15,   15,    5,
    5,    5,    5,    5,    5,    5,    5,    5,   25,   16,
   17,   28,   28,   18,   19,   20,   29,   22,   23,   24,
   21,   27,   27,   27,   27,   27,   27,   26,   26,   26,
   26,   26,   30,   30,   30,   31,   31,   31,   32,   33,
   33,    9,    9,
};
static const short yylen[] = {                            2,
    0,    6,    0,    4,    0,    2,    3,    1,    2,    2,
    0,    3,    1,    1,    4,    1,    2,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    0,    4,
    5,    2,    0,    4,    8,    1,    1,    3,    4,    4,
    0,    3,    3,    3,    3,    3,    3,    1,    2,    2,
    3,    3,    1,    3,    3,    1,    1,    3,    1,    1,
    3,    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
   62,    0,    2,    0,    3,    0,   13,   14,    0,    0,
   16,    0,    0,    0,    7,   63,    0,    0,    0,    0,
    0,    0,    0,    0,    4,   20,   21,   22,   23,   24,
   25,   26,   27,   28,   36,   12,    0,   15,   19,    0,
    0,    0,    0,    0,   57,   59,    0,    0,    0,   53,
   56,    0,    0,    0,    0,   17,   38,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   18,    0,   58,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   54,
   55,   39,   34,   40,    0,    0,    0,   31,    0,   32,
    0,   35,
};
static const short yydgoto[] = {                          1,
    2,    7,    8,   15,   35,   23,    9,   10,   12,   16,
   17,   18,   22,   48,   50,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   65,   57,   58,  108,   45,   59,
   60,   61,    0,
};
static const short yysindex[] = {                         0,
    0, -262, -287, -258, -223, -244, -239, -204, -203,    0,
    0, -198,    0, -230,    0, -188,    0,    0, -223, -189,
    0, -164, -173, -204,    0,    0, -223, -173, -169,  -41,
 -145,  -41, -142,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -173,    0,    0, -246,
 -133, -224, -224,  -41,    0,    0,  -23, -136, -263,    0,
    0, -128, -106, -126, -119,    0,    0, -173,  -41, -263,
 -263, -264, -224, -224,  -41,  -41,  -41,  -41,  -41,  -41,
 -173, -224, -224, -110, -173, -105,  -41,    0, -104,    0,
 -263, -263, -160, -160, -160, -160, -160, -160,  -73,    0,
    0,    0,    0,    0, -160,  -41, -173,    0, -252,    0,
 -173,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -216,    0,    0, -199,    0,    0,
    0,  -96,    0,    0,    0,    0,    0,    0, -228,    0,
    0,    0,  -98, -190,    0,    0, -256, -242,    0,    0,
    0,    0,    0, -149,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -93,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -151,    0,
    0,    0,    0,    0,    0,    0,    0, -242,    0, -124,
  -97,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -140,    0,    0,    0, -140,    0,    0,    0,    0,    0,
  -70,  -43, -182, -178, -171, -165, -162, -156, -257,    0,
    0,    0,    0,    0, -113,    0, -140,    0,    0,    0,
 -140,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  169,    0,  -28,    0,    0,  178,    0,    0,
  176,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -52,  173,    0,    0,  149,
   33,    0,    0,
};
#define YYTABLESIZE 259
static const short yytable[] = {                         49,
    5,   72,   33,    3,    5,  111,    4,    5,   73,   74,
    5,   82,   83,   67,    5,    5,   89,   41,   66,   90,
   73,   74,   93,   94,   95,   96,   97,   98,    6,    5,
   33,    5,    6,   33,  105,    6,    6,    5,    6,   88,
    5,   68,    6,    6,    5,   41,    6,    5,    5,   11,
    5,   13,   99,  109,    5,    5,  103,   11,   54,    6,
   14,   11,    6,   21,   11,    6,   10,   11,   55,   56,
   10,   11,   11,   10,    5,   42,   10,    5,  110,   43,
   10,   10,  112,   28,   19,   42,   45,   29,   20,   43,
   30,   11,   44,   31,   11,   47,   45,   32,   33,   24,
   10,   46,   44,   10,   26,   47,   48,   48,   48,   37,
   37,   46,   73,   74,  100,  101,   48,   48,   41,   41,
   34,   48,   48,   27,   51,   48,   48,   48,   48,   48,
   48,   81,   48,   49,   49,   49,   48,   62,   37,   48,
   64,   37,   29,   49,   49,   30,   30,   41,   49,   49,
   41,   85,   49,   49,   49,   49,   49,   49,   69,   49,
   50,   50,   50,   49,  106,   84,   49,   86,   73,   74,
   50,   50,   87,  102,   30,   50,   50,   30,  104,   50,
   50,   50,   50,   50,   50,  107,   50,   51,   51,   51,
   50,    9,   41,   50,   41,   47,   25,   51,   51,   46,
   70,   71,   51,   51,   63,    0,   51,   51,   51,   51,
   51,   51,    0,   51,   52,   52,   52,   51,    0,    0,
   51,   91,   92,    0,   52,   52,    0,    0,    0,   52,
   52,   52,   53,   52,   52,   52,   52,   52,   52,    0,
   52,   54,    0,    0,   52,    0,    0,   52,    0,   73,
   74,   55,   56,   75,   76,   77,   78,   79,   80,
};
static const short yycheck[] = {                         28,
  257,   54,  260,  266,  261,  258,  294,  264,  273,  274,
  267,  275,  276,  260,  271,  272,   69,  260,   47,  284,
  273,  274,   75,   76,   77,   78,   79,   80,  257,  288,
  288,  288,  261,  291,   87,  264,  265,  294,  267,   68,
  257,  288,  271,  272,  261,  288,  270,  264,  265,  294,
  267,  291,   81,  106,  271,  272,   85,  257,  283,  288,
  265,  261,  291,  294,  264,  294,  257,  267,  293,  294,
  261,  271,  272,  264,  291,  258,  267,  294,  107,  258,
  271,  272,  111,  257,  288,  268,  258,  261,  287,  268,
  264,  291,  258,  267,  294,  258,  268,  271,  272,  288,
  291,  258,  268,  294,  294,  268,  258,  259,  260,  259,
  260,  268,  273,  274,   82,   83,  268,  269,  259,  260,
  294,  273,  274,  288,  294,  277,  278,  279,  280,  281,
  282,  268,  284,  258,  259,  260,  288,  283,  288,  291,
  283,  291,  292,  268,  269,  259,  260,  288,  273,  274,
  291,  258,  277,  278,  279,  280,  281,  282,  292,  284,
  258,  259,  260,  288,  269,  294,  291,  294,  273,  274,
  268,  269,  292,  284,  288,  273,  274,  291,  284,  277,
  278,  279,  280,  281,  282,  259,  284,  258,  259,  260,
  288,  288,  291,  291,  288,   27,   19,  268,  269,   24,
   52,   53,  273,  274,   32,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,
  291,   73,   74,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,  273,  274,  277,  278,  279,  280,  281,  282,   -1,
  284,  283,   -1,   -1,  288,   -1,   -1,  291,   -1,  273,
  274,  293,  294,  277,  278,  279,  280,  281,  282,
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
#line 194 "parser.y"
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
	{ init_fstack(); }
break;
case 2:
#line 42 "parser.y"
	{ outputCode(); }
break;
case 3:
#line 46 "parser.y"
	{ doProcedure("main"); }
break;
case 4:
#line 46 "parser.y"
	{ delete(); }
break;
case 15:
#line 78 "parser.y"
	{ delete(); }
break;
case 16:
#line 82 "parser.y"
	{ insert(yystack.l_mark[0].ident, PROC_NAME); }
break;
case 29:
#line 107 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 30:
#line 107 "parser.y"
	{ doAssign(); }
break;
case 37:
#line 132 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 39:
#line 140 "parser.y"
	{ lookup(yystack.l_mark[-1].ident); }
break;
case 40:
#line 144 "parser.y"
	{ lookup(yystack.l_mark[-1].ident); }
break;
case 51:
#line 164 "parser.y"
	{ doAdd(); }
break;
case 52:
#line 165 "parser.y"
	{ doSub(); }
break;
case 57:
#line 176 "parser.y"
	{ pushNumber(yystack.l_mark[0].num); }
break;
case 59:
#line 181 "parser.y"
	{ lookup(yystack.l_mark[0].ident);doReference(); }
break;
case 62:
#line 190 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR); }
break;
case 63:
#line 191 "parser.y"
	{ insert(yystack.l_mark[0].ident, UNDEFINED_VAR); }
break;
#line 649 "y.tab.c"
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
