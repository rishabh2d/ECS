//
// Created by Rishabh 2 on 12/13/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include "saveLoad.h"
#include "resize.h"
#include "create_canvas.h"

void paint_canvas(int argc, char *argv[]);
void save_canvas(char* FILENAME, int* totalrows, int* totalcols, char** canvas) {

    FILE* fp;
    fp = fopen(FILENAME, "w");

    fprintf(fp, "%d\n", *totalrows);
    fprintf(fp, "%d\n", *totalcols);

    if (fp == NULL) {
        printf("Improper save command or file could not be created.\n");
        create_canvas(totalrows, totalcols, canvas);
    }
    for (int i = 0; i < *totalrows; i++) {
        for (int j = 0; j < *totalcols; j++) {
            fprintf(fp, "%c", canvas[i][j]);
        }
    }
    fclose(fp);
}

void load_canvas(int argc, char* argv[], char* FILENAME, int* totalrows, int* totalcols, char** canvas) {
    int i, j = 0;
    int resized_row, resized_col;
    FILE* fp;
/*
    int* file_rows = 0;
    int* file_cols = 0;
*/

    fp = fopen(FILENAME, "r");

    if (fp == NULL) {
        printf("Failed to open file: %s", FILENAME);
        paint_canvas(argc, argv);
    }

    // Gets the row number and column number
    fscanf(fp, "%d", &resized_row);
    fscanf(fp, "%d", &resized_col);

    resize_canvas(totalrows, totalcols, &resized_row, &resized_col, &canvas) ;

    char** canvasB = (char**)malloc(resized_row * sizeof(char*));
    for (i = 0; i < resized_row; i++) {
        canvasB[i] = (char *) malloc(resized_col * sizeof(char));
        for (j = 0; j < resized_col; j++) {
            fscanf(fp, " %c", &canvasB[i][j]);
        }
    }

    for (i = 0; i < resized_row; i++) {
        for (j = 0; j < resized_col; j++) {
            canvas[i][j] = canvasB[i][j];
        }
    }

    fclose(fp);

}