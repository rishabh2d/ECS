// Homework 4.1 submitted by Rishabh Sharma, James Simonson
#include <stdio.h>

int matrixAddition() {
    int matrixA[100][100], matrixB[100][100], matrixC[100][100] ;
    int i, j, rows, cols;
    
    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &cols);
    
    // Matrix A Input
    printf("Enter Matrix A\n");
    for(i = 0; i < rows; ++i) {
        for(j = 0; j < cols; ++j) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    // Matrix B Input
    printf("Enter Matrix B\n");
    for(i = 0; i < rows; ++i) {
        for(j = 0; j < cols; ++j) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    // Addition: Matrix A + Matrix B
    for(i = 0; i < rows; ++i) {
        for(j = 0; j < cols; ++j) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    // Matrix C Output
    printf("A + B =\n");
    for(i = 0; i < rows; ++i) {
        for(j = 0; j < cols; ++j) {
            printf("%d", matrixC[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}

int main(void) {
    
    return matrixAddition();
}

