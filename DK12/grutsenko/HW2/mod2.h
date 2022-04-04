#ifndef MOD2_H
#define MOD2_H

typedef struct point {
    double x;
    double y;
} Point;

typedef struct rectangle {
    Point *pt1;
    Point *pt2;
    double height;
    double width;
} Rectangle;

Point *createPoint(char s[]);

Rectangle *createRectangle(Point *p1, Point *p2);

void printPromptRec();

int checkPoints(Point *pt1, Point *pt2);

double calculateArea(Rectangle *rec);

void deletePoint(Point *p);

void deleteRectangle(Rectangle *rec);


#endif