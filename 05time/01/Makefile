.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01setitimer  02setitimer 03getitimer
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
