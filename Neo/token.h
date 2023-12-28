#if !defined(TOKEN_H)
#define TOKEN_H 1

#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

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
	struct Token *anterior;
};

/* funcao criaToken: cria e inicializa um Token
 * 
 * parametros: 
 * 	enum tokenName n (nome do token)
 * 	long long valor (valor a ser contido no token)
 * 	char *var (string contendo nome de variavel)
 *
 * retorno: struct Token * (ponteiro para struct Token)
 */
struct Token *criaToken(enum tokenName n, long long valor, char *var);

	
/* funcao destroiToken: destroi um Token e seus elementos
 * 
 * parametros: 
 * 	struct Token *t (ponteiro para struct Token)
 *
 * retorno: void
 */
void destroiToken(struct Token *t);

#endif
