CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = logreader.o logtest.o
EXEC = logreader

$(EXEC) : $(OBJ)
		mkdir -p bin; $(CC) $(OBJ) -o bin/$(EXEC)

logreader.o: logreader.c logreader.h
		$(CC) -c logreader.c $(CFLAGS)

logtest.o: 	logtest.c logtest.h
		$(CC) -c logtest.c $(CFLAGS)

clean:
	rm -f bin/$(OBJ) bin/$(EXEC) $(OBJ)
