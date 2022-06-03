#include "floattree.h"
#include <stdlib.h>

FloatTree *createFloatTree()
{
	FloatTree *theTree = (FloatTree *)malloc(sizeof(FloatTree));
	if(theTree != NULL)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyFloatTree(FloatTree *aTree)
{
	if(aTree != NULL)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertFloatValueToTree(FloatTree *aTree, float aValue)
{
	if(aTree == NULL)
	{
		return;
	}

	FloatNode *theNode = createFloatNodeWithValue(aValue);
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
		FloatNode *theCurrent = aTree->root;
		FloatNode *theParent = NULL;

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

FloatNode *findNodeWithValue(FloatTree *aTree, float aValue)
{
	FloatNode *theCurrentNode = NULL;
	
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

void deleteNodeWithValue(FloatTree *aTree, float aValue)
{
	if(aTree == NULL || aTree->root == NULL){
		return;
	}
	FloatNode *current = aTree->root;
	FloatNode *parent = aTree->root;

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
		FloatNode *successor = getSuccessor(aTree, current);
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

void printTree(FloatTree *aTree)
{
	FloatNode* item = aTree->root;
    printf("\tFloat Tree\t\n");
	print_float_node(item);
    printf("\n");
}

void print_float_node(FloatNode *node)
{
	if(node == NULL){
        return;
    }
	print_float_node(node->leftChild);
	printf("Элемент: %f\n", node->value);
	print_float_node(node->rightChild);
}

void destroyNode(FloatNode *aNode)
{
	if(aNode != NULL)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
		free(aNode);
	}
}

FloatNode *createFloatNodeWithValue(float aValue)
{
	FloatNode *theNode = (FloatNode *)malloc(sizeof(FloatNode));
	if(theNode != NULL)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	return theNode;
}

FloatNode *getSuccessor(FloatTree *tree, FloatNode *toDelete)
{
	FloatNode *successParent = toDelete;
	FloatNode *successor = toDelete;
	FloatNode *current = toDelete->rightChild;
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
