#include <stdio.h>
#include "DLinkedList.h"

int main(void) {
	list List;
	list* plist = &List;
	int data;
	int* pdata = &data;
	
	ListInit(plist);
	// head -> 55 -> 44 -> 33 -> 22 -> 11
	LInsert(plist, 11);
	LInsert(plist, 22);
	LInsert(plist, 33);
	LInsert(plist, 44);
	LInsert(plist, 55);

	printf("data count : %d\n", plist->numofdata);
	
	if (LFirst(plist, pdata)) {
		printf("%d ", *pdata);
		while (LNext(plist, pdata)) {
			printf("%d ", *pdata);
		}
	}

	if (LFirst(plist, pdata)) {
		if (*pdata == 33)
			LRemove(plist);
		while (LNext(plist, pdata)) {
			if (*pdata == 33)
				LRemove(plist);
		}
	}
	printf("\n");
	printf("data count : %d\n", plist->numofdata);
	if (LFirst(plist, pdata)) {
		printf("%d ", *pdata);
		while (LNext(plist, pdata)) {
			printf("%d ", *pdata);
		}
	}

	return 0;
}