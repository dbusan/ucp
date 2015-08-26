CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = numbers.o order.o user_input.o
EXEC = numbers 

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o bin/$(EXEC)

numbers.o : numbers.c order.h user_input.h order.c user_input.c
	$(CC) -c numbers.c $(CFLAGS)

order.o : order.h order.c
	$(CC) -c order.c $(CFLAGS)

user_input.o : user_input.c user_input.h order.h order.c
	$(CC) -c user_input.c $(CFLAGS)

clean: 
	rm -f bin/$(EXEC) bin/$(OBJ)

	
