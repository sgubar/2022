#ifndef TREE_H
#define TREE_H


typedef struct tag_node_int
{
	int data;
    	struct tag_node_int *left;
    	struct tag_node_int *right;
} IntNode;
typedef struct tag_tree_int
{
	struct tag_node_int *root;
    	int nodeCount;
} IntTree;
IntTree *createTree_Int();
void destroyTree_Int();
IntNode *createNodeWithValue_Int(int value);
IntNode *findNodeByValue_Int(IntTree *tree, int value);
IntNode *getSuccessor(IntTree *tree, IntNode *nodeToDelete);
void insertNodeToTree_Int(IntTree *tree, int value);
void deleteNodeByValue_Int(IntTree *tree, int value);
void destroyNode(IntNode *node);
void printNode_Int(IntNode *node);
void printTree_Int(IntNode *root);

#endif
