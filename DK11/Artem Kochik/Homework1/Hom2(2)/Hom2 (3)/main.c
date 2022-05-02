#include <stdlib.h>
#include "tools.h"

int main(void)
{
    Point *point1 = create_point(5, 15);
    Point *point2 = create_point(10, 15);
    Square *square_one = create_square(point1, point2);

    Square *square_two = create_squareXY(15, 30, -16, 5);

    Point *array[2];
    array[0] = create_point(-1, 13);
    array[1] = create_point(12, 4);
    Square *square_three = create_arr_square(array);

    square_info(square_one, area_square(square_one));
    square_info(square_two, area_square(square_two));
    square_info(square_three, area_square(square_three));

    square_destroy(square_one);
    square_destroy(square_two);
    free(square_three);

    return 1;
}
