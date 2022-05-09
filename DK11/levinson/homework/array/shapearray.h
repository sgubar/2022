#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

typedef struct ArrayOfTriangles
{
    TrianglePtr *data_ptr;
    long capacity;
} ArrayOfTriangles, *ArrayOfTrianglesPtr;

ArrayOfTrianglesPtr create_array(long capacity);
void delete_array(ArrayOfTrianglesPtr arr);
int insert_at_index(ArrayOfTrianglesPtr arr, TrianglePtr tri, long index);
int merge_arrays(ArrayOfTrianglesPtr dest, ArrayOfTrianglesPtr src, long index);
TrianglePtr get_at_index(ArrayOfTrianglesPtr arr, long index);
void print_array(ArrayOfTrianglesPtr arr);
long arrlength(ArrayOfTrianglesPtr arr);