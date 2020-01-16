
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "llvm.h"

extern int yylineno;
extern char *yytext;

typedef struct {
  char *var_name;
  int reg;
  Scope scope;

} SymbolTable;

/* define stack and stack length */
SymbolTable symbol_table[1024];
int symbol_table_length = 0;
int is_local_variable = 0;

extern int cntr;

void insert(char *vn, Scope scope)
{
  int i;
  char *var_name;

  var_name = (char *)malloc(128);
  strcpy(var_name, vn);

  // show action
  fprintf(stderr, "variable \'%s\' inserted!!(%d)\n", var_name, yylineno);
  // fprintf(stderr, "--------------------------\n");

  // assignment to table
  symbol_table[symbol_table_length].var_name = var_name;

  if (scope == UNDEFINED_VAR) {
    if (is_local_variable == 1) {
      symbol_table[symbol_table_length].scope = LOCAL_VAR;
      symbol_table[symbol_table_length].reg = cntr;
      defineAlloca(cntr);
      cntr ++;
    } else {
      symbol_table[symbol_table_length].scope = GLOBAL_VAR;
      symbol_table[symbol_table_length].reg = 0;
      defineGlobalVar(var_name);
    }
  } else {
    symbol_table[symbol_table_length].scope = scope;
    symbol_table[symbol_table_length].reg = 0;
  }

  if (scope == PROC_NAME) {
    doProcedure(var_name);
    is_local_variable = 1;
  }
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

      default:
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
          fprintf(stderr, "%d. %s (GLOBAL_VAR, %d)\n", i, symbol_table[i].var_name, symbol_table[i].reg);
          break;

        case LOCAL_VAR:
          fprintf(stderr, "%d. %s (LOCAL_VAR, %d)\n", i, symbol_table[i].var_name, symbol_table[i].reg);
          break;

        case PROC_NAME:
          fprintf(stderr, "%d. %s (PROC_NAME, %d)\n", i, symbol_table[i].var_name, symbol_table[i].reg);
          break;

        default:
          break;

      }
      fprintf(stderr, "\n");
      pushVariable(symbol_table[i].var_name, symbol_table[i].scope, symbol_table[i].reg);
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
  // fprintf(stderr, "--------------------------\n");
  while (1) {
    target_symbol = symbol_table[symbol_table_length-1];
    if (target_symbol.scope == LOCAL_VAR)
    {
      free(target_symbol.var_name);
      symbol_table_length --;
    }
    else break;
  }

  is_local_variable = 0;

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
      default:
        break;

    }
  }
  fprintf(stderr, "\n");


}
