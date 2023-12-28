#if !defined(PARSE_H)
#define PARSE_H 1

#include"tokenmizar.h"
#include"fila.h"

struct Token *observar(struct Token *t, int frente);

void parsing(struct Fila *f);

#endif

