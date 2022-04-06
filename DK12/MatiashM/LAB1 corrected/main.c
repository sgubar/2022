#include "tools.h"


int main(void)
{
    int a = get_A();
    int b = get_B();
    int c = get_C();
    int sum = get_sum(a);
    print_result(result(a,b,c,sum));
    return 1;
}