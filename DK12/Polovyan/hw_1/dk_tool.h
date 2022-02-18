#include <stdio.h>

#ifndef _DK_TOOL_H
#define _DK_TOOL_H

#ifdef __cplusplus
extern "C" {
#endif
          
    int get_N();
    
    int get_matrix1(int n, int arr1[n*n]);
    int get_matrix2(int n, int arr2[n*n]);
    
    void print_matrix1(int n, int arr1[]);
    void print_matrix2(int n, int arr2[]);
    
    void print_matrix3(int n, int arr1[], int arr2[], int arr3[]);

#ifdef __cplusplus
}
#endif

#endif
