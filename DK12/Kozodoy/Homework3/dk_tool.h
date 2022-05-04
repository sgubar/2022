#ifndef dk_tool_h
#define dk_tool_h

typedef struct tag_point
{
	double x;
	double y;
} Point;

typedef struct tag_circle 
{
	Point* center;
	double radius;
} Circle;

typedef struct tag_circleArr
{
	Circle** arr;
	int size;
} CircleArr;

Point* createPoint(double x, double y);
Circle* createCircle(Point* center, double radius);
Circle* createCirclePoints(Point* center, Point* radius);
Circle* createCircleCoord(double centerX, double centerY, double x, double y);
CircleArr* createCircleArr(int size);

int addCircleToArray(CircleArr* array, Circle* circle);
int addCircleAtIndex(CircleArr* array, Circle* circle, int index);

double areaCircle(Circle* circle);
void destroyCircle(Circle* circle);
void destroyCircleArr(CircleArr* array);

void infoCircle(Circle* circle);
void infoCircleArr(CircleArr* array);

#endif // !1