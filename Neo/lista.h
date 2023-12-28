#if !defined(LISTA_H)
#define LISTA_H 1

#include<stdlib.h>
#include<stdio.h>

#include"token.h"

struct Lista {
	struct Token *sentinela;
	int tam;
};


/* funcao criaLista: cria uma lista duplamente encadeada com sentinela
 *
 * parametros:
 *
 * retorno: struct Lista * (ponteiro para struct Lista)
 */
struct Lista *criaLista();


/* funcao removeLista: remove um token da lista e retorna seu endereco
 *
 * parametros: 
 *	struct Lista * (ponteiro para struct Lista)
 * 	struct Token * (ponteiro para struct Token)
 *
 * retorno: void
 */
void removeLista(struct Lista *l, struct Token *t);


/* funcao insereLista: insere um token no fim da lista
 *
 * parametros:
 * 	struct Lista * (ponteiro para struct Lista)
 * 	struct Token * (ponteiro para struct Token)
 *
 *  retorno: void
 */
void insereFimLista(struct Lista *l, struct Token *t);

/* funcao insereLista: insere um token apos um outro token em uma lista
 *
 * parametros:
 * 	struct Token * (ponteiro para struct Token)
 * 	struct Token * (ponteiro para struct Token)
 * 	struct Lista * (ponteiro para struct Lista)
 *
 * retorno: void
 */
void insereLista(struct Token *inserir, struct Token *referencia, struct Lista *l);

/*funcao destroiLista: destroi uma lista e todos os seus tokens
 *
 *parametros:
 *	struct Lista * (ponteiro para struct Lista)
 *
 * retorno: void
 */
void destroiLista(struct Lista *l);

#endif
