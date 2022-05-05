#ifndef _DK_TOOL_H
#define _DK_TOOL_H

typedef struct tagPoint {
	int x;
	int y;
}Point;

typedef struct tagEllipse {
	Point* O;
	int R;
	int r;
}Ellipse;

Ellipse* createEllipse(Point* Centre, int* R, int* r);

float SquareOfEllipse(Ellipse* aEllipse);
void printEllipse(Ellipse* aEllipse);
void destroyEllipse(Ellipse* aEllipse);

#endif
