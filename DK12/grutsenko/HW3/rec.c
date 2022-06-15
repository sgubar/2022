#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "rec.h"
#include "m.h"


Point *createPoint(char s[]) {
	double x, y;
	printf("%s: ", s);
    scanf("%lf,%lf", &x, &y);
    Point *p = (Point*)malloc(sizeof(Point));
    if (p != NULL) {
		p->x = x;
		p->y = y;
	}
    return p;
}

Rectangle *createRectangle(Point *p1, Point *p2) {
	Rectangle *rec = (Rectangle*)malloc(sizeof(Rectangle));
	if (rec != NULL) {
		rec->pt1 = p1;
		rec->pt2 = p2;
        rec->height = abs_extend(rec->pt2->y - rec->pt1->y);
		rec->width = abs_extend(rec->pt2->x - rec->pt1->x);
	}
	return rec;
}

void deletePoint(Point *p) {
	va_list valist;

	if (p != NULL) {
		free(p);
	}
}

void printRectangle(Rectangle *rec) {
	if(NULL != rec) {
		printf("Width: %f\n", rec->width);
		printf("Height: %f\n", rec->height);
	}
}

void deleteRectangle(Rectangle *rec) {
	if (NULL != rec) {
		free(rec);
	}
}

int checkPoints(Point *pt1, Point *pt2) {
	if(pt1 != NULL || pt2 != NULL) {
		if (pt1->x >= pt2->x || pt1->y >= pt2->y) {
			return 0;
		} else return 1;			
	}
}

double calculateArea(Rectangle *rec) {
	return rec->height *= rec->width;
}


