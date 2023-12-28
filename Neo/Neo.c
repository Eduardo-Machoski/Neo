#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"token.h"
#include"lista.h"
#include"tokenmizar.h"
#include"parse.h"
#include"generation.h"

const char *tokenName_str[] = {";", "int", "quit", ""};

int main (int argc, char *argv[]) {

	//verifica se foi passado um arquivo a ser compilado
	if(argc == 1){
		printf("Passe um arquivo para compilar!\n");
		return 1;
	}

	//adquire o tamanho do nome do arquivo
	int len = strlen(argv[1]);

	//verifica se o arquivo passado termina em '.neo'
	{
	char *neo = ".neo";
	for (int i = 0; i < 4; i++)
		if(argv[1][len - (1 + i)] != neo[4 - (1 + i)]){
			printf("Arquivo com formato errado!\n");
			return 1;
		}
	}

	FILE *inFile;

	//abre o arquivo para leitura e verifica se a abertura foi bem sucedida
	if(!(inFile = fopen(argv[1], "r"))){
		printf("Erro abrindo o arquivo!\n");
		return 1;
	}

	//le cada caracter no arquivo e transforma as palavras-chave em tokens
	char atual;
	struct lista *tokens = criaLista();
	while(fscanf(inFile, "%c", &atual) == 1)
		tokenmizar(inFile, tokens, atual, tokenName_str);

	//fecha o arquivo original
	fclose(inFile);

	//imprimirFila(tokens, tokenName_str);
	
	//realiza o processo de parsing com os tokens
	parsing(tokens);

	criaCodigoAssembly(tokens);

	destroiLista(tokens);

	//verifica se o usuario selecionou o nome do executavel	
	char *nome;
	if(argc == 3)
		nome = argv[2];
	else
		nome = "out";

	//cria uma string com o comando para nasm (linux)
	char *str1 = malloc(sizeof(char) * (82 + strlen(nome)));
       	strcpy(str1,"nasm -felf64 assembly.asm && ld assembly.o -o ");
	char *str2 = " && rm assembly.asm && rm assembly.o";
	
	strcat(str1, nome);
	strcat(str1, str2);
	
	system(str1);

	free(str1);

	return 0;
}
