CC=gcc
CFLAGS=-Wall -Wextra -ggdb -DDEBUG_PRINT_CODE -DDEBUG_TRACE_EXECUTION -DREADLINE
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
LDFLAGS=-lreadline

miri: $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) miri
