#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>

#include "dk_tool.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int A = inputA();
    int B = inputB();
    int C = inputC();
    double x = res(A, B, C);
    printf("res = %f", x);
}