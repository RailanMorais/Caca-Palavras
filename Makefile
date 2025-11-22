CC = cc
CFLAGS = -Wall
objects = main.o leitura.o saida.o processamento.o

main: $(objects)
	$(CC) $(CFLAGS) $(objects) -o caca_palavras

main.o: main.c

leitura.o: leitura.h

saida.o: saida.h

processamento.o: processamento.h

.PHONY: clean

clean:
	rm caca_palavras $(objects)