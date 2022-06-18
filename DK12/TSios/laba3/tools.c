#include "tools.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

NodePtr getSuccessor(TreePtr tree, NodePtr delNode);

TreePtr createTree()
{
    TreePtr theTree = (TreePtr)malloc(sizeof(Tree));
    if (theTree != NULL)
    {
        theTree->root = NULL;
    }
    return theTree;
}

void freeNode(NodePtr node)
{
    if (node != NULL)
    {
        if (node->toData != NULL)
        {
            free(node->toData);
        }
        free(node);
    }
}

void destroyNode(NodePtr node)
{
    if (node != NULL)
    {
        destroyNode(node->leftChild);
        destroyNode(node->rightChild);
        free(node);
    }
}

void destroyTree(TreePtr tree)
{
    if (tree != NULL)
    {
        destroyNode(tree->root);
        free(tree);
    }
}

NodePtr findNode(TreePtr tree, float data)
{
    NodePtr theCurrentNode = tree->root;
    float theComparisionResult = 0.0;

    while ((theComparisionResult = data - theCurrentNode->toData->data) != 0)
    {
        theCurrentNode = (theComparisionResult < 0)
                             ? theCurrentNode->leftChild
                             : theCurrentNode->rightChild;
        if (theCurrentNode == NULL)
        {
            break;
        }
    }

    return theCurrentNode;
}

void insertNode(TreePtr tree, float data)
{
    NodePtr theNewNode = (NodePtr)malloc(sizeof(Node));
    bzero(theNewNode, sizeof(Node));

    DataPtr theNote = (DataPtr)malloc(sizeof(Data));
    theNote->data = data;

    theNewNode->toData = theNote;

    if (tree->root == NULL)
    {
        tree->root = theNewNode;
    }
    else
    {
        NodePtr theCurrent = tree->root;
        NodePtr theParent = NULL;

        while (1)
        {
            theParent = theCurrent;
            float theCompare = data - theCurrent->toData->data;

            if (theCompare < 0)
            {
                theCurrent = theCurrent->leftChild;
                if (theCurrent == NULL)
                {
                    theParent->leftChild = theNewNode;
                    break;
                }
            }
            else
            {
                theCurrent = theCurrent->rightChild;
                if (theCurrent == NULL)
                {
                    theParent->rightChild = theNewNode;
                    break;
                }
            }
        }
    }
}

int deleteNode(TreePtr tree, float data)
{
    int theResult = 1;

    NodePtr theCurrent = tree->root;
    NodePtr theParent = tree->root;

    int isLeftChild = 1;
    float theCompare = 0.0;

    while ((theCompare = data - theCurrent->toData->data) != 0)
    {
        theParent = theCurrent;
        if (theCompare < 0)
        {
            isLeftChild = 1;
            theCurrent = theCurrent->leftChild;
        }
        else if (theCompare > 0)
        {
            isLeftChild = -1;
            theCurrent = theCurrent->rightChild;
        }

        if (theCurrent == NULL)
        {
            return 0;
        }
    }

    if (theCurrent->leftChild == NULL && theCurrent->rightChild == NULL)
    {
        if (tree->root == theCurrent)
        {
            tree->root = NULL;
        }
        else if (isLeftChild == 1)
        {
            theParent->leftChild = NULL;
        }
        else
        {
            theParent->rightChild = NULL;
        }
    }
    else if (theCurrent->rightChild == NULL)
    {
        if (tree->root == theCurrent)
        {
            tree->root = theCurrent->leftChild;
        }
        else if (isLeftChild)
        {
            theParent->leftChild = theCurrent->leftChild;
        }
        else
        {
            theParent->rightChild = theCurrent->leftChild;
        }
    }
    else if (theCurrent->leftChild == NULL)
    {
        if (tree->root == theCurrent)
        {
            tree->root = theCurrent->rightChild;
        }
        else if (isLeftChild)
        {
            theParent->leftChild = theCurrent->rightChild;
        }
        else
        {
            theParent->rightChild = theCurrent->rightChild;
        }
    }
    else
    {
        NodePtr theSuccessor = getSuccessor(tree, theCurrent);
        if (tree->root == theSuccessor)
        {
            tree->root = NULL;
        }
        else if (isLeftChild)
        {
            theParent->leftChild = theSuccessor;
        }
        else
        {
            theParent->rightChild = theSuccessor;
        }
    }

    freeNode(theCurrent);
    theResult = 1;
    return theResult;
}

void printTree(TreePtr tree)
{
    printf("\nTree:\n");
    NodePtr item = tree->root;
    printNode(item);
}

void printNode(NodePtr node)
{
    if (node == NULL)
        return;
    printNode(node->leftChild);
    printf("%.3f\n", node->toData->data);
    printNode(node->rightChild);
}

NodePtr getSuccessor(TreePtr tree, NodePtr delNode)
{
    NodePtr theSuccessParent = delNode;
    NodePtr theSuccessor = delNode;
    NodePtr theCurrent = delNode->rightChild;

    while (theCurrent != NULL)
    {
        theSuccessParent = theSuccessor;
        theSuccessor = theCurrent;
        theCurrent = theCurrent->leftChild;
    }

    if (theSuccessor != delNode->rightChild)
    {
        theSuccessParent->leftChild = theSuccessor->rightChild;
        theSuccessor->rightChild = delNode->rightChild;
    }
    return theSuccessor;
}
