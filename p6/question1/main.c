#include <stdio.h>
#include <stdlib.h>

#include "journal.h"

int main(int argc, char* argv[])
{
	char* journalName = {"testjournal"};
	
	

	int index;
	int day = 0; 
	int month = 0;
	int year = 1900;
	char* message;

	if (argc < 2)
	{
		printf("Usage: journal [entry index number]\n");
	}
	else
	{
		Journal alJournal;
		index = atoi(argv[1]);
		
		alJournal = readJournal(journalName);

		message = (char*)malloc( 200 * sizeof(char));
		
		if(getJournalEntry(index, &alJournal, message, &day, &month, &year) != 0)
		{
			printf("%d-%d-%d: %s\n",year, month, day, message);
		}

		free(message);
		freeJournal(&alJournal);
	}



	

	return 0;
}