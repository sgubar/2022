#include "tree.h"
#include <stdlib.h>

DoubleTree *createDoubleTree()
{
	DoubleTree *theTree = (DoubleTree *)malloc(sizeof(DoubleTree));
	if(theTree != NULL)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyDoubleTree(DoubleTree *aTree)
{
	if(aTree != NULL)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertDoubleValueToTree(DoubleTree *aTree, double aValue)
{
	if(aTree == NULL)
	{
		return;
	}

	DoubleNode *theNode = createDoubleNodeWithValue(aValue);
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
		DoubleNode *theCurrent = aTree->root;
		DoubleNode *theParent = NULL;

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

DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue)
{
	DoubleNode *theCurrentNode = NULL;

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

void deleteNodeWithValue(DoubleTree *aTree, double aValue)
{
	if(aTree == NULL || aTree->root == NULL){
		return;
	}
	DoubleNode *current = aTree->root;
	DoubleNode *parent = aTree->root;

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
		DoubleNode *successor = getSuccessor(aTree, current);
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

void printTree(DoubleTree *aTree)
{
	DoubleNode* item = aTree->root;
    printf("\t Double Tree\t\n");
	print_double_node(item);
    printf("\n");
}

void print_double_node(DoubleNode *node)
{
	if(node == NULL)
	return;
	print_double_node(node->leftChild);
	printf("Элемент: %d\n", node->value);
	print_double_node(node->rightChild);
}

void destroyNode(DoubleNode *aNode)
{
	if(aNode != NULL)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
		free(aNode);
	}
}

DoubleNode *createDoubleNodeWithValue(double aValue)
{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));
	if(theNode != NULL)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	return theNode;
}

DoubleNode *getSuccessor(DoubleTree *tree, DoubleNode *toDelete)
{
	DoubleNode *successParent = toDelete;
	DoubleNode *successor = toDelete;
	DoubleNode *current = toDelete->rightChild;
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
