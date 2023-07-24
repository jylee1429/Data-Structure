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
		if (pheap->SetPriority(pheap->heaparr[GetLeftChildNode(index)], pheap->heaparr[GetRightChildNode(index)]) > 0) // 0���� Ŭ ��쿡�� LeftChildNode �켱������ �켱
			return GetLeftChildNode(index);
		else  // 0���� ���� ��쿡�� RightChildNode �켱������ �켱
			return GetRightChildNode(index);
	}
}

void HeapInsert(Heap* pheap, HData data) {
	pheap->numofdata++;
	int index = pheap->numofdata;

	while (index != 1) {
		if (pheap->SetPriority(data, pheap->heaparr[GetParentNode(index)]) > 0) { // data�� �켱������ �켱
			pheap->heaparr[index] = pheap->heaparr[GetParentNode(index)];
			index = GetParentNode(index);
		}
		else // data�� �켱������ �켱�� �ƴ� ���
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
		if (pheap->SetPriority(lastdata, pheap->heaparr[childindex]) > 0) // lastdata�� �켱������ �켱�� ���
			break;
		pheap->heaparr[parentindex] = pheap->heaparr[childindex];
		parentindex = childindex;
	}
	pheap->heaparr[parentindex] = lastdata;
	pheap->numofdata--;
	return removedata;
}