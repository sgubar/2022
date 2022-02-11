#include <stdio.h>
#include <stdlib.h>
#include "dk12_tool.h"


int getFactorialNumber(void) {
    int A;
    printf("Type number A for factorial\nNumber for factorial must be >= 0: ");
    scanf("%d", &A);
    checkFactorialNumber(A);
    return A;
}

int getDenominatorNumber(void) {
    int B;
    printf("Type number B for denominator: ");
    scanf("%d", &B);
    return B;
}

int checkFactorialNumber(int A) {
    if (A >= 0) return 1;
    printf("Number for factorial must be >= 0 !");
    exit(0);
}

int checkDenominatorResult(int result) {
    if (result != 0) return 1;
    printf("Denominator result can't be 0 !");
    exit(0);
}

long factorial(int A) {
    long result = 1;
    for (int i = 1; i < A + 1; i++) {
        result *= i;
    }
    return result;
}

float calcDenominator(int A, int B) {
    float result = abs(2 * A + B);
    checkDenominatorResult(result);
    return result;
}

float mainCalc(long numerator, float denominator) {
    float result = numerator / denominator;
    return result;
}

void printResult(int A, int B, float result) {
    printf("Result: %d! / (2 * %d + %d) = %.3f", A, A, B, result);
}