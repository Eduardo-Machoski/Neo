#include"generation.h"

/* funcao criaCodigoAssembly: cria um arquivo em assembly a partir de tokens
 *
 * parametros:
 * 	struct Fila *tokens (ponteiro para struct Fila)
 *
 * retorno: void
 */
void criaCodigoAssembly(struct Fila *tokens){
	FILE *outFile = fopen("assembly.asm", "w");

	fprintf(outFile, "global _start\n_start:\n");
	fprintf(outFile, "mov rax, 60\nmov rdi, %lld\nsyscall", tokens->ini->proximo->valor);

	fclose(outFile);
}
