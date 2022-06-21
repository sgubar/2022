#include "list.h"

int main() {

    IntSingleList *list = getIntElementToIntSingleList();
    printIntSingleList(list);

    int averageValue = averageValueOfIntSingleList(list);
    if(averageValue == -1) {
        return 0;
    }

    removeFirstElementFromIntSingleList(list);
    printIntSingleList(list);

    countOfIntSingleList(list);

    removeIntElementsLessThanAverageValue(list,averageValue);
    printIntSingleList(list);

    deleteIntSingleList(list);

}
