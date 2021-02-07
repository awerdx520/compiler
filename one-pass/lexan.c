#include <ctype.h>
#include <stdio.h>

#define NUM 256

/* 行号 */
int lineno = 1;

/*  */
int tokenval = NONE;

/**
 * 词法分析器
 *
 *
 **/
int lexan() {
  int t;
  while (1) {
    t = getchar();
    if (t == ' ' || t == '\t') {
    } else if (t == '\n') {
      lineno++;
    } else if (isdigit(t)) {
      tokenval = t - '0';
      t = getchar();
      while (isdigit(t)) {
        tokenval = tokenval * 10 + t - '0';
        t = getchar();
      }

      ungetc('t', stdin);

      return NUM;
    } else {
      tokenval = NONE;

      return t;
    }
  }
}
