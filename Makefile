CC=gcc
CFLAGS=-Wall -Wextra
OBJFILES=chunk.o memory.o main.o

miri: $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o miri

main.o: chunk.o memory.o
	$(CC) $(CFLAGS) -c main.c

chunk.o: chunk.c chunk.h
	$(CC) $(CFLAGS) -c chunk.c

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c
