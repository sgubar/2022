#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>
#include "List.h"

List* input(int* listSize) {
    do {
        printf("Розмір списку:\n");
        scanf("%d", listSize);
    } while (*listSize <= 0);

    printf("Заповніть список: \n");
    int initValue;
    scanf("%d", &initValue);

    List* myList = init(initValue);
    if (*listSize == 1)
        return myList;
    List* iter = myList;

    if (*listSize > 1) {

        for (int i = 0; i < *listSize - 1; i++) {
            int inputNumber;
            scanf("%d", &inputNumber);
            addElement(iter, inputNumber);
            iter = iter->next;
        }
    }
    else {
        return myList;
    }
    return myList;
}

void swapNodes(List* node1, List* node2) {
    int tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;
}

List* addElement(List* lst, int num) {
    List* temp, * p;
    temp = (List*)malloc(sizeof(List));
    p = lst->next; 
    lst->next = temp; 
    temp->val = num; 
    temp->next = p; 
    return(temp);
}

List* init(int i) {
    List* lst;
    lst = (List*)malloc(sizeof(List));
    lst->val = i;
    lst->next = NULL; 
    return(lst);
}

void printList(List* myList) {

    List* iter = myList;
    while (iter != NULL) {
        printf("%d ", iter->val);
        iter = iter->next;
    }
}

void destroyList(List* head) {
    List* tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

}