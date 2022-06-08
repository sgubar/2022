#include "dk_tool.h"

int main(void)
{
    int A = getA();
    float B = getB();
    float C = getC();

    float numerator = calcNumerator(A, B, C);
    int sum = calcSum(A);

    result(numerator, C, sum);
    return 1;
}
