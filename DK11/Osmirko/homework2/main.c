#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circle.h"

int main()
{
    Circle *circle1 = create2(4, 6, 3);
    printCircle(circle1);
    
    destroy(circle1);
    return 0;
}
