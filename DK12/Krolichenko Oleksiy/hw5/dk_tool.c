#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void deleteNode(doubleNode* node);
static doubleNode* createDoubleNode(double value);

doubleTree* createTree() {
	doubleTree* newTree = (doubleTree*)malloc(sizeof(doubleTree));

	if (newTree != NULL) {
		newTree->root = NULL;
		newTree->count = 0;
	}
	return newTree;
}

static doubleNode* createDoubleNode(double value) {
	doubleNode* newNode = (doubleNode*)malloc(sizeof(doubleNode));

	if (NULL != newNode) {
		newNode->l = NULL;
		newNode->r = NULL;
		newNode->value = value;
	}
	return newNode;
}

void insertValue(doubleTree* tree, double value) {
	
	if (NULL == tree) {
		return;
	}
	doubleNode* theNode = createDoubleNode(value);
	if (NULL == theNode) {
		return;
	}
	if (NULL == tree->root) {
		tree->root = theNode;
	} 
	else {
		doubleNode* theCurrent = tree->root;
		doubleNode* theParent = NULL;

		while (1) {
			theParent = theCurrent;

			if (value < theCurrent->value) {
				theCurrent = theCurrent->l;
				if (NULL == theCurrent) {
					theParent->l = theNode;
					break;
				}
			}
			else {
				theCurrent = theCurrent->r;
				if (NULL == theCurrent) {
					theParent->r = theNode;
					break;
				}
			}
		}
	}
	tree->count++;
}

doubleNode* findValue(doubleTree* tree, double value) {
	doubleNode* theCurrentNode = NULL;
	if (NULL != tree) {
		theCurrentNode = tree->root;
		while (value != theCurrentNode->value) {
			theCurrentNode = (value < theCurrentNode->value)
				? theCurrentNode->l
				: theCurrentNode->r;

			if (NULL == theCurrentNode) {
				printf("\nЗначення %.3f не існує\n", value);
				break;
			}
		}
		if (NULL != theCurrentNode) {
			printf("\nЗначення %.3f існує\n", value);
		}
	}
	return theCurrentNode;
}

doubleNode* getRecipient(doubleTree* tree, doubleNode* delNode) {
	doubleNode* theRecipientParent = delNode;
	doubleNode* theRecipient = delNode;
	doubleNode* theCurrent = delNode->r;

	while (NULL != theCurrent) {
		theRecipientParent = theRecipient;
		theRecipient = theCurrent;
		theCurrent = theCurrent->l;
	}

	if (theRecipient != delNode->r) {
		theRecipientParent->l = theRecipient->r;
		theRecipient->r = delNode->r;
	}
	return theRecipient;
}

double deleteValue(doubleTree* tree, double value) {
	double theResult = 1;
	doubleNode* theCurrent = tree->root;
	doubleNode* theParent = tree->root;
	double LeftChild = 1;

	while (value != theCurrent->value) {
		theParent = theCurrent;
		if (value < theCurrent->value) {
			LeftChild = 1;
			theCurrent = theCurrent->l;
		}
		else {
			LeftChild = 0;
			theCurrent = theCurrent->r;
		}
		if (NULL == theCurrent) {
			return 0;
		}
	}

	if (NULL == theCurrent->l && NULL == theCurrent->r) {
		if (tree->root == theCurrent) {
			tree->root = NULL;
		}
		else if (LeftChild) {
			theParent->l = NULL;
		}
		else {
			theParent->r = NULL;
		}
	}
	else if (NULL == theCurrent->r) {
		if (tree->root == theCurrent) {
			tree->root = theCurrent->l;
		}
		else if (LeftChild) {
			theParent->l = theCurrent->l;
		}
		else {
			theParent->r = theCurrent->l;
		}
	}
	else if (NULL == theCurrent->l) {
		if (tree->root == theCurrent) {
			tree->root = theCurrent->r;
		}
		else if (LeftChild) {
			theParent->l = theCurrent->r;
		}
		else {
			theParent->r = theCurrent->r;
		}
	}
	else {
		doubleNode* theRecipient = getRecipient(tree, theCurrent);
		if (tree->root == theRecipient) {
			tree->root = NULL;
		}
		else if (LeftChild) {
			theParent->l = theRecipient;
		}
		else {
			theParent->r = theRecipient;
		}
	}

	free(theCurrent);
	theResult = 1;
	return theResult;
}

static void deleteNode(doubleNode* node) {
	if (NULL != node) {
		deleteNode(node->l);
		deleteNode(node->r);
		free(node);
	}
}

void printTree(doubleNode* root) {
	if (NULL == root) {
		return;
	}
	printf("%.3f ", root->value);
	printTree(root->l);
	printTree(root->r);
}

void deleteTree(doubleTree* tree) {
	deleteNode(tree->root);
	free(tree);
}

