#if !defined(TOKEN_H)
#define TOKEN_H 1

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include "fila.h"

void tokenmizar(FILE *inFile, struct Fila *f, char ini, const char *nomesToken[]);

#endif


