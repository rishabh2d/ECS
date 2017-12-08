#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "create_canvas.h"
#include "resize.h"

#include "horizontal.h"
#include "delete.h"
#include "add.h"
#include "diagonal.h"

void print_help() {

    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
}

void paint_canvas(int argc, char *argv[]) {
    int totalrows, totalcols, start_row = 0, start_col, end_row, end_col;
    int erase_row, erase_col, resized_row, resized_col, chosenRow, chosenCol;
    int i;
    char command2[100], command[100];

    // Storing command line arguments
    sscanf(argv[2], "%d", &totalrows);
    sscanf(argv[3], "%d", &totalcols);

    char** canvas = (char**)malloc(totalrows * sizeof(char*));
    for (i = 0; i < totalrows; i++) {
        canvas[i] = (char*)malloc(totalcols * sizeof(char));
    }

    create_canvas(&totalrows, &totalcols, canvas);

    //Begin painting until user inputs 'q to quit'.
    while (command[0] != 'q') {
        printf("\nEnter your command: ");
        fgets(command, 100, stdin);
        strcpy(command2, command);

        if (command[0] == 'w') { // Write function
            start_row = atoi(command2 + 1);
            start_col = atoi(command2 + 3);
            end_row = atoi(command2 + 5);
            end_col = atoi(command2 + 7);
            if (start_row == end_row) { // Horizontal Paint
                paint_horizontal(&start_row, &start_col, &end_col, canvas);
                create_canvas(&totalrows, &totalcols, canvas);
            } else if (start_col == end_col) {  // Vertical Paint
                paint_vertical(&start_row, &start_col, &end_row, canvas);
                create_canvas(&totalrows, &totalcols, canvas);
            } else if (end_row > start_row && end_col > start_col) {  // Right diagonal paint
                paint_right_diagonal(&start_row, &start_col, &end_row, &end_col, canvas);
                create_canvas(&totalrows, &totalcols, canvas);
            } else {  // Paint Left diagonal
                paint_left_diagonal(&start_row, &start_col, &end_row, &end_col, canvas);
                create_canvas(&totalrows, &totalcols, canvas);
            }
        } else if (command[0] == 'e') {  // Erase function
            erase_row = atoi(command2 + 1);
            erase_col = atoi(command2 + 3);
            erase_canvas(erase_row, erase_col, canvas);
            create_canvas(&totalrows, &totalcols, canvas);
        } else if (command[0] == 'h') {  // Help function
            print_help();
        } else if (command[0] == 'r') {  // Resize function
            resized_row = atoi(command2 + 1);
            resized_col = atoi(command2 + 3);
            resize_canvas(&resized_row, &resized_col, &totalrows, &totalcols, canvas);
            create_canvas(&totalrows, &totalcols, canvas);
        } else if (command[0] == 'a') {  // Add function
            if (command[2] == 'r') {
                chosenRow = atoi(command2 + 3);
                add_row(&totalrows, &totalcols, &chosenRow, canvas);
                create_canvas(&totalrows, &totalcols, canvas);
            } else if (command[2] == 'c') {
                chosenCol = atoi(command2 + 3);
                add_column(&totalrows, &totalcols, &chosenCol, canvas);
                create_canvas(&totalrows, &totalcols, canvas);
            } else {
                printf("Error. ");
            }
        } else if (command[0] == 'd') { // Delete function
            if (command[2] == 'r') {
                chosenRow = atoi(command2 + 3);
                delete_row(&totalrows, &totalcols, &chosenRow, canvas);
                create_canvas(&totalrows, &totalcols, canvas);
            } else if (command[2] == 'c') {
                chosenCol = atoi(command2 + 3);
                delete_col(&totalrows, &totalcols, &chosenCol, canvas);
                create_canvas(&totalrows, &totalcols, canvas);
            } else {
                printf("Error. ");
            }
        } else if (command[0] == 's') {
            printf("Feature to save file is not ready yet.\n");
        } else if (command[0] == 'l') {
            printf("Feature to load file has not been made yet.\n");
        } else {
            printf("error. no such '%c' command", command[0]);
        }
    }

// Quitting Program. Free Malloc for canvas
    for (i = 0; i < totalrows; i++) {
        free(canvas[i]);
    }
    free(canvas);
    printf("\nactually wait, 'q', exists. Quitting Program.");
    exit(0);
}

int main(int argc, char* argv[]) {

    paint_canvas(argc, argv);
    return 0;
}
