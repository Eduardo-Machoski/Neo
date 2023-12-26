#if !defined(PARSE_H)
#define PARSE_H 1

#include"token.h"
#include"fila.h"

struct Token *observar(struct Token **tokens, int index, int tam);

void parsing(struct Token **tokens, int num, int *ini);

#endif

