.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01cp 02lseek 03hole 04ls
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
