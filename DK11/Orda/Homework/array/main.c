#include <stdio.h>
#include <stdlib.h>

#include "circle.h"
#include "array.h"
#include "point.h"

int main()
{
    int x = input_coord(1);
    int y = input_coord(2);
    int r = input_radius();

    Circle *c = createCircleByCoords(x, y, r);
    printf("Коло: ");
    printCircle(c);
    printf("\nПлощею %0.2f\n", circle_area(c));

    Storage *s = createStorage(2);
    printStorage(s);

    setCircleByIndex(s, c, 0);
    printStorage(s);

    setCircleByIndex(s, c, 4);
    printStorage(s);

    deleteCircle(c);
    deleteStorage(s);
}
