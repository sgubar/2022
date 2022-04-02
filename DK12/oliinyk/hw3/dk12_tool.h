#ifndef _DK12_TOOL_H
#define _DK12_TOOL_H

#define CircleArrayIndexError (-1)
typedef struct tag_point {
	double x;
	double y;
} Point;

typedef struct tag_circle {
	Point *center;
	Point *edge;
} Circle;

typedef struct tag_circleArray {
    Circle  **storage;
    int count;
} CircleArray;

Point *createPoint(double x, double y);

Circle *createCircle(Point *center, Point *edge);
Circle *createCircleXY(double centerX, double centerY, double edgeX, double edgeY);
Circle *createArrCircle(Point *array[]);

double radiusCircle(Circle *circle);
double areaCircle(Circle *circle);

void printDetailCircle(Circle *circle);

CircleArray *createCircleArray(int count);

int addCircleToArray(CircleArray *array, Circle *circle);
int setCircleAtIndex(CircleArray *array, Circle *circle, int index);

Circle *getCircleAtIndex (CircleArray *array, int index);

int countCircleArray(CircleArray *array);
void printCircleArray(CircleArray *array);
void deleteCircleArray(CircleArray *array);

#endif