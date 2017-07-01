.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01execve 02exec 03exec hello 04exec 05exec 06exec
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
