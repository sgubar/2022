#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int main() 
{
    int count = getCount();
    getWords(count);
    sortArray(count);
    printArray(count);
    printMaxLettersWords(count);
    return 1;
}
