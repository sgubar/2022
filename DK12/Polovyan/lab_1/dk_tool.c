#include <stdio.h>
#include <math.h>
#include "tools.h"

    int get_A(void)
    {
        int A;
        printf("Введіть A:\n");
        scanf("%d", &A);
        check_A(A);
        return A;
    }
    
    float get_B(void)
    {
        float B;
        printf("Введіть B:\n");
        scanf("%f", &B);
        return B;
    }
   
    int get_C(void)
    {
        float C;
        printf("Введіть C:\n");
        scanf("%f", &C);
        check_C(C);
        return C;
    }

    int check_A(int A)
    {
        if(A<1 && A%1 != 0) return 0;
        printf("А ПОВИННО БУТИ ЦІЛИМ ЧИСЛОМ І БІЛЬШЕ НУЛЯ !!!\n");
        exit(0);
    }
    
    float check_C(float C)
    {
        if(C = 0) return 0;
        printf("C ПОВИННО НЕ ДОРІВНЮВАТИ 0 !!!\n");
        exit(0);
    }

    int factorial(int A)
    {
        int fact1;
        for(int d = 0; d <= A; d++) 
        {
            fact1 = fact1 + pow(2, d);
        }
        return fact1;
    }
    
    float up(int A, float B, float C)
    {
        float up1 = A*C - B;
        if(up1 < 0) up1 = up1*(-1);
        return up1;
    }
    
    float calc(float upp, int fact, int A, float C)
    {
        float calc1 = (upp/(C*C*C)*fact1);
        return calc1;
    }
    
    void show_value(float result)
    {
        printf("Результат: %f \n", result);
    }

