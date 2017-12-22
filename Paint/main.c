#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "add.h"
#include "create_canvas.h"
#include "delete.h"
#include "diagonal.h"
#include "horizontal.h"
#include "resize.h"
#include "saveLoad.h"

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

    int totalrows = 0, totalcols, start_row , start_col, end_row, end_col;
    int erase_row, erase_col, chosenRow, chosenCol;
    int i, j, letter_counter = 0;
    int resized_row, resized_col;
    char command2[500], command[500];
    char FILENAME[500];
    char argumentOne, argumentTwo;
    // Storing command line arguments
    if (argc < 3) {
        totalrows = 10;
        totalcols = 10;
    } else if (argc == 3) {
        sscanf(argv[1], "%c", &argumentOne);
        sscanf(argv[2], "%c", &argumentTwo);
        if (isdigit(argumentOne)) {
            if (isdigit(argumentTwo)) {
                totalrows = argumentOne - '0';
                totalcols = argumentTwo - '0';
            } else if (argumentTwo == '-') {
                printf("The number of columns is less than 1.\nMaking default board of 10 X 10.\n");
                totalrows = 10;
                totalcols = 10;
            } else {
                printf("The number of columns is not an integer.\nMaking default board of 10 X 10.\n");
                totalrows = 10;
                totalcols = 10;
            }
        } else if (argumentOne == '-') {
            printf("The number of rows is less than one.\nMaking default board of 10 X 10.\n");
            totalrows = 10;
            totalcols = 10;
        } else {
            printf("The number of rows is not an integer.\nMaking default board of 10 X 10.\n");
            totalrows = 10;
            totalcols = 10;
        }
        if (totalcols < 1) {
            printf("The number of columns is less than 1.\nMaking default board of 10 X 10.\n");
            totalrows = 10;
            totalcols = 10;
        } else if (totalrows < 1) {
            printf("The number of rows is less than 1.\nMaking default board of 10 X 10.\n");
            totalrows = 10;
            totalcols = 10;
        }
    } else if (argc != 4) {
        printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.\n");
        totalrows = 10;
        totalcols = 10;
    } else if(strlen(argv[2]) > 3 || strlen(argv[3]) > 3) {
        printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.\n");
        totalrows = 10;
        totalcols = 10;
    } else {
        sscanf(argv[1], "%d", &totalrows);
        sscanf(argv[2], "%d", &totalcols);
        if (totalrows < 0 || totalcols < 0) {
            printf("The number of columns is less than 1.\nMaking default board of 10 X 10.");
            totalrows = 10;
            totalcols = 10;
        }
    }

    char** canvas = (char**)malloc(totalrows * sizeof(char*));
    for (i = 0; i < totalrows; i++) {
        canvas[i] = (char*)malloc(totalcols * sizeof(char));
        for (j = 0; j < totalcols; j++) {
            canvas[i][j] = '*';
        }
    }

    create_canvas(&totalrows, &totalcols, canvas);

    // Begin painting until user inputs 'q to quit'.
    while (command[0] != 'q') {
        printf("Enter your command: ");
        fgets(command, 500, stdin);
        strcpy(command2, command);

        if (command[0] != 'w' && command[0] != 'W' && command[0] != 'a' && command[0] != 'A' && command[0] != 'e'
            && command[0] != 'E' && command[0] != 'd' && command[0] != 'D' && command[0] != 'r' && command[0] != 'R'
            && command[0] != 'h' && command[0] != 'H' && command[0] != 'q' && command[0] != 'Q' && command[0] != 's' && command[0] != 'l') {
            printf("Unrecognized command. Type h for help.\n");
            create_canvas(&totalrows, &totalcols, canvas);
            continue;
        }

        if (command[0] == 'w') {  // Write function
            start_row = atoi(command2 + 2);
            start_col = atoi(command2 + 4);
            end_row = atoi(command2 + 6);
            end_col = atoi(command2 + 8);
            int deltaX = abs(end_row - start_row);
            int deltaY = abs(end_col - start_col);

            if (start_row > totalrows || end_row > totalrows ||
                start_col > totalcols || end_col > totalcols ||
                start_col < 0 || start_row < 0 || end_col < 0 || end_row < 0) {
                printf("Improper draw command.\n");
                create_canvas(&totalrows, &totalcols, canvas);
                continue;
            }

            if (deltaX == 0 || deltaY == 0 || (deltaX/deltaY) == 1) {
                // Begin painting
                if (start_row == end_row && start_col == end_col) {  // Printing one position as -
                    if (canvas[start_row][start_col] == '*' || canvas[start_row][start_col] == '-') {
                        canvas[start_row][start_col] = '-';
                    } else {
                        canvas[start_row][start_col] = '+';
                    }
                    create_canvas(&totalrows, &totalcols, canvas);
                } else if (start_row == end_row) {  // Horizontal Paint
                    paint_horizontal(&start_row, &start_col, &end_col, canvas);
                    create_canvas(&totalrows, &totalcols, canvas);
                } else if (start_col == end_col) {  // Vertical Paint
                    paint_vertical(&start_row, &start_col, &end_row, canvas);
                    create_canvas(&totalrows, &totalcols, canvas);
                } else if (end_row > start_row && end_col > start_col) {  // Right diagonal paint
                    paint_right_diagonal(&start_row, &start_col, &end_row, &end_col, canvas);
                    create_canvas(&totalrows, &totalcols, canvas);
                } else if (start_row > end_row && start_col > end_col) {
                    paint_right_diagonal(&start_row, &start_col, &end_row, &end_col, canvas);
                    create_canvas(&totalrows, &totalcols, canvas);
                } else {  // Left diagonalPaint
                    paint_left_diagonal(&start_row, &start_col, &end_row, &end_col, canvas);
                    create_canvas(&totalrows, &totalcols, canvas);
                }
            } else {
                printf("Cannot draw the line as it is not straight.\n");
                create_canvas(&totalrows, &totalcols, canvas);
                continue;
            }
        } else if (command[0] == 'e') {  // Erase function
            if (atoi(command + 2) < 0 || atoi(command + 2) > totalrows - 1 || isalpha(command[4])) {
                printf("Improper erase command.\n");
                create_canvas(&totalrows, &totalcols, canvas);
                continue;
            } else {
                erase_row = atoi(command2 + 2);
            }

            if (atoi(command + 4) < 0 || atoi(command + 4) > totalcols - 1 || isalpha(command[4])) {
                printf("Improper erase command.\n");
                create_canvas(&totalrows, &totalcols, canvas);
                continue;
            } else {
                erase_col = atoi(command2 + 4);
            }
            erase_canvas(erase_row, erase_col, canvas);
            create_canvas(&totalrows, &totalcols, canvas);
        } else if (command[0] == 'h') {  // Help function
            if (isalpha(command[2]) || isdigit(command[2])) {
                printf("Unrecognized command. Type h for help.\n");
                create_canvas(&totalrows, &totalcols, canvas);
            } else {
                print_help();
                create_canvas(&totalrows, &totalcols, canvas);
            }
        } else if (command[0] == 'r') {  // Resize function
            if (atoi(command + 2) <= 0) {
                printf("Improper resize command.\n");
                create_canvas(&totalrows, &totalcols, canvas);
                continue;
            } else {
                resized_row = atoi(command2 + 2);
            }
            if (atoi(command + 4) <= 0) {
                printf("Improper resize command.\n");
                create_canvas(&totalrows, &totalcols, canvas);
                continue;
            } else {
                resized_col = atoi(command2 + 4);
            }
            resize_canvas(&totalrows, &totalcols, &resized_row, &resized_col, &canvas);
            create_canvas(&totalrows, &totalcols, canvas);
        } else if (command[0] == 'a') {  // Add function
            // If user inputs letter instead of row letter
            if (isalpha(command[4])) {
                printf("Improper add command.\n");
                create_canvas(&totalrows, &totalcols, canvas);
                continue;
            }
            if (command[2] == 'r') {  // Add row
                if (atoi(command + 4) < 0 || atoi(command + 4) > totalrows || isalpha(command[4])) {
                    printf("Improper add command.\n");
                    create_canvas(&totalrows, &totalcols, canvas);
                    continue;
                } else {
                    chosenRow = atoi(command2 + 4);
                }
                add_row(&totalrows, &totalcols, &chosenRow, canvas);
            } else if (command[2] == 'c') {  // add col
                if (atoi(command + 4) < 0 || atoi(command + 4) > totalcols) {
                    printf("Improper add command.\n");
                    create_canvas(&totalrows, &totalcols, canvas);
                    continue;
                } else {
                    chosenCol = atoi(command2 + 4);
                }
                add_column(&totalrows, &totalcols, &chosenCol, canvas);
            }
        } else if (command[0] == 'd') { // Delete function
            // If user inputs letter instead of row number
            if (isalpha(command[4])) {
                printf("Improper delete command.\n");
                create_canvas(&totalrows, &totalcols, canvas);
                continue;
            }
            if (command[2] == 'r') {
                if (atoi(command + 4) < 0 || atoi(command + 4) > totalrows -1) {
                    printf("Improper delete command.\n");
                    create_canvas(&totalrows, &totalcols, canvas);
                    continue;
                } else {
                    chosenRow = atoi(command2 + 4);
                }
                delete_row(&totalrows, &totalcols, &chosenRow, canvas);
            } else if (command[2] == 'c') {
                if (atoi(command + 4) < 0 || atoi(command + 4) > totalcols -1) {
                    printf("Improper delete command.\n");
                    create_canvas(&totalrows, &totalcols, canvas);
                    continue;
                } else {
                    chosenCol = atoi(command2 + 4);
                }
                delete_col(&totalrows, &totalcols, &chosenCol, canvas);
            }
        } else if (command[0] == 's') {
            for (i = 2; i < 100; i++) {
                if (isspace(FILENAME[i])) {
                    letter_counter = i;
                    break;
                }
                letter_counter++;
            }
            letter_counter--;
            for (i = 2; i < letter_counter; i++) {
                FILENAME[i - 2] = command[i];
            }
            save_canvas(FILENAME, &totalrows, &totalcols, canvas);
            create_canvas(&totalrows, &totalcols, canvas);
        } else if (command[0] == 'l') {
            for (i = 2; i < 100; ++i) {
                if (isspace(FILENAME[i])) {
                    letter_counter = i;
                    break;
                }
                letter_counter++;
            }
            letter_counter--;
            for (i = 2; i < letter_counter; i++) {
                FILENAME[i - 2] = command[i];
            }
            load_canvas(argc, argv, FILENAME, &totalrows, &totalcols, canvas);
            create_canvas(&totalrows, &totalcols, canvas);
            continue;
        } else if (command[0] == 'q' && (isalpha(command[2]) || isdigit(command[2]) || ispunct(command[2]))) {
            if (command[0] == 'q' && command[1] != '\n') {
                printf("Unrecognized command. Type h for help.\n");
                create_canvas(&totalrows, &totalcols, canvas);
                command[0] = 'x';
            }
        } else if (ispunct(command[0])) {
            printf("Unrecognized command. Type h for help.\n");
            create_canvas(&totalrows, &totalcols, canvas);
            continue;
        } else {
            break;
        }
    }
/*

    for (i = 0; i < totalrows; i++) {
        free(canvas[i]);
    }
    free(canvas);
*/


    exit(0);
}

int main(int argc, char* argv[]) {

    paint_canvas(argc, argv);
    return 0;
}