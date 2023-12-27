#include"parse.h"

struct Token *observar(struct Token *t, int frente){
	int i = 1;
	struct Token *aux = t->proximo;
	while(i < frente && aux != NULL)
		aux = t->proximo;
	return aux;
}

void parsing(struct Fila *f){
	struct Token *aux = f->ini;
	for(int i = 0; i < f->tam; i++)
		switch (aux->nome)
		{
			case semicolon:
			break;

			case _int:
			break;

			case quit:
				struct Token *aux1 = observar(aux, 1);
				struct Token *aux2 = observar(aux, i + 2);
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
