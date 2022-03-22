#include <stdio.h>

#include "tool.h"
 
void input_A(){
        printf("Введіть значення параметра А, А це натуральне число: ");
        scanf("%d", &A);
        if (A < 0){
                while (A < 0)
                {
                        printf("Параметра А має бути більшим 0 та цілим: ");
                        scanf("%d", &A);
                }
        }
}

void input_B(){
        printf("Введіть значення параметра В, від 0 до нескінченості: ");
        scanf("%d", &B);
}

void check(){
        if ((2*A + B) == 0){
                printf("Знаменник рівенб нулю, на нуль ділити не можна, введіть значення А та В повторно\n");
                input_A();
                input_B();
        }
}

void factorial(){
        factor = 1;
        if (A == 0){
                factor = 0;
        }
        else{
                for(int i = A; i >= 1; i--){
                factor *= i;
        }
        }
}

void modul(){
        mod = 2*A + B;
        if (mod < 0){
                mod *= -1;
        }
}

void output(){
        Q = (float)factor/(float)mod;
        if (Q - (int)Q != 0){
                printf("%.1f\n", Q);
        }
        else{
                printf("%.0f\n", Q);
        }
}