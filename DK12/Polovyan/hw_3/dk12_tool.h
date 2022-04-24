#ifndef _DK12_TOOL_H
#define _DK12_TOOL_H

typedef struct tag_point {
	double x;
	double y;
} Point;

typedef struct tag_circle {
	Point *center;
	Point *edge_a;
	Point *edge_b;
} Elips;

typedef struct tag_elipsArray {
    Elips  **storage;
    int count;
} ElipsArray;

Point *createPoint(double x, double y);
Elips *createElips(Point *center, Point *edge_a, Point *edge_b);
Elips *createElipsXY(double centerX, double centerY, double edge_aX, double edge_aY, double edge_bX, double edge_bY);
Elips *createArrElips(Point *array[]);

double areaElips(Elips *elips);
double hypotElips(Elips *elips);

//===========================================================================================================================//
// 2-га частина
void printDetailCircle(Elips *elips);

 ElipsArray *createElipsArray(int count);
 int addElipsToArray(ElipsArray *array, Elips *elips);
 int setElipsAtIndex(ElipsArray *array, Elips *elips, int index);

 Elips *getElipsByIndex (ElipsArray *array, int index);

 int countElipsArray(ElipsArray *array);
 void printElipsArray(ElipsArray *array);
 void deleteElipsArray(ElipsArray *array);
//===========================================================================================================================//

#endif

