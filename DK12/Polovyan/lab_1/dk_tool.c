#include <stdio.h>
#include <math.h>
#include "tools.h"

    float A, B, C, up1, fact1;



 float GetCheck(void)
 {
    printf("Введіть A > 0:\n");
    scanf("%f", &A);
    printf("Введіть B:\n");
    scanf("%f", &B);
    printf("Введіть C =! 0:\n");
    scanf("%f", &C);
     if((A<1 && A%1 != 0)|| C <= 0)
    {
       printf("ПОМИЛКА !!!\n"); 
       return 0;
    }
 }
 
//////////////////////////////////////////

    float fact(float A)
    {
        for(int d = 0; d <= A; d++) 
        {
            fact1 = fact1 + pow(2, d);
        }
        return fact1;
    }
    
////////////////////////////////////////

    float up(float A, float B, float C)
    {
        up1 = A*C - B;
        if(up1 < 0) up1 = up1*(-1);
        return up1;
    }

///////////////////////////////////////////


    float res()
    {
        float res1;
        GetCheck();
        fact();
        up();
        res1 = (up1/(C*C*C))*fact1;
        return res1;
    }

///////////////////////////////////////////
