#include <stdio.h>
#include "ListBaseStack.h"

int main(void) {
	LStack stack;
	LStack* pstack;
	pstack = &stack;

	StackInit(pstack);
	
	Push(pstack, 11);
	Push(pstack, 22);
	Push(pstack, 33);
	Push(pstack, 44);
	Push(pstack, 55);
	while (!StackEmptyCheck(pstack)) {
		printf("%d ", Pop(pstack));
	}
	return 0;
}