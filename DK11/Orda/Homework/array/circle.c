#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "circle.h"

int input_coord(int a){
    int A;
    printf ("Координата точки %i = ", a);
    scanf("%d",  &A);

    return A;
}

int input_radius(){
    int A;
    printf("Радіус кола = ");
    scanf("%d", &A);

    return A;
}

Circle *copyCircle(Circle *c){
    if (NULL == c){
        return NULL;
    }

    return createCircleByCoords(c->A->x, c->A->y, c->r);
}

Circle *createCircleByPoints(Point *p1, int r){
    if(NULL == p1 || NULL == r){
        return NULL;
    }
    Circle *c = (Circle *)malloc(sizeof(Circle));
    if (NULL != c) {
        c->A = copyPoint(p1);
        c->r = r;
    }
    return c;
}

Circle *createCircleByCoords (int x1, int y1, int r){
    Circle *c = (Circle *)malloc(sizeof(Circle));
    if (NULL != c) {
        c->A = createPoint(x1, y1);
        c->r = r;
    }
    return c;
}

Circle *createCircle(void){
    Circle *c = (Circle *)malloc(sizeof(Circle));
    if (c != NULL){
        bzero(c, sizeof(Circle));
    }

    return c;
}

void printCircle(Circle *c){
    if (NULL != c){
        printPoint(c->A);
        printf(" - ");
        printf("%d", c->r);
    }
}

double circle_area(Circle *c){
    if (NULL == c){
        return -1;
    }
    long radius = c -> r;
    return 3.14*radius*radius;
}

void deleteCircle(Circle *c){
    if (NULL != c){
        deletPoint(c->A);
        free(c);
    }
}
