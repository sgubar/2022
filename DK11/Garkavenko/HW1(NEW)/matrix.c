#include <stdio.h>
#include <stdlib.h>

// отримуємо дані від користувача
int enter_size_matrixrow() {
    int x;
    printf("Введіть кількість рядків матриці: ");
    scanf_s("%d", &x);
    return x;
}

int enter_size_matrixcol() {
    int y;
    printf("Введіть кількість стовпців матриці: ");
    scanf_s("%d", &y);
    printf("\n");
    return y;
}
// отримуємо числа від користувача і заповнюємо матриці

void enter_size_matrix1(int* m1, int x, int y) {
    printf("Enter the elements of the first matrix\n\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("[%d][%d] = ", i + 1, j + 1);
            scanf_s("%d", (m1 + i * y + j));
        }
    }
    printf("\n");
}

void enter_size_matrix2(int* m2, int x, int y) {

    printf("Enter the elements of the second matrix\n\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("[%d][%d] = ", i + 1, j + 1);
            scanf_s("%d", (m2 + i * y + j));
        }
    }

    printf("\n");
}
// додаємо матриці
void matrixsum(int* m1, int* m2, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            *(m1 + i * y + j) = *(m1 + i * y + j) + *(m2 + i * y + j);
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", *(m1 + i * y + j));
        }
        printf("\n");
    }
}
