#include "global.h"
#include <stdlib.h>

extern int lineno;

void error(char *msg) {
  fprintf(stderr, "line %d: %s\n", lineno, msg);
  exit(1);
}
