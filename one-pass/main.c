#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 256;

/* 超前扫描符号 */
int lookahead = 0;

/* */
int tokenval = 0;

/**
 *
 *
 *
 */
void error() {
  printf("Syntax error!\n");
  exit(1);
}

/**
 *
 */
void match(int t) {
  if (lookahead == t) {
    lookahead = getchar();
  } else {
    error();
  }
}

/**
 * 产生式：
 * term -> 0 {print '0'} | 1 {print '1'} | .....
 */
void term() {
  if (isdigit(lookahead)) {
    putchar(lookahead);
    match(lookahead);
  } else {
    error();
  }
}

/**
 * 产生式：
 * exr -> term rest
 */
void expr() {
  term();
  while (1) {
    if (lookahead == '+') {
      match('+');
      term();
      putchar('+');
    } else if (lookahead == '-') {
      match('-');
      term();
      putchar('-');
    } else {
      break;
    }
  }
}

/**
 *
 *
 * */
void factor() {
  if (lookahead == '(') {
    match('(');
    expr();
    match(')');
  } else if (lookahead == NUM) {
    printf(" %d ", tokenval);
    match(NUM);
  } else {
    error();
  }
}

/**
 *
 */
int main(int argc, char *argv[]) {
  lookahead = getchar();
  expr();
  putchar('\n');

  return 0;
}
