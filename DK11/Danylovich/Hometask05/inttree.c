#include "inttree.h"
#include <stdlib.h>

IntTree *createIntTree()
{
	IntTree *theTree = (IntTree *)malloc(sizeof(IntTree));
	if(theTree != NULL)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyIntTree(IntTree *aTree)
{
	if(aTree != NULL)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertIntValueToTree(IntTree *aTree, int aValue)
{
	if(aTree == NULL)
	{
		return;
	}

	IntNode *theNode = createIntNodeWithValue(aValue);
	if(theNode == NULL)
	{
		return;
	}
	
	if(aTree->root == NULL)
	{
		aTree->root = theNode;
		aTree->count++;
	}
	else
	{
		IntNode *theCurrent = aTree->root;
		IntNode *theParent = NULL;

		while(1)
		{
			theParent = theCurrent;
			if(aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if(theCurrent == NULL)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if(theCurrent == NULL)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}
		aTree->count++;
	}
}

IntNode *findNodeWithValue(IntTree *aTree, int aValue)
{
	IntNode *theCurrentNode = NULL;
	
	if(aTree != NULL && aTree->root != NULL)
	{
		theCurrentNode = aTree->root;
		while(aValue != theCurrentNode->value)
		{
			theCurrentNode = (aValue < theCurrentNode->value) ? theCurrentNode->leftChild : theCurrentNode->rightChild;
			if(theCurrentNode == NULL)
			{
				break;
			}
		}
	}
	return theCurrentNode;
}

void deleteNodeWithValue(IntTree *aTree, int aValue)
{
	if(aTree == NULL || aTree->root == NULL){
		return;
	}
	IntNode *current = aTree->root;
	IntNode *parent = aTree->root;

	while(aValue != current->value){
		parent = current;
		if(aValue < current->value){
			current = current->leftChild;
		} else{
			current = current->rightChild;
		}
		if(current == NULL){
			return;
		}
	}
	if(current->leftChild == NULL && current->rightChild == NULL) {
		if(aTree->root == current){
			aTree->root = NULL;
		} else if(parent->leftChild == current){
			parent->leftChild = NULL;
		} else{
			parent->rightChild = NULL;
        }
		aTree->count--;
	} else if(current->rightChild == NULL){
		if(aTree->root == current){
			aTree->root = current->leftChild;
		} else if(parent->leftChild == current){
			parent->leftChild = current->leftChild;
		} else{
			parent->rightChild = current->rightChild;
		}
	} else if (current->leftChild == NULL){
		if(aTree->root == current){
			aTree->root = current->rightChild;
		} else if(parent->rightChild == current){
		 	parent->rightChild = current->rightChild;
		} else{
			parent->leftChild = current->leftChild;
		}
	} else{
		IntNode *successor = getSuccessor(aTree, current);
		if(aTree->root == successor){
		    aTree->root = NULL;
		} else if(parent->leftChild == current){
			parent->leftChild = successor;
		} else{
		parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}
	destroyNode(current);
}

void printTree(IntTree *aTree)
{
	IntNode* item = aTree->root;
    printf("\tInt Tree\t\n");
	print_int_node(item);
    printf("\n");
}

void print_int_node(IntNode *node)
{
	if(node == NULL)
	return;
	print_int_node(node->leftChild);
	printf("Элемент: %d\n", node->value);
	print_int_node(node->rightChild);
}

void destroyNode(IntNode *aNode)
{
	if(aNode != NULL)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
		free(aNode);
	}
}

IntNode *createIntNodeWithValue(int aValue)
{
	IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));
	if(theNode != NULL)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	return theNode;
}

IntNode *getSuccessor(IntTree *tree, IntNode *toDelete)
{
	IntNode *successParent = toDelete;
	IntNode *successor = toDelete;
	IntNode *current = toDelete->rightChild;
	while(current != NULL){
		successParent = successor;
		successor = current;
		current = current->leftChild;
	}
	if(successor != toDelete->rightChild) { 
		successParent->leftChild = successor->rightChild;
		successor->rightChild = toDelete->rightChild;
	}
	successor->leftChild = toDelete->leftChild;
	return successor;
}
