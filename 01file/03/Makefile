.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=stat
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
