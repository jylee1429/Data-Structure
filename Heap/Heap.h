#ifndef _HEAP_H_
#define _HEAP_H_

#define TRUE 1
#define FALSE 0
#define HEAP_SIZE 100

typedef char HData;
typedef int Priority;

typedef struct _node {
	HData data;
	Priority priority;
}Node;

typedef struct _heap {
	Node heaparr[HEAP_SIZE];
	int numofdata;
}Heap;

void HeapInit(Heap* pheap);
int HeapEmptyCheck(Heap* pheap);
int GetParentNode(int index);
int GetLeftChildNode(int index);
int GetRightChildNode(int index);
int GetPriorityChildNode(Heap* pheap, int index);
void HeapInsert(Heap* pheap, HData data, Priority priority);
HData HeapDelete(Heap* pheap);

#endif
