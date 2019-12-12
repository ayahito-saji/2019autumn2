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

extern int yylineno;
extern char *yytext;

typedef enum {
  GLOBAL_VAR,
  LOCAL_VAR,
  PROC_NAME,
  CONSTANT
} Scope;

typedef struct {
  char *var_name;
  int reg;
  Scope scope;
  
} SymbolTable;

/* define stack and stack length */
SymbolTable symbol_table[1024];
int symbol_table_length = 0;
int is_local_variable = 0;

#line 36 "parser.y"
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
#line 64 "y.tab.c"

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
    0,    1,    2,    2,    5,    5,    6,    3,    3,    8,
    8,    9,   10,   11,   12,   13,   13,    4,    4,    4,
    4,    4,    4,    4,    4,    4,   14,   15,   25,   25,
   16,   17,   18,   26,   20,   21,   22,   19,   24,   24,
   24,   24,   24,   24,   23,   23,   23,   23,   23,   27,
   27,   27,   28,   28,   28,   29,   30,   30,    7,    7,
};
static const short yylen[] = {                            2,
    5,    3,    0,    2,    3,    1,    2,    2,    0,    3,
    1,    1,    4,    1,    2,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    5,    2,    0,
    4,    8,    1,    1,    3,    4,    4,    0,    3,    3,
    3,    3,    3,    3,    1,    2,    2,    3,    3,    1,
    3,    3,    1,    1,    3,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   59,
    0,    1,    0,    0,    0,   11,   12,    0,    0,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    2,   18,
   19,   20,   21,   22,   23,   24,   25,   26,   33,    0,
    5,   60,    0,   17,    0,    0,    0,    0,    0,   54,
   56,    0,    0,    0,   50,   53,    0,    0,    0,    0,
   10,    0,   13,   35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   15,   16,    0,   55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   51,   52,   36,
   31,   37,    0,    0,   28,    0,   29,    0,   32,
};
static const short yydgoto[] = {                          2,
    6,    7,   14,   29,    8,    9,   11,   15,   16,   17,
   21,   63,   45,   30,   31,   32,   33,   34,   35,   36,
   37,   38,   52,   53,  105,   39,   54,   55,   56,    0,
};
static const short yysindex[] = {                      -258,
 -284,    0, -256, -224, -264, -234, -206, -212,    0,    0,
 -208,    0, -229, -168, -205,    0,    0, -224, -209,    0,
 -196, -168, -181,  -50, -185,  -50, -176, -170,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -206,
    0,    0, -224,    0, -251, -145, -182, -182,  -50,    0,
    0,  -26, -115, -223,    0,    0, -120,  -79, -107,  -50,
    0, -168,    0,    0, -168,  -50, -223, -223, -104, -182,
 -182,  -50,  -50,  -50,  -50,  -50,  -50, -168, -182, -182,
 -124, -168,  -91, -134,    0,    0,  -98,    0, -223, -223,
 -134, -134, -134, -134, -134, -134,  -65,    0,    0,    0,
    0,    0,  -50, -168,    0, -125,    0, -168,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -203,    0,    0, -194,    0,    0,    0,
  -92,    0,    0,  -94,    0,    0,    0, -250,    0,    0,
    0, -213,    0,    0,    0,    0,    0, -257,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -177,
    0,    0, -222,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -150,    0,    0,    0,    0,    0,    0,
    0,  -90,    0,    0, -213,    0, -123,  -96,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -255,    0,    0,
    0, -255,    0, -240,    0,    0,    0,    0,  -69,  -42,
 -252, -245, -187, -152, -143, -116, -186,    0,    0,    0,
    0,    0,    0, -255,    0,    0,    0, -255,    0,
};
static const short yygindex[] = {                         0,
    0,  158,    0,  -22,    0,  184,    0,    0,  163,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -48,  180,    0,    0,   73,   87,    0,    0,
};
#define YYTABLESIZE 256
static const short yytable[] = {                         44,
   69,   34,   34,   38,   38,   39,    4,    1,   64,    3,
    4,   84,   40,    4,    4,   39,    4,   87,   27,   27,
    4,    4,   40,   91,   92,   93,   94,   95,   96,   10,
   34,    4,   38,   34,    3,   38,   65,    4,    3,   85,
    4,    3,   86,    4,    3,    5,   38,   27,    3,    3,
   27,   79,   80,    3,  106,   97,   12,    3,   13,  101,
    3,    3,    9,    3,   20,    3,    9,    3,    3,    9,
   42,    3,    9,   30,   38,   18,    9,    9,   19,    8,
   42,  107,   40,    8,   42,  109,    8,    3,   22,    8,
    3,   43,   23,    8,    8,   24,    9,   57,   25,    9,
   49,   30,   26,   27,   30,   41,   59,   45,   45,   45,
   50,   51,   46,    8,   44,   41,    8,   45,   45,   67,
   68,   60,   45,   45,   44,   28,   45,   45,   45,   45,
   45,   45,  108,   45,   46,   46,   46,   45,   70,   71,
   45,   43,   89,   90,   46,   46,   66,   70,   71,   46,
   46,   43,   78,   46,   46,   46,   46,   46,   46,  100,
   46,   47,   47,   47,   46,   98,   99,   46,   70,   71,
  103,   47,   47,   81,   70,   71,   47,   47,   82,   88,
   47,   47,   47,   47,   47,   47,   83,   47,   48,   48,
   48,   47,  102,  104,   47,    7,   38,   38,   48,   48,
   62,   41,   61,   48,   48,   58,    0,   48,   48,   48,
   48,   48,   48,    0,   48,   49,   49,   49,   48,    0,
    0,   48,   47,   48,    0,   49,   49,    0,    0,    0,
   49,   49,   49,    0,   49,   49,   49,   49,   49,   49,
    0,   49,   50,   51,    0,   49,   70,   71,   49,    0,
   72,   73,   74,   75,   76,   77,
};
static const short yycheck[] = {                         22,
   49,  259,  260,  259,  260,  258,  257,  266,  260,  294,
  261,   60,  258,  264,  265,  268,  267,   66,  259,  260,
  271,  272,  268,   72,   73,   74,   75,   76,   77,  294,
  288,  288,  288,  291,  257,  291,  288,  288,  261,   62,
  291,  264,   65,  294,  267,  270,  260,  288,  271,  272,
  291,  275,  276,  257,  103,   78,  291,  261,  265,   82,
  264,  265,  257,  267,  294,  288,  261,  271,  272,  264,
  258,  294,  267,  260,  288,  288,  271,  272,  287,  257,
  268,  104,  288,  261,  294,  108,  264,  291,  257,  267,
  294,  288,  261,  271,  272,  264,  291,  283,  267,  294,
  283,  288,  271,  272,  291,  258,  283,  258,  259,  260,
  293,  294,  294,  291,  258,  268,  294,  268,  269,   47,
   48,  292,  273,  274,  268,  294,  277,  278,  279,  280,
  281,  282,  258,  284,  258,  259,  260,  288,  273,  274,
  291,  258,   70,   71,  268,  269,  292,  273,  274,  273,
  274,  268,  268,  277,  278,  279,  280,  281,  282,  284,
  284,  258,  259,  260,  288,   79,   80,  291,  273,  274,
  269,  268,  269,  294,  273,  274,  273,  274,  258,  284,
  277,  278,  279,  280,  281,  282,  294,  284,  258,  259,
  260,  288,  284,  259,  291,  288,  291,  288,  268,  269,
   43,   18,   40,  273,  274,   26,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,  258,  259,  260,  288,   -1,
   -1,  291,  273,  274,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,  283,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,  293,  294,   -1,  288,  273,  274,  291,   -1,
  277,  278,  279,  280,  281,  282,
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
"outblock : var_decl_part subprog_decl_part statement",
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
#line 210 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s(%d: \'%s\')\n", s, yylineno, yytext);
}

