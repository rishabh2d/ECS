//
// Created by Rishabh 2 on 12/6/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "resize.h"

void resize_canvas(int* totalrows, int* totalcols, int* resized_row, int* resized_col, char*** canvas) {
    int i, j;
    char STAR = '*';

    // shrinking, if resized is > total then it wouldn't even enter this loop
    for (i = *resized_row; i < *totalrows; i++) {
        free((*canvas)[i]);
        (*canvas)[i] = NULL;
    }

    // reallocation of the new number of rows
    *canvas = (char**)realloc(*canvas, (*resized_row) * sizeof(char*));
    // creation of columns from totalrows to resizedRows
    for (i = *totalrows; i < *resized_row; i++) {
        (*canvas)[i] = (char*)malloc((*resized_col) * sizeof(char));
        // Assigning the created columns into stars
        for (j = 0; j < *resized_col; j++) {  // Assign stars
            (*canvas)[i][j] = STAR;
        }
    }

    for (i = 0; i < *resized_row; i++) {
        (*canvas)[i] = (char*)realloc((*canvas)[i], *resized_col * sizeof(char));
        for (j = *totalcols; j < *resized_col; j++) {
            (*canvas)[i][j] = STAR;
        }
    }
    *totalrows = *resized_row;
    *totalcols = *resized_col;
}

























/*
void new_resize_canvas (int* totalrows, int* totalcols, int* resized_row, int* resized_col, char** canvas) {
    int i, j;

    char** canvasB = (char **)malloc(*resized_row * sizeof(char *));
    for (i = 0; i < *resized_row; i++) {
        canvasB[i] = (char *)malloc(*resized_col * sizeof(char));
    }

    for (i = 0; i < *resized_row; i++) {
        for (j = 0; j < *resized_col; j++) {
            canvasB[i][j] = '*';
        }
    }

    // smaller resized row
    if (*resized_row <= *totalrows) {
        // smaller resized row & smaller resized column
        if (*resized_col <= *totalcols) {
            for (i = 0; i < *resized_row; i++) {
                for (j = 0; j < *resized_col; j++) {
                    canvasB[i][j] = canvas[i][j];
                }
            }
            // smaller resized row & larger resized column
        } else {
            for (i = 0; i < *resized_row; i++) {
                for (j = 0; j < *totalcols; j++) {
                    canvasB[i][j] = canvas[i][j];
                }
            }
        }
        // larger resized row
    } else if (*resized_row > *totalrows) {
        // larger resized row & larger resized column
        if (*resized_col > *totalcols) {
            for (i = 0; i < *totalrows; i++) {
                for (j = 0; j < *totalcols; j++) {
                    canvasB[i][j] = canvas[i][j];
                }
            }
            // larger resized row & smaller resized column
        } else {
            for (i = 0; i < *totalrows; i++) {
                for (j = 0; j < *resized_col; j++) {
                    canvasB[i][j] = canvas[i][j];
                }
            }
        }
    }

    *totalrows = *resized_row;
    *totalcols = *resized_col;

    canvas = (char**)realloc(canvas, *resized_row * sizeof(char*));
    for (i = 0; i < *resized_row; i++) {
        canvas[i] = (char*)malloc(*resized_col * sizeof(char));
    }

    for (i = 0; i < *resized_row; i++) {
        for (j = 0; j < *resized_col; j++) {
            canvas[i][j] = canvasB[i][j];
        }
    }

    for (i = 0; i < *resized_row; i++) {
        free(canvasB[i]);
    }
    free(canvasB);
}*/
