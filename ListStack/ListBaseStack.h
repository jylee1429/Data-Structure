#ifndef _LIST_BASE_STACK_
#define _LIST_BASE_STACK_

#define TRUE 1
#define FALSE 0 

typedef int Data;
typedef struct _Node {
	Data data;
	struct _Node* next;
}Node;


typedef struct _ListStack {
	Node* head;
}ListStack;
typedef ListStack LStack;


void StackInit(LStack* pstack);
int StackEmptyCheck(LStack* pstack);
void Push(LStack* pstack, Data data);
Data Pop(LStack* pstack);


#endif
