CC=gcc

main: main.o list.o
	$(CC) main.o list.o -o main

main.o: main.c
	$(CC) -c main.c

list.o: list.c list.h
	$(CC) -c list.c

clean:
	rm *.o main
