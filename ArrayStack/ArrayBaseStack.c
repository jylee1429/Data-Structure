#include "ArrayBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack* pstack) {
	pstack->topindex = -1;
}

int StackEmptyCheck(Stack* pstack) {
	if (pstack->topindex < 0)
		return TRUE;
	else
		return FALSE;
}

void Push(Stack* pstack, Data data) {
	pstack->topindex += 1;
	pstack->stackarr[pstack->topindex] = data;
}

Data Pop(Stack* pstack) {
	int rmdata;
	if (StackEmptyCheck(pstack)) {
		printf("empty error\n");
		exit(-1);
	}
	rmdata = pstack->stackarr[pstack->topindex];
	pstack->topindex--;
	return rmdata;
}


Data Peek(Stack* pstack) {
	if (StackEmptyCheck(pstack)) {
		printf("empty error\n");
		exit(-1);
	}
	return pstack->stackarr[pstack->topindex];
}