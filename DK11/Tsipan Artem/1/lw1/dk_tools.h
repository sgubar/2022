#ifndef DK_TOOLS_H_INCLUDED
#define DK_TOOLS_H_INCLUDED
#endif

int fact(int n)
{
    return n == 1 ? 1 : n * fact(n - 1);
}
