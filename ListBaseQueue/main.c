#include <stdio.h>
#include "ListBaseQueue.h"

int main(void) {
	queue q;
	queue* pq = &q;

	QueueInit(pq);

	Enqueue(pq, 11);
	Enqueue(pq, 22);
	Enqueue(pq, 33);
	Enqueue(pq, 44);
	Enqueue(pq, 55);

	while (!Queue_Empty_Check(pq)) {
		printf("%d ", Dequeue(pq));
	}

	return 0;
}