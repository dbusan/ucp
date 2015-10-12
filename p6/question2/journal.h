#ifndef JOURNAL_H
#define JOURNAL_H

/*
	Need function to read all entries
	Write a C program to read a file and store the contents in a dynamically-allocated array of structs.
	The file contains journal entries, each consisting of a date and a text string. Each
	entry occupies two lines. The first line of each entry contains the date (in “day/-month/year” format) and
	the second contains the text. The text can be up to 100 characters long, not including the new-line character.
	The very first line of the file contains a single integer, indicating the number of Journal entries in the file.
 */

typedef struct JournalEntry{
	int day, month, year;
	char* message;
} JournalEntry;


/**
 * @param char* filename - name of the journalfile to be read
 * @param JournalEntry* j[] - array of JournalEntries that stores the journalEntries
 * returns number of entries read
 */
int readEntries(char* filename, JournalEntry* j[]);

/**
 * @param JournalEntry* j[]; a pointer to an array of JournalEntries.
 * @param int i - index of thing to be returned
 * Function that returns a pointer to the journalEntry specified by index i
 */
JournalEntry* getEntry(JournalEntry* j[], int i);

/**
 * Function prints the JournalEntry pointed to by j; format:
 * YYYY-MM-DD: Message
 * @param JournalEntry* j - the journal entry to be printed
 */
void printEntry(JournalEntry* j);


/**
 * Frees the memory allocated for the array of JournalEntries
 * @param JournalEntry* j[] - JournalEntry* array to be freed
 */
void freeJournal(JournalEntry* j[], int size);

#endif
