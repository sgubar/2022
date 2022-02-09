#include "helper.h"

int kv(int a)
{
    return a*a;
}

int upgrade(int c)
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
    while(i<a)
    {
        l=a-1;
        k=s*l;
        s=k;
        a=l;
        i++;
    }
return s;
}
