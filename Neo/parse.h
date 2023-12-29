#if !defined(PARSE_H)
#define PARSE_H 1

#include"tokenmizar.h"
#include"lista.h"


/* funcao observar: observe o nome do token 'frente' numeros apos t
 *
 * parametros:
 * 	struct Token * (ponteiro para struct Token)
 * 	int frente (numeros para frente a ser observado)
 *
 * retorno: struct Token * (ponteiro para struct Token)
 */
struct Token *observar(struct Token *t, int frente);


/* funcao parsing: realiza o processo de parsing com a lista de tokens
 *
 * parametros:
 * 	struct Lista * (ponteiro para struct Lista)
 *
 * retorno: void
 */
void parsing(struct Lista *l);

#endif

