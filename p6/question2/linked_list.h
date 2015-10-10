#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "journal.h"

typedef struct Node {
	JournalEntry *entry;
	struct Node *next;
} Node;

typedef struct LinkedList { /* Linked List Journal */
	Node* head;
} LinkedList;

/**
 * list pointer is passed. It sets the head of the list to point to NULL
 * sets the list size to 0
 */
LinkedList* createList();

void insertElementStart(LinkedList *list, JournalEntry *mEntry);

Node* removeFirstElement(LinkedList *list);

Node* getJEntry(LinkedList *list, int i);

void printList(LinkedList *list);

void freeList(LinkedList *list);

#endif