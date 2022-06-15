#ifndef REC_H
#define REC_H

typedef struct tag_point {
    double x;
    double y;
} Point;

typedef struct tag_rectangle {
    Point *pt1;
    Point *pt2;
    double height;
    double width;
} Rectangle;

Point *createPoint(char s[]);

Rectangle *createRectangle(Point *p1, Point *p2);

int checkPoints(Point *pt1, Point *pt2);

double calculateArea(Rectangle *rec);

void deletePoint(Point *p);

void printRectangle(Rectangle *rec);

void deleteRectangle(Rectangle *rec);


#endif