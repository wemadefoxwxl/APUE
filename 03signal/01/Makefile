.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01signal 02signal
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
