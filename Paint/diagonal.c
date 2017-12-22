//
// Created by Rishabh 2 on 12/6/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "diagonal.h"

void paint_right_diagonal(int *start_row, int *start_col, int *end_row, int *end_col, char** canvas) {
    char STAR = '*';
    char PLUS = '+';
    char RIGHT_DIAGONAL_LINE = '/';
    int i, j = *start_col;

        // Going down to up
    if (*start_row < *end_row && *start_col < *end_col) {
        for (i = *start_row; i <= *end_row; i++) {
            if (canvas[i][j] == STAR || canvas[i][j] == RIGHT_DIAGONAL_LINE) {
                canvas[i][j] = RIGHT_DIAGONAL_LINE;
            } else {
                canvas[i][j] = PLUS;
            }
            j++;
            if (j > *end_col) {
                break;
            }
        }
    } else if (*start_row > *end_row && *start_col > *end_col) {
        for (i = *start_row; i >= *end_row; i--) {
            if (canvas[i][j] == STAR || canvas[i][j] == RIGHT_DIAGONAL_LINE) {
                canvas[i][j] = RIGHT_DIAGONAL_LINE;
            } else {
                canvas[i][j] = PLUS;
            }
            j--;
            if (j < *end_col) {
                break;
            }
        }
    }
}

void paint_left_diagonal(int *start_row, int *start_col, int *end_row, int *end_col, char** canvas) {
    char STAR = '*';
    char PLUS = '+';
    char LEFT_DIAGONAL_LINE = '\\';
    int i, j = *start_col;

        // Going down to up
    if (*start_row < *end_row && *start_col > *end_col) {
        for (i = *start_row; i <= *end_row; i++) {
            if (canvas[i][j] == STAR || canvas[i][j] == LEFT_DIAGONAL_LINE) {
                canvas[i][j] = LEFT_DIAGONAL_LINE;
            } else {
                canvas[i][j] = PLUS;
            }
            j--;
            if (j < *end_col) {
                break;
            }
        }
        // Going to up to down
    } else if (*start_row > *end_row && *start_col < *end_col) {
        for (i = *start_row; i >= *end_row; i--) {
            if (canvas[i][j] == STAR || canvas[i][j] == LEFT_DIAGONAL_LINE) {
                canvas[i][j] = LEFT_DIAGONAL_LINE;
            } else {
                canvas[i][j] = PLUS;
            }
            j++;
            if (j > *end_col) {
                break;
            }
        }
    }
}