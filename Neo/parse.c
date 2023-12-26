#include"parse.h"

struct Token *observar(struct Token *t, int frente){
	int i = 1;
	struct Token *aux = t->proximo;
	while(i < frente && aux != NULL)
		aux = t->proximo;
	return aux;
}

void parsing(struct Fila *f){
	for(int i = *ini; i < num; i++)
		switch (tokens[i]->nome){
			case semicolon:
			break;

			case _int:
			break;

			case quit:
				struct Token *aux1 = observar(tokens, 1);
				struct Token *aux2 = observar(tokens, i + 2, num);
				if(aux1->nome != _int || aux2->nome != semicolon)
					exit(1);	
			break;

			case var:
			break;

			default:
				printf("erro!\n");
				exit(1);
		}
	return;
}
