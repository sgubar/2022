#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int main(int argc, const char * argv[])
{
    float a = param(1);
    float b = param(2);
    float c = param(3);
    printf("Answer:%f\n",answer(a,b,c));
}
