.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01fcntl 02fcntl 03fcntl
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
