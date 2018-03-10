#include <sstream>
#include "MatrixSizeError.h"

MatrixSizeError::MatrixSizeError(int rowCounter, int numRows, int colCounter, int numCols) {
    std::stringstream errorString;
    // All rows of the matrix should have the same number of elements.
    // Expected rows to contain 3 elements but found row that contained 2 elements.

    if (rowCounter != numRows) {
        errorString << "All columns of the matrix should have the same number of elements. Expected columns to contain "
                    << numRows << " elements but found column that contained " << rowCounter << " elements." << std::endl;
    } else if (colCounter != numCols) {
        errorString << "All rows of the matrix should have the same number of elements. Expected rows to contain "
                    << numCols << " elements but found row that contained " << colCounter << " elements." << std::endl;
    }

    errString = errorString.str();

}