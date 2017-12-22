#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "create_canvas.h"

void create_canvas(int *totalrows, int *totalcols, char **canvas) {
    // Star Canvas
    char STAR = '*';
    char RIGHT_DIAGONAL_LINE = '/';
    char LEFT_DIAGONAL_LINE = '\\';
    char VERTICAL_LINE = '|';
    char HORIZONTAL_LINE = '-';
    char PLUS = '+';

    int i, j;
    for (i = 0; i < *totalrows; i++) {
        for (j = 0; j < *totalcols; j++) {
            if (canvas[i][j] == RIGHT_DIAGONAL_LINE ||
                canvas[i][j] == LEFT_DIAGONAL_LINE  ||
                canvas[i][j] == VERTICAL_LINE       ||
                canvas[i][j] == HORIZONTAL_LINE     ||
                canvas[i][j] == PLUS) {
                continue;
            } else {
                canvas[i][j] = STAR;
            }
        }
    }
    // Num canvas
    for (i = (*totalrows) - 1; i >= 0; i--) {
        // printing the row number
        printf("%d ", i);
        for (j = 0; j < *totalcols; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
    // printing the column number
    for (j = 0; j < *totalcols; j++) {
        if (j == 0) {
            printf("  0 ");
        } else {
            printf("%d ", j);
        }
    }
    printf("\n");
}