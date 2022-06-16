#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

typedef struct tag_node_singleLink_float {
    float data;
    struct tag_node_singleLink_float *next;
} NodeSingleFloat;

typedef struct tag_list_singleLink_float {
    NodeSingleFloat *head;
} ListSingleFloat;

ListSingleFloat *createListSingleFloat();

NodeSingleFloat *createNodeSingleFloat(float value);

int addValueTo_ListSingleFloat(ListSingleFloat *list, float value);

int addValueTo_ListSingleFloat_atIndex(ListSingleFloat *list, float value, int index);

int deleteFromList_NodeSingleFloat_byValue(ListSingleFloat *list, float value);

int deletefromList_NodeSingleFloat_atIndex(ListSingleFloat *list, int index);

int getSize_ListSingleFloat(ListSingleFloat *list);

void deleteListSingleFloat(ListSingleFloat* list);

void printNodeSingleFloat(NodeSingleFloat *node);

void printListSingleFloat(ListSingleFloat *list);


#endif