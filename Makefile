CC=gcc
CFLAGS=-Wall -Wextra
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

miri: $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) miri
