#ifndef JOURNAL_H
#define JOURNAL_H

typedef struct JournalEntry{

	int day, month, year;
	char* message;

} JournalEntry;

typedef struct Journal {

	JournalEntry* entry;
	int size;

} Journal;


/**
 * function: getJournalEntry
 * Returns 0 if entry doesn't exist
 */
int getJournalEntry(int index, 
	Journal* mJournal, 
	char message[], 
	int *day, 
	int *month, 
	int *year);

Journal readJournal(char* filename);

void freeJournal(Journal* mJournal);
 
Journal readEntries(FILE *journal);

#endif
