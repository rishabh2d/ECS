#include "Matrix.h"
#include "MatrixSizeMismatchError.h"
#include "MatrixInnerDimensionMismatchError.h"
#include "MatrixSizeError.h"
#include <vector>
#include <iostream>
#include <sstream>

//CONSTRUCTORS
Matrix::Matrix(const std::vector<std::vector<double>> &mat) {
    myMatrix = mat;
    numRows = static_cast<int>(mat.size());
    numCols = static_cast<int>(mat.at(0).size());
    for (unsigned long i = 0; i < static_cast<unsigned long>(numRows); i++) {
        if (static_cast<int>(mat.at(i).size()) != numCols) {
            throw MatrixSizeError(numRows, numRows, static_cast<int>(mat.at(i).size()), numCols);
        }
    }
}

Matrix::Matrix(const double val, const int numRowsSetter, const int numColsSetter){

    numRows = numRowsSetter;
    numCols = numColsSetter;
    for (unsigned long i = 0; i < static_cast<unsigned long>(numRows); ++i){
        myMatrix.emplace_back(std::vector<double>());
        for (unsigned long j = 0; j < static_cast<unsigned long>(numCols); ++j){
            myMatrix.at(i).push_back(val);
        }
    }
}

Matrix::Matrix(){
    numRows = 2;
    numCols = 2;
}

//>> AND << OPERATORS
std::ostream& operator<< (std::ostream& stream, Matrix& matrix) {

    for (unsigned long i = 0; i < static_cast<unsigned long>(matrix.getNumRows()); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(matrix.getNumCols()); j++) {
            stream << matrix.myMatrix.at(i).at(j) << " ";
        }
        stream << std::endl;
    }
    return stream;
}

std::istream& operator >> (std::istream& in, Matrix& matrix) {
    int numRowsSetter, numColsSetter;
    //int rowCounter = 0, colCounter = 0;
    //int counter = 0;

    in >> numRowsSetter >> numColsSetter;

    matrix.setNumCols(numColsSetter);
    matrix.setNumRows(numRowsSetter);

    for (unsigned long i = 0; i < static_cast<unsigned long>(matrix.getNumRows()); i++) {
        matrix.myMatrix.emplace_back(std::vector<double>());
        for (unsigned long j = 0; j < static_cast<unsigned long>(matrix.getNumCols()); j++) {
            matrix.myMatrix.at(i).push_back(0);
            in >> matrix.myMatrix.at(i).at(j);
        }
    }



//     if (colCounter != matrix.getNumCols()) {
//         throw MatrixSizeError::MatrixSizeError(rowCounter, colCounter, matrix.getNumRows(), matrix.getNumCols());
//     } else if (rowCounter != matrix.getNumRows()) {
//         throw MatrixSizeError::MatrixSizeError(rowCounter, colCounter, matrix.getNumRows(), matrix.getNumCols());
//     }

    return in;
}

//NEGATE
Matrix Matrix::operator-() const{
    Matrix copy(*this);
    for (unsigned long i = 0; i < static_cast<unsigned long>(numRows); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(numCols); j++){
            copy.myMatrix.at(i).at(j) = -copy.myMatrix.at(i).at(j);
        }
    }
    return copy;
}

//ADDITION
//matrix addition
Matrix& Matrix::operator+=(const Matrix& rhs) {
    //MatrixSizeMismatchError error;


    // Exception
    if (numCols != rhs.getNumCols() && numRows != rhs.getNumRows()) {
        throw MatrixSizeMismatchError(numRows, numCols, rhs.getNumRows(), rhs.getNumCols());
    }

    for (unsigned long i = 0; i < static_cast<unsigned long>(numRows); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(numCols); j++){
            myMatrix.at(i).at(j) += rhs.myMatrix.at(i).at(j); //FIXME ask cole on how to access specfic values
        }
    }

    return (*this);
}

Matrix Matrix::operator+(const Matrix& rhs) const{
    Matrix copy(*this);
    copy += rhs;
    return copy;
}

//scalar addition
Matrix& Matrix::operator +=(const double& rhs){

    for (unsigned long i = 0; i < static_cast<unsigned long>(numRows); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(numCols); j++){
            myMatrix.at(i).at(j)+= rhs;
        }
    }
    return *this;
}

