#ifndef _LLVM_H_
#define _LLVM_H_

void init_fstack();
void pushNumber(int number);
void loadVariable(char *var_name, Scope type);

void outputCode ();

#endif // _LLVM_H_
