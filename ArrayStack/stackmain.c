#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {
	Stack stack;
	Stack* pstack = &stack;

	StackInit(pstack);
	
	Push(pstack, 11);
	Push(pstack, 22);
	Push(pstack, 33);
	Push(pstack, 44);
	Push(pstack, 55);

	printf("stack data count : %d\n", pstack->topindex);
	printf("stack pop : ");
	while (!StackEmptyCheck(pstack)) {
		printf("%d ",Pop(pstack));
	}
	return 0;
}