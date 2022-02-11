#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int main(int argc, const char * argv[])
{
    float arr[4];float j;
    if(argv[1]==NULL || argv[2]==NULL || argv[3]==NULL)
    {
        return 0;
    }else
    for(int i=0;i<4;i++)
    {
        arr[i]=atoi(argv[i]);
    }
    float a=arr[1];float b=arr[2];float c=arr[3];
    float qq = square(a) + square(b);
    float s = b + math_pow(c);
    if(s==0){
        return 0;
    }else
    j = qq/s;
    float kk = factor(b);
    float p = j+kk;
    printf("Answer:%f\n",p);
}
