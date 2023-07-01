#ifndef _CIRCLE_QUEUE_H_
#define _CIRCLE_QUEUE_H_

#define TRUE 1
#define FALSE 0

#define QUEUE_LEN 100
typedef int Data;

typedef struct _CQueue {
	int front;
	int now;
	Data quearr[QUEUE_LEN];
}cqueue;

typedef cqueue queue;

void QueueInit(queue* pq);
int Queue_Empty_Check(queue* pq);
// Return index value corresponding to the next position in the queue
int NextIndex(int pos);
void Enqueue(queue* pq, Data data);
Data Dequeue(queue* pq);
#endif
