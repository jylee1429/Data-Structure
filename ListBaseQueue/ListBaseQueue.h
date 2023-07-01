#ifndef _LIST_BASE_QUEUE_
#define _LIST_BASE_QUEUE_

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _Queue {
	Node* front;
	Node* now;
}queue;

void QueueInit(queue* pq);
int Queue_Empty_Check(queue* pq);
void Enqueue(queue* pq, Data data);
Data Dequeue(queue* pq);
#endif
