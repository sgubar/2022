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

    int** m1 = createMatrix(2, 2);
    int** m2 = createMatrix(2, 2);

    inputMatrix1(m1, 2, 2);
    inputMatrix2(m2, 2, 2);

    int** mult = multiply(m2, m1, 2, 2);
    result(mult, 2, 2);
}