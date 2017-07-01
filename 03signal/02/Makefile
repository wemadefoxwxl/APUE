.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01kill 02kill 03pause
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
