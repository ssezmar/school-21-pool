CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11 -c
BUILD=../build/graph
 
all: graph.o stack.o tokenizer.o polish_notation.o out.o
	$(CC) graph.o stack.o tokenizer.o polish_notation.o out.o -o $(BUILD) -lm

out.o: out.c
	$(CC) $(FLAGS) out.c -o out.o -lm

graph.o: graph.c
	$(CC) $(FLAGS) graph.c -o graph.o -lm

tokenizer.o: tokenizer.c tokenizer.h
	$(CC) $(FLAGS) tokenizer.c -o tokenizer.o -lm

stack.o: stack.c stack.h
	$(CC) $(FLAGS) stack.c -o stack.o -lm

polish_notation.o: polish_notation.c polish_notation.h
	$(CC) $(FLAGS) polish_notation.c -o polish_notation.o -lm

clean:
	-rm -rf *.o ../build/*

rebuild: clean all
