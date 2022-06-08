#ifndef tool_h
#define tool_h

#define KvadratArrayIndexError (-1)
typedef struct tagPoint
{
    int x;
    int y;
} Point;

typedef struct tagSquare
{
    Point *A;
    Point *B;
} Kvadrat;

typedef struct tagKvadratArray
{
    Kvadrat **storage;
    int count;
} KvadratArray;

Kvadrat *createSquare(Point *A, Point *B);
Kvadrat *createSquareWithCoordinate(int xA, int yA, int xB, int yB);
Point *createPointWithCoordinate(int x, int y);
Point *createPoint(Point *aPoint);
Kvadrat *createSquareWithArrayOfPoint(Point *arrayOfPoint);

void destroySquare(Kvadrat *aSquare);
void printSquare(Kvadrat *aSquare);
float plOfsquare(Kvadrat *aSquare);


void printDetailKvadrat(Kvadrat *Kvadrat);
KvadratArray *createKvadratArray(int count);

int addKvadratToArray(KvadratArray *array, Kvadrat *Kvadrat);
int setKvadratAtIndex(KvadratArray *array, Kvadrat *Kvadrat, int index);

Kvadrat *getKvadratAtIndex(KvadratArray *array, int index);

int countKvadratArray(KvadratArray *array);
void printKvadratArray(KvadratArray *array);
void deleteKvadratArray(KvadratArray *array);

#endif
