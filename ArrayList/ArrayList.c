#include "ArrayList.h"
#include <stdio.h>

void ListInit(List* plist) {
	plist->numofdata = 0;
	plist->cur_position = -1;
}

void LInsert(List* plist, LData data) {
	if (plist->numofdata >= LIST_LEN) {
		printf("Insert disable");
		return -1;
	}
	plist->arr[plist->numofdata] = data;
	(plist->numofdata)++;
}

int LFirst(List* plist, LData* pdata) {
	if (plist->numofdata == 0)
		return FALSE;
	(plist->cur_position) = 0;
	*pdata = plist->arr[plist->cur_position];
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if ((plist->cur_position) >= (plist->numofdata) - 1)
		return FALSE;
	(plist->cur_position)++;
	*pdata = plist->arr[plist->cur_position];
	return TRUE;
}

LData LRemove(List* plist) {
	int i;
	LData temp;
	if (plist->numofdata <= 0) {
		printf("No data");
		return -1;
	}
	temp = plist->arr[plist->cur_position];
	for (i = plist->cur_position; i < (plist->numofdata) - 1; i++)
		plist->arr[i] = plist->arr[i + 1];
	(plist->cur_position)--;
	(plist->numofdata--);
	return temp;
}

int LCount(List* plist) {
	return plist->numofdata;
}