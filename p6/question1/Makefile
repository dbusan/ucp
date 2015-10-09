CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o journal.o
EXEC = journal

$(EXEC) : $(OBJ)
		mkdir -p bin; $(CC) $(OBJ) -o bin/$(EXEC)


main.o: main.c journal.h
		$(CC) -c main.c $(CFLAGS)

journal.o: journal.c journal.h
		$(CC) -c journal.c $(CFLAGS)

clean:
	rm -f bin/$(OBJ) bin/$(EXEC) $(OBJ)
