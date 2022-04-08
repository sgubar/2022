#include "tools.h"

int main()
{
    int len = get_hexadecimal_number();
    int decimal = transformation_number(len);
    print_result(decimal);
    return 1;
}