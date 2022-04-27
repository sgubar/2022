#ifndef tool_h
#define tool_h

typedef struct point {
	int x;
	int y;
}Point;

typedef struct sqere {
	Point* A;
	Point* B;
	Point* C;
	Point* D;
}Sqere;

double tool(Sqere* Sqere);

void free_all(Sqere* Sqere);

#endif