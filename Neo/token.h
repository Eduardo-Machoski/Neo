#if !defined(TOKEN_H)
#define TOKEN_H 1

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include "fila.h"

/* funcao tokenmizar: cria tokens a partir do arquivo original
 * 
 * parametros: 
 * 	FILE *inFile (ponteiro para arquivo de texto)
 * 	struct Fila *f (ponteiro para struct Fila)
 * 	char ini (char inicial de cada token)
 * 	const char *nomesToken[] (vetor de strings com os nomes dos Tokens)
 *
 * retorno: void
 */
void tokenmizar(FILE *inFile, struct Fila *f, char ini, const char *nomesToken[]);

#endif


