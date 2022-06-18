#include <stdio.h>
#include "tree.h"

void main(int argc, const char *argv[])
{
      tree *Tree = createTree();
      
      insertElement(Tree, 4.476F);
      insertElement(Tree, 8.908F);
      insertElement(Tree, 24.58F);
      insertElement(Tree, 9.3F);
      insertElement(Tree, 2.0F);
      insertElement(Tree, 4.3F);

      printTree(Tree);

      deleteTree(Tree);
}