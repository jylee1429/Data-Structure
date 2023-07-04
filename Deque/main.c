#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Deque deque;
	Deque* pdeque = &deque;

	DequeInit(pdeque);
	DequeFrontInsert(pdeque, 33);
	DequeFrontInsert(pdeque, 22);
	DequeFrontInsert(pdeque, 11);

	DequeLastInsert(pdeque, 44);
	DequeLastInsert(pdeque, 55);
	DequeLastInsert(pdeque, 66);

	printf("%d\n", DequeFrontSeek(pdeque));
	printf("%d\n", DequeLastSeek(pdeque));

	while (!Deque_Empty_check(pdeque)) {
		printf("%d ", DequeRemoveFront(pdeque));
	}
	printf("\n");
	return 0;
}