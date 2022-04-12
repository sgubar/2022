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

Point* createPoint(double x, double y);
Circle* createCircle(Point* center, double radius);
Circle* createCirclePoints(Point* center, Point* radius);
Circle* createCircleCoord(double centerX, double centerY, double x, double y);

double areaCircle(Circle* circle);
void destroyCircle(Circle* circle);
void infoCircle(Circle* circle);

#endif // !1
