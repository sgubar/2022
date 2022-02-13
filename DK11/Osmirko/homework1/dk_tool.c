#include "dk_tool.h"

int powered(int a)
{
    int i=0, j=1, m=1, d=2;
    while(i<a)
    {
        m=j*d;
        j=m;
        i++;
    }
    return j;
}
