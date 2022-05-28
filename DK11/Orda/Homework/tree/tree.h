#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>

typedef struct tag_node{
	char *data;
	struct tag_node *leftChild;
	struct tag_node *rightChild;
}node, *nodePtr;

typedef struct tag_tree{
	nodePtr root;
}tree, *treePtr;

treePtr createTree();
void deleteTree(treePtr atree);

void displayTree(treePtr atree);

nodePtr findNode(treePtr atree, char *adata);
void insertNode(treePtr atree, char *adata);

void deleteNodeWithData(treePtr atree, char *adata);

#endif // TREE_H_INCLUDED
