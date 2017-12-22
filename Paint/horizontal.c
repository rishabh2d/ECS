//
// Created by Rishabh 2 on 12/6/17.
//

#include "horizontal.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void paint_horizontal(int* start_row, int* start_col, int* end_col, char** canvas) {
    char STAR = '*';
    char PLUS = '+';
    char HORIZONTAL_LINE = '-';
    int j;

    // Printing left to right
    if (*start_col < *end_col) {
        for(j = *start_col; j <= *end_col; j++) {
            if (canvas[*start_row][j] == STAR || canvas[*start_row][j] == HORIZONTAL_LINE) {
                canvas[*start_row][j] = HORIZONTAL_LINE;
            } else {
                canvas[*start_row][j] = PLUS;
            }
        }
        // Printing right to left
    } else if (*start_col > *end_col) {
        for(j = *start_col; j >= *end_col; j--) {
            if (canvas[*start_row][j] == STAR || canvas[*start_row][j] == HORIZONTAL_LINE) {
                canvas[*start_row][j] = HORIZONTAL_LINE;
            } else {
                canvas[*start_row][j] = PLUS;
            }
        }
    }
}

void paint_vertical(int* start_row, int* start_col, int* end_row, char** canvas) {
    char VERTICAL_LINE = '|';
    char STAR = '*';
    char PLUS = '+';
    int i;

    // Printing bottom to top
    if (*start_row < *end_row) {
        for(i = *start_row; i <= *end_row; i++) {
            if (canvas[i][*start_col] == STAR || canvas[i][*start_col] == VERTICAL_LINE) {
                canvas[i][*start_col] = VERTICAL_LINE;
            } else {
                canvas[i][*start_col] = PLUS;
            }
        }
        // Printing top to bottom
    } else if (*start_row > *end_row) {
        for(i = *start_row; i >= *end_row; i--) {
            if (canvas[i][*start_col] == STAR || canvas[i][*start_col] == VERTICAL_LINE) {
                canvas[i][*start_col] = VERTICAL_LINE;
            } else {
                canvas[i][*start_col] = PLUS;
            }
        }
    }
}