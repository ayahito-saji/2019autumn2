#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include <string.h>

/* LLVM命令名の定義 */
typedef enum {
  Alloca,   /* alloca */
  Store,    /* store  */
  Load,     /* load   */
  BrUncond, /* br     */
  BrCond,   /* brc    */
  Label,    /* label  */
  Add,      /* add    */
  Sub,      /* sub    */
  Icmp,     /* icmp   */
  Ret,      /* ret    */
  CommonGlobal /* common_global */ /* 実験4 追加 */
} LLVMcommand;

/* 比較演算子の種類 */
typedef enum {
  EQUAL, /* eq （==）*/
  NE,    /* ne （!=）*/
  SGT,   /* sgt （>，符号付き） */
  SGE,   /* sge （>=，符号付き）*/
  SLT,   /* slt （<，符号付き） */
  SLE    /* sle （<=，符号付き）*/
} Cmptype;

/* 変数もしくは定数の型 */
typedef struct {
  Scope type;      /* 変数（のレジスタ）か整数の区別 */
  char vname[256]; /* 変数の場合の変数名 */
  int val;         /* 整数の場合はその値，変数の場合は割り当てたレジスタ番号 */
} Factor;

/* 変数もしくは定数のためのスタック */
typedef struct {
  Factor element[100];  /* スタック（最大要素数は100まで） */
  unsigned int top;     /* スタックのトップの位置         */
} Factorstack;

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

void init_fstack(){ /* fstackの初期化 */
  fstack.top = 0;
  return;
}

typedef struct llvmcode {
  LLVMcommand command; /* 命令名 */
  union { /* 命令の引数 */
    struct { /* common_global */
      Factor retval;
    } common_global;
    struct { /* alloca */
      Factor retval;
    } alloca;
    struct { /* store  */
      Factor arg1;  Factor arg2;
    } store;
    struct { /* load   */
      Factor arg1;  Factor retval;
    } load;
    struct { /* br     */
      int arg1;
    } bruncond;
    struct { /* brc    */
      Factor arg1;  int arg2;  int arg3;
    } brcond;
    struct { /* label  */
      int l;
    } label;
    struct { /* add    */
      Factor arg1;  Factor arg2;  Factor retval;
    } add;
    struct { /* sub    */
      Factor arg1;  Factor arg2;  Factor retval;
    } sub;
    struct { /* icmp   */
      Cmptype type;  Factor arg1;  Factor arg2;  Factor retval;
    } icmp;
    struct { /* ret    */
      Factor arg1;
    } ret;
  } args;
  /* 次の命令へのポインタ */
  struct llvmcode *next;
} LLVMcode;

LLVMcode *codehd = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *codetl = NULL; /* 命令列の末尾のアドレスを保持するポインタ */
unsigned int cntr = 0;

/* LLVMの関数定義 */
typedef struct fundecl {
  char fname[256];      /* 関数名                      */
  unsigned arity;       /* 引数個数                    */
  Factor args[10];      /* 引数名                      */
  LLVMcode *codes;      /* 命令列の線形リストへのポインタ */
  struct fundecl *next; /* 次の関数定義へのポインタ      */
} Fundecl;

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
Fundecl *declhd = NULL;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
Fundecl *decltl = NULL;

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
  int i;
  fprintf(stderr, "FACTOR POP! (index: %d)\n", fstack.top);

  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top --;
  return tmp;
}

void factorpush(Factor x) {
  int i;

  fstack.top ++;
  fstack.element[fstack.top] = x;

  fprintf(stderr, "FACTOR PUSH! (index: %d)\n", fstack.top);

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
    case Add:
      displayFactor(fp, (code->args).add.retval );
      fprintf(fp, " = add nsw i32 ");
      displayFactor(fp, (code->args).add.arg1 );
      fprintf(fp, ", ");
      displayFactor(fp, (code->args).add.arg2 );
      fprintf(fp, ", align 4\n");
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
  fprintf(stderr, "OUTPUT CODE\n");

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
  fprintf(stderr, "DEFINE GLOBAL VARIABLE: %s\n", var_name);

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
}

/* LLVM Alloca命令の作成 */
LLVMcode *defineAlloca(int reg) {
  fprintf(stderr, "DEFINE ALLOCA: %%%d\n", reg);

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
  fprintf(stderr, "DEFINE STORE\n");

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
  fprintf(stderr, "DEFINE LOAD\n");

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
  fprintf(stderr, "DEFINE LOAD\n");

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

/* 数字をFactorとして追加 */
void pushNumber(int number) {
  fprintf(stderr, "PUSH NUMBER %d\n", number);

  Factor tmp;
  tmp.type = CONSTANT;
  tmp.val = number;

  factorpush(tmp);
}

/* 変数をFactorとして追加 */
void pushVariable(char *var_name, Scope type) {
  fprintf(stderr, "PUSH VARIABLE %s(%d)\n", var_name, type);

  Factor tmp;
  tmp.type = type;
  strcpy(tmp.vname, var_name);

  factorpush(tmp);

}

/* 変数代入の実装 */
void doAssign() {
  fprintf(stderr, "DEFINE ASSIGNMENT\n");

  Factor arg1, arg2;
  arg1 = factorpop();
  arg2 = factorpop();

  defineStore(arg1, arg2);
}

/* 変数参照の実装 */
void doReference() {
  fprintf(stderr, "DEFINE REFERENCE\n");

  Factor arg1;
  arg1 = factorpop();

  defineLoad(arg1);
}

/* 足し算の実行 */
void doAdd() {
  fprintf(stderr, "DEFINE ADD\n");

  Factor arg1, arg2;
  arg2 = factorpop();
  arg1 = factorpop();

  defineAdd(arg1, arg2);
}

/* mainを含めた手続き／関数の実装 */
void doProcedure(char *proc_name) {
  fprintf(stderr, "DEFINE PROCEDURE: %s\n", proc_name);
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
