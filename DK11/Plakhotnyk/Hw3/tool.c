#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "tool.h"

long reallocateInternalStorage(ElipsArray *array, int requestedCount);

Point *createPoint(double x, double y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    if (point != NULL)
    {
        point->x = x;
        point->y = y;
    }
    return point;
}

Elips *createElips(Point *center, Point *edge_a, Point *edge_b)
{
    Elips *elipse = (Elips *)malloc(sizeof(Elips));
    if (elipse != NULL)
    {
        elipse->center = center;
        elipse->edge_a = edge_a;
        elipse->edge_b = edge_b;
    }
    return elipse;
}

Elips *createElipsXY(double centerX, double centerY, double edge_aX, double edge_aY, double edge_bX, double edge_bY)
{
    Point *center = createPoint(centerX, centerY);
    Point *edge_a = createPoint(edge_aX, edge_aY);
    Point *edge_b = createPoint(edge_bX, edge_bY);
    Elips *elips = createElips(center, edge_a, edge_b);
    return elips;
}

double hypot_a_Elips(Elips *elips)
{
    double hypotenuse_a = 0;
    if (elips != NULL)
    {
        hypotenuse_a = hypot(
            (elips->edge_a->x - elips->center->x),
            (elips->edge_a->y - elips->center->y));
    }
    return hypotenuse_a;
}

double hypot_b_Elips(Elips *elips)
{
    double hypotenuse_b = 0;
    if (elips != NULL)
    {
        hypotenuse_b = hypot(
            (elips->edge_b->x - elips->center->x),
            (elips->edge_b->y - elips->center->y));
    }
    return hypotenuse_b;
}

double areaElips(Elips *elips)
{
    double hypotenuse_a = hypot_a_Elips(elips);
    double hypotenuse_b = hypot_b_Elips(elips);
    double area = acos(-1) * hypotenuse_a * hypotenuse_b;
    return area;
}

Elips *createArrElips(Point *array[])
{
    Elips *arrayElips = createElips(*array, (*array + 1), (*array + 2));
    return arrayElips;
}



void printDetailElips(Elips *elips)
{
    if (elips != NULL)
    {
        printf("Center point: x = %.3lf; y = %.3lf\n", elips->center->x, elips->center->y);
        printf("Edge a point: x = %.3lf; y = %.3lf\n", elips->edge_a->x, elips->edge_a->y);
        printf("Edge b point: x = %.3lf; y = %.3lf\n", elips->edge_b->x, elips->edge_b->y);
        printf("1st semiaxis: %.3lf;\n", hypot_a_Elips(elips));
        printf("2nd semiaxis: %.3lf;\n", hypot_b_Elips(elips));
        printf("Elips area: %.3lf;\n", areaElips(elips));
        printf("\n");
    }
}

ElipsArray *createElipsArray(int count)
{
    ElipsArray *array = (ElipsArray *)malloc(sizeof(ElipsArray));
    if (array != NULL)
    {
        if (count == 0)
        {
            printf("Count must be > 0!");
            return NULL;
        }
        array->count = abs(count);
        array->storage = (Elips **)malloc(sizeof(Elips *) * array->count);
        bzero(array->storage, sizeof(Elips *) * array->count);
    }
    return array;
};

int addElipsToArray(ElipsArray *array, Elips *elips)
{
    if (array == NULL)
    {
        return -1;
    }
    int index = 0;
    if (array->storage[array->count - 1] != NULL)
    {
        printf("Full array!!!\n");
        return -1;
    }

    for (int i = 0; i < array->count; i++)
    {
        if (array->storage[i] == NULL)
        {
            array->storage[i] = elips;
            index = i;
            break;
        }
    }
    return index;
};

int setElipsAtIndex(ElipsArray *array, Elips *elips, int index)
{
    if (array == NULL || index < 0)
    {
        return -1;
    }

    if (index >= array->count)
    {
        if (-1 == reallocateInternalStorage(array, index + 1))
        {
            return -1;
        }
    }

    array->storage[index] = elips;
    return index;
};

Elips *getElipsByIndex(ElipsArray *array, int index)
{
    if (array == NULL || index < 0 || index >= array->count)
    {
        return NULL;
    }

    return array->storage[index];
};

int countElipsArray(ElipsArray *array)
{
    if (array == NULL)
    {
        return -1;
    }

    return array->count;
};

void printElipsArray(ElipsArray *array)
{
    if (array == NULL)
    {
        return;
    }

    for (int i = 0; i < array->count; i++)
    {
        if (array->storage[i] != NULL)
        {
            printf("Index:  %d\n", i);
            printDetailElips(array->storage[i]);
        }
        else
        {
            printf("empty\n");
        }
    }
};

void deleteElipsArray(ElipsArray *array)
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

long reallocateInternalStorage(ElipsArray *array, int requestedCount)
{
    if (array->count >= requestedCount)
    {
        return array->count;
    }

    int count = requestedCount * 2;

    Elips **storage = (Elips **)malloc(sizeof(Elips *) * count);
    if (storage == NULL)
    {
        return -1;
    }

    bzero(storage, sizeof(Elips *) * count);

    memcpy(storage, array->storage, sizeof(Elips *) * array->count);
    free(array->storage);

    array->storage = storage;
    array->count = count;

    return count;
}