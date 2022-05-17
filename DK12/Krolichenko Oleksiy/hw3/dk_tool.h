#define _CRT_SECURE_NO_WARNINGS

#ifndef dk_tool_h
#define dk_tool_h


typedef struct tagPoint {
	int x;
	int y;
}Point;


typedef struct tagEllipse {
	Point* O;
	int r;
	int R;
}Ellipse;


Ellipse* createEllipse(Point* Centre, int r, int R);
void destroyEllipse(Ellipse* el);
float SquareOfEllipse(Ellipse* el);
void printEllipse(Ellipse* el);

#endif 
