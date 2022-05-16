#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include "circle.h"

long reallocateInternalStorage(CircleArray *array, int requestedCount);

Point *createPoint(double X, double Y) 
{
    Point *point = (Point *)malloc(sizeof(Point));
    if (point != NULL) 
    {
        point->X = X;
        point->Y = Y;
    }
    return point;
}

Circle *createCircle(Point *center, Point *edge) 
{
    Circle *circle = (Circle *)malloc(sizeof(Circle));
    if(circle != NULL) 
    {
        circle->center = center;
        circle->edge = edge;
    }
    return circle;
}

Circle *createCircleXY(double centerX, double centerY, double edgeX, double edgeY) 
{
    Point *center = createPoint(centerX, centerY);
    Point *edge = createPoint(edgeX, edgeY);
    Circle *circle = createCircle(center, edge);
    return circle;
}

Circle *createArrCircle(Point *array[]) 
{
    Circle *arrayCircle = createCircle(*array, (*array + 1));
    return arrayCircle;
}

double radiusCircle(Circle *circle) 
{
    double radius;
    if (circle != NULL) 
    {
        radius = hypot(
            (circle->edge->X - circle->center->X),
            (circle->edge->Y - circle->center->Y)
        );
    }
    return radius;
}

double areaCircle(Circle *circle) {
    double radius;
    if(circle != NULL) 
    {
        radius = radiusCircle(circle);
        radius = acos(-1) * radius * radius;
    }
    return radius;
}

void printDetailCircle(Circle *circle) {
    if(circle != NULL) 
    {
        printf("\n");
        printf("Центральна точка: x = %.3lf; y = %.3lf\n", circle->center->X, circle->center->Y);
        printf("Крайня точка: x = %.3lf; y = %.3lf\n", circle->edge->X, circle->edge->Y);
        printf("Радіус: %.3lf\n", radiusCircle(circle));
        printf("Площа: %.3lf\n", areaCircle(circle));
        printf("\n");
    }
}

CircleArray *createCircleArray(int count) {
    CircleArray *array = (CircleArray *)malloc(sizeof(CircleArray));
    if (array != NULL) 
    {
        if (count == 0) 
        {
            printf("Count mustn't be 0!");
            return NULL;
        }
        array->count = abs(count);
        array->storage = (Circle **)malloc(sizeof(Circle *) * array->count);
        bzero(array->storage, sizeof(Circle *) * array->count);
    }
    return array;
};

int addCircleToArray(CircleArray *array, Circle *circle) {
    if (array == NULL) 
    {
        return CircleArrayIndexError;
	}
    int index;
    if (array->storage[array->count - 1] != NULL) 
    {
        printf("Максимальна кількість елементів масива!\n\n");
        return CircleArrayIndexError;
    }

    for (int i = 0; i < array->count; i++) 
    {
        if (array->storage[i] == NULL) 
        {
            array->storage[i] = circle;
            index = i;
            break;
        }
    }
    return index;
};

int setCircleAtIndex(CircleArray *array, Circle *circle, int index) {
    if (array == NULL || index < 0) 
    {
        return CircleArrayIndexError;
    }

    if (index >= array->count) 
    {
        if (CircleArrayIndexError == reallocateInternalStorage(array, index + 1)) 
        {
            return CircleArrayIndexError;
		    }
    }

    array->storage[index] = circle;
    return index;
};

Circle *getCircleAtIndex (CircleArray *array, int index) {
    if (array  == NULL || index < 0 || index >= array->count) 
    {
        return NULL;
    }

    return array->storage[index];
};

int countCircleArray(CircleArray *array) {
    if (array == NULL) 
    {
    return CircleArrayIndexError;
    }

    return array->count;
};

void printCircleArray(CircleArray *array) {
    if (array == NULL) 
    {
    return ;
    }

    for (int i = 0; i < array->count; i ++) 
    {
        if (array->storage[i] != NULL) 
        {
            printf("Індекс кола:  %d\n", i);
            printDetailCircle(array->storage[i]);
        } 
      else 
      {
            printf("NULL");
        }
    }
};

void deleteCircleArray(CircleArray *array) {
    if (array != NULL) 
    {
        if (array->storage != NULL) {
            free(array->storage);
        }
        free(array);
    }
};

long reallocateInternalStorage(CircleArray *array, int requestedCount) 
{
    if (array->count >= requestedCount) 
    {
        return array->count;
    }
    int count = requestedCount * 2;

    Circle **storage = (Circle **)malloc(sizeof(Circle *) * count);
    if (storage ==  NULL) 
    {
        return CircleArrayIndexError;
    }
    bzero(storage, sizeof(Circle *) * count);

    memcpy(storage, array->storage, sizeof(Circle *) * array->count);
    free(array->storage);

    array->storage = storage;
    array->count = count;

    return count;
}
