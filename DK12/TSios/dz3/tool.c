#include "tool.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <strings.h>

long reallocateInternalStorage(KvadratArray *array, int requestedCount);

Kvadrat *createSquare(Point *A, Point *B)
{
    Kvadrat *theResult = NULL;

    if (NULL != A && NULL != B)
    {
        theResult = (Kvadrat *)malloc(sizeof(Kvadrat));
        if (NULL != theResult)
        {
            theResult->A = createPoint(A);
            theResult->B = createPoint(B);
        }
    }
    return theResult;
}

Kvadrat *createSquareWithArrayOfPoint(Point *arrayOfPoint)
{
    Kvadrat *theResult = (Kvadrat *)malloc(sizeof(Kvadrat));
    if (theResult != NULL)
    {
        theResult->A = createPoint(&arrayOfPoint[0]);
        theResult->B = createPoint(&arrayOfPoint[1]);
    }
    return theResult;
}

Kvadrat *createSquareWithCoordinate(int xA, int yA, int xB, int yB)
{
    Kvadrat *theResult = (Kvadrat *)malloc(sizeof(Kvadrat));

    if (theResult != NULL)
    {
        theResult->A = createPointWithCoordinate(xA, yA);
        theResult->B = createPointWithCoordinate(xB, yB);
    }

    return theResult;
}

Point *createPointWithCoordinate(int x, int y)
{
    Point *theResult = (Point *)malloc(sizeof(Point));
    if (theResult != NULL)
    {
        theResult->x = x;
        theResult->y = y;
    }
    return theResult;
}

Point *createPoint(Point *aPoint)
{
    Point *theResult = (Point *)malloc(sizeof(Point));
    if (NULL != theResult)
    {
        theResult->x = aPoint->x;
        theResult->y = aPoint->y;
    }
    return theResult;
}

void printSquare(Kvadrat *aSquare)
{
    if (NULL != aSquare)
    {
        printf("[Square]. A(%d,%d) B(%d,%d)\n",
               aSquare->A->x, aSquare->A->y,
               aSquare->B->x, aSquare->B->y);
    }
}

float plOfsquare(Kvadrat *aSquare)
{
    float result;
    if (aSquare != NULL)
    {
        float dx = (aSquare->B->x - aSquare->A->x);
        float dy = (aSquare->B->y - aSquare->A->y);
        result = sqrt(dx * dx + dy * dy) * 2;
        result *= result;
    }
    return result;
}

void destroySquare(Kvadrat *aSquare)
{
    if (aSquare != NULL)
    {
        free(aSquare->A);
        free(aSquare->B);
        free(aSquare);
    }
}


void printDetailKvadrat(Kvadrat *kvadrat) {
    if(kvadrat != NULL) {
        printf("\n");
        printf("Point A: x = %d; y = %d\n", kvadrat->A->x, kvadrat->A->y);
        printf("Point B: x = %d; y = %d\n", kvadrat->B->x, kvadrat->B->y);
        printf("Ploshad: %.3lf\n", plOfsquare(kvadrat));
        printf("\n");
    }
}

KvadratArray *createKvadratArray(int count) {
    KvadratArray *array = (KvadratArray *)malloc(sizeof(KvadratArray));
    if (array != NULL) {
        if (count == 0) {
            printf("Count mustn't be 0!");
            return NULL;
        }
        array->count = abs(count);
        array->storage = (Kvadrat **)malloc(sizeof(Kvadrat *) * array->count);
        bzero(array->storage, sizeof(Kvadrat *) * array->count);
    }
    return array;
};

int addKvadratToArray(KvadratArray *array, Kvadrat *kvadrat) {
    if (array == NULL) {
        return KvadratArrayIndexError;
	}
    int index;
    if (array->storage[array->count - 1] != NULL) {
        printf("Maximum count of elements in the array!\n\n");
        return KvadratArrayIndexError;
    }

    for (int i = 0; i < array->count; i++) {
        if (array->storage[i] == NULL) {
            array->storage[i] = kvadrat;
            index = i;
            break;
        }
    }
    return index;
};

int setKvadratAtIndex(KvadratArray *array, Kvadrat *kvadrat, int index) {
    if (array == NULL || index < 0) {
        return KvadratArrayIndexError;
    }

    if (index >= array->count) {
        if (KvadratArrayIndexError == reallocateInternalStorage(array, index + 1)) {
            return KvadratArrayIndexError;
		}
    }

    array->storage[index] = kvadrat;
    return index;
};

Kvadrat *getKvadratAtIndex (KvadratArray *array, int index) {
    if (array  == NULL || index < 0 || index >= array->count) {
        return NULL;
    }

    return array->storage[index];
};

int countKvadratArray(KvadratArray *array) {
    if (array == NULL) {
    return KvadratArrayIndexError;
    }

    return array->count;
};

void printKvadratArray(KvadratArray *array) {
    if (array == NULL) {
    return ;
    }

    for (int i = 0; i < array->count; i ++) {
        if (array->storage[i] != NULL) {
            printf("Kvadrat index:  %d\n", i);
            printDetailKvadrat(array->storage[i]);
        } else {
            printf("NULL");
        }
    }
};

void deleteKvadratArray(KvadratArray *array) {
    if (array != NULL) {
        if (array->storage != NULL) {
            free(array->storage);
        }
        free(array);
    }
};

long reallocateInternalStorage(KvadratArray *array, int requestedCount) {
    if (array->count >= requestedCount) {
        return array->count;
    }

    int count = requestedCount * 2;

    Kvadrat **storage = (Kvadrat **)malloc(sizeof(Kvadrat *) * count);
    if (storage ==  NULL) {
        return KvadratArrayIndexError;
    }

    bzero(storage, sizeof(Kvadrat *) * count);

    memcpy(storage, array->storage, sizeof(Kvadrat *) * array->count);
    free(array->storage);

    array->storage = storage;
    array->count = count;

    return count;
}
