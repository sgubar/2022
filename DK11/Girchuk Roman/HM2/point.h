#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

typedef struct tag_point {
   int x;
   int y;
}Point;

Point *createPoint(int x, int y);
void deletePoint (Point *p);
void printPoint (Point *p);
Point *copyPoint(Point *p);
int isEqualPoint (Point *lp, Point *rp);

#endif // POINT_H_INCLUDED
