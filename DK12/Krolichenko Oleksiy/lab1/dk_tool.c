#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>
#include "dk_tool.h"

int inputA(void) {
    int A;
    printf("A = ");
    scanf("%d", &A);
    return A;
}

int inputB(void) {
    int B;
    printf("B = ");
    scanf("%d", &B);
    if (B < 0) {
        printf("B не може бути меншим за 0 \n");
        exit(EXIT_FAILURE);
    }
    return B;
}

int inputC(void) {
    int C;
    printf("C = ");
    scanf("%d", &C);
    return C;
}

int factorial(int fac) {
    return (fac < 2) ? 1 : fac * factorial(fac - 1);
}

int powFunc(int base, int exp) {
    int a = base;
    if (exp > 0) {

        for (int i = 1; i < exp; i++) {
            base *= a;
        }
        return base;
    }
    else if (exp < 0) {
        for (; exp < -1; exp++) {
            base *= a;
        }
        return 1.0 / base;
    }
    else {
        return 1;
    }
}


int res(int A, int B, int C) {
    int D = 0;
    for (int i = 0; i <= B; i++) {
        D += factorial(i);
    }
    double x = (A * B) / (B + powFunc(C, 2)) + D;
    return x;
}