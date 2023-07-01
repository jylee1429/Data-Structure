#include "CircleQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(queue* pq) {
	pq->front = 0;
	pq->now = 0;
}

int Queue_Empty_Check(queue* pq) {
	if (pq->front == pq->now)
		return TRUE;
	else
		return FALSE;
}

// Return index value corresponding to the next position in the queue
int NextIndex(int pos) {
	if (pos == QUEUE_LEN - 1)
		return 0;        // initialization
	else
		return pos + 1;  
}

void Enqueue(queue* pq, Data data) {
	if (NextIndex(pq->now) == pq->front) {
		printf("Queue Memory error\n");
		exit(-1);
	}
	pq->now = NextIndex(pq->now);
	pq->quearr[pq->now] = data;
}

Data Dequeue(queue* pq) {
	if (Queue_Empty_Check(pq)) {
		printf("Queue Memory empty\n");
		exit(-1);
	}
	pq->front = NextIndex(pq->front);
	return pq->quearr[pq->front];
}

