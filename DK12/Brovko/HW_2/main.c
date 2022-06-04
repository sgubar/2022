#include <stdio.h>
#include <stdlib.h>
#include "dk12_tool.h"
#include <conio.h>

int main() {
    DK12_crd *Triangle = CreateCrd(3);
    import(Triangle);
    float S=calculate(Triangle);
    printf("Result: %f", S);
    if (NULL != Triangle) {
        free (Triangle);
    }
    getch();
    return 0;
}

