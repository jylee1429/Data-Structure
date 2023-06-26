#ifndef _D_LINKED_LIST_H_
#define _D_LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

typedef int LData;
typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _linkedlist {
	Node* head;
	Node* cur;
	Node* before;
	int (*comp)(LData d1, LData d2);        // sorting criteria
	int numofdata;
}LinkedList;

typedef LinkedList list;

void ListInit(list* plist);
void LInsert(list* plist, LData data);
void FInsert(list* plist, LData data);
void SInsert(list* plist, LData data);
int LFirst(list* plist, LData* pdata);
int LNext(list* plist, LData* pdata);
LData LRemove(list* plist);


#endif