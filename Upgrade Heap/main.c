#include <stdio.h>
#include <stdlib.h>
#include "Upgrade_Heap.h"

int DataSetPriority(int data1, int data2);

int main(void) {
	int i;
	Heap heap;
	Heap* pheap = &heap;

	HeapInit(pheap, DataSetPriority);

	/*HeapInsert(pheap, 'A');
	HeapInsert(pheap, 'B');
	HeapInsert(pheap, 'D');
	HeapInsert(pheap, 'E');
	HeapInsert(pheap, 'C');
	HeapInsert(pheap, 'I');
	HeapInsert(pheap, 'H');
	HeapInsert(pheap, 'F');
	HeapInsert(pheap, 'G');*/


	HeapInsert(pheap, 2);
	HeapInsert(pheap, 1);
	HeapInsert(pheap, 5);
	HeapInsert(pheap, 3);
	HeapInsert(pheap, 4);
	HeapInsert(pheap, 6);
	HeapInsert(pheap, 7);

	printf("Heap node : %d\n", pheap->numofdata);
	for (i = 1; i <= pheap->numofdata; i++)
		printf("%d ", pheap->heaparr[i]);
	printf("\n");
	printf("%d ", HeapDelete(pheap));
	printf("Heap node : %d\n", pheap->numofdata);
	for (i = 1; i <= pheap->numofdata; i++)
		printf("%d ", pheap->heaparr[i]);
	printf("\n");

	printf("Delete node : ");
	while (!HeapEmptyCheck(pheap))
		printf("%d ", HeapDelete(pheap));

	return 0;
}

int DataSetPriority(int data1, int data2) {
	return data2 - data1;
}