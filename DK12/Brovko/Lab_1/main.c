#include <stdio.h>
#include "dk12_tool.h"

int main(int argc, const char *argv[])
{
    float a = getA();
    float b = getB();
    float c = getC();
    calc(a, b, c);
    return 0;
}
