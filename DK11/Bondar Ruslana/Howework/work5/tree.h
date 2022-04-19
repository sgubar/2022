#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>

typedef struct __tagNode
{
	float value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} FloatNode;

typedef struct __tagTree
{
	FloatNode *root;
	float count;
} FloatTree;


FloatTree *createFloatTree();
void destroyFloatTree(FloatTree *aTree);

void insertFloatValueToTree(FloatTree *aTree, float aValue);
FloatNode *findNodeWithValue(FloatTree *aTree, float aValue);
void deleteNodeWithValue(FloatTree *aTree, float aValue);

void mergeTrees(FloatTree *aTreeDst, FloatTree *aTreeSrc);

void printTree(FloatTree *aTree);
int countNodesWithTree(FloatTree *aTree);

#endif // TREE_H_INCLUDED
