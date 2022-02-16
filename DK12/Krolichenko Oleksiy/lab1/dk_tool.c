#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>
#include "dk_tool.h"

void input() {
    printf("A = ");
    scanf("%d", &A);
    printf("B = ");
    scanf("%d", &B);
    if (B < 0) {
        printf("B не може бути меншим за 0 \n");
        exit(EXIT_FAILURE);
    }
    printf("C = ");
    scanf("%d", &C);
}

int factorial(int fac) {
    return (fac < 2) ? 1 : fac * factorial(fac - 1);
}

void res() {
    input();
    for (int i = 0; i <= B; i++) {
        D += factorial(i);
    }
    x = (A * B) / (B + pow(C, 2)) + D;
    return x;
}