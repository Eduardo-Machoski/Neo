#include"fila.h"

struct Token *desinfilera(struct Fila *f){
	if(filaVazia(f))
		return NULL;
	struct Token *aux = f->ini;
	f->ini = f->ini->proximo;
	f->tam -= 1;
	if(filaVazia(f))
		f->fim = NULL;
	return aux;
}

void enfileira(struct Fila *f, struct Token *t){
	if(filaVazia(f)){
		f->ini = t;
		f->fim = t;
		return;
	}
	f->fim->proximo = t;
	f->fim = t;
	f->tam += 1;
	return;
}

bool filaVazia(struct Fila *f){
	if(f->ini == NULL)
		return true;
	return false;
}

struct Fila *criaFila(){
	struct Fila *aux;
	if(!(aux = malloc(sizeof(struct Fila)))){
		printf("Erro Malloc\n");
		exit(1);
	}
	aux->fim = NULL;
	aux->ini = NULL;
	aux->tam = 0;
	return aux;
}


void imprimirFila(struct Fila *f, const char *nomesToken[]){
	struct Token *aux = f->ini;
	while(aux != NULL){
		printf("%s\n", nomesToken[aux->nome]);
		aux = aux->proximo;
	}
}

void destroiToken(struct Token *t){
	if(t->var != NULL)
		free(t->var);
	free(t);
}

void destroiFila(struct Fila *f){
	while(f->ini != NULL){
		struct Token *aux = desinfilera(f);
		destroiToken(aux);
	}
	free(f);
}
