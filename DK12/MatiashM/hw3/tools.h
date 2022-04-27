#ifndef tools_h
#define tools_h
#define SquareArrayIndexError (-1)

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

typedef struct tag_square_array
{
    Square  **storage;
    int count;
} SquareArray;

Point *create_point(double x, double y);

Square *create_square(Point *point1, Point *point2);
Square *create_squareXY(double point1x, double point1y, double point2x, double point2y);
Square *create_arr_square(Point *array[]);

double area_square(Square *square);
void square_destroy(Square *square);
void square_info(Square *square);

SquareArray *create_square_array(int count);

int add_square_to_array(SquareArray *array, Square *circle);
int set_square_at_index(SquareArray *array, Square *square, int index);

Square *get_square_at_index (SquareArray *array, int index);

int count_square_array(SquareArray *array);
void print_square_array(SquareArray *array);
void delete_square_array(SquareArray *array);

#endif