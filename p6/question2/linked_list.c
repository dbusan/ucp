#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


LinkedList* createList()	
{
	LinkedList* list = malloc(sizeof(LinkedList));

	list->head = NULL;

	return list;
}

void insertElementStart(LinkedList *list, JournalEntry *mEntry)
{

	Node *mNode = (Node*) malloc(sizeof(Node));

	/* 	Create node, make its next node = NULL; 
		Make it point to the JournalEntry
	 */
	
	mNode->entry = mEntry;
	mNode->next = list->head;
	
	list->head = mNode;	
}

/**
 * 
 * @param *list - The linked list passed
 * @return NULL if the list is now empty, or returns the address of the new Head Node
 */
Node* removeFirstElement(LinkedList *list)
{
	Node *mHead = malloc(sizeof(Node));

	mHead = list->head;

	mHead->entry->message = NULL;
	mHead->entry->day = 0;
	mHead->entry->month = 0;
	mHead->entry->year = 0;

	free(mHead->entry->message);
	free(mHead->entry);

	/* if this was the last node, next will be NULL */
	free(mHead);

	return list->head->next;
}

Node* getJEntry(LinkedList *list, int i)
{
	int length = 0;

	/* Might be lost during runtime */
	Node *mNode = malloc(sizeof(Node));
	mNode = list->head;

	while (( mNode != NULL ) || (length < i))
	{
		length++;
		mNode= mNode->next; /* kek */
	}
	return mNode;
}

void printList(LinkedList *list)
{
	int i = 0;
	Node *car = malloc(sizeof(Node));

	car = list->head;

	while( car != NULL)
	{
		printf("Node %d: %d-%d-%d: %s\n",i, car->entry->year
			, car->entry->month
			, car->entry->day
			, car->entry->message);

		car = car->next;
		i++;
	}

	free(car);
}

void freeList(LinkedList *list)
{
	
	Node *car = malloc(sizeof(Node));

	car = list->head;

	while (car != NULL)
	{
		
		car->entry->message = NULL;
		car->entry->day = 0;
		car->entry->month = 0;
		car->entry->year = 0;

		free(car->entry->message);
		free(car->entry);

		car = car->next;
	}

	free(car);
	free(list);

}

