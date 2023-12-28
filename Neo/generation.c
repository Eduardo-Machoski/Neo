#include"generation.h"

/* funcao criaCodigoAssembly: cria um arquivo em assembly a partir de tokens
 *
 * parametros:
 * 	struct Lista *tokens (ponteiro para struct Lista)
 *
 * retorno: void
 */
void criaCodigoAssembly(struct Lista *tokens){
	FILE *outFile = fopen("assembly.asm", "w");

	fprintf(outFile, "global _start\n_start:\n");
	fprintf(outFile, "mov rax, 60\nmov rdi, %lld\nsyscall", tokens->sentinela->anterior->valor);

	fclose(outFile);
}
