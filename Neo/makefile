nome = Neo
parametros = -Wall

all: $(nome)

$(nome): Neo.o token.o lista.o tokenmizar.o parse.o generation.o
	gcc -o $(nome) Neo.o token.o lista.o tokenmizar.o parse.o generation.o $(parametros)

Neo.o: Neo.c
	gcc -c Neo.c $(parametros)

token.o: token.h token.c
	gcc -c token.c $(parametros)

lista.o: lista.h lista.c
	gcc -c lista.c $(parametros)

tokenmizar.o: tokenmizar.h tokenmizar.c
	gcc -c tokenmizar.c $(parametros)

parse.o: parse.h parse.c
	gcc -c parse.c $(parametros)

generation.o: generation.h generation.c
	gcc -c generation.c $(parametros)


clean:
	rm -f *.o *.gch $(nome)
