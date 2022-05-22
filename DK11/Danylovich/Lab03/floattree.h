#ifndef floattree_h
#define floattree_h

#include <stdio.h>

typedef struct tag_Node
{
	float value;
	struct tag_Node *leftChild;
	struct tag_Node *rightChild;
}FloatNode;

void destroyNode(FloatNode *aNode);
FloatNode *createFloatNodeWithValue(float aValue);

typedef struct tag_Tree
{
	FloatNode *root;
	float count;
}FloatTree;

FloatNode *getSuccessor(FloatTree *tree, FloatNode *toDelete);
void print_float_node(FloatNode *node);
FloatTree *createFloatTree();
void destroyFloatTree(FloatTree *aTree);

void insertFloatValueToTree(FloatTree *aTree, float aValue);
FloatNode *findNodeWithValue(FloatTree *aTree, float aValue);
void deleteNodeWithValue(FloatTree *aTree, float aValue);

void mergeTrees(FloatTree *aTreeDst, FloatTree *aTreeSrc);

void printTree(FloatTree *aTree);
float countNodesWithTree(FloatTree *aTree);

#endif
