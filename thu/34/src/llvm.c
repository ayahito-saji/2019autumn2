#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "llvm.h"
#include <string.h>

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

LLVMcode *codehd = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *codetl = NULL; /* 命令列の末尾のアドレスを保持するポインタ */
unsigned int cntr = 0;

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
Fundecl *declhd = NULL;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
Fundecl *decltl = NULL;

LabelSyntaxStack lstack;

void pushLabelSyntax(LabelSyntax x) {
  lstack.top ++;
  lstack.elements[lstack.top] = x;
}

LabelSyntax popLabelSyntax() {
  LabelSyntax tmp;
  tmp = lstack.elements[lstack.top];
  lstack.top --;
  return tmp;
}

LabelSyntax getLabelSyntax() {
  return lstack.elements[lstack.top];
}
void displayLabelSyntax(LabelSyntax labelSyntax) {
  switch (labelSyntax.command) {
    case While:
      fprintf(stderr, "While: %d %p %p\n", labelSyntax.args.While.label1, labelSyntax.args.While.br1, labelSyntax.args.While.br2);
    default:
      break;
  }
}

/* Factorの表示 */
void displayFactor(FILE *fp, Factor factor ){
  switch(factor.type){
    case GLOBAL_VAR:
      fprintf(fp, "@%s", factor.vname);
      break;
    case LOCAL_VAR:
      fprintf(fp, "%%%d", factor.val);
      break;
    case CONSTANT:
      fprintf(fp, "%d", factor.val);
      break;
    default:
      break;
  }
}

Factor factorpop() {
  // fprintf(stderr, "FACTOR POP! (index: %d)\n", fstack.top);

  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top --;
  return tmp;
}

void factorpush(Factor x) {
  int i;

  fstack.top ++;
  fstack.element[fstack.top] = x;

  // fprintf(stderr, "FACTOR PUSH! (index: %d)\n", fstack.top);

  return;
}

/* LLVMコードを表示する */
void displayLlvmcodes(FILE *fp, LLVMcode *code) {
  if (code == NULL) return;
  fprintf(fp, "  ");
  switch (code->command){
    case CommonGlobal:
      displayFactor(fp, (code->args).common_global.retval );
      fprintf(fp, " = common global i32 0, align 4\n");
      break;
    case Alloca:
      displayFactor(fp, (code->args).alloca.retval );
      fprintf(fp, " = alloca i32, align 4\n");
      break;
    case Store:
      fprintf(fp, "store i32 ");
      displayFactor(fp, (code->args).store.arg1 );
      fprintf(fp, ", i32* ");
      displayFactor(fp, (code->args).store.arg2 );
      fprintf(fp, ", align 4\n");
      break;
    case Load:
      displayFactor(fp, (code->args).load.retval );
      fprintf(fp, " = load i32, i32* ");
      displayFactor(fp, (code->args).load.arg1 );
      fprintf(fp, ", align 4\n");
      break;
    case BrUncond:
      fprintf(fp, "br label %%%d\n\n", (code->args).bruncond.arg1);
      break;
    case BrCond:
      fprintf(fp, "br label i1 %%");
      displayFactor(fp, (code->args).brcond.arg1 );
      fprintf(fp, ", label %%%d, label %%%d\n\n", (code->args).brcond.arg2, (code->args).brcond.arg3);
      break;
    case Label:
      fprintf(fp, "; <label>:%d:\n", (code->args).label.l);
      break;
    case Add:
      displayFactor(fp, (code->args).add.retval );
      fprintf(fp, " = add nsw i32 ");
      displayFactor(fp, (code->args).add.arg1 );
      fprintf(fp, ", ");
      displayFactor(fp, (code->args).add.arg2 );
      fprintf(fp, ", align 4\n");
      break;
    case Sub:
      displayFactor(fp, (code->args).sub.retval );
      fprintf(fp, " = sub nsw i32 ");
      displayFactor(fp, (code->args).sub.arg1 );
      fprintf(fp, ", ");
      displayFactor(fp, (code->args).sub.arg2 );
      fprintf(fp, ", align 4\n");
      break;
    case Icmp:
      displayFactor(fp, (code->args).icmp.retval );
      fprintf(fp, " = icmp ");
      switch ((code->args).icmp.type) {
        case EQUAL:
          fprintf(fp, "eq");break;
        case NE:
          fprintf(fp, "ne");break;
        case SGT:
          fprintf(fp, "sgt");break;
        case SGE:
          fprintf(fp, "sge");break;
        case SLT:
          fprintf(fp, "slt");break;
        case SLE:
          fprintf(fp, "sle");break;
      }
      fprintf(fp, " i32 ");
      displayFactor(fp, (code->args).icmp.arg1 );
      fprintf(fp, ", ");
      displayFactor(fp, (code->args).icmp.arg2 );
      fprintf(fp, ", align 4\n");
      break;
    default:
      break;
  }
  displayLlvmcodes(fp, code->next);
}

