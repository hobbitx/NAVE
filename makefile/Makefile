CC=gcc
OPCOES_COMPILADOR=-I. -I/usr/include/SOIL -lglut -lGLU -lSOIL -lGLEW -lGL -lm
TODOS_ARQUIVOS_PONTOH = 
TODOS_ARQUIVOS_OBJ = main.o score.o texto.o terreno.o variaveis.o desenha.o estrelas.o texturas.o loja.o


%.o: ../files/arquivos/%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o main $^ $(OPCOES_COMPILADOR)

run: all
	./main

clean:
	rm *.o main
