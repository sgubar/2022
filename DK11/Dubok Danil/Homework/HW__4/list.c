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

long countOfIntList(IntList *list)
{
      if (NULL == list)
      {
            return 0;
      }
      long count = 0;

      for (Element *element = list->head; element != NULL; element = element->next, count++);

      return count;
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

void insertElementToListAtIndex(IntList *list, int index, int value)
{

      if (NULL == list || (list->head == NULL && list->head != list->tail))
      {
            return;
      }

      long count = countOfIntList(list);

      if (count == index)
      {
            return addValueToList(list, value);
      }
      else if (index > count)
      {
            return;
      }

      Element *element = createElement(value);
      if (NULL == element)
      {
            return;
      }

      if (0 == index)
      {
            element->next = list->head;
            list->head = element;
      }
      else
      {
            int current = 0;
            Element *ex_element = list->head;
            for (; ex_element != NULL && current != index; ex_element = ex_element->next, current++)
                  ;

            element->next = ex_element;
      }
}