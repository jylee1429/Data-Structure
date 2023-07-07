#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

typedef int Data;
typedef struct _BTnode {
	Data data;
	struct _BTnode* right;
	struct _BTnode* left;
}Binary_Tree_Node;
typedef Binary_Tree_Node BTnode;

BTnode* MakeBTNode(void);
void SetData(BTnode* btnode, Data data);
Data GetData(BTnode* btnode);
BTnode* GetLeftSubTree(BTnode* btnode);
BTnode* GetRightSubTree(BTnode* btnode);
void ConnectLeftSubTree(BTnode* parent_node, BTnode* child_node);
void ConnectRightSubTree(BTnode* parent_node, BTnode* child_node);

#endif

