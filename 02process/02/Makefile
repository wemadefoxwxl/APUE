.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01fork 02fork 03vfork 04exit 05atexit 06fork
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
