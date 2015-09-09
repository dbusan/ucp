CC = gcc
CFLAGS = -Wall -pedantic -ansi
EXEC = main
OBJ = main_temp.o array_op.o

$(EXEC) : $(OBJ)
		$(CC) $(OBJ) -o bin/$(EXEC)

main_temp.o: main_temp.c array_op.h
		$(CC) -c main_temp.c $(CFLAGS)

array_op.o: array_op.c array_op.h
		$(CC) -c array_op.c $(CFLAGS)

clean:
	rm -f bin/$(OBJ) bin/$(EXEC) $(OBJ)