void insert(char *vn, Scope scope)
{
  int i;
  char *var_name;

  var_name = (char *)malloc(128);
  strcpy(var_name, vn);

  // show action
  fprintf(stderr, "variable \'%s\' inserted!!(%d)\n", var_name, yylineno);
  fprintf(stderr, "--------------------------\n");


  // assignment to table
  symbol_table[symbol_table_length].var_name = var_name;
  symbol_table[symbol_table_length].reg = symbol_table_length + 2;
  symbol_table[symbol_table_length].scope = scope;
  symbol_table_length++;

  // show symbol table
  for (i=0;i<symbol_table_length;i++)
  {
    switch (symbol_table[i].scope)
    {
      case GLOBAL_VAR:
        fprintf(stderr, "%d. %s (GLOBAL_VAR, %d)\n", i, symbol_table[i].var_name, symbol_table[i].reg);
        break;

      case LOCAL_VAR:
        fprintf(stderr, "%d. %s (LOCAL_VAR, %d)\n", i, symbol_table[i].var_name, symbol_table[i].reg);
        break;

      case PROC_NAME:
        fprintf(stderr, "%d. %s (PROC_NAME, %d)\n", i, symbol_table[i].var_name, symbol_table[i].reg);
        break;

    }
  }
  fprintf(stderr, "\n");
}

