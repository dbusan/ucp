#ifndef JOURNAL_H
#define JOURNAL_H

typedef struct {
	
	JournalEntry* entry;
	int size;

} Journal;

typedef struct {

	int day, month, year;
	char* message;

} JournalEntry;

JournalEntry getJournalEntry(int index);

Journal readJournal(char* filename);

static void readEntry(FILE *journal);

#endif
