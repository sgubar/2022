#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


typedef struct node{
    int id;
    struct node *next;
}tNode;

tNode* add(int a);
tNode* RemoveEachThird( tNode * startNode);

#endif // LIST_H_INCLUDED



