#ifndef _DK11_TOOL_H
#define _DK11_TOOL_H

typedef struct tag_data {
	char *data;
}Data, *DataPtr;

typedef struct tag_node {
	DataPtr toData;
	struct tag_node *leftChild;
	struct tag_node *rightChild;
}Node, *NodePtr;

typedef struct tag_tree {
	NodePtr root;
}Tree, *TreePtr;

TreePtr createTree();
void deleteTree(TreePtr tree);

int countTree(TreePtr tree);
void displayTree(TreePtr tree);

NodePtr findNode(TreePtr tree, char *data);
void insertNode(TreePtr tree, char *data);
int deleteNode(TreePtr tree, char *data);

void destroyNode(NodePtr node);
void destroyTree(TreePtr tree);

void printTree(TreePtr tree);
void printNode(NodePtr node);
