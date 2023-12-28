#include"fila.h"

/* funcao desinfileira: remove o primeiro token da fila
 * 
 * parametros: struct Fila *f (ponteiro para struct Fila)
 *
 * retorno: struct Token * (ponteiro para struct Token)
 */
struct Token *desinfileira(struct Fila *f){
	
	//verifica se a fila contem ao menos um token
	if(filaVazia(f))
		return NULL;

	//remove o primeiro token e retorna seu endereço de memoria
	struct Token *aux = f->ini;
	f->ini = f->ini->proximo;
	f->tam -= 1;
	if(filaVazia(f))
		f->fim = NULL;
	return aux;
}


/* funcao enfileira: adiciona o token no fim da fila
 * 
 * parametros: 
 * 	struct Fila *f (ponteiro para struct Fila)
 *	struct Token *t (ponteiro para struct Token)
 *
 * retorno: void
 */
void enfileira(struct Fila *f, struct Token *t){

	// adiciona o token em uma fila vazia
	if(filaVazia(f)){
		f->ini = t;
		f->fim = t;
		return;
	}

	//adiciona o token em uma fila não vazia
	f->fim->proximo = t;
	f->fim = t;
	f->tam += 1;
	return;
}

/* funcao filaVazia: verifica se uma fila é vazia
 * 
 * parametros: 
 * 	struct Fila *f (ponteiro para struct Fila)
 *
 * retorno: bool (True se vazia; False se nao vazia)
 */
bool filaVazia(struct Fila *f){
	if(f->ini == NULL)
		return true;
	return false;
}

/* funcao criarFila: cria e inicializa uma nova fila
 * 
 * parametros:
 *
 * retorno: seturct Fila * (ponteiro para struct Fila)
 */
struct Fila *criaFila(){
	struct Fila *aux;
	
	//verifica se malloc da fila foi bem sucedido
	if(!(aux = malloc(sizeof(struct Fila)))){
		printf("Erro Malloc\n");
		exit(1);
	}

	//inicializa a Fila
	aux->fim = NULL;
	aux->ini = NULL;
	aux->tam = 0;
	return aux;
}


/* funcao imprimirFila: imprime os nomes dos tokens de uma fila
 * 
 * parametros: 
 * 	struct Fila *f (ponteiro para struct Fila)
 * 	const char *nomesToken[] (vetor contendo os nomes dos tokens)
 *
 * retorno: void
 */
void imprimirFila(struct Fila *f, const char *nomesToken[]){
	struct Token *aux = f->ini;

	//percorre cada elemento da fila e imprime o nome correspondente
	while(aux != NULL){
		printf("%s\n", nomesToken[aux->nome]);
		aux = aux->proximo;
	}
}


/* funcao destroiFila: destroi uma fila e todos os seus tokens
 * 
 * parametros: 
 * 	struct Fila *f (ponteiro para struct Fila)
 *
 * retorno: void
 */
void destroiFila(struct Fila *f){

	//destroi todos os tokens da fila
	while(f->ini != NULL){
		struct Token *aux = desinfileira(f);
		destroiToken(aux);
	}

	//destroi a fila
	free(f);
}
