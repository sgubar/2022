#include "dk12_tool.h"


int main() {
    int count = getCount();
    getWords(count);
    sortArray(count);
    printArray(count);
    printMaxLettersWords(count);
    return 1;
}