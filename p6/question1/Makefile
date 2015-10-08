CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = journal.o
EXEC = journal

$(EXEC) : $(OBJ)
		mkdir -p bin; $(CC) $(OBJ) -o bin/$(EXEC)

journal: journal.c journal.h
		$(CC) -c journal.c $(CFLAGS)

clean:
	rm -f bin/$(OBJ) bin/$(EXEC) $(OBJ)
