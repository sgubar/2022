#include "dk11_tool.h"


int main(void) {
    int A = getFactorialNumber();
    int B = getDenominatorNumber();
    long numerator = factorial(A);
    int denominator = calcDenominator(A, B);
    float result = mainCalc(numerator, denominator);
    printResult(A, B, result);
    return 1;
}
