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

#endif 
