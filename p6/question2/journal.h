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

JournalEntry* getEntry(Journal *j, int i);

int getJournalEntry(int index, 
	Journal* mJournal, 
	char message[], 
	int *day, 
	int *month, 
	int *year);
/**
 * @param Used to read the journal from the file into a struct
 * @return a journal object
 */
Journal readJournal(char* filename);

void freeJournal(Journal* mJournal);
 
/* Called internally */
void readEntries(FILE *journal, Journal* mJournal);

#endif
