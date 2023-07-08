#include "BinaryTreeTraversal.h"
#include <stdio.h>
#include <stdlib.h>


BTnode* MakeBTNode(void) {
	BTnode* newnode = (BTnode*)malloc(sizeof(BTnode));
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

void SetData(BTnode* btnode, Data data) {
	btnode->data = data;
}

Data GetData(BTnode* btnode) {
	return btnode->data;
}

BTnode* GetLeftSubTree(BTnode* btnode) {
	return btnode->left;
}

BTnode* GetRightSubTree(BTnode* btnode) {
	return btnode->right;
}

void ConnectLeftSubTree(BTnode* parent_node, BTnode* child_node) {
	if (parent_node->left != NULL)
		free(parent_node->left);
	parent_node->left = child_node;
}

void ConnectRightSubTree(BTnode* parent_node, BTnode* child_node) {
	if (parent_node->right != NULL)
		free(parent_node->right);
	parent_node->right = child_node;

}

void Traverse(BTnode* btnode) {
	printf("%d ", btnode->data);
}

void InOrderTraverse(BTnode* btnode) {
	if (btnode == NULL)
		return;
	InOrderTraverse(btnode->left);
	Traverse(btnode);
	InOrderTraverse(btnode->right);
}

void PrevOrderTraverse(BTnode* btnode) {
	if (btnode == NULL)
		return;
	Traverse(btnode);
	PrevOrderTraverse(btnode->left);
	PrevOrderTraverse(btnode->right);
}

void PostOrderTraverse(BTnode* btnode) {
	if (btnode == NULL)
		return;
	PostOrderTraverse(btnode->left);
	PostOrderTraverse(btnode->right);
	Traverse(btnode);
}


