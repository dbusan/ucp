#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "journal.h"


JournalEntry* getEntry(Journal *j, int i)
{
	JournalEntry *mEntry;
	mEntry = malloc(sizeof(JournalEntry));
	mEntry->message = (char*)malloc(102*sizeof(char));

	strcpy(mEntry.message, j->entry[i].message);
	mEntry.day = j->entry[i].day;
	mEntry.month = j->entry[i].month;
	mEntry.year = j->entry[i].year;

	return mEntry;
}

int getJournalEntry(int index, Journal* mJournal, char message[], int *day, int *month, int *year)
{
	/* Probably not gonna like the null there */
	
	/**
	 * R
	 */
	
	int exists = 0;

	if (index > sizeof(JournalEntry)/sizeof(mJournal->entry))
	{
		printf("Entry does not exist\n");
	}
	else
	{
		*day = mJournal->entry[index].day;
		*month = mJournal->entry[index].month;
		*year = mJournal->entry[index].year;
		strcpy(message, mJournal->entry[index].message);
		exists = 1;
	}	

	return exists;
}

Journal readJournal(char* filename)
{
	FILE *journal;
	Journal mJournal;

	
	if ((journal = fopen(filename,"r")) == NULL)
	{
		perror("Error opening journal file.");
	}
	else
	{	/*  */
		readEntries(journal, &mJournal);
	}

	fclose(journal);
	return mJournal;
}



void freeJournal(Journal* mJournal)
{
	int i;
	int n_entries = sizeof(JournalEntry)/sizeof(mJournal->entry);

	for (i = 0; i < n_entries+1 ; i++)
	{
		if (mJournal->entry[i].message != NULL)
			free(mJournal->entry[i].message);
	}

	if (mJournal->entry != NULL)
		free(mJournal->entry);
}


/**
 *  
 *
 */
void readEntries(FILE *infile, Journal *mJournal)
{

	
	int i;
	int day, month, year;
	int size;

	/* String that stores the entire message*/
	char message[102];
	
	

	if (infile == NULL)
	{
		printf("readEntry: File hasn't been opened properly\n");
	}
	else
	{
		fscanf(infile,"%d\n",&size); /* First line of the file contains the number of entries. Read that and store in n_entries*/
		
		mJournal->size = size;
		mJournal->entry = (JournalEntry*)malloc( size * sizeof(JournalEntry) ); /* Allocate enough memory to hold all messages */
		
		for (i = 0 ; i < size ; i++)
		{
			fscanf(infile, "%d/%d/%d\n",&day, &month, &year);

			fgets(message, sizeof(message), infile);

			if (message[strlen(message)-1] == '\n')
			{
				message[strlen(message)-1] = '\0';
			}
			
			mJournal->entry[i].day = day;
			mJournal->entry[i].month = month;
			mJournal->entry[i].year = year;

			mJournal->entry[i].message = (char*)malloc((102) * sizeof(char));

			strcpy(mJournal->entry[i].message, message);
		}
		/* I need to free the allocated memory for the returned object. But i need to return it before I free it. free it using freeJournal */

	}
}
