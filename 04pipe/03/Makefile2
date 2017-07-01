.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01mkfifo 02fifor 03fifow 04fifor 05fifow
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
