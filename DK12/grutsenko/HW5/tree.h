#ifndef TREE_H
#define TREE_H

typedef struct tag_node {
    float data;
    struct tag_node *left;
    struct tag_node *right;
} FloatNode;

typedef struct tag_tree {
    struct tag_node *root;
    int nodeCount;
} FloatTree;


FloatTree *createTree_Float();
void destroyTree_Float();

FloatNode *createNodeWithValue_Float(float value);
FloatNode *findNodeByValue_Float(FloatTree *tree, float value);
FloatNode *getSuccessor(FloatTree *tree, FloatNode *nodeToDelete);
void insertNodeToTree_Float(FloatTree *tree, float value);
void deleteNodeByValue_Float(FloatTree *tree, float value);
void destroyNode(FloatNode *node);

void printNode_Float(FloatNode *node);
void printTree_Float(FloatNode *root);


#endif

