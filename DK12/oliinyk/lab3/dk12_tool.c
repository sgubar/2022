#include "dk12_tool.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


NodePtr getSuccessor(TreePtr tree, NodePtr aDelNode);

TreePtr createTree() {
    TreePtr theTree = (TreePtr)malloc(sizeof(Tree));

    if (theTree != NULL) {
        theTree->root = NULL;
    }

    return theTree;
}

void freeNode(NodePtr node) {
    if (node != NULL) {
        if (node->toData != NULL) {
            free(node->toData);
        }
        free(node);
    }
}

void destroyNode(NodePtr node) {
    if (node != NULL) {
        destroyNode(node->leftChild);
        destroyNode(node->rightChild);
        free(node);
    }
}

void destroyTree(TreePtr tree) {
    if (tree != NULL) {
        destroyNode(tree->root);
        free(tree);
    }
}

NodePtr findNode(TreePtr tree, char *data) {
    NodePtr theCurrentNode = tree->root;
    int theComparisionResult = 0;

    while ((theComparisionResult = strcmp(data, theCurrentNode->toData->data)) != 0) {
        theCurrentNode = (theComparisionResult < 0)
                            ? theCurrentNode->leftChild
                            : theCurrentNode->rightChild;
        if (theCurrentNode == NULL) {
            break;
        }
    }

    return theCurrentNode;
}

void insertNode(TreePtr tree, char *data) {
    NodePtr theNewNode = (NodePtr)malloc(sizeof(Node));
    bzero(theNewNode, sizeof(Node));

    DataPtr theNote = (DataPtr)malloc(sizeof(Data));
    theNote->data = data;

    theNewNode->toData = theNote;

    if (tree->root == NULL) {
        tree->root = theNewNode;
    }
    else {
        NodePtr theCurrent = tree->root;
        NodePtr theParent = NULL;

        while (1) {
            theParent = theCurrent;
            int theCompare = strcmp(data, theCurrent->toData->data);

            if (theCompare < 0) {
                theCurrent = theCurrent->leftChild;
                if (theCurrent == NULL) {
                    theParent->leftChild = theNewNode;
                    break;
                }
            }
            else {
                theCurrent = theCurrent->rightChild;
                if (theCurrent == NULL) {
                    theParent->rightChild = theNewNode;
                    break;
                }
            }
        }
    }
}

int deleteNode(TreePtr tree, char *data) {
    int theResult = 1;

    NodePtr theCurrent = tree->root;
    NodePtr theParent = tree->root;

    int isLeftChild = 1;
    int theCompare = 0;

    while ((theCompare = strcmp(data, theCurrent->toData->data)) != 0) {
        theParent = theCurrent;
        if (theCompare < 0) {
            isLeftChild = 1;
            theCurrent = theCurrent->leftChild;
        }
        else if (theCompare > 0) {
            isLeftChild = -1;
            theCurrent = theCurrent->rightChild;
        }

        if (theCurrent == NULL) {
            return 0;
        }
    }

    if (theCurrent->leftChild == NULL && theCurrent->rightChild == NULL) {
        if (tree->root == theCurrent) {
            tree->root = NULL;
        }
        else if (isLeftChild == 1) {
            theParent->leftChild = NULL;
        }
        else {
            theParent->rightChild = NULL;
        }
    }
    else if (theCurrent->rightChild == NULL)
    {
        if (tree->root == theCurrent) {
            tree->root = theCurrent->leftChild;
        }
        else if (isLeftChild) {
            theParent->leftChild = theCurrent->leftChild;
        }
        else {
            theParent->rightChild = theCurrent->leftChild;
        }
    }
    else if (theCurrent->leftChild == NULL)
    {
        if (tree->root == theCurrent) {
            tree->root = theCurrent->rightChild;
        }
        else if (isLeftChild) {
            theParent->leftChild = theCurrent->rightChild;
        }
        else {
            theParent->rightChild = theCurrent->rightChild;
        }
    }
    else
    {
        NodePtr theSuccessor = getSuccessor(tree, theCurrent);
        if (tree->root == theSuccessor) {
            tree->root = NULL;
        }
        else if (isLeftChild) {
            theParent->leftChild = theSuccessor;
        }
        else {
            theParent->rightChild = theSuccessor;
        }
    }

    freeNode(theCurrent);
    theResult = 1;
    return theResult;
}

void printTree(TreePtr tree) {
    printf("\nTree:\n");
    NodePtr item = tree->root;
    printNode(item);
}

void printNode(NodePtr node) {
    if (node == NULL)
        return;
    printNode(node->leftChild);
    printNode(node->rightChild);
    printf("%s\n", node->toData->data);
}

NodePtr getSuccessor(TreePtr tree, NodePtr aDelNode) {
    NodePtr theSuccessParent = aDelNode;
    NodePtr theSuccessor = aDelNode;
    NodePtr theCurrent = aDelNode->rightChild;

    while (theCurrent != NULL) {
        theSuccessParent = theSuccessor;
        theSuccessor = theCurrent;
        theCurrent = theCurrent->leftChild;
    }

    if (theSuccessor != aDelNode->rightChild) {
        theSuccessParent->leftChild = theSuccessor->rightChild;
        theSuccessor->rightChild = aDelNode->rightChild;
    }
    return theSuccessor;
}