/* 手続きを表示する */
void displayLlvmfundecl(FILE *fp, Fundecl *decl ) {
  if (decl == NULL) return;
  fprintf(fp, "define i32 @%s #0() {\n", decl->fname);
  displayLlvmcodes(fp, decl->codes);
  fprintf(fp, "}\n");
  if(decl->next != NULL) {
    fprintf(fp, "\n");
    displayLlvmfundecl(fp, decl->next);
  }
  return;
}

void outputCode () {
  // fprintf(stderr, "OUTPUT CODE\n");

  FILE *outputfile;
  outputfile = fopen("result.ll", "w");
  if (outputfile == NULL) {
    fprintf(stderr, "unexpected error\n");
    exit(1);
  }

  displayLlvmcodes(outputfile, codehd);
  displayLlvmfundecl(outputfile, declhd);

  fclose(outputfile);
}

/* LLVM Common Global命令の作成 */
LLVMcode *defineGlobalVar( char *var_name ) {
  // fprintf(stderr, "DEFINE GLOBAL VARIABLE: %s\n", var_name);

  LLVMcode *tmp;
  Factor retval;
  retval.type = GLOBAL_VAR;
  strcpy(retval.vname, var_name);

  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = CommonGlobal;
  (tmp->args).common_global.retval = retval;

  if (codetl == NULL){
    if (codehd == NULL) {
      codehd = tmp;
    }
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }
  return tmp;
}

/* LLVM Alloca命令の作成 */
LLVMcode *defineAlloca(int reg) {
  // fprintf(stderr, "DEFINE ALLOCA: %%%d\n", reg);

  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = Alloca;

  Factor retval;
  retval.type = LOCAL_VAR;
  retval.val = reg;
  (tmp->args).alloca.retval = retval;

  if (codetl == NULL){
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }

  return tmp;
}

/* LLVM Store命令の作成 */
LLVMcode *defineStore(Factor arg1, Factor arg2) {
  // fprintf(stderr, "DEFINE STORE\n");

  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = Store;

  (tmp->args).store.arg1 = arg1;
  (tmp->args).store.arg2 = arg2;

  if (codetl == NULL){
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }

  return tmp;
}

/* LLVM Load命令の作成 */
LLVMcode *defineLoad(Factor arg1) {
  // fprintf(stderr, "DEFINE LOAD\n");

  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = Load;

  Factor retval;
  retval.type = LOCAL_VAR;
  retval.val = cntr;
  cntr++;

  (tmp->args).load.arg1 = arg1;
  (tmp->args).load.retval = retval;

  factorpush(retval);

  if (codetl == NULL){
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }

  return tmp;
}

/* LLVM Add命令の作成 */
LLVMcode *defineAdd(Factor arg1, Factor arg2) {
  // fprintf(stderr, "DEFINE ADD\n");

  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = Add;

  Factor retval;
  retval.type = LOCAL_VAR;
  retval.val = cntr;
  cntr++;

  (tmp->args).add.arg1 = arg1;
  (tmp->args).add.arg2 = arg2;
  (tmp->args).add.retval = retval;

  factorpush(retval);

  if (codetl == NULL){
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }

  return tmp;
}

