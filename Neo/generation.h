#if !defined(GEN_H)
#define GEN_H 1

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"fila.h"

/* funcao criaCodigoAssembly: cria um arquivo em assembly a partir de tokens
 *
 * parametros:
 * 	struct Fila *tokens (ponteiro para struct Fila)
 *
 * retorno: void
 */
void criaCodigoAssembly(struct Fila *tokens);

#endif
