#ifndef _DEQUE_H_
#define _DEQUE_H_

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _deque {
	Node* head;
	Node* tail;
}Deque;


void DequeInit(Deque* pdeque);
int Deque_Empty_check(Deque* qdeque);
void DequeFrontInsert(Deque* pdeque, Data data);
void DequeLastInsert(Deque* pdeque, Data data);
Data DequeRemoveFront(Deque* pdeque);
Data DequeRemoveLast(Deque* pdeque);
Data DequeFrontSeek(Deque* pdeque);
Data DequeLastSeek(Deque* pdeque);
#endif
