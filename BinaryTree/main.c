#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int  main(void) {

	BTnode* node1 = MakeBTNode();
	BTnode* node2 = MakeBTNode();
	BTnode* node3 = MakeBTNode();
	BTnode* node4 = MakeBTNode();
	BTnode* node5 = MakeBTNode();

	SetData(node1, 1);
	SetData(node2, 2);
	SetData(node3, 3);
	SetData(node4, 4);
	SetData(node5, 5);

	ConnectLeftSubTree(node1, node2);
	ConnectRightSubTree(node1, node3);
	ConnectLeftSubTree(node2, node3);
	ConnectRightSubTree(node2, node4);
	ConnectRightSubTree(node3, node5);

	printf("%d\n", GetData(GetLeftSubTree(node1)));
	printf("%d\n", GetData(GetRightSubTree(node3)));
	return 0;

}