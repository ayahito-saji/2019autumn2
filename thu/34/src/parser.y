%{
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

%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS                       //← 注意
%left MULT DIV                         //← 注意

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACE RBRACE
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER                    //← yylval の型を指定
%token <ident> IDENT                   //← yylval の型を指定

%%

program
        : PROGRAM IDENT SEMICOLON outblock PERIOD
        ;

outblock
        : var_decl_part subprog_decl_part statement
        ;

var_decl_part
        : /* empty */
        | var_decl_list SEMICOLON
        ;

var_decl_list
        : var_decl_list SEMICOLON var_decl
        | var_decl
        ;

var_decl
        : VAR id_list
        ;

subprog_decl_part
        : subprog_decl_list SEMICOLON
        | /* empty */
        ;

subprog_decl_list
        : subprog_decl_list SEMICOLON subprog_decl
        | subprog_decl
        ;

subprog_decl
        : proc_decl
        ;

proc_decl
        : PROCEDURE proc_name SEMICOLON inblock
        ;

proc_name
        : IDENT
        ;

inblock
        : var_decl_part statement
        ;

statement_list
        : statement_list SEMICOLON statement
        | statement
        ;

statement
        : assignment_statement
        | if_statement
        | while_statement
        | for_statement
        | proc_call_statement
        | null_statement
        | block_statement
        | read_statement
        | write_statement
        ;

assignment_statement
        : IDENT ASSIGN expression
        ;

if_statement
        : IF condition THEN statement else_statement
        ;

else_statement
        : ELSE statement
        |
        ;

while_statement
        : WHILE condition DO statement
        ;

for_statement
        : FOR IDENT ASSIGN expression TO expression DO statement
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN
        ;

write_statement
        : WRITE LPAREN IDENT RPAREN
        ;

null_statement
        : /*empty*/
        ;

condition
        : expression EQ expression
        | expression NEQ expression
        | expression LT expression
        | expression LE expression
        | expression GT expression
        | expression GE expression
        ;

expression
        : term
        | PLUS term
        | MINUS term
        | expression PLUS term
        | expression MINUS term
        ;

term
        : factor
        | term MULT factor
        | term DIV factor
        ;

factor
        : var_name
        | NUMBER
        | LPAREN expression RPAREN
        ;

var_name
        : IDENT{ lookup($1); }
        ;

arg_list
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT { insert($1, GLOBAL_VAR); }
        | id_list COMMA IDENT { insert($3, GLOBAL_VAR); }

%% 
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
  fprintf(stderr, "variable \'%s\' inserted!!\n", var_name);
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
    }
  }
  fprintf(stderr, "\n");
}

int lookup(char *vn)
{
  int i;
  fprintf(stderr, "variable \'%s\' looked up!!\n", vn);
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
      }
      fprintf(stderr, "\n");
      return i;
    }
  }
  return -1;
}

void delete()
{
  fprintf(stderr, "deleted!!\n");
  while (symbol_table[i].scope == LOCAL_VAR)
  {

  }
}
