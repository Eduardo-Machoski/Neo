#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include"token.h"
#include"fila.h"
#include"parse.h"

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
	struct Fila *tokens = criaFila();
	while(fscanf(inFile, "%c", &atual) == 1)
		tokenmizar(inFile, tokens, atual, tokenName_str);

	fclose(inFile);

	imprimirFila(tokens, tokenName_str);
	
	//parsing(tokens);

	/*	
	int index = 0;
	parsing(tokens, numToken, &index);

	char *nome;

	FILE *outFile = fopen("assembly.asm", "w");
	fprintf(outFile, "global _start\n_start:\n");


	for(int i = 0; i < numToken; i++){
		if(tokens[i]->nome == quit && tokens[i + 1]->nome == _int && tokens[i+2]->nome == semicolon)
			fprintf(outFile, "mov rax, 60\nmov rdi, %lld\nsyscall", tokens[i+1]->valor);
		free(tokens[i]);
	}
	free(tokens);
	fclose(outFile);
	
	if(argc == 3)
		nome = argv[2];
	else
		nome = "out";

	char *str1 = malloc(sizeof(char) * (82 + strlen(nome)));
       	strcpy(str1,"nasm -felf64 assembly.asm && ld assembly.o -o ");
	char *str2 = " && rm assembly.asm && rm assembly.o";
	
	strcat(str1, nome);
	strcat(str1, str2);
	
	system(str1);

	free(str1);
	*/

	destroiFila(tokens);
	return 0;
}
