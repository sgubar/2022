#ifndef _DK12_TOOL_H
#define _DK12_TOOL_H

typedef struct tag_point {
	double x;
	double y;
} Point;

typedef struct tag_circle {
	Point *center;
	Point *edge;
} Circle;

Point *createPoint(double x, double y);

Circle *createCircle(Point *center, Point *edge);
Circle *createCircleXY(double centerX, double centerY, double edgeX, double edgeY);
Circle *createArrCircle(Point array[]);

double radiusCircle(Circle *circle);
double areaCircle(Circle *circle);
void destroyCircle(Circle *circle);
void printDetailCircle(int count, Circle *arrayCirles[]);

#endif