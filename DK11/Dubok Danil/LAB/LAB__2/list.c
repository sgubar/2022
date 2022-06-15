#include "list.h"
#include <stdlib.h>
#include <string.h>

Element *createElement(int value)
{
      Element *i = (Element *)calloc(0, sizeof(Element));

      if (i != NULL)
      {
            i->value = value;
      }

      return i;
}

void deleteElement(Element *element)
{
      if (element != NULL)
      {
            free(element);
      }
}

void printElement(Element *element)
{
      if (NULL != element)
      {
            printf("%d", element->value);
      }
}


IntList *createIntList(void)
{
      IntList *i = (IntList *)calloc(0, sizeof(IntList));
      return i;
}

void deleteIntList(IntList *list)
{
      if (NULL == list)
      {
            return;
      }

      Element *element = list->head;

      while (NULL != element)
      {
            Element *tmp = element->next;
            deleteElement(element);
            element = tmp;
      }

      free(list);
}

void printIntList(IntList *list)
{

      if (NULL == list)
      {
            printf("Invalid a pointer to the list\n");
            return;
      }

      printf("[");

      Element *element = NULL;
      for (element = list->head; element != list->tail; element = element->next)
      {
            printElement(element);
            printf(",");
      }

      if (element != NULL)
      {
            printElement(element);
      }

      printf("]\n");
}

void addValueToList(IntList *list, int value)
{
      if (NULL == list || (list->head == NULL && list->head != list->tail))
      {
            return;
      }

      Element *element = createElement(value);
      if (NULL == element)
      {
            return;
      }

      if (NULL == list->head)
      {
            list->head = element;
            list->tail = list->head;
            return ;
      }

      list->tail->next = element;
      list->tail = element;

      return ;
}

void reList(IntList *listI, IntList *listCor)
{
      Element *in_line = (Element *)calloc(0, sizeof(Element));
      Element *not_in_line = (Element *)calloc(0, sizeof(Element));
      for (in_line = listI->head; in_line != NULL; in_line = in_line->next)
      {
            if (in_line->value != 0){
            addValueToList(listCor, in_line->value);
            for (not_in_line = in_line->next; not_in_line != NULL; not_in_line = not_in_line->next)
            {
                  if (not_in_line->value == in_line->value )
                  {
                        not_in_line->value = 0;
                  }
            }
            }
      }
      deleteIntList(listI);
}