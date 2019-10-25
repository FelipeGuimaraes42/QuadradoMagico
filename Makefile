CC=gcc # compilador
CFLAGS=-Wall -Wextra #  compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./qmagico # nome do executavel que sera gerado, nao troque

run: $(EXEC)
	$(EXEC)

$(EXEC): qmagico.c qmagico.o
	$(CC) $(CFLAGS) qmagico.c -o $(EXEC)

qmagico.o: qmagico.c
	$(CC) $(CFLAGS) -c qmagico.c -o qmagico.o

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf qmagico.o

# Para mais informacoes sobre o Makefile, procure os monitores ou consulte
# outras referencias disponiveis na internet como:
# https://opensource.com/article/18/8/what-how-makefile
