#include"lista.h"


/* funcao criaLista: cria uma lista duplamente encadeada com sentinela
 *
 * parametros:
 *
 * retorno: struct Lista * (ponteiro para struct Lista)
 */
struct Lista *criaLista(){
	struct Lista *aux;

	//verifica se o malloc foi bem sucedido
	if (!(aux = malloc(sizeof(struct Lista)))){
		printf("Erro Malloc!\n");
		exit(1);
	}

	//inicializa a lista e cria o sentinela
	aux->sentinela = criaToken(__END, 0, NULL);
	aux->sentinela->proximo = aux->sentinela;
	aux->sentinela->anterior = aux->sentinela;
	aux->tam = 0;
	return aux;
}


/* funcao removeLista: remove um token da lista e retorna seu endereco
 *
 * parametros: 
 *	struct Lista * (ponteiro para struct Lista)
 * 	struct Token * (ponteiro para struct Token)
 *
 * retorno: void 
 */
void removeLista(struct Lista *l, struct Token *t){
	
	//verifica se o sentinela não está sendo removido incorretamente
	if(t == l->sentinela){
		printf("Erro Remoção!\n");
		exit(1);
	}

	//remove o token da lista
	struct Token *aux = t;
	aux->anterior->proximo = aux->proximo;
	aux->proximo->anterior = aux->anterior;
	l->tam -= 1;
}


/* funcao insereFimLista: insere um token no fim da lista
 *
 * parametros:
 * 	struct Token * (ponteiro para struct Token)
 *
 *  retorno: void
 */
void insereFimLista(struct Lista *l, struct Token *t){
	l->sentinela->anterior->proximo = t;
	t->anterior = l->sentinela->anterior;
	t->proximo = l->sentinela;
	l->sentinela->anterior = t;
}


/* funcao insereLista: insere um token apos um outro token em uma lista
 *
 * parametros:
 * 	struct Token * (ponteiro para struct Token)
 * 	struct Token * (ponteiro para struct Token)
 * 	struct Lista * (ponteiro para struct Lista)
 *
 * retorno: void
 */
void insereLista(struct Token *inserir, struct Token *referencia, struct Lista *l){
	inserir->proximo = referencia->proximo;
	inserir->anterior = referencia;
	referencia->proximo->anterior = inserir;
	referencia->proximo = inserir;
	l->tam += 1;
}


/*funcao destroiLista: destroi uma lista e todos os seus tokens
 *
 *parametros:
 *	struct Lista * (ponteiro para struct Lista)
 *
 * retorno: void
 */
void destroiLista(struct Lista *l){

	//percorre todos os tokens (exceto sentinela) e os destroi
	struct Token *aux = l->sentinela->proximo;
	while(aux != l->sentinela){
		l->sentinela->proximo = aux->proximo;
		destroiToken(aux);
		aux = l->sentinela->proximo;
	}

	//destroi o sentinela
	destroiToken(l->sentinela);

	//destroi a lista
	free(l);
}
