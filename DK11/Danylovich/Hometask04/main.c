#include <stdio.h>
#include "dbllist.h"

int main(){

    IntDblList *a = createIntDblList();

    addIntValueToIntDblList(a,28);
    printIntDblListFromHead(a);

    addIntValueToIntDblList(a,41);
    printIntDblListFromHead(a);

    addIntValueToIntDblList(a,12);
    printIntDblListFromHead(a);

    removeLastElementFromIntDblList(a);
    printIntDblListFromHead(a);

    removeFirstElementFromIntDblList(a);
    printIntDblListFromHead(a);

    removeLastElementFromIntDblList(a);
    printIntDblListFromHead(a);

    addIntValueToIntDblList(a,1);
    addIntValueToIntDblList(a,2);
    addIntValueToIntDblList(a,3);
    addIntValueToIntDblList(a,4);
    addIntValueToIntDblList(a,5);
    printIntDblListFromHead(a);

    insertIntElementToIntDblListAtIndex(a,3,228);
    printIntDblListFromHead(a);
    
    removeIntElementFromIntDblListAtIndex(a,2);
    printIntDblListFromHead(a);
    

    deleteIntDblList(a);
}
