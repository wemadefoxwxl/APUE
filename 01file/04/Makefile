.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01fileshare 02dup 03dup2
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
