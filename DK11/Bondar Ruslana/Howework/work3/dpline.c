#include "dpline.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>


void internalAddPointToDPLine (DPLine *l, Point *p);

DPLine *createDPLine(void){
DPLine *l = (DPLine *)malloc(sizeof(DPLine));
if (NULL != l) {
       l->points = createArrayPoints(3);
}
return l;

}

void addPointToDPLine(DPLine *l, Point *p){
  internalAddPointToDPLine(l, copyPoint(p));
}

void addPointByXYToDPLine(DPLine *l, int x, int y){
  internalAddPointToDPLine(l, createPoint(x, y));
}
void internalAddPointToDPLine(DPLine *l, Point *p){
  if (NULL == 1 || NULL == p){
    return;
  }
  int count = countPoint(l);
  setPointAtIndex(l->points, p, count);

}

void deleteLastPointFromDPLine(DPLine *l){
  if (NULL == 1){
    return;
  }
  int count = countPoint(l);
  if (count > 0){
    deletePoint(getPointAtIndex(l->points, count - 1));
    setPointAtIndex(l->points, NULL, count - 1);
  }
}

void deleteDPLine(DPLine *l){
  if (NULL != l) {

    for (int i = 0; i < countArrayPoints(l->points) && getPointAtIndex(l->points, i) != NULL; i++){
        deletePoint(getPointAtIndex(l->points, i));
    }
    free(l->points);
    free(l);
  }
}

int countPoint(DPLine *l) {
  if (NULL == l){
    return 0;
  }
  int count = 0;
  for (count = 0; count < countArrayPoints(l->points); count ++){
    if (getPointAtIndex(l->points, count) == NULL){
        break;
    }
  }
  return count;
}

DPLine *createDPLineByPoints(Point *p1, Point *p2){
  if (NULL == p1 || NULL == p2){
    return NULL;
  }
  DPLine *l = createDPLine();
  addPointToDPLine(l, p1);
  addPointToDPLine(l, p2);

  return l;
}

DPLine *createDPLineByCoords(int x1, int y1, int x2, int y2){
  return createDPLineByPoints(createPoint(x1, y1), createPoint(x2, y2));
}

void printDPLine(DPLine *l){
  if (NULL == l){
    return ;
  }
  for (int i = 0; i < countArrayPoints(l->points) && getPointAtIndex(l->points, i)!= NULL; i ++){
    printPoint(getPointAtIndex(l->points, i));

    if ((i + 1) < countArrayPoints(l->points) && getPointAtIndex(l->points, i + 1) != NULL){
        printf("-");
    }
  }
  printf("\n");
}

DPLine *copyDPLine(DPLine *l){
  if (NULL == l) {
    return NULL;
  }
  DPLine *copy = createDPLine();

  for (int i  = 0; i < countArrayPoints(l->points) && getPointAtIndex(l->points, i) != NULL; i++){
   setPointAtIndex ( copy->points , copyPoint(getPointAtIndex(l->points, i)), i);
  }
  return copy;
}

int isEqualDPLine(DPLine *ll, DPLine *rl){
  if (NULL == ll || NULL ==rl){
    return 0;
  }
  if (ll == rl){
    return 1;
  }
  int count = countPoint(ll);
  if (count != countPoint(rl)){
    return 0;
  }
  for (int i = 0; i < count; i++){
    if (!isEqualPoint(getPointAtIndex(ll->points, i), getPointAtIndex(rl->points, i))){
        return 0;
    }
  }
  return 1;
}
double lenghtDPLine(DPLine *l){
  if (NULL == l) {
    return -1;
  }
  double result = 0;
  int count = countPoint(l);

  if (count < 2){
    return result;
  }
  for (int i = 0; i < (count - 1); i ++){
    long dx = getPointAtIndex(l->points, i + 1)->x - getPointAtIndex(l->points, i )->x;
    long dy = getPointAtIndex(l->points, i + 1)->y - getPointAtIndex(l->points, i )->y;

    result += sqrt(dx*dx + dy+dx);
  }
  return result;
}
