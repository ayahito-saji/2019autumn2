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
extern unsigned int useRead;
extern unsigned int useWrite;

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
            useRead = 0;
            useWrite = 0;
          } PROGRAM IDENT SEMICOLON outblock PERIOD { outputCode(); }
        ;

outblock
        : var_decl_part subprog_decl_part { doMainProcedure(); } statement { defineRet(INT32);delete(); }
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
        : PROCEDURE proc_name SEMICOLON inblock { defineRet(VOID);delete(); }
        | PROCEDURE proc_name LPAREN id_list RPAREN SEMICOLON inblock { defineRet(VOID);delete(); }
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
        : IF condition {
            // if ~~~ BR1 then LABEL2 ~~~~~ BR2 else LABEL3 ~~~~~~ BR3 LABEL4
            LabelSyntax lsyntax;
            lsyntax.command = If;
            lsyntax.args.If.br1 = defineBrCondition(1, 1);
            lsyntax.args.If.br2 = NULL;
            lsyntax.args.If.br3 = NULL;
            pushLabelSyntax(lsyntax);
            displayLabelSyntax(lsyntax);
          } THEN {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg2 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          } statement {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br2 = defineBr(1);
            pushLabelSyntax(lsyntax);
          } else_statement {
            LabelSyntax lsyntax = popLabelSyntax();
            int label1 = defineLabel()->args.label.l;
            lsyntax.args.If.br2->args.bruncond.arg1 = label1;
            if (lsyntax.args.If.br3 != NULL)
              lsyntax.args.If.br3->args.bruncond.arg1 = label1;
            else
              lsyntax.args.If.br1->args.brcond.arg3 = label1;
          }
        ;

else_statement
        : ELSE {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br1->args.brcond.arg3 = defineLabel()->args.label.l;
            pushLabelSyntax(lsyntax);
          } statement {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.If.br3 = defineBr(1);
            pushLabelSyntax(lsyntax);
          }
        |
        ;

while_statement
        : WHILE {
            // BR1 LABEL1 while ~~~ BR2 do LABEL2 ~~~~~ BR3 LABEL3
            LabelSyntax lsyntax;
            lsyntax.command = While;
            lsyntax.args.While.br1 = defineBr(1); // LABEL1へのジャンプ命令を定義して，LLVM命令の場所を記憶
            lsyntax.args.While.label1 = defineLabel()->args.label.l; // LABEL1を定義して，LABEL1のレジスタ番号を代入
            lsyntax.args.While.br1->args.bruncond.arg1 = lsyntax.args.While.label1; // BR1にLABEL1のレジスタ番号を代入
            lsyntax.args.While.br2 = NULL;
            // displayLabelSyntax(lsyntax);
            pushLabelSyntax(lsyntax);
          } condition {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2 = defineBrCondition(1, 1); // LABEL2またはLABEL3へのジャンプ命令を定義して，LLVM命令の場所を記憶
            pushLabelSyntax(lsyntax);
            // displayLabelSyntax(lsyntax);
          } DO {
            LabelSyntax lsyntax = popLabelSyntax();
            lsyntax.args.While.br2->args.brcond.arg2 = defineLabel()->args.label.l; // LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入
            pushLabelSyntax(lsyntax);
            // displayLabelSyntax(lsyntax);
          }  statement {
            LabelSyntax lsyntax = popLabelSyntax();
            defineBr(lsyntax.args.While.label1); // LABEL1へジャンプするBR命令を定義
            lsyntax.args.While.br2->args.brcond.arg3 = defineLabel()->args.label.l; // LABEL2を定義して，BR2のジャンプ先1にLABEL2のレジスタ番号を代入
            // displayLabelSyntax(lsyntax);
          }
        ;

for_statement
        : FOR IDENT ASSIGN expression {
            LabelSyntax lsyntax;
            lsyntax.command = For;
            lookup($2);

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
          } TO expression {
            LabelSyntax lsyntax = popLabelSyntax();

            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLE, arg1, arg2);

            lsyntax.args.For.br2 = defineBrCondition(1, 1);

            lsyntax.args.For.br2->args.brcond.arg2 = defineLabel()->args.label.l;

            pushLabelSyntax(lsyntax);


          } DO statement {
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
        ;

proc_call_statement
        : proc_call_name {
            Factor arg1;
            arg1 = factorpop();
            defineCall(arg1);
          }
        | proc_call_name LPAREN arg_list RPAREN {
            Factor arg1;
            arg1 = factorpop();
            defineCall(arg1);
          }
        ;

proc_call_name
        : IDENT{ lookup($1); }
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN {
            useRead = 1;
            lookup($3);
            defineScanf();
          }
        ;

write_statement
        : WRITE LPAREN expression RPAREN {
            useWrite = 1;

            Factor arg1;
            arg1 = factorpop();
            definePrintf(arg1);
          }
        ;

null_statement
        : /*empty*/
        ;

condition
        : expression EQ expression {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(EQUAL, arg1, arg2);
          }
        | expression NEQ expression {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(NE, arg1, arg2);
          }
        | expression LT expression {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLT, arg1, arg2);
          }
        | expression LE expression {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SLE, arg1, arg2);
          }
        | expression GT expression {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGT, arg1, arg2);
          }
        | expression GE expression {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();
            defineIcmp(SGE, arg1, arg2);
          }
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
        | term MULT factor {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineMul(arg1, arg2);
          }
        | term DIV factor {
            Factor arg1, arg2;
            arg2 = factorpop();
            arg1 = factorpop();

            defineDiv(arg1, arg2);
          }
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

            if (arg1.type == GLOBAL_VAR) defineLoad(arg1);
            else if (arg1.type == LOCAL_VAR) defineLoad(arg1);
            else factorpush(arg1);
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
