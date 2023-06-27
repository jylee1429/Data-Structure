#ifndef _C_LINKED_LIST_
#define _C_LINKED_LIST_

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _CLL {
	Node* tail;
	Node* cur;
	Node* before;
	int numofdata;
}CList;

typedef CList list;

void ListInit(list* plist);
void LInsert(list* plist, Data data);
void LInsertFront(list* plist, Data data);
int LFirst(list* plist, Data* data);
int  LNext(list* plist, Data* data);
Data LRemove(list* plist);
int LCount(list* plist);

#endif