.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=fileno error 01open 02open 03open 04open
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
