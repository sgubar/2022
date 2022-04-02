#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>

#include "dk12_tool.h"

long reallocateInternalStorage(CircleArray *array, int requestedCount);

Point *createPoint(double x, double y) {
	Point *point = (Point *)malloc(sizeof(Point));
	if (point != NULL) {
        point->x = x;
        point->y = y;
    }
	return point;
}

Circle *createCircle(Point *center, Point *edge) {
	Circle *circle = (Circle *)malloc(sizeof(Circle));
	if(circle != NULL) {
        circle->center = center;
        circle->edge = edge;
    }
	return circle;
}

Circle *createCircleXY(double centerX, double centerY, double edgeX, double edgeY) {
	Point *center = createPoint(centerX, centerY);
	Point *edge = createPoint(edgeX, edgeY);
	Circle *circle = createCircle(center, edge);
	return circle;
}

Circle *createArrCircle(Point *array[]) {
	Circle *arrayCircle = createCircle(*array, (*array + 1));
	return arrayCircle;
}

double radiusCircle(Circle *circle) {
    double radius;
    if (circle != NULL) {
        radius = hypot(
            (circle->edge->x - circle->center->x),
            (circle->edge->y - circle->center->y)
        );
    }
    return radius;
}

double areaCircle(Circle *circle) {
    double radius;
    if(circle != NULL) {
        radius = radiusCircle(circle);
        radius = acos(-1) * radius * radius;
    }
    return radius;
}

void printDetailCircle(Circle *circle) {
    if(circle != NULL) {
        printf("\n");
        printf("Center point: x = %.3lf; y = %.3lf\n", circle->center->x, circle->center->y);
        printf("Edge point: x = %.3lf; y = %.3lf\n", circle->edge->x, circle->edge->y);
        printf("Radius: %.3lf\n", radiusCircle(circle));
        printf("Area: %.3lf\n", areaCircle(circle));
        printf("\n");
    }
}

CircleArray *createCircleArray(int count) {
    CircleArray *array = (CircleArray *)malloc(sizeof(CircleArray));
    if (array != NULL) {
        if (count == 0) {
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
    if (array == NULL) {
		return CircleArrayIndexError;
	}
    int index;
    if (array->storage[array->count - 1] != NULL) {
        printf("Maximum count of elements in the array!\n\n");
        return CircleArrayIndexError;
    }

    for (int i = 0; i < array->count; i++) {
        if (array->storage[i] == NULL) {
            array->storage[i] = circle;
            index = i;
            break;
        }
    }
    return index;
};

int setCircleAtIndex(CircleArray *array, Circle *circle, int index) {
    if (array == NULL || index < 0) {
		return CircleArrayIndexError;
	}

	if (index >= array->count) {
		if (CircleArrayIndexError == reallocateInternalStorage(array, index + 1)) {
			return CircleArrayIndexError;
		}
	}

	array->storage[index] = circle;
	return index;
};

Circle *getCircleAtIndex (CircleArray *array, int index) {
    if (array  == NULL || index < 0 || index >= array->count) {
		return NULL;
	}

	return array->storage[index];
};

int countCircleArray(CircleArray *array) {
    if (array == NULL) {
		return CircleArrayIndexError;
	}

	return array->count;
};

void printCircleArray(CircleArray *array) {
    if (array == NULL) {
		return ;
	}

	for (int i = 0; i < array->count; i ++) {
		if (array->storage[i] != NULL) {
			printf("Circle index:  %d\n", i);
			printDetailCircle(array->storage[i]);
		} else {
			printf("NULL");
		}
	}
};

void deleteCircleArray(CircleArray *array) {
    if (array != NULL) {
		if (array->storage != NULL) {
			free(array->storage);
		}
		free(array);
	}
};

long reallocateInternalStorage(CircleArray *array, int requestedCount) {
	if (array->count >= requestedCount) {
		return array->count;
	}

	int count = requestedCount * 2;

	Circle **storage = (Circle **)malloc(sizeof(Circle *) * count);
	if (storage ==  NULL) {
		return CircleArrayIndexError;
	}

	bzero(storage, sizeof(Circle *) * count);

	memcpy(storage, array->storage, sizeof(Circle *) * array->count);
	free(array->storage);

	array->storage = storage;
	array->count = count;

	return count;
}