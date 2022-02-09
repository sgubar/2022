CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -lm
BIN=run

$(BIN): main.o figure.o
	$(CC) $(CFLAGS) main.o figure.o -o $(BIN)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

figure.o: figure.h figure.c
	$(CC) $(CFLAGS) -c figure.c

clean:
	rm *.o $(BIN)
