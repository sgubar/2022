#define Square
#include "square.h"
#include "point.h"
typedef struct point {
	double x;
	double y;
} Point;

typedef struct square {
	Point* a; 
	Point* b; 
} Square;

Point* point_create(const double x, const double y);

Square* square_create_arr(Point arr[]);
Square* square_create(Point* a , Point* b;
Square* square_create_xy(const double ax, const double ay, const double bx, const double by);
double square_area(Square* square);
void square_destroy(Square* square);
void square_info(Square* square);
SquareArray *create_square_array(int count);

int add_square_to_array(SquareArray *array, Square *circle);
int set_square_at_index(SquareArray *array, Square *square, int index);

Square *get_square_at_index (SquareArray *array, int index);

int count_square_array(SquareArray *array);
void print_square_array(SquareArray *array);
void delete_square_array(SquareArray *array);

#endif
