//
// Created by mfbut on 3/2/2018.
//

#ifndef MATRIX_COLELEMENTITR_H
#define MATRIX_COLELEMENTITR_H

class Matrix;
class ColItr;

class ColElementItr{
public:

    double& operator*();
    explicit ColElementItr( ColItr& colItrSetter, int positionSetter = 0, int stepSetter = 1);

    //move one element forward
    ColElementItr& operator++(); // pre
    ColElementItr& operator++(int); // post

    //move one element back
    ColElementItr& operator--(); // pre
    ColElementItr& operator--(int); // post

    ColElementItr& operator+=(const int& rhs); //move self rhs elements forward
    ColElementItr operator+(const int& rhs); // new iterator rhs elements after self

    ColElementItr& operator-=(const int& rhs); //move self rhs elements backward
    ColElementItr operator-(const int& rhs); //new iterator rhs elements before self

    operator bool() const; //true if in bounds
    bool operator!() const; //ture if out of bounds
    bool operator==(const ColElementItr& rhs) const; //referring to same matrix and (at same position or out of bounds)
    bool operator!=(const ColElementItr& rhs) const; //opposite of ==
    bool operator<(const ColElementItr& rhs) const; // referring to same matrix and before rhs
    bool operator>(const ColElementItr& rhs) const; //referring to same matrix and after rhs
    bool operator<=(const ColElementItr& rhs) const;
    bool operator>=(const ColElementItr& rhs) const;

private:
    int position;
    int step;
    ColItr& colItr;
};


#endif //MATRIX_COLELEMENTITR_H