int lookup(char *vn)
{
  int i;
  fprintf(stderr, "variable \'%s\' looked up!!(%d)\n", vn, yylineno);
  for (i=symbol_table_length-1;i>=0;i--)
  {
    if (strcmp(vn, symbol_table[i].var_name) == 0)
    {
      switch (symbol_table[i].scope)
      {
        case GLOBAL_VAR:
          fprintf(stderr, "GLOBAL_VAR\n");
          break;
        case LOCAL_VAR:
          fprintf(stderr, "LOCAL_VAR\n");
          break;
        case PROC_NAME:
          fprintf(stderr, "PROC_NAME\n");
          break;
      }
      fprintf(stderr, "\n");
      return i;
    }
  }
  return -1;
}

void delete()
{
  int i;
  SymbolTable target_symbol;
  fprintf(stderr, "deleted!!\n");
  fprintf(stderr, "--------------------------\n");
  while (1) {
    target_symbol = symbol_table[symbol_table_length-1];
    if (target_symbol.scope == LOCAL_VAR)
    {
      free(target_symbol.var_name);
      symbol_table_length --;
    }
    else break;
  }

  // show symbol table
  for (i=0;i<symbol_table_length;i++)
  {
    switch (symbol_table[i].scope)
    {
      case GLOBAL_VAR:
        fprintf(stderr, "%d. %s (GLOBAL_VAR, %d)\n", i, symbol_table[i].var_name, symbol_table[i].reg);
        break;

      case LOCAL_VAR:
        fprintf(stderr, "%d. %s (LOCAL_VAR, %d)\n", i, symbol_table[i].var_name, symbol_table[i].reg);
        break;

      case PROC_NAME:
        fprintf(stderr, "%d. %s (PROC_NAME, %d)\n", i, symbol_table[i].var_name, symbol_table[i].reg);
        break;

    }
  }
  fprintf(stderr, "\n");

  
}
#line 491 "y.tab.c"

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
case 13:
#line 95 "parser.y"
	{ delete();is_local_variable = 0; }
break;
case 14:
#line 99 "parser.y"
	{ insert(yystack.l_mark[0].ident, PROC_NAME); is_local_variable = 1; }
break;
case 27:
#line 124 "parser.y"
	{ lookup(yystack.l_mark[-2].ident); }
break;
case 34:
#line 149 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 36:
#line 157 "parser.y"
	{ lookup(yystack.l_mark[-1].ident); }
break;
case 37:
#line 161 "parser.y"
	{ lookup(yystack.l_mark[-1].ident); }
break;
case 56:
#line 198 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 59:
#line 207 "parser.y"
	{ insert(yystack.l_mark[0].ident, is_local_variable ? LOCAL_VAR : GLOBAL_VAR); }
break;
case 60:
#line 208 "parser.y"
	{ insert(yystack.l_mark[0].ident, is_local_variable ? LOCAL_VAR : GLOBAL_VAR); }
break;
#line 733 "y.tab.c"
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
