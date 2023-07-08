#include <stdio.h>
#include <stdlib.h>
#include "BinaryTreeTraversal.h"

int  main(void) {
	int i;

	BTnode* btnode1 = MakeBTNode();
	BTnode* btnode2 = MakeBTNode();
	BTnode* btnode3 = MakeBTNode();
	BTnode* btnode4 = MakeBTNode();
	BTnode* btnode5 = MakeBTNode();
	BTnode* btnode6 = MakeBTNode();

	SetData(btnode1, 1);
	SetData(btnode2, 2);
	SetData(btnode3, 3);
	SetData(btnode4, 4);
	SetData(btnode5, 5);
	SetData(btnode6, 6);

	ConnectLeftSubTree(btnode1, btnode2);
	ConnectRightSubTree(btnode1, btnode3);
	ConnectLeftSubTree(btnode2, btnode4);
	ConnectRightSubTree(btnode2, btnode5);
	ConnectRightSubTree(btnode3, btnode6);

	PrevOrderTraverse(btnode1);

	return 0;
}