Matrix Matrix::operator+(const double& rhs) const{
    Matrix copy(*this);
    copy += rhs;
    return copy;
}

// friend matrix
Matrix operator+(const double lhs, const Matrix& rhs){
    Matrix copy(rhs);
    copy += lhs;
    return copy;

}

//TIMES
//matrix multiplication
Matrix& Matrix::operator*=(const Matrix& rhs) {
    //MatrixInnerDimensionMismatchError;

    if (numCols != rhs.getNumRows()) {
        throw MatrixInnerDimensionMismatchError(numCols, rhs.getNumRows());
    }

    Matrix copy(0, numRows, rhs.getNumCols());

    for (unsigned long i = 0; i < static_cast<unsigned long>((*this).getNumRows()); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(rhs.getNumCols()); j++){
            double tempNum = 0;
            for (unsigned long k = 0; k < static_cast<unsigned long>(numCols); k++){
                tempNum += myMatrix.at(i).at(k) * rhs.myMatrix.at(k).at(j);
            }
            copy.myMatrix.at(i).at(j) = tempNum;
        }
    }
    *this = copy;
    return *this;

}

Matrix Matrix::operator*(const Matrix& rhs) const{
    Matrix copy(*this);
    copy*= rhs;
    return copy;
}
//scalar multiplication
Matrix& Matrix::operator*=(const double& rhs) {

    for (unsigned long i = 0; i < static_cast<unsigned long>(numRows); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(numCols); j++){
            myMatrix.at(i).at(j) *= rhs;
        }
    }
    return *this;

}
Matrix Matrix::operator*(const double& rhs) const{
    Matrix copy(*this);
    copy*=rhs;
    return copy;
}
//friend matrix
Matrix operator*(const double& lhs, const Matrix& rhs){
    Matrix copy(rhs);
    copy *= lhs;
    return copy;
}

//SUBTRACTION
//matrix subtraction
Matrix& Matrix::operator-=(const Matrix& rhs){
    //MatrixSizeMismatchError error;

    // Exception
    if (numCols != rhs.getNumCols() && numRows != rhs.getNumRows()) {
        throw MatrixSizeMismatchError(numRows, numCols, rhs.getNumRows(), rhs.getNumCols());
    }

    for (unsigned long i = 0; i < static_cast<unsigned long>(numRows); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(numCols); j++){
            myMatrix.at(i).at(j) -= rhs.myMatrix.at(i).at(j);
        }
    }

    return (*this);
}

Matrix Matrix::operator-(const Matrix& rhs) const{
    Matrix copy(*this);
    copy-=rhs;
    return copy;
}
//scalar subtraction
Matrix& Matrix::operator-=(const double& rhs) {
    for (unsigned long i = 0; i < static_cast<unsigned long>(numRows); i++){
        for (unsigned long j = 0; j < static_cast<unsigned long>(numCols); j++){
            myMatrix.at(i).at(j) -= rhs;
        }
    }
    return *this;
}

Matrix Matrix::operator-(const double& rhs) const{
    Matrix copy(*this);
    copy-=rhs;
    return copy;
}

//friend matrix
Matrix operator-(const double lhs, const Matrix& rhs){
    Matrix copy(rhs);
    copy = -rhs + lhs;
    return copy;
}

// OTHER
int Matrix::getNumRows() const {
    return numRows;
}

int Matrix::getNumCols() const {
    return numCols;
}

void Matrix::setNumRows( int setter){
    numRows = setter;
}

void Matrix::setNumCols( int setter){
    numCols = setter;
}

//RowIters
RowItr Matrix::rowBegin(){
    return RowItr(*this, 0);
}

RowItr Matrix::rowEnd(){
    return RowItr(*this, getNumRows());
}

//ColItrs
ColItr Matrix::colBegin() {
    ColItr copy (*this, 0, 1);
    return copy;
}

ColItr Matrix::colEnd(){
    ColItr copy (*this, getNumCols(), 1);
    return copy;

}

RowItr Matrix::operator [] (int i) {
    std::stringstream errorString;

    errorString << "RowItr dereferenced out of bounds. Acceptable values 0 -"
                << numCols << ". Current position: " << i << std::endl;

    std::string errorMessage;
    errorMessage = errorString.str();

    if (i < 0 || i > numRows) {
        throw std::out_of_range(errorMessage);
    }

    return RowItr(*this, i);
}