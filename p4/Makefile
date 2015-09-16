CC = gcc
CFLAGS = -Wall -pedantic -ansi
EXEC = main
OBJ = main_temp.o array_op.o str_conv.o

$(EXEC) : $(OBJ)
		$(CC) $(OBJ) -o bin/$(EXEC)

main_temp.o: main_temp.c array_op.h str_conv.h
		$(CC) -c main_temp.c $(CFLAGS)

array_op.o: array_op.c array_op.h
		$(CC) -c array_op.c $(CFLAGS)

str_conv.o: str_conv.c str_conv.h 
		$(CC) -c str_conv.c $(CFLAGS)

clean:
	rm -f bin/$(OBJ) bin/$(EXEC) $(OBJ)
