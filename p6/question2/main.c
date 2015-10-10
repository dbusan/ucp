#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "journal.h"


int main(int argc, char* argv[])
{
	int date[3];

	int i;

	char message[100];

	char* filename = {"testjournal"};
	LinkedList* myList;
	Journal elJournal;

	if (argc < 2)
	{
		printf("Usage: journal [action:print/delete]");
	}
	else
	{

		elJournal = readJournal(filename);
		myList = createList();
		

		
		freeJournal(&elJournal);
		free(myList);
	}
	
	
	return 0;
}