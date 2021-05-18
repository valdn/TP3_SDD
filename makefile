CC=gcc
OPT= -g -Wall -Wextra

all : prog test
prog : main.o tree.o specific_tree.o pile.o
	$(CC) -o prog main.o tree.o specific_tree.o pile.o
test : maintest.o tree.o specific_tree.o pile.o
	$(CC) -o test maintest.o tree.o specific_tree.o pile.o
	rm *.o
main.o : main.c Tree/tree.h
	$(CC) -c main.c $(OPT)
maintest.o : maintest.c Tree/tree.h
	$(CC) -c maintest.c $(OPT)
tree.o : Tree/tree.c Tree/tree.h Tree/specific_tree.h
	$(CC) -c Tree/tree.c $(OPT)
specific_tree.o : Tree/specific_tree.c Tree/specific_tree.h
	$(CC) -c Tree/specific_tree.c $(OPT)
pile.o : Pile/pile.c Pile/pile.h
	$(CC) -c Pile/pile.c $(OPT)