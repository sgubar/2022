#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>

typedef struct __tagNode
{
	int value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} IntNode;

typedef struct __tagTree
{
	IntNode *root;
	int count;
} IntTree;


IntTree *createIntTree();
void destroyIntTree(IntTree *aTree);

void insertIntValueToTree(IntTree *aTree, int aValue);
IntNode *findNodeWithValue(IntTree *aTree, int aValue);
void deleteNodeWithValue(IntTree *aTree, int aValue);

void mergeTrees(IntTree *aTreeDst, IntTree *aTreeSrc);

void printTree(IntTree *aTree);
int countNodesWithTree(IntTree *aTree);

#endif // TREE_H_INCLUDED
