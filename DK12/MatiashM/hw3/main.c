#include <stdlib.h>
#include <stdio.h>
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

    SquareArray *square_array = create_square_array(3);

    int index_zero = add_square_to_array(square_array, square_one);
    int index_one = add_square_to_array(square_array, square_two);
    int index_two = add_square_to_array(square_array, square_three);

    printf("One: %d\n", index_zero);
    printf("Two: %d\n", index_one);
    printf("Three: %d\n", index_two);

    index_two = set_square_at_index(square_array, square_one, 2);

    printf("Array count: %d\n\n", count_square_array(square_array));

    print_square_array(square_array);

    delete_square_array(square_array);

    return 1;
}