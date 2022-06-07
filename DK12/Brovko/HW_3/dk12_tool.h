#include <stdio.h>
#include <malloc.h>


typedef struct coordinates
{
    float x_crd;
    float y_crd;
}DK12_crd;

typedef struct st_triangle
{
    DK12_crd A_Vertex;
    DK12_crd B_Vertex;
    DK12_crd C_Vertex;
}triangle_str;

float calculate(DK12_crd RCTriangle0, DK12_crd RCTriangle1, DK12_crd RCTriangle2);

void read_coor(DK12_crd *rTriangle, char index, int i);
//void read_coor(triangle_str *rTriangle, char dindex, int i);

void print_triangl(DK12_crd *rTriangle, char dindex, int dnumber);

void write_dot(FILE *aFile, DK12_crd dArray, char index);

void write_triangle(FILE *aFile, triangle_str dTriangle, int index, int allsize);

void Write_all(FILE *File_main, int long_array, triangle_str *Triangle);