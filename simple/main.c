#include "global.h"

extern void init();

extern void parse();

int main(int argc, char *argv[]) {
  init();
  parse();

  return 0;
}
