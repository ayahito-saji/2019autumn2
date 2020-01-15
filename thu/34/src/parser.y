%{
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
        : {
            fstack.top = 0;
            lstack.top = 0;
          } PROGRAM IDENT SEMICOLON outblock PERIOD { outputCode(); }
        ;

outblock
        : var_decl_part subprog_decl_part { doProcedure("main"); } statement { delete(); }
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
        : PROCEDURE proc_name SEMICOLON inblock { delete(); }
        ;

proc_name
        : IDENT { insert($1, PROC_NAME); }
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
        : IDENT { lookup($1); } ASSIGN expression {
            Factor arg1, arg2;
            arg1 = factorpop();
            arg2 = factorpop();
            defineStore(arg1, arg2);
          }
        ;

if_statement
        : IF condition THEN statement else_statement
        ;

else_statement
        : ELSE statement
        |
        ;

while_statement
        : WHILE {
            LabelSyntax lsyntax;
            lsyntax.command = While;
            lsyntax.labels.While.br1 = defineBr(1);
            lsyntax.labels.While.label1 = defineLabel()->args.label.l;
            lsyntax.labels.While.br1->args.bruncond.arg1 = lsyntax.labels.While.label1;
            lsyntax.labels.While.br2 = NULL;
            lsyntax.labels.While.br3 = NULL;
            displayLabelSyntax(lsyntax);
            pushLabelSyntax(lsyntax);
          } condition {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.labels.While.br2 = defineBrCondition(1, 1);
            pushLabelSyntax(lsyntax);
            displayLabelSyntax(lsyntax);
          } DO {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.labels.While.br1->args.brcond.arg2 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
            displayLabelSyntax(lsyntax);
          }  statement {
            LabelSyntax lsyntax = getLabelSyntax();
            displayLabelSyntax(lsyntax);
          }
        ;

for_statement
        : FOR IDENT ASSIGN expression TO expression DO statement
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT{ lookup($1); }
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN { lookup($3); }
        ;

write_statement
        : WRITE LPAREN IDENT RPAREN { lookup($3); }
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
        | expression PLUS term {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineAdd(arg1, arg2);
          }
        | expression MINUS term {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineSub(arg1, arg2);
          }
        ;

term
        : factor
        | term MULT factor
        | term DIV factor
        ;

factor
        : var_name
        | NUMBER { pushNumber($1); }
        | LPAREN expression RPAREN
        ;

var_name
        : IDENT{ lookup($1);
            Factor arg1;
            arg1 = factorpop();

            defineLoad(arg1);
          }
        ;

arg_list
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT { insert($1, UNDEFINED_VAR); }
        | id_list COMMA IDENT { insert($3, UNDEFINED_VAR); }

%%
int yyerror(char *s)
{
  fprintf(stderr, "%s(%d: \'%s\')\n", s, yylineno, yytext);
  return 0;
}
