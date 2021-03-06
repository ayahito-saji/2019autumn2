#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

  typedef enum {
    UNDEFINED_VAR,
    GLOBAL_VAR,
    LOCAL_VAR,
    PROC_NAME,
    CONSTANT
  } Scope;

  void insert(char *vn, Scope scope);
  int lookup(char *vn);
  void delete();

#endif // _SYMBOL_TABLE_H_
