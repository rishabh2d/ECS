#include <sstream>
#include "MatrixInnerDimensionMismatchError.h"
#include "MatrixSizeMismatchError.h"


MatrixSizeMismatchError::MatrixSizeMismatchError(int numRowsM1, int numColsM1, int numRowsM2, int numColsM2) {
    std::stringstream errorString;

    errorString << "Matrices must be the same size but Matrix1 is " << numRowsM1 << " X " << numColsM1
                << " and Matrix2 is " << numRowsM2 << " X " << numColsM2 << std::endl;

    errString = errorString.str();

}