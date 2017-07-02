.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01sigaction 02sigaction 03sigaction 04sigaction
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
