#include <stdlib.h>
#include <stdio.h>
#include "single_list.h"

ListSingleFloat *createListSingleFloat() { 
    ListSingleFloat *list = (ListSingleFloat*)malloc(sizeof(ListSingleFloat));
    if (NULL != list) {
        list->head = NULL;
    }
    return list;
}//

NodeSingleFloat *createNodeSingleFloat(float value) { 
    NodeSingleFloat *n = (NodeSingleFloat*)malloc(sizeof(NodeSingleFloat));
    if (NULL != n) {        
        n->data = value;
        n->next = NULL;
    }
    return n;
}//

int addValueTo_ListSingleFloat(ListSingleFloat *list, float value) {
    if (NULL == list) {
        return 0;
    }
    NodeSingleFloat *node = createNodeSingleFloat(value);
    if (NULL == node) {
        return 0;
    }
    
    if (NULL == list->head) {
        list->head = node;
    } else {
        NodeSingleFloat *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;

    }
    return 1;
}//

int addValueTo_ListSingleFloat_atIndex(ListSingleFloat *list, float value, int index) {
    if (NULL == list || index < 0 || index > getSize_ListSingleFloat(list)) {
        return 0;
    }
    NodeSingleFloat *node = createNodeSingleFloat(value);
    if (NULL == node) {
        return 0;
    }

    if (index == 0) {
        node->next = list->head;
        list->head = node;
    } else {
        NodeSingleFloat *prev = list->head;
        for (int i = 0; i < index-1; i++) {
            if (NULL != prev) {            
                prev = prev->next;
            } else 
                return 0;
        }
        node->next = prev->next;
        prev->next = node;
    } 
    return 1;
}//

int deleteFromList_NodeSingleFloat_byValue(ListSingleFloat *list, float value) {
    if (NULL == list || NULL == list->head) {
        return 0;
    }

    NodeSingleFloat *current = list->head;
    NodeSingleFloat *nodeToDelete;
    while (current->next->data != value) {
        current = current->next;
    }
    nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    free(nodeToDelete);
}//
 
int deletefromList_NodeSingleFloat_atIndex(ListSingleFloat *list, int index) {
    if (NULL == list || NULL == list->head
    || index < 0 || index > getSize_ListSingleFloat(list)-1) {
        return 0;
    }

    NodeSingleFloat *nodeToDelete;
    if (index == 0) {
        nodeToDelete = list->head;
        list->head = nodeToDelete->next;
        free(nodeToDelete);
    } else {
        NodeSingleFloat *prev = list->head;
        for (int i = 0; i < index-1; i++) {
            prev = prev->next; //2
        }
        nodeToDelete = prev->next;
        prev->next = nodeToDelete->next;
        free(nodeToDelete);
    } 
    return 1;
}


int getSize_ListSingleFloat(ListSingleFloat *list) {  // number of elements in list
    if (NULL == list) {
        return -1;
    }

    int count = 0;    
    if (NULL != list->head) {        
        NodeSingleFloat *current = list->head;
        count = 1;
        while (current->next != NULL) {
            current = current->next;
            count ++;
        }
    }
    return count;
}//

void deleteListSingleFloat(ListSingleFloat* list) {
    if (NULL == list) {
        return;
    }

    NodeSingleFloat *current = list->head;
    NodeSingleFloat *next;
    while (NULL != current) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
    list = NULL;
}//

void printNodeSingleFloat(NodeSingleFloat *node) {
    if (NULL != node) {
        printf("%f\n", node->data);
    }
}

void printListSingleFloat(ListSingleFloat *list) {
    if (NULL == list) {
        printf("list doesn't exist\n");
        return;
    }
    if (NULL == list->head) {
        printf("list is empty\n");
        return;
    }

    NodeSingleFloat *current = list->head;
     while (current != NULL) {
        printNodeSingleFloat(current);
        current = current->next;
    }
    return;

}