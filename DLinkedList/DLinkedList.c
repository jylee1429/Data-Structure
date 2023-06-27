#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(list* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numofdata = 0;
}

void LInsert(list* plist, LData data) {
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

void FInsert(list* plist, LData data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = plist->head->next;
	plist->head->next = newnode;
	(plist->numofdata)++;
}

void SInsert(list* plist, LData data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newnode->data = data;

	while ((pred->next != NULL) && (plist->comp(data, pred->next->data) != 0))
		pred = pred->next;
	newnode->next = pred->next;
	pred->next = newnode;
	(plist->numofdata)++;
}


int LFirst(list* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(list* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(list* plist) {
	Node* delnode = plist->cur;
	LData deldata = delnode->data;

	plist->before->next = delnode->next;
	plist->cur = plist->before;
	free(delnode);
	(plist->numofdata)--;
	return deldata;
}

void SetSortRule(list* plist, int(*comp(LData d1, LData d2))) {
	plist->comp = comp;
}

int LCount(list* plist) {
	return plist->numofdata;
}

// ascending order
int PrecedeSort(int d1, int d2) { // d1 = newnode -> data, d2 = pred -> next -> data
	if (d1 > d2)
		return TRUE;
	else
		return FALSE;
}