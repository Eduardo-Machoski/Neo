#if !defined(GEN_H)
#define GEN_H 1

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"lista.h"

/* funcao criaCodigoAssembly: cria um arquivo em assembly a partir de tokens
 *
 * parametros:
 * 	struct Lista *tokens (ponteiro para struct Lista)
 *
 * retorno: void
 */
void criaCodigoAssembly(struct Lista *tokens);

#endif
