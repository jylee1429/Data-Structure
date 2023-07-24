#ifndef _UPGRADE_HEAP_H_
#define _UPGRADE_HEAP_H_

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char HData;
typedef int SetPriorityfunc(HData data1, HData data2);

typedef struct _heap {
	SetPriorityfunc* SetPriority;
	int numofdata;
	HData heaparr[HEAP_LEN];
}Heap;

void HeapInit(Heap* pheap, SetPriorityfunc* SetPriority);
int HeapEmptyCheck(Heap* pheap);
int GetParentNode(int index);
int GetLeftChildNode(int index);
int GetRightChildNode(int index);
void HeapInsert(Heap* pheap, HData data);
HData HeapDelete(Heap* pheap);

#endif
