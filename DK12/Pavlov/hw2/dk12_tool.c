#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dk12_tool.h"

void checkTrapezoid(double point1x, double point1y, double point2x, double point2y, double point3x, double point3y, double point4x, double point4y)
// Чтобы проверить на параллельность запишите формулу для вычисления углового коэффициента. Формула имеет вид k = (y2 - y1)/(x2 - x1), У параллельных прямых коэф. k равен.
{
    if ((fabs(point2y - point1y) / fabs(point2x - point1x)) == fabs(point4y - point3y) / fabs(point4x - point3x) && fabs(point3y - point2y) / fabs(point3x - point2x) == fabs(point4y - point1y) / fabs(point4x - point1x))
    {
        printf("!EXIT PROGRAM!\nWRONG DATA (MORE THAN 2 SIDE's ARE ||)");
        exit(0);
    }
    else if ((fabs(point2y - point1y) / fabs(point2x - point1x)) != fabs(point4y - point3y) / fabs(point4x - point3x) && fabs(point3y - point2y) / fabs(point3x - point2x) != fabs(point4y - point1y) / fabs(point4x - point1x))
    {
        printf("!EXIT PROGRAM!\nWRONG DATA (NONE OF THE SIDE's ARE ||)");
        exit(0); 
    }
}

Point *createPoint(double x, double y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    if (point != NULL)
    {
        point->x = x;
        point->y = y;
    }
    return point;
}

Trapezoid *createTrapezoid(Point *point1, Point *point2, Point *point3, Point *point4)
{
    Trapezoid *trapezoid = (Trapezoid *)malloc(sizeof(Trapezoid));
    if (trapezoid != NULL)
    {
        trapezoid->point1 = point1;
        trapezoid->point2 = point2;
        trapezoid->point3 = point3;
        trapezoid->point4 = point4;
        checkTrapezoid(trapezoid->point1->x, trapezoid->point1->y, trapezoid->point2->x, trapezoid->point2->y, trapezoid->point3->x, trapezoid->point3->y, trapezoid->point4->x, trapezoid->point4->y);
    }
    return trapezoid;
}

Trapezoid *createTrapezoidXY(double point1x, double point1y, double point2x, double point2y, double point3x, double point3y, double point4x, double point4y)
{
    Point *point1 = createPoint(point1x, point1y);
    Point *point2 = createPoint(point2x, point2y);
    Point *point3 = createPoint(point3x, point3y);
    Point *point4 = createPoint(point4x, point4y);
    Trapezoid *trapezoid = createTrapezoid(point1, point2, point3, point4);
    return trapezoid;
}

Trapezoid *createArrayTrapezoid(Point *array[])
{
    checkTrapezoid((*array + 0)->x, (*array + 0)->y, (*array + 1)->x, (*array + 1)->y, (*array + 2)->x, (*array + 2)->y, (*array + 3)->x, (*array + 3)->y);
    Trapezoid *arrayTrapezoid = createTrapezoid(*array, (*array + 1), (*array + 2), (*array + 3));
    return arrayTrapezoid;
}

double areaTrapezoid(Trapezoid *trapezoid)
{   
    double s;
    double h;
    double lenghtB = hypot(fabs(trapezoid->point2->x - trapezoid->point3->x), fabs(trapezoid->point2->y - trapezoid->point3->y));
    double lenghtC = hypot(fabs(trapezoid->point3->x - trapezoid->point4->x), fabs(trapezoid->point3->y - trapezoid->point4->y));
    double lenghtD = hypot(fabs(trapezoid->point1->x - trapezoid->point4->x), fabs(trapezoid->point1->y - trapezoid->point4->y));
    double lenghtA = hypot(fabs(trapezoid->point1->x - trapezoid->point2->x), fabs(trapezoid->point1->y - trapezoid->point2->y));
    printf("%lf\n", lenghtA);
    printf("%lf\n", lenghtB);
    printf("%lf\n", lenghtC);
    printf("%lf\n", lenghtD);
    double a = fabs(trapezoid->point2->y - trapezoid->point1->y) / fabs(trapezoid->point2->x - trapezoid->point1->x);
    double b = fabs(trapezoid->point2->y - trapezoid->point3->y) / fabs(trapezoid->point2->x - trapezoid->point3->x);
    double c = fabs(trapezoid->point3->y - trapezoid->point4->y) / fabs(trapezoid->point3->x - trapezoid->point4->x);
    double d = fabs(trapezoid->point4->y - trapezoid->point1->y) / fabs(trapezoid->point4->x - trapezoid->point1->x);

    if (a == c)

    {
        // ищем длину отрезка по теореме Пифагора (1 катет по х, 2 катет по у)
        // формула высоты трапеции: sqrt(a^2-((d-b)^2+a^2-c^2)/2(d-b))^2
        // https://allcalc.ru/node/1024; - будь ласка, не задавайте більше таких завдань xD, виникли великі труднощі, бо постійно плутався через к-сть точок :0
        // s = h(a+b)/2
        h = pow(lenghtB, 2) - pow((pow((lenghtA - lenghtC), 2) + pow(lenghtB, 2) - pow(lenghtD, 2)) / (2 * (lenghtA - lenghtC)), 2);
        h = sqrt(h);
        s = (h * (lenghtA + lenghtC)) / 2;
    }
    else if (b == d)
    {
        h = pow(lenghtA, 2) - pow((pow((lenghtD - lenghtB), 2) + pow(lenghtA, 2) - pow(lenghtC, 2)) / (2 * (lenghtD - lenghtB)), 2);
        h = sqrt(h);
        s = (h * (lenghtB + lenghtD)) / 2.0;
    }
    return s;
}

void destroyTrapezoid(Trapezoid *trapezoid)
{
    free(trapezoid->point1);
    free(trapezoid->point2);
    free(trapezoid->point3);
    free(trapezoid->point4);
    free(trapezoid);
}

void infoTrapezoid(Trapezoid *trapezoid, double s)
{
    printf("First point: x = %.2lf; y = %.2lf\n", trapezoid->point1->x, trapezoid->point1->y);
    printf("Second point: x = %.2lf; y = %.2lf\n", trapezoid->point2->x, trapezoid->point2->y);
    printf("Third point: x = %.2lf; y = %.2lf\n", trapezoid->point3->x, trapezoid->point3->y);
    printf("Firth point: x = %.2lf; y = %.2lf\n", trapezoid->point4->x, trapezoid->point4->y);
    printf("Areo of the figure: %.2lf\n", s);
}
