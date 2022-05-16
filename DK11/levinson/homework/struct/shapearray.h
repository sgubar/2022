#include "shapes.h"

typedef struct ArrayOfTriangles
{
    TrianglePtr *data_ptr;
    long capacity;
} ArrayOfTriangles, *ArrayOfTrianglesPtr;

ArrayOfTrianglesPtr create_array(long capacity);
int merge_arrays(ArrayOfTrianglesPtr dest, ArrayOfTrianglesPtr src, long dest_index);
int insert_at_index(ArrayOfTrianglesPtr arr, TrianglePtr tri, long index);
TrianglePtr get_at_index(ArrayOfTrianglesPtr arr, long index);
void free_array(ArrayOfTrianglesPtr arr);
void print_array(ArrayOfTrianglesPtr arr);