#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
   int count = 5;
   tNode* StartNode = add(count);

   while(count > 2)
   {
     StartNode = RemoveEachThird(StartNode);
     count --;
   }

   if( count == 2)
   {
     printf("Left node1 %d\n", StartNode->id);

     printf("Left node2 %d\n", StartNode->next->id);
   }
   return 0;
}
