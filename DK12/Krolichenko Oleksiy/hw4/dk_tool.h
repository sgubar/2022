#ifndef _DK_TOOL_H
#define _DK_TOOL_H

typedef struct tagPoint {
	int x;
	int y;
}Point;

typedef struct tagEllipse {
	Point* O;
	int r;
	int R;
}Ellipse;

Ellipse* createEllipse(Point* Centre, int* r, int* R);

float SquareOfEllipse(Ellipse* aEllipse);
void printEllipse(Ellipse* aEllipse);
void destroyEllipse(Ellipse* aEllipse);

#endif
