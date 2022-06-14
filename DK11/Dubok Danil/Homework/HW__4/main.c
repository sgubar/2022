/*Дубок Данило 
  ДК-11
  ДЗ-4
  Однозв'язний список int*/

#include <stdio.h>
#include "list.h"

int main(int argc, const char *argv[])
{
      IntList *list = createIntList();
      int value, i;
      printf("Щоб додати значення натисніть 1+Enter:\n");
      scanf("%d", &i);
      while(i==1){
            printf("Введіть значення нового елементу:\n");
            scanf("%d", &value);
            addValueToList(list, value);
            i = 0;
            printf("Щоб додати значення натисніть 1+Enter, або 'іншу клавішу'+Enter, для виводу списку:\n");
            scanf("%d", &i);
      }
      printIntList(list);

      deleteIntList(list);
}