//
// Created by mfbut on 3/2/2018.
//

#ifndef MATRIX_MATRIXINNERDIMENSIONMISMATCHERROR_H
#define MATRIX_MATRIXINNERDIMENSIONMISMATCHERROR_H

#include "MatrixError.h"
#include "Matrix.h"

class MatrixInnerDimensionMismatchError : public MatrixError {

public:
    MatrixInnerDimensionMismatchError(int numColsM1, int numRowsM1);

};

#endif //MATRIX_MATRIXINNERDIMENSIONMISMATCHERROR_H
