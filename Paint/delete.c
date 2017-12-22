//
// Created by Rishabh 2 on 12/6/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "delete.h"
#include "create_canvas.h"
#include "delete_struct.h"

void erase_canvas(int erase_row, int erase_col, char** canvas) {
    canvas[erase_row][erase_col] = '*';
}

void delete_row(int* totalrows, int* totalcols, int* chosenRow, char** canvas) {
    int i;

    struct modifier delete;
    delete.row = *chosenRow;

    free(canvas[delete.row]);
    (*totalrows)--;
    for (i = delete.row; i < *totalrows; ++i) {
        canvas[i] = canvas[i + 1];
    }
    canvas = (char**)realloc(canvas, *totalrows * sizeof(char*));
    create_canvas(&*totalrows, &*totalcols, canvas);
}

void delete_col(int* totalrows, int* totalcols, int* chosenCol, char** canvas) {
    int i, j;
    struct modifier {
        int col;
        int row;
    };

    (*totalcols)--;

    struct modifier delete;
    delete.col = *chosenCol;

    for (i = 0; i < *totalrows; i++) {
        for (j = delete.col; j < *totalcols; j++) {
            canvas[i][j] = canvas[i][j + 1];
        }
        canvas[i] = (char*)realloc(canvas[i], *totalcols * sizeof(char));
    }
    create_canvas(&*totalrows, &*totalcols, canvas);
}
