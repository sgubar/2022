#include "tree.h"
#include <stdlib.h>

static void destroyNode(IntNode *aNode);
static IntNode *createIntNodeWithValue(int aValue);
static IntNode *getSuccessor(IntTree *tree, IntNode *toDelete);
static void print_int_node(IntNode *node);

IntTree *createIntTree()
{
	IntTree *theTree = (IntTree *)malloc(sizeof(IntTree));
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}
void destroyIntTree(IntTree *aTree)
{
	if (NULL != aTree)
	{І
		destroyNode(aTree->root);
		free(aTree);
	}
}
void insertIntValueToTree(IntTree *aTree, int aValue)
{
	if (NULL == aTree)
	{
		return;
	}
	IntNode *theNode = createIntNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
	{
		IntNode *theCurrent = aTree->root;
		IntNode *theParent = NULL;
	while (1)
		{
			theParent = theCurrent;

			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}

		aTree->count ++;
	}
}
IntNode *findNodeWithValue(IntTree *aTree, int aValue)
{
	IntNode *theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		IntNode *theCurrentNode = aTree->root;
		while (aValue != theCurrentNode->value)
		{
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}

	return theCurrentNode;
}

void deleteNodeWithValue(IntTree *aTree, int aValue) {


	if (NULL == aTree || NULL == aTree->root) {
		return ;
	}

	IntNode *current = aTree->root;
	IntNode *parent = aTree->root;


	while (aValue != current->value) {
		parent = current;
		if (aValue < current->value) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}

	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		} else {
			parent->rightChild = NULL;
		}

		aTree->count --;
	} else if (NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = current->leftChild;
		} else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		} else {
			parent->rightChild = current->rightChild;
		}
	} else if (NULL == current->leftChild) {
		if (aTree->root == current) {
			aTree->root = current->rightChild;
		} else if (parent->rightChild == current) {
		 	parent->rightChild = current->rightChild;
		} else {
			parent->leftChild = current->leftChild;
		}
	} else {
		IntNode *successor = getSuccessor(aTree, current);
		if (aTree->root == successor) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = successor;
		} else {
			parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}

	destroyNode(current);
}


void printTree(IntTree *aTree) {
	IntNode* item = aTree->root;
	print_int_node(item);
}

void print_int_node(IntNode *node) {
	if (node == NULL)
		return;
	print_int_node(node->leftChild);
	print_int_node(node->rightChild);
	printf("element: %d\n", node->value);
}

void destroyNode(IntNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}

IntNode *createIntNodeWithValue(int aValue)
{
	IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

IntNode *getSuccessor(IntTree *tree, IntNode *toDelete) {
	IntNode *successParent = toDelete;
	IntNode *successor = toDelete;
	IntNode *current = toDelete->rightChild;

	while(NULL != current) {
		successParent = successor;
		successor = current;
		current = current->leftChild;
	}
	if (successor != toDelete->rightChild) {
		successParent->leftChild = successor->rightChild;
		successor->rightChild = toDelete->rightChild;
	}
	successor->leftChild = toDelete->leftChild;
	return successor;
}
