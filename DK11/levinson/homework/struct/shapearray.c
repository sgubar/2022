#include "shapearray.h"

#pragma region InternalUtilities

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
    if(!validate_array(arr))
    {
        printf("\nIndex access failed: invalid array passed to funciton.\n");
        return 0;
    }
    if(arr->capacity <= index || index < 0)
    {
        printf("\nIndex access failed: index out of range.\n");
        return 0;
    }
    
    return 1;
}
long extend_array_storage(ArrayOfTrianglesPtr arr, int extend_by)
{
    if(extend_by < 1 || !validate_array(arr))
    {
        printf("\nInvalid parameters passed to extend_array_storage().\n");
        return 0;
    }

    TrianglePtr *new = calloc(arr->capacity + extend_by, sizeof(TrianglePtr));

    if(new == NULL)
    {
        printf("\ncalloc() has failed to allocate memory.\n");
        return 0;
    }

    memcpy(new, arr->data_ptr, arr->capacity * sizeof(TrianglePtr));
    free(arr->data_ptr);

    arr->data_ptr = new;
    arr->capacity += extend_by;

    return arr->capacity;
}

#pragma endregion

ArrayOfTrianglesPtr create_array(long capacity)
{
    ArrayOfTrianglesPtr arr = calloc(1, sizeof(ArrayOfTriangles));

    if(arr == NULL)
        return arr;
    
    arr->capacity = capacity;
    arr->data_ptr = calloc(capacity, sizeof(TrianglePtr));

    return arr;
};
void free_array(ArrayOfTrianglesPtr arr)
{
    if(arr == NULL)
        return;
    
    free(arr->data_ptr);
    free(arr);

    arr->data_ptr = NULL;
    arr = NULL;
};
int insert_at_index(ArrayOfTrianglesPtr arr, TrianglePtr tri, long index)
{
    if(validate_index_access(arr, index) && arr->data_ptr[index] == NULL)
    {
        arr->data_ptr[index] = tri;
        tri = NULL;

        return 1;
    }
    if(!validate_array(arr))
    {
        return 0;
    }

    long extend_by = index <= arr->capacity ? 1 : index + 1 - arr->capacity;
    long shift = arr->capacity - index;

    if(!extend_array_storage(arr, extend_by))
    {
        return 0;
    }
    if(shift > 0)
    {
        memmove(&arr->data_ptr[index + 1], &arr->data_ptr[index], sizeof(TrianglePtr) * (shift));
    }

    arr->data_ptr[index] = tri;
    tri = NULL;

    return 1;
};
int merge_arrays(ArrayOfTrianglesPtr dest, ArrayOfTrianglesPtr src, long dest_index)
{
    if(!validate_array(dest) || !validate_array(dest) || !(dest_index >= 0))
    {
        return 0;
    }

    long i = 0;

    if(validate_index_access(dest, dest_index))
    {
        fill: ;
        for(i; i < src->capacity; i++)
        {
            if(dest->data_ptr[dest_index + i] != NULL)
            {
                goto shift;
            }

            dest->data_ptr[dest_index + i] = src->data_ptr[i];
        }

        free_array(src);

        return 1;
    }

    shift: ;
    long shift = src->capacity - i;

    if(extend_array_storage(dest, shift))
    {
        memmove(&dest->data_ptr[dest_index + src->capacity], &dest->data_ptr[dest_index + i], sizeof(TrianglePtr) * shift);
        goto fill;
    }
}
TrianglePtr get_at_index(ArrayOfTrianglesPtr arr, long index)
{
    if(!validate_index_access(arr, index))
        return NULL;

    return arr->data_ptr[index];
};
void print_array(ArrayOfTrianglesPtr arr)
{
    printf("\nArray contents: ");

    for(int i = 0; i < arr->capacity; i++)
    {
        if(i % 3 == 0)
            printf("\n");

        TrianglePtr current = arr->data_ptr[i];
        printf(" [%s] ", triangle_info(current));
    }

    printf("\nArray capacity: %li;\n", arr->capacity);
};

