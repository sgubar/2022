#include <stdlib.h>
#include <stdio.h>

#include "square"

int main(void)
{
	Square* s1;
	Square* s2;
	Square* s3;

	Point* a = point_create(0, 0);
	Point* b = point_create(2, 2);
    s1 = square_create(a, b);
	s2 = square_create_xy(0, 0, 4, 4);
    
    Point arr[2];
	arr[0].x = 0;
	arr[0].y = 0;
	arr[1].x = 3;
	arr[1].y = 3;

	s3 = square_create_arr(arr);

	printf("S1:\n\n"); square_info(s1);
	printf("S1 AREA: %.2lf\n\n", square_area(s1));
	printf("S2:\n\n"); square_info(s2);
	printf("S2 AREA: %.2lf\n\n", square_area(s2));
	printf("S3:\n\n"); square_info(s1);
	printf("S3 AREA: %.2lf\n", squara_area(s3));

	square_destroy(s1);
	square_destroy(s2);
	free(s3);

	return ;
}
