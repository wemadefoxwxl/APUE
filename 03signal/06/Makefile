.PHONY:all clean
CC=gcc
CFLAGS=-Wall -std=c99 -D_POSIX_C_SOURCE=199309L
BIN=01sigqueue_recv 02sigqueue_send 03sigqueue_recv 04sigqueue_send
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BIN)
