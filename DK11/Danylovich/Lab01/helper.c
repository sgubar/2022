#include "helper.h"

int param(int a)
{
    float b;
    printf("%i Параметр: ",a);
    scanf("%f",&b);
    return b;
}

int square(float a)
{
    return a*a;
}

int math_pow5(float c)
{
float i = 0, k = 1, l=1, a=5;
    while(i<c)
    {
        l=k*a;
        k=l;
        i++;
    }
return k;
}

int factor(float a)
{
    float i=0,changenumb=1,sumfact=1,justparam=1;
    sumfact=a;
    if(a>0)
    {
        while(i<a)
        {
            changenumb=a-1;
            justparam=sumfact*changenumb;
            sumfact=justparam;
            a=changenumb;
            i++;
        }
return sumfact;
}else 
{
    if(a==0)
    {
        return 1;
    }else return 0;
}
}

int answer(float a,float b,float c)
{
    float fraction;
    float numerator = square(a) + square(b);
    float denominator = b + math_pow5(c);
    if(denominator==0){
        return 0;
    }else
    fraction = numerator/denominator;
    float Q = fraction+factor(b);
    return Q;
}

