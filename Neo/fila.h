#if !defined(FILA_H)
#define FILA_H 1

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

struct Fila {
	struct Token *ini;
	struct Token *fim;
	int tam;
};

enum tokenName {
	semicolon = 0,
	_int,
	quit,
	var,
	__END
};


struct Token {
	enum tokenName nome;
	long long valor;
	char *var;
	struct Token *proximo;
};

struct Token *desinfilera(struct Fila *fila);

void enfileira(struct Fila *f, struct Token *t);

bool filaVazia(struct Fila *f);

struct Fila *criaFila();

void imprimirFila(struct Fila *f, const char *nomesToken[]);

void destroiFila(struct Fila *f);
#endif

