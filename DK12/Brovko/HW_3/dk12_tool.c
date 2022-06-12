
#include <stdio.h>
#include "dk12_tool.h"
#include <stdlib.h>
#include <string.h>


float read_tru(float min_s, float max_s);

float read_tru(float min_s, float max_s)
{
    float sc_sym;
    int t;
    do
    {
        t=scanf("%f",&sc_sym);
        fflush(stdin);
        if(t!=1 || sc_sym<min_s || sc_sym>max_s) printf("%s","Invalid input. Try again.\n");
    }
    while(t!=1 || sc_sym<min_s || sc_sym>max_s);
    return sc_sym;
}

void read_coor(DK12_crd *rTriangle, char dindex, int i)
{
    printf("Please enter tgiangle number %i dot %c  (-100000.000; 100000.000)\n", i+1, dindex);
    rTriangle->x_crd = read_tru(-100000.000, 100000.000);
    rTriangle->y_crd = read_tru(-100000.000, 100000.000);
    return;
}

void print_triangl(DK12_crd *rTriangle, char dindex, int dnumber)
{
    printf("Triangl: %i Vertex: %c (%f ; %f)\n",dnumber+1,dindex, rTriangle->x_crd, rTriangle->y_crd);
    return;
}


//calculate area triangl
float calculate(DK12_crd RCTriangle0, DK12_crd RCTriangle1, DK12_crd RCTriangle2)
{
    float rez=((RCTriangle0.x_crd-RCTriangle2.x_crd)*(RCTriangle1.y_crd - RCTriangle2.y_crd) - (RCTriangle1.x_crd - RCTriangle2.x_crd) * (RCTriangle1.y_crd - RCTriangle2.y_crd))/(float)2;
    if(rez<0)rez = rez * (-1);
    return rez;
}

void write_dot(FILE *aFile, DK12_crd dArray, char index)
{
    fprintf(aFile, "\"%c\" : {\n", index);

    fprintf(aFile, "\"X\" : %f,\n", dArray.x_crd);

    fprintf(aFile, "\"Y\" : %f\n", dArray.y_crd);

    if (index=='C')  fprintf (aFile, "}\n");
                else fprintf (aFile, "},\n");
    //fprintf (aFile, "}\n");
}

void write_triangle(FILE *aFile, triangle_str dTriangle, int index, int allsize)
{
    fprintf(aFile, "\"Triangl number %i\" : ", index+1);
    fprintf(aFile, "{\n");

    write_dot(aFile, dTriangle.A_Vertex, 'A');
    write_dot(aFile, dTriangle.B_Vertex, 'B');
    write_dot(aFile, dTriangle.C_Vertex, 'C');

    if (index==(allsize-1))  fprintf (aFile, "}\n");
                else fprintf (aFile, "},\n");
}


void Write_all(FILE *File_main, int long_array, triangle_str *Triangle)
{
    fprintf (File_main, "{\n");
    fprintf(File_main, "\"Triangls\" : [\n");
    for (int i = 0; i < long_array; ++i) {
        write_triangle(File_main, Triangle[i], i, long_array);
    }

    fprintf (File_main, "]\n}\n");
}