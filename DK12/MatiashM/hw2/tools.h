#ifndef tools_h
#define tools_h

typedef struct tag_point
{
    double x;
    double y;
} Point;

typedef struct tag_square
{
    Point *point1;
    Point *point2;
} Square;

Point *create_point(double x, double y);

Square *create_square(Point *point1, Point *point2);
Square *create_squareXY(double point1x, double point1y, double point2x, double point2y);
Square *create_arr_square(Point *array[]);

double area_square(Square *square);
void square_destroy(Square *square);
void square_info(Square *square, double area);

#endif