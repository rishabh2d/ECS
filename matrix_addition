/*
This program multiplies two matrices.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mat_add(int rows, int cols, int i, int j);
int mat_add(int rows, int cols, int i, int j) {
    i = 0; j = 0;
    // dynamically allocating memory for the matrices
    int **matrixA = (int **)malloc(rows * sizeof(int*));
    int **matrixB = (int **)malloc(rows * sizeof(int*));
    int **matrixC = (int **)malloc(rows * sizeof(int*));
    
    // Creating memory for the 2d matrixA
    for (i = 0; i < rows; i++) {
        matrixA[i] = (int *)malloc(cols * sizeof(int*));
    }
    // Creating memory for the 2d matrixB
    for (i = 0; i < rows; i++) {
        matrixB[i] = (int *)malloc(cols * sizeof(int*));
    }
    // Creating memory for the 2d matrixC
    for (i = 0; i < rows; i++) {
        matrixC[i] = (int *)malloc(cols * sizeof(int*));
    }
    
    // Matrix A Input
    printf("Enter Matrix A\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    // Matrix B Input
    printf("Enter Matrix B\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    // Addition: Matrix C = Matrix A + Matrix B
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    // Matrix C Output
    printf("A + B =\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("%d", matrixC[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
int main(void) {
    int rownum, colnum, i = 0 , j = 0;
    printf("Please enter the number of rows: ");
    scanf("%d", &rownum);
    printf("Please enter the number of columns: ");
    scanf("%d", &colnum);
    mat_add(rownum, colnum, i, j);
    return 0;
}
