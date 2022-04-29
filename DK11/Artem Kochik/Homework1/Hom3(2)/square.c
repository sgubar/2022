#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "square.h"
Point* point_create(const double x, const double y)
{
	Point* tmp = (Point*)malloc(sizeof(Point));
	if(tmp == NULL) return NULL;
	tmp->x = x;
	tmp->y = y;
	return tmp;
}

Square* square_create_arr(Point arr[])
{
	Square* tmp = square_create(arr, (arr+1));
	return tmp;
}

Square* square_create(Point* a, Point* b)
{
	Square* tmp = (Square*)malloc(sizeof(Square));
	if(tmp == NULL) return NULL;
	tmp-> a = a;
	tmp-> b  = b;
	return tmp;
}

Square* square_create_xy(const double ax, const double ay , const double bx, const double by )
{
	Point* a = point_create(ax, ay);
	Point* b = point_create(bx, by);
	Square* tmp = square_create(a, b);
	return tmp;
}

double square_area(Square* sq)
{
	double d = hypot((sq->b->x - sq->a->x), (sq->b->y - sq->a->y));
	return d * d / 2;
}

void square_destroy(Square* sq)
{
	free(sq->a);
	free(sq->b);
	free(sq);
}

void sq_info(Square* sq)
{
	printf("Перший кут: x = %.2lf; y = %.2lf\n", sq->a->x, sq->a->y);
	printf("Другий кут: x = %.2lf; y = %.2lf\n", sq->b->x, sq->b->y);
} 
void printDetailSquare(Square*square)
{   
    double s = areaSquare(square);
    printf("Перша точка: x = %.2lf; y = %.2lf\n", square->point1->x, square->point1->y);
    printf(" Друга точка : x = %.2lf; y = %.2lf\n", square->point2->x, square->point2->y);
    printf("Третя точка: x = %.2lf; y = %.2lf\n", square->point3->x, square->point3->y);
    printf("Четверта точка: x = %.2lf; y = %.2lf\n", square->point4->x, square->point4->y);
    printf("Площа фігури : %.2lf\n", s);
}

SquareArray *createSquareArray(int count) {
    SquareArray *array = (SquareArray *)malloc(sizeof(SquareArray));
    if (array != NULL) {
        if (count == 0) {
            printf("Не повинно бути нуль");
            return NULL;
        }
        array->count = abs(count);
        array->storage = (Square **)malloc(sizeof(Square *) * array->count);
        bzero(array->storage, sizeof(Square *) * array->count);
    }
    return array;
};

int addSquareToArray(SquareArray *array, Square *square) {
    if (array == NULL) {
        return SquareArrayIndexError;
	}
    int index;
    if (array->storage[array->count - 1] != NULL) {
        printf("Максимальна кількість елементів у масиві!\n\n");
        return SquareArrayIndexError;
    }

    for (int i = 0; i < array->count; i++) {
        if (array->storage[i] == NULL) {
            array->storage[i] = square;
            index = i;
            break;
        }
    }
    return index;
};

int setSquareAtIndex(SquareArray *array, Square *square, int index) {
    if (array == NULL || index < 0) {
        return SquareArrayIndexError;
    }

    if (index >= array->count) {
        if (SquareArrayIndexError == reallocateInternalStorage(array, index + 1)) {
            return SquareArrayIndexError;
		}
    }

    array->storage[index] = square;
    return index;
};

Square *getSquareAtIndex (SquareArray *array, int index) {
    if (array  == NULL || index < 0 || index >= array->count) {
        return NULL;
    }

    return array->storage[index];
};

int countSquareArray(SquareArray *array) {
    if (array == NULL) {
    return SquareArrayIndexError;
    }

    return array->count;
};


void deleteSquareArray(SquareArray *array) {
    if (array != NULL) {
        if (array->storage != NULL) {
            free(array->storage);
        }
        free(array);
    }
};

long reallocateInternalStorage(SquareArray *array, int requestedCount) {
    if (array->count >= requestedCount) {
        return array->count;
    }

    int count = requestedCount * 2;

    Square **storage = (Square **)malloc(sizeof(Square *) * count);
    if (storage ==  NULL) {
        return SquareArrayIndexError;
    }
    memcpy(storage, array->storage, sizeof(Square *) * array->count);
    free(array->storage);

    array->storage = storage;
    array->count = count;

    return count;
}
