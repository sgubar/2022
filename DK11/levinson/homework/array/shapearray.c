#include <shapearray.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ArrayOfTrianglesPtr create_array(long capacity)
{
    ArrayOfTrianglesPtr arr = calloc(1, sizeof(ArrayOfTriangles));

    if(arr == NULL)
        return arr;
    
    arr->capacity = capacity;
    arr->data_ptr = calloc(capacity, sizeof(TrianglePtr));

    return arr;
};
void delete_array(ArrayOfTrianglesPtr arr)
{
    if(arr == NULL)
        return;
    
    if(arr->data_ptr != NULL)
    {
        free(arr->data_ptr);
        arr->data_ptr = NULL;
    }

    free(arr);
    arr = NULL;
};
int insert_at_index(ArrayOfTrianglesPtr arr, TrianglePtr tri, long index)
{
    if(!validate_index_access(arr, index))
        return 0;

    if(extend_array_storage(arr, 1) == -1)
        return 0;

    memmove(&arr->data_ptr[index+1], &arr->data_ptr[index], sizeof(TrianglePtr));

    arr->data_ptr[index] = tri;

    return 1;
};
int merge_arrays(ArrayOfTrianglesPtr dest, ArrayOfTrianglesPtr src, long index)
{

}
TrianglePtr get_at_index(ArrayOfTrianglesPtr arr, long index)
{
    if(!validate_index_access(arr, index))
        return NULL;

    return arr->data_ptr[index];
};
void print_array(ArrayOfTrianglesPtr arr);
long arrlength(ArrayOfTrianglesPtr arr);

#pragma region InternalUtilities
long extend_array_storage(ArrayOfTrianglesPtr arr, int extend_by)
{
    if(extend_by < 1 || !validate_array(arr))
    {
        printf("\nInvalid parameters passed to extend_array_storage().\n");
        return -1;
    }

    TrianglePtr *new = calloc(arr->capacity + extend_by, sizeof(TrianglePtr));

    if(new == NULL)
    {
        printf("\ncalloc() failed to allocate memory.\n");
        return -1;
    }

    memcpy(new, arr->data_ptr, arr->capacity * sizeof(TrianglePtr));
    free(arr->data_ptr);

    arr->data_ptr = new;
    arr->capacity += extend_by;

    return arr->capacity;
}
int validate_array(ArrayOfTrianglesPtr arr)
{
    if(arr == NULL || arr->data_ptr == NULL || arr->capacity < 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
};
int validate_index_access(ArrayOfTrianglesPtr arr, long index)
{
    if(arr->capacity <= index || index < 0)
    {
        printf("\nIndex access failed: index out of range.\n");
        return 0;
    }
    if(!array_is_valid(arr))
    {
        printf("\nIndex access failed: invalid array passed to funciton.\n");
        return 0;
    }

    return 1;
}
#pragma endregion