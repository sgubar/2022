#ifndef inttree_h
#define inttree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *leftChild;
	struct Node *rightChild;
}IntNode;

void destroyNode(IntNode *aNode);
IntNode *createIntNodeWithValue(int aValue);

typedef struct intTree
{
	IntNode *root;
	int count;
}IntTree;

IntNode *getSuccessor(IntTree *tree, IntNode *toDelete);
void print_int_node(IntNode *node);
IntTree *createIntTree();
void destroyIntTree(IntTree *aTree);

void insertIntValueToTree(IntTree *aTree, int aValue);
IntNode *findNodeWithValue(IntTree *aTree, int aValue);
void deleteNodeWithValue(IntTree *aTree, int aValue);

void mergeTrees(IntTree *aTreeDst, IntTree *aTreeSrc);

void printTree(IntTree *aTree);
int countNodesWithTree(IntTree *aTree);

#endif

