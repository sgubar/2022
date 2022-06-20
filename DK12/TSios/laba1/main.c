#include "tools.h"


int main(void)
{
    int A = getA();
    int B = getB();
    int C = getC();

    int sum = getSum(A);

    printResult(calcResult(A,B,C,sum));

    return 0;
}
