#ifndef __GLOBAL_H_
#define __GLOBAL_H_

#include <ctype.h>
#include <stdio.h>

#define BSIZE 128
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

#define STRMAX 999
#define SYMMAX 100

/* 符号表项  */
typedef struct {
  char *lexptr;
  int token;
} entry;

#endif // __GLOBAL_H_
