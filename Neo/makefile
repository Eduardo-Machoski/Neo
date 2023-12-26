nome = Neo
parametros = -Wall

all: $(nome)

$(nome): Neo.o parse.o token.o fila.o
	gcc -o $(nome) Neo.o fila.o parse.o token.o $(parametros)

Neo.o: Neo.c
	gcc -c Neo.c $(parametros)

fila.o: fila.h fila.c
	gcc -c fila.c $(parametros)

parse.o: parse.h parse.c
	gcc -c parse.c $(parametros)

token.o: token.h token.c
	gcc -c token.c $(parametros)


clean:
	rm -f *.o *.gch $(nome)
