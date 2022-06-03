#ifndef inttree_h
#define inttree_h

#include <stdio.h>

typedef struct Node IntNode;
struct Node{
	int value;
	IntNode *leftChild;
	IntNode *rightChild;
};

void deleteNode(IntNode *aNode);
IntNode *createIntNodeWithValue(int aValue);

typedef struct Tree{
	IntNode *root;
	int count;
}IntTree;

IntNode *getSuccessor(IntTree *tree, IntNode *toDelete);
void print_int_node(IntNode *node);
IntTree *createIntTree();
void deleteIntTree(IntTree *aTree);

void insertIntValueToTree(IntTree *aTree, int aValue);
IntNode *findNodeWithValue(IntTree *aTree, int aValue);
void deleteNodeWithValue(IntTree *aTree, int aValue);

void mergeTrees(IntTree *aTreeDst, IntTree *aTreeSrc);

void printTree(IntTree *aTree);
int countNodesWithTree(IntTree *aTree);

#endif /* inttree_h */
