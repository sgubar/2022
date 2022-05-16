#include <stdio.h>
#include "single_list.h"

int main() {

    IntSingleList *a = getIntElementToIntSingleList();
    printIntSingleList(a);

    int b = MNOfIntSingleList(a);
    if(b == -1){
        return 0;
    }

    removeFirstElementFromIntSingleList(a);
    printIntSingleList(a);

    countOfIntSingleList(a);

    removeIntElementsWhichLessThenMN(a,b);
    printIntSingleList(a);

    deleteIntSingleList(a);

}
