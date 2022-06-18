#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void printElement(Element *El);
tree *createTree()
{
      tree *aTree = (tree *)calloc(0, sizeof(tree));

      if(aTree != NULL){
            aTree->root = NULL;
      }

      return aTree;
}
void deleteTree(tree *aTree)
{
      if (NULL != aTree)
      {
            destroyElement(aTree->root);
            free(aTree);
      }
}

Element *createElement(float Value)
{
      Element *newEl = (Element *)malloc(sizeof(Element));

      if (NULL != newEl)
      {
            newEl->left = NULL;
            newEl->right = NULL;
            newEl->value = Value;
      }

      return newEl;
}
void destroyElement(Element *El)
{
      if (NULL != El)
      {
            destroyElement(El->left);
            destroyElement(El->right);

            free(El);
      }
}
Element *getSuccessor(tree *aTree, Element *toDelete)
{
      Element *successParent = toDelete;
      Element *successor = toDelete;
      Element *current = toDelete->right;

      while (NULL != current)
      {
            successParent = successor;
            successor = current;
            current = current->left;
      }
      if (successor != toDelete->right)
      {
            successParent->left = successor->right;
            successor->right = toDelete->right;
      }
      successor->left = toDelete->left;
      return successor;
}

void insertElement(tree *aTree, float Value)
{
      {
            if (NULL == aTree)
            {
                  return;
            }
            Element *newEl = createElement(Value);
            if (NULL == newEl)
            {
                  return;
            }

            if (NULL == aTree->root)
            {
                  aTree->root = newEl;
            }
            else
            {
                  Element *theCurrent = aTree->root;
                  Element *theParent = NULL;
                  while (1)
                  {
                        theParent = theCurrent;

                        if (Value < theCurrent->value)
                        {
                              theCurrent = theCurrent->left;
                              if (NULL == theCurrent)
                              {
                                    theParent->left = newEl;
                                    break;
                              }
                        }
                        else
                        {
                              theCurrent = theCurrent->right;
                              if (NULL == theCurrent)
                              {
                                    theParent->right = newEl;
                                    break;
                              }
                        }
                  }
            }
      }
}
Element *findElement(tree *aTree, float Value)
{
      Element *theCurrentNode = NULL;

      if (NULL != aTree && NULL != aTree->root)
      {
            theCurrentNode = aTree->root;
            while (Value != theCurrentNode->value)
            {
                  theCurrentNode = (Value < theCurrentNode->value)
                                       ? theCurrentNode->left
                                       : theCurrentNode->right;

                  if (NULL == theCurrentNode)
                  {
                        break;
                  }
            }
      }

      return theCurrentNode;
}
void deleteElement(tree *aTree, float Value)
{
      if (NULL == aTree || NULL == aTree->root)
      {
            return ;
      }

      Element *current = aTree->root;
      Element *parent = aTree->root;

      while (Value != current->value)
      {
            parent = current;
            if (Value < current->value)
            {
                  current = current->left;
            }
            else
            {
                  current = current->right;
            }

            if (NULL == current)
            {
                  return ;
            }
      }

      if (NULL == current->left && NULL == current->right)
      {
            if (aTree->root == current)
            {
                  aTree->root = NULL;
            }
            else if (parent->left == current)
            {
                  parent->left = NULL;
            }
            else
            {
                  parent->right = NULL;
            }
      }
      else if (NULL == current->right)
      {
            if (aTree->root == current)
            {
                  aTree->root = current->left;
            }
            else if (parent->left == current)
            {
                  parent->left = current->left;
            }
            else
            {
                  parent->right = current->right;
            }
      }
      else if (NULL == current->left)
      {
            if (aTree->root == current)
            {
                  aTree->root = current->right;
            }
            else if (parent->right == current)
            {
                  parent->right = current->right;
            }
            else
            {
                  parent->left = current->left;
            }
      }
      else
      {
            Element *successor = getSuccessor(aTree, current);
            if (aTree->root == successor)
            {
                  aTree->root = NULL;
            }
            else if (parent->left == current)
            {
                  parent->left = successor;
            }
            else
            {
                  parent->right = successor;
            }
            current->left = NULL;
            current->right = NULL;
      }

      destroyElement(current);
}


void printTree(tree *aTree)
{
      Element *El = aTree->root;
      printElement(El);
}
void printElement(Element *El)
{
      if (El == NULL)
            return;
      printElement(El->left);
      printf("element: %f\n", El->value);
      printElement(El->right);
}