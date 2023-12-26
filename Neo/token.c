#include"token.h"

struct Token *criaToken(enum tokenName n, long long valor, char *var){
	struct Token *aux;
	if(!(aux = malloc(sizeof(struct Token)))){
		printf("Erro malloc!\n");
		exit(1);
	}
	aux->nome = n;
	aux->valor = valor;
	aux->var = var;
	aux->proximo = NULL;
	return aux;
}
enum tokenName obterNomeToken(char *str, const char *nomesToken[]){
	enum tokenName aux;
	for(aux = 0; aux < __END; aux++)
		if(strcmp(str, nomesToken[aux]) == 0)
			return aux;
	return var;
}

void tokenmizar(FILE *inFile, struct Fila *f, char ini, const char *nomesToken[]){
	if(isspace(ini))
		return;
	
	struct Token *tokenAtual;

	if(isalpha(ini)){
		char *str;
	       	if(!(str = malloc(sizeof(char) * 51))){
	       		printf("Erro Malloc!\n");
			exit(1);
	       	}
		
		int tam = 1;
		str[0] = ini;
		while(fscanf(inFile, "%c", &ini) == 1 && isalnum(ini)){
			if(tam >= 50){
				printf("Tamanho de nome excedido!\n");
				exit(1);
			}
			str[tam] = ini;
			tam++;
		}
		str[tam] = '\0';
		enum tokenName nome = obterNomeToken(str, nomesToken);
		switch (nome){
			case var:
				tokenAtual = criaToken(nome, 0, str);
				enfileira(f, tokenAtual);
			break;

			case quit:
				tokenAtual = criaToken(nome, 0, NULL);
				free(str);
				enfileira(f, tokenAtual);
			break;

			default:
			break;
		}
	} else if(isdigit(ini)){
		long long aux = 0;
		int aux2 = ini;
		aux += aux2 - 48;
		while(fscanf(inFile, "%c", &ini) == 1 && isdigit(ini)){
			aux2 = ini;
			aux = aux * 10 + aux2 - 48;
		}
		tokenAtual = criaToken(_int, aux, NULL);
		enfileira(f, tokenAtual);
	}

	if(ini == ';'){
		tokenAtual = criaToken(semicolon, 0, NULL);;
		enfileira(f, tokenAtual);
	} else if(!isspace(ini)){
		printf("Erro Criar Token!\n");
		exit(1);
	}
}
