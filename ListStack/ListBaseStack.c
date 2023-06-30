#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"


void StackInit(LStack* pstack) {
	pstack->head = NULL;
}

int StackEmptyCheck(LStack* pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void Push(LStack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data Pop(LStack* pstack) {
	Data rmdata;
	Node* rmnode;

	if (StackEmptyCheck(pstack)) {
		printf("Stack empty\n");
		exit(-1);
	}

	rmnode = pstack->head;
	rmdata = pstack->head->data;
	pstack->head = rmnode->next;
	free(rmnode);
	return rmdata;
}
