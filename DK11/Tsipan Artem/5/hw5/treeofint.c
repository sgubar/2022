#include "treeofint.h"
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

	Node *theNode = createIntNodeWithValue(aValue);
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
		Node *theCurrent = aTree->root;
		Node *theParent = NULL;

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

Node *findNodeWithValue(IntTree *aTree, int aValue)
{
	Node *theCurrentNode = NULL;
	
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
	Node *current = aTree->root;
	Node *parent = aTree->root;

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
		Node *successor = getSuccessor(aTree, current);
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
	Node* item = aTree->root;
    printf("\tДерево інтів\t\n");
	print_int_node(item);
    printf("\n");
}

void print_int_node(Node *node)
{
	if(node == NULL)
	return;
	print_int_node(node->leftChild);
	printf("Елемент: %d\n", node->value);
	print_int_node(node->rightChild);
}

void destroyNode(Node *aNode)
{
	if(aNode != NULL)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
		free(aNode);
	}
}

Node *createIntNodeWithValue(int aValue)
{
	Node *theNode = (Node *)malloc(sizeof(Node));
	if(theNode != NULL)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	return theNode;
}

Node *getSuccessor(IntTree *tree, Node *toDelete)
{
	Node *successParent = toDelete;
	Node *successor = toDelete;
	Node *current = toDelete->rightChild;
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
