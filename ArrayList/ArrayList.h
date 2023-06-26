#ifndef _ARRAY_LIST_
#define _ARRAY_LIST_

#define TRUE 1
#define FALSE 0
#define LIST_LEN 100  //  array size

typedef int LData;

// setting struct List
typedef struct _ArrayList {
	LData arr[LIST_LEN];
	int numofdata;
	int cur_position;
}ArrayList;
typedef ArrayList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);

#endif


