#if !defined(FILA_H)
#define FILA_H 1

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#include"token.h"

struct Fila {
	struct Token *ini;
	struct Token *fim;
	int tam;
};



/* funcao desinfileira: remove o primeiro token da fila
 * 
 * parametros: struct Fila *f (ponteiro para struct Fila)
 *
 * retorno: struct Token * (ponteiro para struct Token)
 */
struct Token *desinfileira(struct Fila *fila);


/* funcao enfileira: adiciona o token no fim da fila
 * 
 * parametros: 
 * 	struct Fila *f (ponteiro para struct Fila)
 *	struct Token *t (ponteiro para struct Token)
 *
 * retorno: void
 */
void enfileira(struct Fila *f, struct Token *t);


/* funcao filaVazia: verifica se uma fila é vazia
 * 
 * parametros: 
 * 	struct Fila *f (ponteiro para struct Fila)
 *
 * retorno: bool (True se vazia; False se nao vazia)
 */
bool filaVazia(struct Fila *f);


/* funcao criarFila: cria e inicializa uma nova fila
 * 
 * parametros:
 *
 * retorno: seturct Fila * (ponteiro para struct Fila)
 */
struct Fila *criaFila();


/* funcao imprimirFila: imprime os nomes dos tokens de uma fila
 * 
 * parametros: 
 * 	struct Fila *f (ponteiro para struct Fila)
 * 	const char *nomesToken[] (vetor contendo os nomes dos tokens)
 *
 * retorno: void
 */
void imprimirFila(struct Fila *f, const char *nomesToken[]);




/* funcao destroiFila: destroi uma fila e todos os seus tokens
 * 
 * parametros: 
 * 	struct Fila *f (ponteiro para struct Fila)
 *
 * retorno: void
 */
void destroiFila(struct Fila *f);
#endif

