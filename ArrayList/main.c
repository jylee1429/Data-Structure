#include <stdio.h>
#include "ArrayList.h"

int main(void) {
	int i;
	LData data;
	List list; // struct list 
	List* plist = &list;
	
	ListInit(plist);
	
	for (i = 0; i < 5; i++)
		LInsert(plist, i);

	printf("Data Count : %d\n", plist->numofdata);

	if (LFirst(plist, &data)) {
		printf("data : %d", data);
		while (LNext(plist, &data))
			printf(" %d", data);
		printf("\n");
	}
	LRemove(plist);

	printf("Data Count : %d\n", plist->numofdata);
	if (LFirst(plist, &data)) {
		printf("data : %d", data);
		while (LNext(plist, &data))
			printf(" %d", data);
		printf("\n");
	}

	LRemove(plist);

	printf("Data Count : %d\n", plist->numofdata);
	if (LFirst(plist, &data)) {
		printf("data : %d", data);
		while (LNext(plist, &data))
			printf(" %d", data);
		printf("\n");
	}
	return 0;
}