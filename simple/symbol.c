#include "global.h"
#include <string.h>

extern void error(char *msg);

/* 符号表 */
entry symtable[SYMMAX];

int lastchar = -1;

char lexemes[STRMAX];

int lastentry = 0;

int lookup(char str[]) {
  int p;
  for (p = lastentry; p > 0; p--) {
    if (strcmp(symtable[p].lexptr, str) == 0) {
      return p;
    }
  }
  
  return 0;
}

int insert(char str[], int tok) {
  int len = strlen(str);
  if (lastentry + 1 >= SYMMAX) {
    error("symbol table full");
  }

  if (lastchar + len + 1 >= STRMAX) {
    error("lexemes array full");
  }

  lastentry = lastentry + 1;
  symtable[lastentry].token = tok;
  symtable[lastentry].lexptr = &lexemes[lastchar + 1];
  lastchar = lastchar + len + 1;
  strcpy(symtable[lastentry].lexptr, str);

  return lastentry;
}
