#include "dk12_tool.h"

int main(void)
{
    int binaryNumber = getBinaryNumber();
    int result = binaryToInt(binaryNumber);
    printResult(result);
}