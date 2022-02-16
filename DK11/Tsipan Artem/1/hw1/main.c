#include <stdio.h>
#include <stdlib.h>
#include "dktool.h"

int main()
{
    sorry();
    int size;
    int b;
    printf("Введіть висоту або довжину вашої квадратичної матриці: \n");
    scanf("%d", &size);
    int a[size][size];
    printf("Введіть кожне значення матриці через пробіл \n");
    for (int i = 0; i < size; ++i) {           // коритсувач вводить матрицю
        for (int j = 0; j < size; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Введіть множник: \n");
    scanf("%d", &b);                            // користувач вводить множник
    printf("Фінальна матриця: \n");
    for (int i = 0; i < size; ++i) {           // виводить на екран фінальну матрицю
        for (int j = 0; j < size; ++j) {
            printf("%d ", a[i][j] * b   );
        }
        printf("\n");
    }
    return 0;
}