/* LLVM Sub命令の作成 */
LLVMcode *defineSub(Factor arg1, Factor arg2) {
  // fprintf(stderr, "DEFINE SUB\n");

  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = Sub;

  Factor retval;
  retval.type = LOCAL_VAR;
  retval.val = cntr;
  cntr++;

  (tmp->args).sub.arg1 = arg1;
  (tmp->args).sub.arg2 = arg2;
  (tmp->args).sub.retval = retval;

  factorpush(retval);

  if (codetl == NULL){
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }

  return tmp;
}

/* LLVM Br命令の作成 */
LLVMcode *defineBr(int arg1) {
  // fprintf(stderr, "DEFINE BR\n");

  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = BrUncond;

  (tmp->args).bruncond.arg1 = arg1;

  if (codetl == NULL){
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }

  return tmp;
}
/* LLVM Br Condition命令の作成 */
LLVMcode *defineBrCondition(int arg2, int arg3) {
  // fprintf(stderr, "DEFINE BR CONDITION\n");

  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = BrCond;

  (tmp->args).brcond.arg1 = factorpop();
  (tmp->args).brcond.arg2 = arg2;
  (tmp->args).brcond.arg3 = arg3;

  if (codetl == NULL){
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }

  return tmp;
}
/* LLVM Label命令の作成 */
LLVMcode *defineLabel() {
  // fprintf(stderr, "DEFINE LABEL\n");

  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = Label;

  (tmp->args).label.l = cntr;
  cntr ++;

  if (codetl == NULL){
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }

  return tmp;
}

/* LLVM Icmp命令の作成 */
LLVMcode *defineIcmp(Cmptype type, Factor arg1, Factor arg2) {
  // fprintf(stderr, "DEFINE SUB\n");

  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = Icmp;

  Factor retval;
  retval.type = LOCAL_VAR;
  retval.val = cntr;
  cntr++;

  (tmp->args).icmp.type = type;
  (tmp->args).icmp.arg1 = arg1;
  (tmp->args).icmp.arg2 = arg2;
  (tmp->args).icmp.retval = retval;

  factorpush(retval);

  if (codetl == NULL){
    codetl = tmp;
  } else {
    codetl->next = tmp;
    codetl = tmp;
  }

  return tmp;
}

/* 数字をFactorとして追加 */
void pushNumber(int number) {
  // fprintf(stderr, "PUSH NUMBER %d\n", number);

  Factor tmp;
  tmp.type = CONSTANT;
  tmp.val = number;

  factorpush(tmp);
}

/* 変数をFactorとして追加 */
void pushVariable(char *var_name, Scope type) {
  // fprintf(stderr, "PUSH VARIABLE %s(%d)\n", var_name, type);

  Factor tmp;
  tmp.type = type;
  strcpy(tmp.vname, var_name);

  factorpush(tmp);

}

/* mainを含めた手続き／関数の実装 */
void doProcedure(char *proc_name) {
  // fprintf(stderr, "DEFINE PROCEDURE: %s\n", proc_name);
  codetl = NULL;
  cntr = 1;

  LLVMcode *alloca_statement = defineAlloca(1);

  Factor arg1, arg2;

  arg1.type = CONSTANT;
  arg1.val = 0;

  arg2.type = LOCAL_VAR;
  arg2.val = cntr;
  cntr ++;


  LLVMcode *store_statement = defineStore(arg1, arg2);

  Fundecl *tmp;
  tmp = (Fundecl *)malloc(sizeof(Fundecl));
  tmp->codes = alloca_statement;
  strcpy(tmp->fname, proc_name);

  if (decltl == NULL){
    if (declhd == NULL) {
      declhd = tmp;
    }
    decltl = tmp;
  } else {
    decltl->next = tmp;
    decltl = tmp;
  }
}
