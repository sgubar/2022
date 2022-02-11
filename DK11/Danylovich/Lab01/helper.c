#include "helper.h"

int square(int a)
{
    return a*a;
}

int math_pow(int c)
{
int i = 0;int k = 1;int l=1;int a=5;
    while(i<c)
    {
        l=k*a;
        k=l;
        i++;
    }
return k;
}

int factor(int a)
{
    int i=0,l=1,s=1,k=1;
    s=a;
    if(a>0 && a!=0)
    {
        while(i<a)
        {
            l=a-1;
            k=s*l;
            s=k;
            a=l;
            i++;
        }
return s;
}else 
{
    if(a==0)
    {
        return 1;
    }else return 0;
}
}
