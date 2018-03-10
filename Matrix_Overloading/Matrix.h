//
// Created by mfbut on 1/22/2018.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <vector>
#include <iostream>

#include "RowItr.h"
#include "RowElementItr.h"
#include "ColItr.h"
#include "ColElementItr.h"


class Matrix {
    friend RowItr;
    friend RowElementItr;
    friend ColItr;
    friend ColElementItr;
public:
    Matrix();

    //create a matrix from a vector of vector of doubles
    //where each inner vector is a row of the matrix
    explicit Matrix(const std::vector<std::vector<double>>& mat);

    // create a matrix that is numRows X numCols where all elements are val
    Matrix(const double val, const int numRows, const int numCols);
    Matrix(const Matrix& rhs) = default;

    int getNumRows() const;
    int getNumCols() const;
    void setNumRows( int setter);
    void setNumCols(int setter);

    Matrix operator-() const; // negation. negate all elements of matric

    Matrix& operator+=(const Matrix& rhs); // matrix addition
    Matrix& operator+=(const double& rhs); //scalar addition

    Matrix operator+(const Matrix& rhs) const; // matrix addition
    Matrix operator+(const double& rhs) const; // scalar addition
    friend Matrix operator+(const double lhs, const Matrix& rhs); // scalar addition

    Matrix& operator-=(const Matrix& rhs); // matrix subtraction
    Matrix& operator-=(const double& rhs); // scalar subtraction

    Matrix operator-(const Matrix& rhs) const; //matrix subtraction
    Matrix operator-(const double& rhs) const; // scalar subtraction
    friend Matrix operator-(const double lhs, const Matrix& rhs); // scalar subtraction

    Matrix& operator*=(const Matrix& rhs); // matrix multiplication
    Matrix& operator*=(const double& rhs); // scalar multiplication

    Matrix operator*(const Matrix& rhs) const; //matrix multiplication
    Matrix operator*(const double& rhs) const; // scalar multiplication
    friend Matrix operator*(const double& lhs, const Matrix& rhs); // scalar multiplication

    RowItr operator [](int i); // get RowItr over row i

    friend std::ostream& operator<<(std::ostream& out, Matrix& matrix);
    friend std::istream& operator>>(std::istream& in, Matrix& matrix);

    RowItr rowBegin(); //get itr to first row
    RowItr rowEnd(); //get itr to one past last row

    ColItr colBegin(); // get itr to first column
    ColItr colEnd(); // get itr to one past last column

private:
    int numRows;
    int numCols;
    std::vector<std::vector<double>> myMatrix;

};

#endif //MATRIX_MATRIX_H
