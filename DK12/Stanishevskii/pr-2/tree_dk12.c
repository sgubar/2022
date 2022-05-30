#define _CRT_SECURE_NO_WARNINGS
#include "tree_dk12.h"
#include <stdlib.h>
#include <string.h>

BinTree* createTree() {
	BinTree* aTree = (BinTree*)malloc(sizeof(BinTree));
	if (NULL != aTree) {
		aTree->root = NULL;
		aTree->count = 0;
	}
	return aTree;
}

void destroyTree(BinTree* aTree) {
	if (NULL != aTree) {
		free(aTree);
	}
}

void debugTree(BinTree* ATree) {
	addNode(ATree, 1);
	addNode(ATree, 9);
	addNode(ATree, 19);
	addNode(ATree, 10);
	addNode(ATree, 21);
	addNode(ATree, 14);
	addNode(ATree, 27);
	addNode(ATree, 17);
	addNode(ATree, 3);
	addNode(ATree, 1);
	addNode(ATree, 6);
	addNode(ATree, 1);
	addNode(ATree, 8);
	addNode(ATree, 17);
	addNode(ATree, 7);
	addNode(ATree, 2);
	addNode(ATree, 3);
	addNode(ATree, 0);
	addNode(ATree, 19);
	addNode(ATree, 15);

}

Node* createNode(int aValue) {
	Node* theNode = (Node*)malloc(sizeof(Node));

	if (NULL != theNode) {
		theNode->LChild = NULL;
		theNode->RChild = NULL;
		theNode->value = aValue;
	}
	return theNode;
}

void destroyNode(Node* aNode) {
	if (NULL != aNode) {
		free(aNode);
	}
}

Node* destroyTreeNode(Node* treeRoot, int value) {
	if (treeRoot == NULL) {
		return treeRoot;
	}
	if (value < treeRoot->value) {
		treeRoot->LChild = destroyTreeNode(treeRoot->LChild, value);
	} else if (value > treeRoot->value) {
		treeRoot->RChild = destroyTreeNode(treeRoot->RChild, value);
	} else {
		if (treeRoot->LChild == NULL) {
			Node* tempNode = treeRoot->RChild;
			destroyNode(treeRoot);
			return tempNode;
		} else if (treeRoot->RChild == NULL) {
			Node* tempNode = treeRoot->LChild;
			destroyNode(treeRoot);
			return tempNode;
		}
		Node* tempNode = getaword(treeRoot->RChild);
		treeRoot->value = tempNode->value;
		treeRoot->RChild = destroyTreeNode(treeRoot->RChild, tempNode->value);
	}
	return treeRoot;
}

Node* getaword(Node* treeRoot) {
	Node* theCurrent = treeRoot;
	while (theCurrent && theCurrent->LChild != NULL) {
		theCurrent = theCurrent->LChild;
	}
	return theCurrent;
}

void addNode(BinTree* aTree, int aValue) {
	if (NULL == aTree) {
		return;
	}
	Node* theNode = createNode(aValue);
	if (NULL == theNode) {
		return;
	}
	if (NULL == aTree->root) {
		aTree->root = theNode;
		aTree->count++;
	} else {
		Node* theCurrent = aTree->root;
		Node* theParent = NULL;
		while (1) {
			theParent = theCurrent;
			if (aValue < theCurrent->value) {
				theCurrent = theCurrent->LChild;
				if (NULL == theCurrent)
				{
					theParent->LChild = theNode;
					break;
				}
			} else {
				theCurrent = theCurrent->RChild;
				if (NULL == theCurrent) {
					theParent->RChild = theNode;
					break;
				}
			}
		}
		aTree->count++;
	}
}

Node* findNode(BinTree* aTree, int aValue) {
	Node* theCurrentNode = NULL;
	if (NULL != aTree->root) {
		theCurrentNode = aTree->root;
		while (aValue != theCurrentNode->value) {
			if (aValue < theCurrentNode->value) {
				theCurrentNode = theCurrentNode->LChild;
			} else
				theCurrentNode = theCurrentNode->RChild;
			if (NULL == theCurrentNode) {
				break;
			}
		}
	}
	return theCurrentNode;
}

void printTree(Node* aNode) {
	if (NULL != aNode) {
		printTree(aNode->LChild);
		printTree(aNode->RChild);
		printf("[%d] ", aNode->value);
	}
}

int deleteValueFromTheTree(BinTree* aTree, int aValue) {
	int Result = 1;
	Node* theCurrentNode = aTree->root;
	Node* theParent = aTree->root;
	int LChild = 1;
	while (aValue != theCurrentNode->value) {
		theParent = theCurrentNode;
		if (aValue < theCurrentNode->value) {
			LChild = 1;
			theCurrentNode = theCurrentNode->LChild;
		} else {
			LChild = 0;
			theCurrentNode = theCurrentNode->RChild;
		}
		if (NULL == theCurrentNode)
			return 0;
	}

	if (NULL == theCurrentNode->LChild && NULL == theCurrentNode->RChild) {
		if (aTree->root == theCurrentNode)
			aTree->root = NULL;
		else if (LChild)
			theParent->LChild = NULL;
		else
			theParent->RChild = NULL;
	}
	else if (NULL == theCurrentNode->RChild) {
		if (aTree->root == theCurrentNode)
			aTree->root = theCurrentNode->LChild;
		else if (LChild)
			theParent->LChild = theCurrentNode->LChild;
		else
			theParent->RChild = theCurrentNode->LChild;
	}
	else if (NULL == theCurrentNode->LChild) {
		if (aTree->root == theCurrentNode)
			aTree->root = theCurrentNode->RChild;
		else if (LChild)
			theParent->LChild = theCurrentNode->RChild;
		else
			theParent->RChild = theCurrentNode->RChild;
	}

	free(theCurrentNode);
	Result = 1;
	return Result;
}
