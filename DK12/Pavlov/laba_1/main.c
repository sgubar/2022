#include <stdio.h>
#include "dk12tool.h"

int main(void)
{
    float a = 0, b = 0, c = 0;
    float q = calc(a, b, c);
    if (q != -1)
    {
    printf("\nResult: %f", q);
    }
    return 0;
}
