#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"

int main() 
{
  DoubleSingleList *list = createDoubleSingleList();

  printDoubleSingleList(list);

  addDoubleValueToSingleList(list, 10.23);

  addDoubleValueToSingleList(list, 1.11);
  printDoubleSingleList(list);

  removeFirstElementFromDoubleSingleList(list);
  printDoubleSingleList(list);

  removeLastElementFromDoubleSingleList(list);
  printDoubleSingleList(list);
    
  printf("Hello world!\n");

  deleteDoubleSingleList(list);
  return 0;
}
