#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "journal.h"


JournalEntry getJournalEntry(int index)
{
	JournalEntry mEntry;



	return mEntry;
}

Journal readJournal(char* filename)
{
	FILE *journal;
	Journal mJournal;
	int no_entries;
	int i;

	Journal.entry = (*JournalEntry)malloc( no_entries * sizeof(*JournalEntry) );

	if ((journal = fopen(filename,"r")) == NULL)
	{
		perror("Error opening journal file.");
	}
	else
	{
		fscanf(filename,"%d\n",&no_entries);
		for (i = 0; i < no_entries; i++)
		{
			mJournal.entry[i] = getJournalEntry(i);
		}
	}

	fclose(journal);
	return 
}