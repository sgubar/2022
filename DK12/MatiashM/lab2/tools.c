#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

Node *node_create(int value)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

void node_destroy(Node *nd)
{
    free(nd);
}

List *list_create(void)
{
    List *tmp = (List *)malloc(sizeof(List));
    tmp->head = NULL;
    tmp->tail = NULL;
    return tmp;
}

void list_destroy(List *ls)
{
    Node *tmp = NULL;
    while (ls->head != NULL)
    {
        tmp = ls->head;
        ls->head = ls->head->next;
        node_destroy(tmp);
    }
    free(ls);
}

void list_add_node(List *ls, int value)
{
    if (ls->head == NULL)
    {
        ls->head = node_create(value);
        ls->tail = ls->head;
        return;
    }

    Node *curr = ls->head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = node_create(value);
    ls->tail = curr->next;
}

void list_sort(List *ls)
{
    Node *p1 = ls->head;
    Node *p2 = ls->head->next;

    int tmp = 0;

    int onemore = 0;

    while (p2 != NULL)
    {
        if (p1->value > p2->value)
        {
            onemore = 1;
            tmp = p1->value;
            p1->value = p2->value;
            p2->value = tmp;
        }
        p1 = p1->next;
        p2 = p2->next;
        if (p2 == NULL && onemore == 1)
        {
            p1 = ls->head;
            p2 = ls->head->next;
            onemore = 0;
        }
    }
}

void list_print(List *ls)
{
    if (ls->head == NULL)
    {
        printf("[EMPTY]\n");
        return;
    }

    Node *curr = ls->head;
    while (curr != NULL)
    {
        printf("%d ", curr->value);
        curr = curr->next;
        if (curr != NULL)
        {
            printf(", ");
        }
    }
    printf("\n");
}
