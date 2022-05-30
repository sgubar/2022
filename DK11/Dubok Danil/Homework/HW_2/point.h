#ifndef point_h
#define point_h

typedef struct inf_p
{
      int x;
      int y;
} IP;

IP *createPoint(int x, int y);
void delitPoint(IP *q);
void printPoint(IP *q);
IP *copyPoint(IP *q);

#endif