#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(list* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numofdata = 0;
}

// add node to tail
void LInsert(list* plist, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newnode;
		plist->tail->next = newnode;
	}
	else {
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	(plist->numofdata)++;
}


// add node to head
void LInsertFront(list* plist, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
	}
	(plist->numofdata)++;
}

int LFirst(list* plist, Data* data) {
	if (plist->tail == NULL)
		return FALSE;
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	*data = plist->cur->data;
	return TRUE;
}

int  LNext(list* plist, Data* data) {
	if (plist->tail == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*data = plist->cur->data;
	return TRUE;
}

Data LRemove(list* plist) {
	Node* delnode = plist->cur;
	Data deldata = plist->cur->data;

	if (delnode == plist->tail) {  
		if (plist->tail->next == plist->tail) // only tail node
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(delnode);
	(plist->numofdata)--;
	return deldata;
}


int LCount(list* plist) {
	return plist->numofdata;
}