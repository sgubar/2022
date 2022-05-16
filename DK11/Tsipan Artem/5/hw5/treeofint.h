#ifndef treeofint_h
#define treeofint_h

#include <stdio.h>

typedef struct tag_Node
{
	int value;
	struct tag_Node *leftChild;
	struct tag_Node *rightChild;
}Node;

void destroyNode(Node *aNode);
Node *createIntNodeWithValue(int aValue);

typedef struct tag_Tree
{
	Node *root;
	int count;
}IntTree;

Node *getSuccessor(IntTree *tree, Node *toDelete);
void print_int_node(Node *node);
IntTree *createIntTree();
void destroyIntTree(IntTree *aTree);

void insertIntValueToTree(IntTree *aTree, int aValue);
Node *findNodeWithValue(IntTree *aTree, int aValue);
void deleteNodeWithValue(IntTree *aTree, int aValue);

void mergeTrees(IntTree *aTreeDst, IntTree *aTreeSrc);

void printTree(IntTree *aTree);
int countNodesWithTree(IntTree *aTree);

#endif
