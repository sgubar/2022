#include <stdio.h>
#include <stdlib.h>
#include "math.h"


int main()
{
    printf("enter 3 parameters\n");
    printf("rule1 - value1 must be no more 10\n");
    printf("rule2 - value2 + value3 must not be equal to 100\n");
    int a = value(1);
    int b = value(2);
    int c = value(3);

    if (a>20 || b+c==100)
    {
        printf("math error, violated rules\n" );
    }
    else
    {
        printf(" Q = %f", q(a , b, c));
        return 0;
    }


}
