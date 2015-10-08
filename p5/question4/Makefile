CC = gcc
CFlAGS = -Wall -ansi -pedantic
OBJ1 =  question3.o plot.o
OBJ2 = question4.o plot.o randomarray.o
EXEC1 = display
EXEC2 = generate


all: $(EXEC1) $(EXEC2)
	

$(EXEC1): $(OBJ1)
	mkdir -p bin; $(CC) $(OBJ1) -o bin/$(EXEC1)

$(EXEC2): $(OBJ2)
	mkdir -p bin; $(CC) $(OBJ2) -o bin/$(EXEC2)

question3.o: question3.c plot.h 
	$(CC) -c question3.c $(CFLAGS)

question4.o: question4.c randomarray.h plot.h
	$(CC) -c question4.c $(CFLAGS)

randomarray.o: randomarray.c randomarray.h plot.h
	$(CC) -c randomarray.c $(CFLAGS)

plot.o: plot.c plot.h
	$(CC) -c plot.c $(CFLAGS)

clean: 
	rm -f bin/$(EXEC1) bin/$(EXEC2) $(OBJ1) $(OBJ2)

