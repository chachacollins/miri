CC=gcc
CFLAGS=-Wall -Wextra
OBJFILES=chunk.o memory.o main.o debug.o value.o vm.o

miri: $(OBJFILES) common.h
	$(CC) $(CFLAGS) $(OBJFILES) -o miri

main.o: chunk.o memory.o
	$(CC) $(CFLAGS) -c main.c

chunk.o: chunk.c chunk.h
	$(CC) $(CFLAGS) -c chunk.c

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c

debug.o: debug.c debug.h
	$(CC) $(CFLAGS) -c debug.c

value.o: value.c value.h
	$(CC) $(CFLAGS) -c value.c

vm.o: vm.c vm.h
	$(CC) $(CFLAGS) -c vm.c

.PHONY: clean
clean:
	rm -f $(OBJFILES) miri
