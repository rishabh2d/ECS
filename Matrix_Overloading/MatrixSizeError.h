//
// Created by mfbut on 3/2/2018.
//

#ifndef MATRIX_MATRIXSIZEERROR_H
#define MATRIX_MATRIXSIZEERROR_H
#include "Matrix.h"
#include "MatrixError.h"

class MatrixSizeError : public MatrixError{
public:
    MatrixSizeError(int rowCounter, int colCounter, int numRows, int numCols);
};

#endif //MATRIX_MATRIXSIZEERROR_H
