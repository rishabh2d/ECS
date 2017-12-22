//
// Created by Rishabh 2 on 12/6/17.
//


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef UNTITLED3_DELETE_H
#define UNTITLED3_DELETE_H
void erase_canvas(int erase_row, int erase_col, char** canvas);
void delete_row(int* totalrows, int* totalcols, int* chosenrow, char** canvas);
void delete_col(int* totalrows, int* totalcols, int* chosenCol, char** canvas);
#endif //UNTITLED3_DELETE_H
