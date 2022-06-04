#include "stdio.h"
#include "dk12_tool.h"
#include "stdlib.h"
#include "string.h"


DK12_crd *CreateCrd(int Size_c)
{
    DK12_crd *Triangle = (DK12_crd *) malloc(Size_c * sizeof(DK12_crd));
    if(NULL != Triangle)
    {
        memset(Triangle, 0, Size_c * sizeof(DK12_crd));


    }

    return Triangle;
}

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

void import(DK12_crd *rTriangle)
{
    if (NULL != rTriangle) {
        char mas[3] = {'A', 'B', 'C'};
        for (int i = 0; i < 3; ++i) {
            printf("Please enter dot %c (-100000.000; 100000.000)", mas[i]);
            rTriangle[i].x_crd = read_tru(-100000.000, 100000.000);
            rTriangle[i].y_crd = read_tru(-100000.000, 100000.000);
        }
    }
}

float calculate(DK12_crd *RCTriangle)
{
    char mas[3] = {'A', 'B', 'C'};
    for (int i = 0; i < 3; ++i) {
        printf("%c (%f ; %f)\n",mas[i], RCTriangle[i].x_crd, RCTriangle[i].y_crd);
    }
    float rez=(((RCTriangle+0)->x_crd-(RCTriangle+2)->x_crd)*((RCTriangle+1)->y_crd - (RCTriangle+2)->y_crd) - ((RCTriangle+1)->x_crd - (RCTriangle+2)->x_crd) * ((RCTriangle+1)->y_crd - (RCTriangle+2)->y_crd))/(float)2;
    if(rez<0)rez = rez * (-1);
    return rez;
}