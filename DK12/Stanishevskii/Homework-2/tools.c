#include "tools.h"

// создание треугольника
RightTriangle* createRightTriangle(Point* A, Point* B, Point* C)
{
    RightTriangle* theResult = NULL;

    if (A != NULL && B != NULL && C != NULL) // если точки не пустые
    {
        if (abs(A->y) == abs(C->y) && abs(C->x) == abs(B->x)) // проверяем по условию прямоугольности
        {
            theResult = (RightTriangle*)malloc(sizeof(RightTriangle)); // выделяем память

            if (theResult != NULL) // если выделили
            {
                theResult->A = A;
                theResult->B = B;
                theResult->C = C;
            }
        }
        else
            printf("The triangle is not rectangular!\n");

    }
    return theResult; // возвращаем треугольник
}

//Функция площади
int AreaOfRightTriangle(RightTriangle* aTriangle)
{
    int theResult = 0; 

    if (aTriangle != NULL) // если получили не пустой треугольник
    {
        // находим длинну первой и второй стороны
        int FirstSide = (float)sqrt(pow(aTriangle->B->x - aTriangle->C->x, 2) + pow(aTriangle->B->y - aTriangle->C->y, 2));
        int SecondSide = (float)sqrt(pow(aTriangle->A->x - aTriangle->C->x, 2) + pow(aTriangle->A->y - aTriangle->C->y, 2));

        // формула высчитываем площадь
        theResult = (FirstSide * SecondSide) / 2;
    }

    return theResult; 
}

// выводим точки треугольнка
void PrintRightTriangle(RightTriangle* aTriangle)
{
    if (NULL != aTriangle) // если получили не пустой треугольник
    {
        printf("Coordinates of vertices:\nA(%d,%d)\nB(%d,%d)\nC(%d,%d)\n\n",
            aTriangle->A->x, aTriangle->A->y, aTriangle->B->x, aTriangle->B->y, aTriangle->C->x, aTriangle->C->y); // выводим в консоль координаты
    }
}

// разрушение
void destroyRightTriangle(RightTriangle* aTriangle)
{
    if (aTriangle != NULL) // если получили не пустой треугольник
    {
        free(aTriangle); // и высвобождаем память всего треугольника
    }
}
