#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

void DequeInit(Deque* pdeque) {
	pdeque->head = NULL;
	pdeque->tail = NULL;
}

int Deque_Empty_check(Deque* qdeque) {
	if ((qdeque->head == NULL)) {
		return TRUE;
	}
	else 
		return FALSE;
}

void DequeFrontInsert(Deque* pdeque, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->next = pdeque->head;
	if (Deque_Empty_check(pdeque))
		pdeque->tail = newnode;
	else
		pdeque->head->prev = newnode;
	newnode->prev = NULL;
	pdeque->head = newnode;
}

void DequeLastInsert(Deque* pdeque, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->prev = pdeque->tail;
	if (Deque_Empty_check(pdeque))
		pdeque->head = newnode;
	else
		pdeque->tail->next = newnode;
	newnode->next = NULL;
	pdeque->tail = newnode;
}

Data DequeRemoveFront(Deque* pdeque) {
	if (Deque_Empty_check(pdeque)) {
		printf("No data\n");
		exit(-1);
	}
	Node* delnode = pdeque->head;
	Data delnodedata = pdeque->head->data;

	pdeque->head = pdeque->head->next;
	if (pdeque->head == NULL)
		pdeque->tail = NULL;
	else
		pdeque->head->prev = NULL;
	free(delnode);
	return delnodedata;
}


Data DequeRemoveLast(Deque* pdeque) {
	if (Deque_Empty_check(pdeque)) {
		printf("No data\n");
		exit(-1);
	}
	Node* delnode = pdeque->tail;
	Data delnodedata = pdeque->tail->data;
	pdeque->tail = pdeque->tail->prev;
	if (pdeque->tail == NULL)
		pdeque->head = NULL;
	else
		pdeque->tail->next = NULL;
	free(delnode);
	return delnodedata;
}

Data DequeFrontSeek(Deque* pdeque) {
	if (Deque_Empty_check(pdeque)) {
		printf("No data\n");
		exit(-1);
	}
	return pdeque->head->data;
}

Data DequeLastSeek(Deque* pdeque) {
	if (Deque_Empty_check(pdeque)) {
		printf("No data\n");
		exit(-1);
	}
	return pdeque->tail->data;
}
