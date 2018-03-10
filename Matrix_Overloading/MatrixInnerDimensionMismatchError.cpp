#include <sstream>
#include "MatrixInnerDimensionMismatchError.h"

MatrixInnerDimensionMismatchError::MatrixInnerDimensionMismatchError(int numColsM1, int numRowsM2) {
    std::stringstream errorString;

    errorString << "Inner dimensions do not agree. First matrix has " << numColsM1
                << " columns but second matrix has " << numRowsM2 << " rows." << std::endl;

    errString = errorString.str();

}