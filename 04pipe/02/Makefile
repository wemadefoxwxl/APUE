.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99
BIN=01pipe 02pipe 03pipe 04pipe 05pipe
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
