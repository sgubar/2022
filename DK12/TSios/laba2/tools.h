#ifndef tools_h
#define tools_h

struct tag_node
{
    int value;
    struct node *next;
};
typedef struct tag_node *Node;

struct tag_list
{
    struct tag_node *head;
    struct tag_node *tail;
};
typedef struct tag_list *List;

Node nodeCreate(int value);
void nodeDestroy(Node node);

List listCreate(void);
void listDestroy(List list);

void listAddNode(List list, int value);

void listSortAscend(List list);

void listPrint(List list);

#endif
