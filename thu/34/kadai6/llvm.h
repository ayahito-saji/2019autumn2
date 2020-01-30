#ifndef _LLVM_H_
#define _LLVM_H_

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
  Mul,      /* mul    */
  Div,      /* div    */
  Icmp,     /* icmp   */
  Ret,      /* ret    */
  CommonGlobal, /* common_global */ /* 実験4 追加 */
  Printf,   /* printf */
  Scanf,    /* scanf  */
  Call      /* call   */
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

/* 返り値の型 */
typedef enum {
  VOID,
  INT32
} ReturnType;

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
    struct { /* mul    */
      Factor arg1;  Factor arg2;  Factor retval;
    } mul;
    struct { /* div    */
      Factor arg1;  Factor arg2;  Factor retval;
    } div;
    struct { /* icmp   */
      Cmptype type;  Factor arg1;  Factor arg2;  Factor retval;
    } icmp;
    struct { /* ret    */
      ReturnType type;
      Factor arg1;
    } ret;
    struct { /* printf */
      Factor retval;
      Factor arg1;
    } printf;
    struct { /* scanf */
      Factor retval;
      Factor arg1;
    } scanf;
    struct { /* call */
      Factor arg1;
      Factor args[10];
      unsigned int arity;
    } call;
  } args;
  /* 次の命令へのポインタ */
  struct llvmcode *next;
} LLVMcode;

/* LLVMの関数定義 */
typedef struct fundecl {
  char fname[256];      /* 関数名                      */
  unsigned arity;       /* 引数個数                    */
  Factor args[10];      /* 引数名                      */
  LLVMcode *codes;      /* 命令列の線形リストへのポインタ */
  struct fundecl *next; /* 次の関数定義へのポインタ      */
  ReturnType rettype;
} Fundecl;

/* ラベルを必要とする構文 */
typedef enum {
  While,
  If,
  For
} labelSyntaxCommand;

/* ラベルを必要とする構文 */
typedef struct labelSyntax {
  labelSyntaxCommand command;
  union {
    struct { /* while文のラベル */
      int label1;
      LLVMcode *br1;
      LLVMcode *br2;
    } While;
    struct {
      LLVMcode *br1;
      LLVMcode *br2;
      LLVMcode *br3;
    } If;
    struct {
      Factor var;
      LLVMcode *br1;
      int label1;
      LLVMcode *br2;
    } For;
  } args;
} LabelSyntax;

/* ラベルを必要とする構文のスタック */
typedef struct {
  LabelSyntax elements[100];
  unsigned int top;
} LabelSyntaxStack;

Factor factorpop();
void factorpush(Factor x);

LabelSyntax popLabelSyntax();
void pushLabelSyntax(LabelSyntax x);
LabelSyntax getLabelSyntax();
void displayLabelSyntax(LabelSyntax labelSyntax);

void displayFactor(FILE *fp, Factor factor );
void displayLlvmcodes(FILE *fp, LLVMcode *code);
void displayLlvmfundecl(FILE *fp, Fundecl *decl );

void outputCode ();

LLVMcode *defineGlobalVar( char *var_name );
LLVMcode *defineAlloca();
LLVMcode *defineStore(Factor arg1, Factor arg2);
LLVMcode *defineLoad(Factor arg1);
LLVMcode *defineAdd(Factor arg1, Factor arg2);
LLVMcode *defineSub(Factor arg1, Factor arg2);
LLVMcode *defineMul(Factor arg1, Factor arg2);
LLVMcode *defineDiv(Factor arg1, Factor arg2);
LLVMcode *defineBr(int arg1);
LLVMcode *defineBrCondition(int arg2, int arg3);
LLVMcode *defineLabel();
LLVMcode *defineIcmp(Cmptype type, Factor arg1, Factor arg2);
LLVMcode *defineRet(ReturnType type);
LLVMcode *definePrintf(Factor arg1);
LLVMcode *defineScanf();
LLVMcode *defineCall(Factor arg1, unsigned int arity, Factor args[10]);

void doProcedure(char *proc_name, unsigned int arity, char args[10][256]);
void doMainProcedure();

void pushNumber(int number);
void pushVariable(char *var_name, Scope type, int val);

#endif // _LLVM_H_
