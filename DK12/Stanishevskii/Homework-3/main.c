#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tools.h"

int main()
{

    // ����� ������������
    Point A = { 4,5 };
    Point B = { 1,1 };
    Point C = { 1,5 };

    // �������� ������� �������� ���������� � ���������� �������
    RightTriangle* ABC = createRightTriangle(&A, &B, &C);
    RightTriangle* BCA = createRightTriangle(&B, &C, &A);
    RightTriangle* CBA = createRightTriangle(&C, &B, &A);

    // ������ ���� ����������� �� ��������
    if (ABC == NULL)
        printf("������!\n");
    else // ���� ��� ������
    {
        PrintRightTriangle(ABC); // ����� ����� ������������ ��������
        printf("S(ABC) = %.2f\n", (float)AreaOfRightTriangle(ABC)); // � ������� ������������
    }

    destroyRightTriangle(ABC); // � ����� ��������� �����������

    
    Array arr;
    RightTriangle triangles[] = {ABC, BCA};
    arr.elements = triangles;
    destroyArray(arr.elements);
    addElementToArray(arr.elements, CBA);
    addIndexElement(arr.elements, ABC, 0);
    display(arr.elements);

}

