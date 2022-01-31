CC=gcc
CFLAGS=-Wall -Wextra -std=c11
BIN=run

$(BIN): main.o dk_tool.o
	$(CC) $(CFLAGS) main.o dk_tool.o -o $(BIN)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

dk_tool.o: dk_tool.h dk_tool.c
	$(CC) $(CFLAGS) -c dk_tool.c

clean:
	rm *.o $(BIN)
