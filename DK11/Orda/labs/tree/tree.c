#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

static void destroyNode(nodePtr node);
static nodePtr createCharNode(char *data);
static nodePtr getSuccessor(treePtr tree, nodePtr toDelete);
static void printnode(nodePtr node);

treePtr createTree(){
    treePtr atree = (treePtr)malloc(sizeof(tree));

    if(NULL != atree){
        atree->root = NULL;
    }

    return atree;
}

nodePtr createCharNode(char *adata){
    nodePtr anode = (nodePtr)malloc(sizeof(node));

    if(NULL != anode){
        anode->leftChild = NULL;
        anode->rightChild = NULL;
        anode->data = adata;
    }
}

void deleteTree(treePtr atree){
    if(NULL != atree){
        destroyNode(atree->root);
        free(atree);
    }
}

void destroyNode(nodePtr node){
    if(NULL != node){
        destroyNode(node->leftChild);
        destroyNode(node->rightChild);
        free(node);
    }
}

void displayTree(treePtr atree){
    printf("Tree:\n");
    nodePtr item = atree->root;
    printnode(item);
}

void printnode(nodePtr node){
    if(node == NULL){
        return;
    }
    printnode(node->leftChild);
    printf("%s\n", node->data);
    printnode(node->rightChild);
}

nodePtr findNode(treePtr atree, char *adata){
    nodePtr currentNode = atree->root;

    int result = 0;

    if(NULL != atree && NULL != atree->root){
        nodePtr currentNode = atree->root;
        while((result = strcmp(adata, currentNode->data)) != 0){
            currentNode = (result < 0)
                ? currentNode->leftChild
                : currentNode->rightChild;

            if(NULL == currentNode){
                break;
            }
        }
    }

    return currentNode;
}

void insertNode(treePtr atree, char *adata){
    if(NULL == atree){
        return;
    }
    nodePtr anode = createCharNode(adata);
    if(NULL == anode){
        return;
    }

    if(NULL == atree->root){
        atree->root = anode;
    }else{
        nodePtr current = atree->root;
        nodePtr parent = NULL;

        while(1){
            parent = current;

            if(strcmp(adata, current->data) < 0){
                current = current->leftChild;
                if(NULL == current){
                    parent->leftChild = anode;
                    break;
                }
            }else{
                current = current->rightChild;
                if(NULL == current){
                    parent->rightChild = anode;
                    break;
                }
            }
        }
    }
}

void deleteNodeWithData(treePtr atree, char *adata){
    if(NULL == atree && NULL == atree->root){
        return;
    }

    nodePtr current = atree->root;
    nodePtr parent = atree->root;

    while(strcmp(adata, current->data) != 0){
        parent = current;
        if(strcmp(adata, current->data) < 0){
            current = current->leftChild;
        }else{
            current = current->rightChild;
        }

        if(NULL == current){
            return;
        }
    }

    if(NULL == current->leftChild && NULL == current->rightChild){
        if(atree->root == current){
            atree->root = NULL;
        }else if(parent->leftChild == current){
            parent->leftChild = NULL;
        }else{
            parent->rightChild = NULL;
        }
    }else if(current->rightChild == NULL){
        if(atree->root == current){
            atree->root = current->leftChild;
        }else if(parent->leftChild == current){
            parent->leftChild = current->leftChild;
        }else{
            parent->rightChild = current->rightChild;
        }
    }else if(current->leftChild == NULL){
        if(atree->root == current){
            atree->root = current->rightChild;
        }else if(parent->rightChild == current){
            parent->rightChild = current->rightChild;
        }else{
            parent->leftChild = current->leftChild;
        }
    }else{
        nodePtr successor = getSuccessor(atree, current);
        if(atree->root == successor){
            atree->root == NULL;
        }else if(parent->leftChild == current){
            parent->leftChild = successor;
        }else{
            parent->rightChild = successor;
        }
        current->leftChild = NULL;
        current->rightChild = NULL;
    }

    destroyNode(current);
}

nodePtr getSuccessor(treePtr atree, nodePtr toDelet){
    nodePtr successParent = toDelet;
    nodePtr successor = toDelet;
    nodePtr current = toDelet->rightChild;

    while(NULL != current){
        successParent = successor;
        successor = current;
        current = current->leftChild;
    }

    if(successor != toDelet->rightChild){
        successParent->leftChild = successor->rightChild;
        successor->rightChild = toDelet->rightChild;
    }

    successor->leftChild = toDelet->leftChild;

    return successor;
}
