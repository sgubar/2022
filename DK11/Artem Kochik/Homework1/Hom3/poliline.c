#include "polyline.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
PolyLine *createLine(void){
 PolyLine *1 = (PolyLine *)malloc(sizeof(PolyLine));
 if( NULL !=1) {
  bzero (l, sizeof (PolyLine));
 }
 return ;
}
void addPoint (PolyLine *1, Point *p);{
    if( NULL == 1){
        return ;
    }
    int count = countPoints(1);
    if (count < MAX_POINTS){
        1->points[count]= copyPoint(p);
        count ++
    }
}
int countPoints(PolyLine *1);{
    if( NULL == 1){
        return ;
}
 int count = 0;
 for(count = 0; count< MAX_POINTS;  ++ count  ){
     if (1-> points(count) == NULL ){
         break ;

    }
 }

