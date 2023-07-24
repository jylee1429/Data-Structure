#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main(void) {
	int i;
	Heap heap;
	Heap* pheap = &heap;

	HeapInit(pheap);

	HeapInsert(pheap, 'A', 1);
	HeapInsert(pheap, 'B', 2);
	HeapInsert(pheap, 'D', 4);
	HeapInsert(pheap, 'E', 5);
	HeapInsert(pheap, 'C', 3);
	HeapInsert(pheap, 'I', 9);
	HeapInsert(pheap, 'H', 8);
	HeapInsert(pheap, 'F', 6);
	HeapInsert(pheap, 'G', 7);

	printf("Heap node : %d\n", pheap->numofdata);
	for (i = 1; i <= pheap->numofdata; i++)
		printf("%c ", pheap->heaparr[i].data);
	printf("\n");
	printf("%c ", HeapDelete(pheap));
	printf("Heap node : %d\n", pheap->numofdata);
	for (i = 1; i <= pheap->numofdata; i++)
		printf("%c ", pheap->heaparr[i].data);
	printf("\n");

	printf("Delete node : ");
	while (!HeapEmptyCheck(pheap))
		printf("%c ", HeapDelete(pheap));

	return 0;
}