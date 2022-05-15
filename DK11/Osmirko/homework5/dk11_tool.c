#include "dk11_tool.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


NodePtr getSuccessor(TreePtr tree, NodePtr aDelNode);

TreePtr createTree()
{
    TreePtr theTree = (TreePtr)malloc(sizeof(Tree));

    if (NULL != theTree)
    {
        theTree->root = NULL;
    }

    return theTree;
}

void freeNode(NodePtr node)
{
    if (NULL != node)
    {
        if (NULL != node->toData)
        {
            free(node->toData);
        }

        free(node);
    }
}

void destroyNode(NodePtr node)
{
    if (NULL != node)
    {
        destroyNode(node->leftChild);
        destroyNode(node->rightChild);

        free(node);
    }
}

void destroyTree(TreePtr tree)
{
    if (NULL != tree)
    {
        destroyNode(tree->root);
        free(tree);
    }
}

NodePtr findNode(TreePtr tree, char *data)
{
    NodePtr theCurrentNode = tree->root;
    int theComparisionResult = 0;

    while (0 != (theComparisionResult = strcmp(data, theCurrentNode->toData->data)))
    {
        theCurrentNode = (theComparisionResult < 0)
                            ? theCurrentNode->leftChild
                            : theCurrentNode->rightChild;

        if (NULL == theCurrentNode)
        {
            break;
        }
    }

    return theCurrentNode;
}

void insertNode(TreePtr tree, char *data)
{
    NodePtr theNewNode = (NodePtr)malloc(sizeof(Node));
    bzero(theNewNode, sizeof(Node));

    DataPtr theNote = (DataPtr)malloc(sizeof(Data));
    theNote->data = data;

    theNewNode->toData = theNote;

    if (NULL == tree->root)
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
            int theCompare = strcmp(data, theCurrent->toData->data);

            if (theCompare < 0)
            {
                theCurrent = theCurrent->leftChild;
                if (NULL == theCurrent)
                {
                    theParent->leftChild = theNewNode;
                    break;
                }
            }
            else
            {
                theCurrent = theCurrent->rightChild;
                if (NULL == theCurrent)
                {
                    theParent->rightChild = theNewNode;
                    break;
                }
            }
        }
    }
}

int deleteNode(TreePtr tree, char *data)
{
    int theResult = 1;

    NodePtr theCurrent = tree->root;
    NodePtr theParent = tree->root;

    int isLeftChild = 1;
    int theCompare = 0;

    while (0 != (theCompare = strcmp(data, theCurrent->toData->data)))
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

        if (NULL == theCurrent)
        {
            return 0;
        }
    }

    if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
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
    else if (NULL == theCurrent->rightChild)
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
    else if (NULL == theCurrent->leftChild)
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

NodePtr getSuccessor(TreePtr tree, NodePtr aDelNode)
{
    NodePtr theSuccessParent = aDelNode;
    NodePtr theSuccessor = aDelNode;
    NodePtr theCurrent = aDelNode->rightChild;

    while (NULL != theCurrent)
    {
        theSuccessParent = theSuccessor;
        theSuccessor = theCurrent;
        theCurrent = theCurrent->leftChild;
    }

    if (theSuccessor != aDelNode->rightChild)
    {
        theSuccessParent->leftChild = theSuccessor->rightChild;
        theSuccessor->rightChild = aDelNode->rightChild;
    }

    return theSuccessor;
}

void printTree(TreePtr tree)
{
    printf("\nTree:\n");
    NodePtr item = tree->root;
    printCharNode(item);
}

void printCharNode(NodePtr node)
{
    if (node == NULL)
        return;
    printCharNode(node->leftChild);
    printf("%s\n", node->toData->data);
    printCharNode(node->rightChild);
}
