#include "shapearray.h"

int main(void)
{
    PointPtr origin = create_point(0, 0);
    PointPtr a = create_point(5, 0);
    PointPtr b = create_point(0, 10);
    LinePtr s_a = create_line_pts(a, b);
    LinePtr s_b = create_line_pts(a, origin);
    TrianglePtr trn1 = create_triangle_LL(s_a, s_b);
    printf("area: %f \n", calculate_triangle_area(trn1));
    free_line(s_a);
    free_line(s_b);
    free_point(origin);

    PointPtr c = create_point(2, 5);
    PointPtr d = create_point(3, 6);
    PointPtr e = create_point(6, 4);
    TrianglePtr trn2 = create_triangle_PPP(c, d, e);
    free_point(c);
    free_point(d);
    free_point(e);

    PointPtr f = create_point(1, 1);
    PointPtr g = create_point(4, 1);
    PointPtr h = create_point(1, 2);
    TrianglePtr trn3 = create_triangle_PPP(f, g, h);
    free_point(f);
    free_point(g);
    free_point(h);

    PointPtr i = create_point(7, 7);
    PointPtr a_cpy = cpy_point(a);
    PointPtr b_cpy = cpy_point(b);
    TrianglePtr trn4 = create_triangle_PPP(i, a_cpy, b_cpy);
    free_point(a);
    free_point(a_cpy);
    free_point(b);
    free_point(b_cpy);
    free_point(i);
    

    TrianglePtr trn5 = cpy_tringle(trn3);

    LinePtr j_k = create_line_coord(0, 1, 5, 5);
    LinePtr l_m = create_line_coord(0, 1, 0, 4);
    TrianglePtr trn6 = create_triangle_LL(j_k, l_m);
    free_line(j_k);
    free_line(l_m);
    
    ArrayOfTrianglesPtr array1 = create_array(3);
    print_array(array1);
    insert_at_index(array1, trn1, 0);
    print_array(array1);
    insert_at_index(array1, trn2, 1);
    insert_at_index(array1, trn3, 2);
    print_array(array1);
    insert_at_index(array1, trn4, 5);
    insert_at_index(array1, cpy_tringle(trn1), 6);
    printf("\nARRAY 1\n");
    print_array(array1);

    ArrayOfTrianglesPtr array2 = create_array(3);
    insert_at_index(array2, trn5, 0);
    insert_at_index(array2, trn6, 1);
    insert_at_index(array2, cpy_tringle(trn4), 2);
    printf("\nARRAY 2\n");
    print_array(array2);

    merge_arrays(array1, array2, 4);
    printf("\nARRAY 1 (MERGED)\n");
    print_array(array1);
    
    
    free_triangle(trn1);
    free_triangle(trn2);
    free_triangle(trn3);
    free_triangle(trn4);
    free_triangle(trn5);
    free_triangle(trn6);
    free_array(array1);
    free_array(array2);
}

