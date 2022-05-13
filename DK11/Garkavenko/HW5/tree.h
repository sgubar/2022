#ifndef doubletree_h
#define doubletree_h

#include <stdio.h>

typedef struct tag_Node
{
	double value;
	struct tag_Node *leftChild;
	struct tag_Node *rightChild;
}DoubleNode;

void destroyNode(DoubleNode *aNode);
DoubleNode *createDoubleNodeWithValue(double aValue);

typedef struct tag_Tree
{
	DoubleNode *root;
	double count;
}DoubleTree;

DoubleNode *getSuccessor(DoubleTree *tree, DoubleNode *toDelete);
void print_double_node(DoubleNode *node);
DoubleTree *createDoubleTree();
void destroyDoubleTree(DoubleTree *aTree);

void insertDoubleValueToTree(DoubleTree *aTree, double aValue);
DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue);
void deleteNodeWithValue(DoubleTree *aTree, double aValue);

void mergeTrees(DoubleTree *aTreeDst, DoubleTree *aTreeSrc);

void printTree(DoubleTree *aTree);
int countNodesWithTree(DoubleTree *aTree);

#endif
