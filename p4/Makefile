CC = gcc
CFLAGS = -Wall -pedantic -ansi
EXEC = main
OBJ = main.o

$(EXEC) : $(OBJ)
		$(CC) $(OBJ) -o $(EXEC)

main.o: main.c main.h
		$(CC) -c main.c $(CFLAGS)

