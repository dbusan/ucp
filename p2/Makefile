CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = download.o download_stats.o
EXEC = download

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o bin/$(EXEC)

download.o : download.c download_stats.h
	$(CC) -c download.c download_stats.c $(CFLAGS)

download_stats.o : download_stats.h download_stats.c
	$(CC) -c download_stats.c $(CFLAGS)


clean: 
	rm -f $(EXEC) $(OBJ)

	
