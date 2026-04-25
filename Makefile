CC=gcc
CFLAGS=-Wall -Wextra -ggdb # -DREADLINE # -DDEBUG_PRINT_CODE -DDEBUG_TRACE_EXECUTION
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
#LDFLAGS=-lreadline

miri: $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) miri
