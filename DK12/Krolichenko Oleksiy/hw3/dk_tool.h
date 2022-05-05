#define _CRT_SECURE_NO_WARNINGS

#ifndef dk_tool_h
#define dk_tool_h

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Line description
typedef struct tagEllipse
{
	Point* O;
	int R;
	int r;
}Ellipse;

// Init interface
Ellipse* createEllipse(Point* Centre, int* R, int* r);
void destroyEllipse(Ellipse* aEllipse);
float SquareOfEllipse(Ellipse* aEllipse);
void printEllipse(Ellipse* aEllipse);
void pointsJson(FILE* aFile, Point* aPoint);
void ellipsesJson(FILE* aFile, Ellipse* aEllipses);

#endif /* dk_tool_h */
