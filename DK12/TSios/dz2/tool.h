#ifndef tool_h
  #define tool_h
#include <stdio.h>

typedef struct tagPoint
{
	int x;
	int y;
}                    Point;

typedef struct tagSquare
{
	Point* A;
	Point* B;
}kvadrat;


kvadrat* createSquare(Point* A, Point* B);
kvadrat* createSquareWithCoordinate(int xA, int yA, int xB, int yB);
Point* createPointWithCoordinate(int x, int y);
Point* createPoint(Point* aPoint);
kvadrat* createSquareWithArrayOfPoint(Point* arrayOfPoint);

void destroySquare(kvadrat* aSquare);
void printSquare(kvadrat* aSquare);
float plOfsquare(kvadrat* aSquare);


#endif
