//
// Created by mfbut on 3/2/2018.
//

#ifndef MATRIX_MATRIXSIZEMISMATCHERROR_H
#define MATRIX_MATRIXSIZEMISMATCHERROR_H

#include "MatrixError.h"
#include "Matrix.h"
class MatrixSizeMismatchError : public MatrixError {
public:
    MatrixSizeMismatchError (int numRowsM1, int numRowsM2, int numColsM1, int numColsM2);

};

#endif //MATRIX_MATRIXSIZEMISMATCHERROR_H
