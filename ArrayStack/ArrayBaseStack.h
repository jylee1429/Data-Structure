#ifndef _ARRAY_BASE_STACK_
#define _ARRAY_BASE_STACK_

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;
typedef struct _ArrayStack {
	Data stackarr[STACK_LEN];
	int topindex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);
int StackEmptyCheck(Stack* pstack);
void Push(Stack* pstack, Data data);
Data Pop(Stack* pstack);
Data Peek(Stack* pstack);

#endif

