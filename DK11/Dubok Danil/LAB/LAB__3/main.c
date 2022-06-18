#include <stdio.h>
#include "tree.h"

void main(int argc, const char *argv[])
{
      tree *Tree = createTree();
      float value;
      int i;
      printf("Щоб додати значення натисніть 1+Enter:");
      scanf("%d", &i);
      while (i == 1)
      {
            printf("Введіть значення нового елементу:");
            scanf("%e", &value);
            insertElement(Tree, value);
            i = 0;
            printf("Щоб додати значення натисніть 1+Enter, або 'іншу клавішу'+Enter, для виводу списку:");
            scanf("%d", &i);
      }
      printTree(Tree);

      deleteTree(Tree);

}