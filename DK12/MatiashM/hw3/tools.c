#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>

#include "tools.h"

long reallocate_internal_storage(SquareArray *array, int requestedCount);

Point *create_point(double x, double y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    if (point != NULL)
    {
        point->x = x;
        point->y = y;
    }
    return point;
}

Square *create_square(Point *point1, Point *point2)
{
    Square *square = (Square *)malloc(sizeof(Square));
    if (square != NULL)
    {
        square->point1 = point1;
        square->point2 = point2;
    }
    return square;
}

Square *create_squareXY(double point1x, double point1y, double point2x, double point2y)
{
    Point *point1 = create_point(point1x, point1y);
    Point *point2 = create_point(point2x, point2y);
    Square *square = create_square(point1, point2);
    return square;
}

Square *create_arr_square(Point *array[])
{
    Square *array_square = create_square(*array, (*array + 1));
    return array_square;
}

double area_square(Square *square)
{
    double area;
    if (square != NULL)
    {
        area = pow(hypot((square->point1->x - square->point2->x), (square->point1->y - square->point2->y)), 2);
    }
    return area;
}

void square_destroy(Square *square)
{
    free(square->point1);
    free(square->point2);
    free(square);
}

void square_info(Square *square)
{
    double area = area_square(square);
    printf("\nFirst point: x = %lf; y = %lf;\n", square->point1->x, square->point1->y);
    printf("Second point: x = %lf; y = %lf;\n", square->point2->x, square->point2->y);
    printf("Area: %lf;\n", area);
}

SquareArray *create_square_array(int count)
{
    SquareArray *array = (SquareArray *)malloc(sizeof(SquareArray));
    if (array != NULL)
    {
        if (count <= 0)
        {
            printf("Count must >= 0!");
            return NULL;
        }
        array->count = abs(count);
        array->storage = (Square **)malloc(sizeof(Square *) * array->count);
        bzero(array->storage, sizeof(Square *) * array->count);
    }
    return array;
};

int add_square_to_array(SquareArray *array, Square *Square)
{
    if (array == NULL)
    {
        return SquareArrayIndexError;
    }
    int index;
    if (array->storage[array->count - 1] != NULL)
    {
        printf("Maximum count of elements in the array!\n\n");
        return SquareArrayIndexError;
    }

    for (int i = 0; i < array->count; i++)
    {
        if (array->storage[i] == NULL)
        {
            array->storage[i] = Square;
            index = i;
            break;
        }
    }
    return index;
};

int set_square_at_index(SquareArray *array, Square *square, int index)
{
    if (array == NULL || index < 0)
    {
        return SquareArrayIndexError;
    }

    if (index >= array->count)
    {
        if (SquareArrayIndexError == reallocate_internal_storage(array, index + 1))
        {
            return SquareArrayIndexError;
        }
    }

    array->storage[index] = square;
    return index;
};

Square *get_square_at_index(SquareArray *array, int index)
{
    if (array == NULL || index < 0 || index >= array->count)
    {
        return NULL;
    }

    return array->storage[index];
};

int count_square_array(SquareArray *array)
{
    if (array == NULL)
    {
        return SquareArrayIndexError;
    }

    return array->count;
};

void print_square_array(SquareArray *array)
{
    if (array == NULL)
    {
        return;
    }
    for (int i = 0; i < array->count; i++)
    {
        if (array->storage[i] != NULL)
        {
            printf("\n\nSquare index:  %d\n", i);
            square_info(array->storage[i]);
        }
        else
        {
            printf("NULL");
        }
    }
};

void delete_square_array(SquareArray *array)
{
    if (array != NULL)
    {
        if (array->storage != NULL)
        {
            free(array->storage);
        }
        free(array);
    }
};

long reallocate_internal_storage(SquareArray *array, int requestedCount)
{
    if (array->count >= requestedCount)
    {
        return array->count;
    }

    int count = requestedCount * 2;

    Square **storage = (Square **)malloc(sizeof(Square *) * count);
    if (storage == NULL)
    {
        return SquareArrayIndexError;
    }

    bzero(storage, sizeof(Square *) * count);

    memcpy(storage, array->storage, sizeof(Square *) * array->count);
    free(array->storage);

    array->storage = storage;
    array->count = count;

    return count;
}