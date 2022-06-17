#include <stdio.h>
#include "tools.h"

int main()
{

    // точки треугольника
    Point A = { 4,5 };
    Point B = { 1,1 };
    Point C = { 1,5 };

    // вызываем функцию создания треуголька с указанными точками
    RightTriangle* ABC = createRightTriangle(&A, &B, &C);

    // ошибка если треугольник не создался
    if (ABC == NULL)
        printf("Ошибка!\n");
    else // если все прошло
    {
        PrintRightTriangle(ABC); // принт точек треугольника функцией
        printf("S(ABC) = %.2f\n", (float)AreaOfRightTriangle(ABC)); // и площадь треугольника
    }

    destroyRightTriangle(ABC); // в конце разрушаем треугольник
}
