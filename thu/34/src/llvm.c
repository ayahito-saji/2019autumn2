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

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

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


void displayFactor( Factor factor ){
  switch(factor.type){
    case GLOBAL_VAR:
      printf("@%s", factor.vname);
      break;
    case LOCAL_VAR:
      printf("%%%d", factor.val);
      break;
    default:
      break;
  }
}

void displayLlvmcodes( LLVMcode *code) {
  if (code == NULL) return;
  printf(" ");
  switch (code->command){
    case CommonGlobal:
      displayFactor( (code->args).common_global.retval );
      printf(" = common global i32 0, align 4\n");
      break;
    case Alloca:
      displayFactor( (code->args).alloca.retval );
      printf(" = alloca i32, align 4\n");
      break;
  }
  displayLlvmcodes(code->next);
}

void displayLlvmfundecl( Fundecl *decl ) {
  if (decl == NULL) return;
  printf("definei32 @%s() {\n", decl->fname);
  displayLlvmcodes(decl->codes);
  printf("}\n");
  if(decl->next != NULL) {
    printf("\n");
    displayLlvmfundecl(decl->next);
  }
  return;
}

void outputCode () {
  fprintf(stderr, "OUTPUT CODE\n");
  displayLlvmcodes(codehd);
  displayLlvmfundecl(declhd);
  
}

void defineGlobalVar( char *var_name ) {
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

void defineProcedure(char *proc_name) {
  fprintf(stderr, "DEFINE PROCEDURE: %s\n", proc_name);

  LLVMcode *tmp1;
  tmp1 = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp1->next = NULL;
  tmp1->command = Alloca;
  Factor retval;
  retval.type = LOCAL_VAR;
  retval.val = 1;
  (tmp1->args).alloca.retval = retval;

  Fundecl *tmp2;
  tmp2 = (Fundecl *)malloc(sizeof(Fundecl));
  tmp2->codes = tmp1;
  strcpy(tmp2->fname, proc_name);

  if (decltl == NULL){
    if (declhd == NULL) {
      declhd = tmp2;
    }
    decltl = tmp2;
  } else {
    decltl->next = tmp2;
    decltl = tmp2;
  }

}

void defineLocalVar( char *var_name ) {
  fprintf(stderr, "DEFINE GLOBAL VARIABLE: %s\n", var_name);
}
