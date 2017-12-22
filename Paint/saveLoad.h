//
// Created by Rishabh 2 on 12/13/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef UNTITLED3_SAVELOAD_H
#define UNTITLED3_SAVELOAD_H
void save_canvas(char* fileName, int* totalrows, int* totalcols, char** canvas);
void load_canvas(int argc, char* argv[], char* FILENAME, int* totalrows, int* totalcols, char** canvas);
#endif //UNTITLED3_SAVELOAD_H

