#ifndef DK12_TOOL_H
#define DK12_TOOL_H

#endif //DK12_TOOL_H

typedef struct coordinates
{
    float x_crd;
    float y_crd;
}DK12_crd;

DK12_crd *CreateCrd(int Size_c);

float tru_scan();

void import(DK12_crd *rTriangle);

float calculate(DK12_crd *RCTriangle);