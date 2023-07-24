#include "Heap.h"

void HeapInit(Heap* pheap) {
	pheap->numofdata = 0;
}

int HeapEmptyCheck(Heap* pheap) {
	if (pheap->numofdata == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentNode(int index) {
	return index / 2;
}

int GetLeftChildNode(int index) {
	return index * 2;
}

int GetRightChildNode(int index) {
	return (index * 2) + 1;
}

int GetPriorityChildNode(Heap* pheap, int index) {
	if (GetLeftChildNode(index) > pheap->numofdata)
		return 0;
	else if (GetLeftChildNode(index) == pheap->numofdata)
		return GetLeftChildNode(index);
	else {
		if (pheap->heaparr[GetLeftChildNode(index)].priority < pheap->heaparr[GetRightChildNode(index)].priority)
			return GetLeftChildNode(index);
		else
			return GetRightChildNode(index);
	}
}

void HeapInsert(Heap* pheap, HData data, Priority priority) {
	pheap->numofdata++;
	int index = pheap->numofdata;

	Node node;
	node.data = data;
	node.priority = priority;

	while (index != 1) {
		if (priority < pheap->heaparr[GetParentNode(index)].priority) {
			pheap->heaparr[index] = pheap->heaparr[GetParentNode(index)];
			index = GetParentNode(index);
		}
		else
			break;
	}
	pheap->heaparr[index] = node;
}

HData HeapDelete(Heap* pheap) {
	HData removedata = pheap->heaparr[1].data;
	Node lastnode = pheap->heaparr[pheap->numofdata];

	int parentindex = 1;
	int childindex;

	while (childindex = GetPriorityChildNode(pheap, parentindex)) {
		if (lastnode.priority < pheap->heaparr[childindex].priority)
			break;
		pheap->heaparr[parentindex] = pheap->heaparr[childindex];
		parentindex = childindex;
	}
	pheap->heaparr[parentindex] = lastnode;
	pheap->numofdata--;
	return removedata;
}