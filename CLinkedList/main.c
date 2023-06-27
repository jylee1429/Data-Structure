#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main(void) {
	list List;
	list* plist = &List;
	int i, count;
	int data;
	int* pdata = &data;

	ListInit(plist);

	LInsert(plist, 11);
	LInsert(plist, 33);
	LInsert(plist, 22);
	LInsert(plist, 55);
	LInsert(plist, 44);
	LInsert(plist, 33);

	if (LFirst(plist, pdata)) {
		printf("%d ", *pdata);
		for (i = 0; i < 10; i++) {
			if (LNext(plist, pdata))
				printf("%d ", *pdata);
		}
	}
	printf("\n");

	count = LCount(plist);

	if (count != 0) {
		LFirst(plist, pdata);
		if ((*pdata) == 33)
			LRemove(plist);
		for (i = 0; i < count-1; i++) {
			LNext(plist, pdata);
			if ((*pdata) == 33)
				LRemove(plist);
		}
	}

	if (LFirst(plist, pdata)) {
		printf("%d ", *pdata);
		for (i = 0; i < 10; i++) {
			if (LNext(plist, pdata))
				printf("%d ", *pdata);
		}
	}

	printf("\n");
	printf("%d\n", plist->numofdata);

	return 0;
}