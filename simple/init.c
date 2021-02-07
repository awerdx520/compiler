#include "global.h"

extern void insert(char str[], int token);

entry keywords[] = {
  {"div", DIV}, 
  {"mod", MOD}, 
  {0, 0}
};

void init() {
  entry *p;
  for (p = keywords; p->token; p++) {
    insert(p->lexptr, p->token);
  }
}
