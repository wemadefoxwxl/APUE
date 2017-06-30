.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01cp
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
