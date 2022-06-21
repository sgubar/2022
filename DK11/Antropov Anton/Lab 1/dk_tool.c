#include "dk_tool.h"

int factorial(float b){
    int sum = 0, fact = 1;
    for(int d = 1; d <= b; d++)
    {
            fact = fact*d;
            sum = sum+fact; 
    }
    return sum;
}

float result() {

    float a = 0, b = 0, c = 0, under = 0; 
    printf("Введіть три числа a, b та c : "); 
    scanf("%f %f %f", &a, &b, &c); 
    under = b+(c*c);
    if(under == 0){
        printf("Знаменник рівний нулю\n");
        return 0;
    } else {
    float result = (a*b)/(under); 
    printf("Результат розрахунку лівої частини : %.3f\n", result);
    int sum = factorial(b);
    printf("Сума факторіалів : %d\n", sum);
    float Q = result + sum;
    return Q;
    }
}
