#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tools.h"

void print_mat(double* mat, int width, int height, int limit)
{
    int i = 0;
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            if(i == limit) return;
            printf("%-5.1lf ", *(mat + i++));
        }
        printf("\n");
    }
}

void get_int(const char* prompt, int* num)
{
    printf(prompt);
    if(scanf("%i", num) < 1)
    {
        for(int c; c != EOF && c != '\n'; c = getchar());
        get_int(prompt, num);
    }
}

void get_double(const char* prompt, int* num)
{
    printf(prompt);
    if(scanf("%lf", num) < 1)
    {
        for(int c; c != EOF && c != '\n'; c = getchar());
        get_int(prompt, num);
    }
}

void get_file(const char* mode, FILE** out)
{
    char path[256];
    scanf("%s", path);
    printf("Opening... ");
    if((*out = fopen(path, mode)) == NULL)
    {
        printf("Can't open file. Try again:");
        get_file(mode, out);
    }
    printf("Success!\n");
}

void get_fill_source(double** mat, int* width, int* height)
{
    system("cls");
    printf("Enter source of matrix elements:\n1. From console\n2. From file\n");
    switch(getchar())
    {
    case '1':
        system("cls");
        *mat = (double*) malloc(sizeof(double) * *width * *height);
        for(int i = 0, area = *width * *height; i < area; i++)
        {
            printf("___\n");
            get_double("Enter value: ", (*mat + i));
            system("cls");
            print_mat(*mat, *width, *height, i + 1);
        }
        break;

    case '2':
        system("cls");
        *mat = (double*) malloc(sizeof(double) * *width * *height);
        printf("Enter path to file: ");
        FILE* f;
        get_file("r",&f);
        printf("Reading... ");
        int i = 0;
        while(fscanf(f, "%lf", *mat + i++) > 0);
        printf("Success!\n");
        if(i < *width * *height)
        {
            printf("\nToo few values in file!\nFilled partially.\n\n");
            for(;i < *width * *height; i++) *(*mat + i) = 0.;
        }
        print_mat(*mat, *width, *height, i + 1);
        break;

    default:
        get_fill_source(mat, width, height);
    }
}

void get_mat(double** mat, int* width, int* height)
{
    get_int("Enter width: ", width);
    while(*width < 1)
    {
        printf("Width can't be lower than 1.\n");
        get_int("Enter width: ", width);
    }
    get_int("Enter height: ", height);
    while(*height < 1)
    {
        printf("Height can't be lower than 1.\n");
        get_int("Enter height: ", height);
    }
    get_fill_source(mat, width, height);
}


int main()
{
    double *mat1, *mat2, *sub;
    int w1 = 0, h1 = 0, w2 = 0, h2 = 0;
    while(1)
    {
        printf("Select action ('q' for exit):\n1. Print first matrix\n2. Print second matrix\n3. Set first matrix\n4. Set second matrix\n5. Print difference matrix\n");
        switch(getchar())
        {
        case '1':
            system("cls");
            printf("Matrix 1: %ix%i\n", w1, h1);
            print_mat(mat1, w1, h1, w1 * h1);
            system("pause");
            break;

        case '2':
            system("cls");
            printf("Matrix 2: %ix%i\n", w2, h2);
            print_mat(mat2, w2, h2, w2 * h2);
            system("pause");
            break;

        case '3':
            system("cls");
            get_mat(&mat1, &w1, &h1);
            system("pause");
            break;

        case '4':
            system("cls");
            get_mat(&mat2, &w2, &h2);
            system("pause");
            break;

        case '5':
            system("cls");
            if(w1 != w2 || h1 != h2)
            {
                printf("Cannot get difference of matrices with different sizes.\n");
                system("pause");
                break;
            }
            sub = (double*) malloc(sizeof(double) * w1 * h1);
            mat_sub(mat1, mat2, sub, w1, h1);
            print_mat(sub, w1, h1, w1 * h1);
            system("pause");
            break;

        case 'q':
            free(mat1);
            free(mat2);
            exit(0);
        }
        system("cls");
    }
    return 0;
}
