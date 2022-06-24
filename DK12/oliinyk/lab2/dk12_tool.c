#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dk12_tool.h"

Node *createNode(char *value) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

void destroyNode(Node *node) {
    free(node);
}

List *createWordsList(void) {
    List *tmp = (List *)malloc(sizeof(List));
    tmp->head = NULL;
    tmp->tail = NULL;
    return tmp;
}

void destroyWordsList(List *list) {
    Node *tmp = NULL;
    while (list->head != NULL) {
        tmp = list->head;
        list->head = list->head->next;
        destroyNode(tmp);
    }
    free(list);
}

void addNodeToWordsList(List *list, char *value) {
    if (list->head == NULL) {
        list->head = createNode(value);
        list->tail = list->head;
        return;
    }

    Node *curr = list->head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = createNode(value);
    list->tail = curr->next;
}

void sortWords(List *list) {
    Node *p1 = list->head;
    Node *p2 = list->head->next;

    char *tmp;
    int reply = 0;

    int onemore = 0;

    while (p2 != NULL)
    {
        if (strlen(p1->value) > strlen(p2->value)) {
            onemore = 1;
            tmp = p1->value;
            p1->value = p2->value;
            p2->value = tmp;
        }
        p1 = p1->next;
        p2 = p2->next;
        if (p2 == NULL && onemore == 1) {
            onemore = 0;
            if (reply == 0 && onemore == 0) {
                printf("Max long word is: %s\n\n", p1->value);
                reply = 1;
            }
            p1 = list->head;
            p2 = list->head->next;
        }
    }
}

void printWordsList(List *list) {
    if (list->head == NULL) {
        printf("EMPTY\n");
        return;
    }

    Node *curr = list->head;
    printf("[");
    while (curr != NULL) {
        printf("%s ", curr->value);
        curr = curr->next;
        if (curr != NULL) {
            printf(", ");
        }
    }
    printf("]");
    printf("\n\n");
}