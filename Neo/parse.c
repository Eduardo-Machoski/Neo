#include"parse.h"

struct Token *observar(struct Token *t, int frente){
	int i = 1;
	struct Token *aux = t->proximo;
	while(i < frente && aux != NULL){
		aux = aux->proximo;
		i++;
	}
	return aux;
}

void parsing(struct Lista *l){
	struct Token *aux = l->sentinela->proximo;
	for(int i = 0; i < l->tam; i++){
		switch (aux->nome)
		{
			case semicolon:
			break;

			case _int:
			break;

			case quit:
				struct Token *aux1 = observar(aux, 1);
				struct Token *aux2 = observar(aux, 2);
				if(aux1->nome != _int || aux2->nome != semicolon){
					printf("erro parsing");
					exit(1);
				}
			break;

			case var:
			break;

			default:
				printf("erro!\n");
				exit(1);
		}
		aux = aux->proximo;
	}
	return;
}
