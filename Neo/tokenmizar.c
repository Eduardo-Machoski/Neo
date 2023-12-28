#include"tokenmizar.h"



/* funcao obterNomeToken: obtem o enum tokenName correto do token
 * 
 * parametros: 
 * 	char *str (substring do arquivo original)
 * 	const char *nomesToken[] (vetor de strings com os nomes dos Tokens)
 *
 * retorno: enum tokenName
 */
enum tokenName obterNomeToken(char *str, const char *nomesToken[]){
	enum tokenName aux;

	//percorre cada posicao de nomesTOken e compara com str
	for(aux = 0; aux < __END; aux++)

		//se for igual, retorna o tokenName correspondente
		if(strcmp(str, nomesToken[aux]) == 0)
			return aux;

	//se nao for achado match, retorna var
	return var;
}


/* funcao tokenmizar: cria tokens a partir do arquivo original
 * 
 * parametros: 
 * 	FILE *inFile (ponteiro para arquivo de texto)
 * 	struct Fila *f (ponteiro para struct Fila)
 * 	char ini (char inicial de cada token)
 * 	const char *nomesToken[] (vetor de strings com os nomes dos Tokens)
 *
 * retorno: void
 */
void tokenmizar(FILE *inFile, struct Fila *f, char ini, const char *nomesToken[]){
	
	//retorna se ini for um espaço em branco
	if(isspace(ini))
		return;
	
	struct Token *tokenAtual;

	//ini é uma letra do alfabeto
	if(isalpha(ini)){


		//aloca um espaço de 50 chars para verifica o nome do Token
		char *str;
	       	if(!(str = malloc(sizeof(char) * 51))){
	       		printf("Erro Malloc!\n");
			exit(1);
	       	}
		
		int tam = 1;
		str[0] = ini;

		//percorre o arquiuvo e armazena o nome do Token em str
		while(fscanf(inFile, "%c", &ini) == 1 && isalnum(ini)){
			
			//caso o nome no arquivo exceda 50 retorna erro
			if(tam >= 50){
				printf("Tamanho de nome excedido!\n");
				exit(1);
			}
			str[tam] = ini;
			tam++;
		}

		//sinaliza o fim do nome em str
		str[tam] = '\0';

		//obtem qual o token correto, cria e enfileira ele
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
	} else if(isdigit(ini)){ //ini é um número
		
		//le o arquivo e armazena o numero em aux
		long long aux = 0;
		int aux2 = ini;
		aux += aux2 - 48;
		while(fscanf(inFile, "%c", &ini) == 1 && isdigit(ini)){
			aux2 = ini;
			aux = aux * 10 + (aux2 - 48);
		}

		//cria e enfileira um token _int com valor de aux
		tokenAtual = criaToken(_int, aux, NULL);
		enfileira(f, tokenAtual);
	}

	//cria e enfileira um token do tipo semicolon
	if(ini == ';'){
		tokenAtual = criaToken(semicolon, 0, NULL);;
		enfileira(f, tokenAtual);
	} else if(!isspace(ini)){ //verificaçao de erro na criaçao de token
		printf("Erro Criar Token!\n");
		exit(1);
	}
}
