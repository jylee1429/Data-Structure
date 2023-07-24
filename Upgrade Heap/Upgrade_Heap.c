#include "Upgrade_Heap.h"

void HeapInit(Heap* pheap, SetPriorityfunc* SetPriority) {
	pheap->numofdata = 0;
	pheap->SetPriority = SetPriority;
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
		if (pheap->SetPriority(pheap->heaparr[GetLeftChildNode(index)], pheap->heaparr[GetRightChildNode(index)]) > 0) // 0보다 클 경우에는 LeftChildNode 우선순위가 우선
			return GetLeftChildNode(index);
		else  // 0보다 작을 경우에는 RightChildNode 우선순위가 우선
			return GetRightChildNode(index);
	}
}

void HeapInsert(Heap* pheap, HData data) {
	pheap->numofdata++;
	int index = pheap->numofdata;

	while (index != 1) {
		if (pheap->SetPriority(data, pheap->heaparr[GetParentNode(index)]) > 0) { // data의 우선순위가 우선
			pheap->heaparr[index] = pheap->heaparr[GetParentNode(index)];
			index = GetParentNode(index);
		}
		else // data의 우선순위가 우선이 아닐 경우
			break;
	}
	pheap->heaparr[index] = data;
}

HData HeapDelete(Heap* pheap) {
	HData removedata = pheap->heaparr[1];
	HData lastdata = pheap->heaparr[pheap->numofdata];

	int parentindex = 1;
	int childindex;

	while (childindex = GetPriorityChildNode(pheap, parentindex)) {
		if (pheap->SetPriority(lastdata, pheap->heaparr[childindex]) > 0) // lastdata의 우선순위가 우선일 경우
			break;
		pheap->heaparr[parentindex] = pheap->heaparr[childindex];
		parentindex = childindex;
	}
	pheap->heaparr[parentindex] = lastdata;
	pheap->numofdata--;
	return removedata;
}