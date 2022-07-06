#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct tNode *head = NULL;
struct tNode *tail = NULL;

tNode* add(int a){

    tNode* firsttNode = NULL;
    tNode* currtNode = NULL;
    tNode* prevtNode = NULL;
    int id = 1;
    for(int i = 1; i <= a; i++)
    {
        currtNode = (struct tNode*)malloc(sizeof(struct node));
        currtNode->id = i;
        if( i == 1 )
            firsttNode  = currtNode;
        else
            prevtNode->next = currtNode;

        prevtNode = currtNode;

        id++;
    }

    if(firsttNode != NULL && currtNode != NULL)
    {
       currtNode->next  = firsttNode;
    }

    return firsttNode;
}

tNode* RemoveEachThird( tNode * starttNode) {
    if(starttNode != NULL)
    {
        tNode* toDelete = starttNode->next->next;
        starttNode->next->next = toDelete->next;
        starttNode = toDelete->next;

        printf("Deleted Node %d\n", toDelete->id);
        printf("New start Node %d\n", starttNode->id);

        free(toDelete);

    }
    else{

        printf("List is empty");
    }

  return starttNode;
}



