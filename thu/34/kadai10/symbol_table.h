#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

  void insert(char *vn, Scope scope, int reg, ReturnType rettype);
  int lookup(char *vn);
  void delete();

#endif // _SYMBOL_TABLE_H_
