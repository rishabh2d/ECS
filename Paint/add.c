//
// Created by Rishabh 2 on 12/6/17.
//

#include "add.h"
#include "create_canvas.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void add_column(int* totalrows, int* totalcols, int *chosenCol, char** canvas) {
    int i, j;
    char STAR = '*';
    (*totalcols)++;

    for (i = 0; i < *totalrows; i++) {
        canvas[i] = (char*)realloc(canvas[i], *totalcols * sizeof(char));
        //shuffling
        for (j = *totalcols - 1; j  > *chosenCol; --j) {
            canvas[i][j] = canvas[i][j - 1];
        }
        canvas[i][j] = STAR;
    }
    create_canvas(totalrows, totalcols, canvas);
}

void add_row(int* totalrows, int* totalcols, int *chosenRow, char** canvas) {
    int i, j;
    char STAR = '*';
    (*totalrows)++;

    // reallocate for new row
    canvas = (char **) realloc(canvas, *totalrows * sizeof(char *));

    //shuffling the new row
    for (i = *totalrows - 1; i > *chosenRow; --i) {
        canvas[i] = canvas[i - 1];
    }

    //make new cols for the new row
    canvas[i] = (char *) malloc(*totalcols * sizeof(char));
    for (j = 0; j < *totalcols; j++) {
        canvas[i][j] = STAR;
    }


    create_canvas(totalrows, totalcols, canvas);
}