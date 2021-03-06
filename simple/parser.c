#include "global.h"

/*  */
extern int tokenval;

/*  */
extern void error(char *msg);

/*  */
extern void emit(int t, int tval);

/*  */
extern int lexan();

/*  */
void term();

/*  */
void factor();

/*  */
void expr();

/*  */
int lookahead;

void match(int t) {
  if (lookahead == t) {
    lookahead = lexan();
  } else {
    error("syntax error");
  }
}

void expr() {
  int t;
  term();
  while (1) {
    switch (lookahead) {
    case '+':
    case '-':
      t = lookahead;
      match(lookahead);
      term();
      emit(t, NONE);
      continue;
    default:
      return;
    }
  }
}

/*
 *
 */
void factor() {
  switch (lookahead) {
  case '(':
    match('(');
    expr();
    match(')');
    break;
  case NUM:
    emit(NUM, tokenval);
    match(NUM);
    break;
  case ID:
    emit(ID, tokenval);
    match(ID);
    break;
  default:
    error("syntax error");
  }
}

/*
 *
 */
void term() {
  int t;
  factor();
  while (1) {
    switch (lookahead) {
    case '*':
    case '/':
    case DIV:
    case MOD:
      t = lookahead;
      match(lookahead);
      factor();
      emit(t, NONE);
    default:
      return;
    }
  }
}

void parse() {
  lookahead = lexan();
  while (lookahead != DONE) {
    expr();
    match(';');
  }
}
