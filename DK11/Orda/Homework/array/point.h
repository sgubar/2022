#ifndef point_h
#define point_h

typedef struct tag_point
{
    int x;
    int y;
}Point;

Point *createPoint(int x, int y);
void deletPoint(Point *p);
void printPoint(Point *p);

Point *copyPoint(Point *p);
int isEqualPoint(Point *lp, Point *rp);


#endif
