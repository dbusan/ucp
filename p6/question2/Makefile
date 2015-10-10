CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o linked_list.o journal.o
EXEC = journal

$(EXEC) : $(OBJ)
		mkdir -p bin; $(CC) $(OBJ) -o bin/$(EXEC)


main.o: main.c linked_list.h journal.h
		$(CC) -c main.c $(CFLAGS)

linked_list.o: linked_list.c linked_list.h journal.h
		$(CC) -c linked_list.c $(CFLAGS)

journal.o: journal.c journal.h
		$(CC) -c journal.c $(CFLAGS)

clean:
	rm -f bin/$(OBJ) bin/$(EXEC) $(OBJ)
