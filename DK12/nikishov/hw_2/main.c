#include <stdlib.h>
#include <stdio.h>

#include "figure.h"

int main(void)
{
	Square* s1;
	Square* s2;
	Square* s3;
	
	/* First square: two points. */
	Point* a = pt_create(0, 0);
	Point* b = pt_create(2, 2);

	s1 = sq_create(a, b);
	
	/* Second square: coordinates. */
	s2 = sq_create_xy(0, 0, 4, 4);

	/* Third square: array of points. */
	Point arr[2];
	arr[0].x = 0;
	arr[0].y = 0;
	arr[1].x = 3;
	arr[1].y = 3;

	s3 = sq_create_arr(arr);

	printf("S1:\n\n"); sq_info(s1);
	printf("S1 AREA: %.2lf\n\n", sq_area(s1));
	printf("S2:\n\n"); sq_info(s2);
	printf("S2 AREA: %.2lf\n\n", sq_area(s2));
	printf("S3:\n\n"); sq_info(s1);
	printf("S3 AREA: %.2lf\n", sq_area(s3));

	sq_destroy(s1);
	sq_destroy(s2);
	free(s3); // sq_destroy call will result in an eror with s3.

	return EXIT_SUCCESS;
}

