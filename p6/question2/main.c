#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "journal.h"


int main(int argc, char* argv[])
{

	char* filename = {"testjournal"};
	int size;

	JournalEntry *journal;

	int j = atoi(argv[1]);

	if (argc < 2)
	{
		printf("Usage: journal [action:print/delete]");
	}
	else
	{
		size = readEntries(filename, &journal);
		
		if (j < size)
			printf("%2d-%02d-%02d: %s\n",journal[j].year, journal[j].month, journal[j].day, journal[j].message);
		else
		{
			printf("Error - Entry specified does not exist\n");
		}

		freeJournal(&journal,size);

		free(journal);
	}
	
	
	return 0;
}