#include <stdlib.h>
#include <stdio.h>
#include "ListBaseQueue.h"

void QueueInit(queue* pq) {
	pq->front = NULL;
	pq->now = NULL;
}

int Queue_Empty_Check(queue* pq) {
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(queue* pq, Data data) {
	
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;

	if (pq->front == NULL) {
		pq->front = newnode;
		pq->now = newnode;
	}
	else {
		pq->now->next = newnode;
		pq->now = newnode;
	}
}

Data Dequeue(queue* pq) {
	Node* delnode;
	Data deldata;

	if (Queue_Empty_Check(pq)) {
		printf("Queue Memory Empty\n");
		exit(-1);
	}
	
	delnode = pq->front;
	deldata = pq->front->data;
	pq->front = delnode->next;
	return deldata;

}