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
      printf("Щоб додати значення натисніть 1+Enter:");
      scanf("%d", &i);
      while(i==1){
            printf("Введіть значення нового елементу:");
            scanf("%d", &value);
            addValueToList(list, value);
            i = 0;
            printf("Щоб додати значення натисніть 1+Enter, або 'іншу клавішу'+Enter, для виводу списку:");
            scanf("%d", &i);
      }
      printf("Заданий список:");
      printIntList(list);

      IntList *listC = createIntList();
      printf("Список без повторень:");
      reList(list, listC);
      printIntList(listC);
      deleteIntList(listC);
}