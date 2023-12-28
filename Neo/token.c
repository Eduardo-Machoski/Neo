#include"token.h"

/* funcao criaToken: cria e inicializa um Token
 * 
 * parametros: 
 * 	enum tokenName n (nome do token)
 * 	long long valor (valor a ser contido no token)
 * 	char *var (string contendo nome de variavel)
 *
 * retorno: struct Token * (ponteiro para struct Token)
 */
struct Token *criaToken(enum tokenName n, long long valor, char *var){
	struct Token *aux;

	//verifica se o malloc foi bem sucedido
	if(!(aux = malloc(sizeof(struct Token)))){
		printf("Erro malloc!\n");
		exit(1);
	}

	//inicializa os valores do Token
	aux->nome = n;
	aux->valor = valor;
	aux->var = var;
	aux->proximo = NULL;
	return aux;
}

/* funcao destroiToken: destroi um Token e seus elementos
 * 
 * parametros: 
 * 	struct Token *t (ponteiro para struct Token)
 *
 * retorno: void
 */
void destroiToken(struct Token *t){

	//destroi a string var caso exista
	if(t->var != NULL)
		free(t->var);
	free(t);
}
