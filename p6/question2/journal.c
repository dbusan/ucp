#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "journal.h"



int readEntries(char* filename, JournalEntry** j)
{
	
	int i;
	int day, month, year;
	int size;

	/* String that stores the entire message*/
	char message[102];

	FILE *infile = fopen(filename,"r");


	if (infile == NULL)
	{
		printf("readEntry: File hasn't been opened properly\n");
	}
	else
	{
		JournalEntry *mJournal;

		fscanf(infile,"%d\n",&size); /* First line of the file contains the number of entries. Read that and store in n_entries*/
		
		/* Initialize array of JournalEntries to hold all entries 
		initJournalEntriesArray(size,*j); */
		
		mJournal = (JournalEntry*)malloc(sizeof(JournalEntry) * size);


		for (i = 0 ; i < size ; i++)
		{
			fscanf(infile, "%d/%d/%d\n",&day, &month, &year);

			fgets(message, sizeof(message), infile);

			/* Removes trailing newline character */
			if (message[strlen(message)-1] == '\n')
			{
				message[strlen(message)-1] = '\0';
			}
			
			


			mJournal[i].day = day;
			mJournal[i].month = month;
			mJournal[i].year = year;

			
			mJournal[i].message = (char*)malloc(sizeof(char) * (strlen(message) + 1));
			strcpy(mJournal[i].message, message);
		}

		*j = mJournal;
	}

	fclose(infile);

	return size;
}



void freeJournal(JournalEntry** j, int size)
{

	int i;

	
	for(i = 0; i < size; i++)
		free((*j)[i].message);

}

