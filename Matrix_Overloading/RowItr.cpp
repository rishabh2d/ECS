#include "RowItr.h"
#include <sstream>

RowItr::RowItr( Matrix& matrix, int positionSetter, int stepSetter)
        : position(positionSetter), step(stepSetter), myMatrix(matrix) {}

RowElementItr RowItr::operator*(){
    return RowElementItr(*this, 0);
}

RowItr& RowItr::operator++(){
    position++;
    return *this;
}

RowItr& RowItr::operator++(int){
    return ++(*this);
}

RowItr& RowItr::operator--() {
    position--;
    return *this;
}

RowItr& RowItr::operator--(int){
    return --(*this);
}

RowItr& RowItr::operator+=(const int& rhs){
    step = rhs;
    position += step;

    return *this;
}

RowItr RowItr::operator+(const int& rhs){
    RowItr copy (*this);
    copy.position += rhs;
    return copy;
}

RowItr& RowItr::operator-=(const int& rhs){
    step = rhs;
    position -= step;

    return *this;
}

RowItr RowItr::operator-(const int& rhs){
    RowItr copy(*this);
    copy.position-= rhs;

    return copy;
}

RowItr::operator bool() const{
    if (position >= 0 && position < myMatrix.getNumRows()){
        return true;
    } else {
        return false;
    }
}

bool RowItr::operator!() const{
    if (position >= 0 && position < myMatrix.getNumRows()){
        return true;
    } else {
        return false;
    }
}

bool RowItr::operator==(const RowItr& rhs) const{
    if (step != rhs.step){
        return false;
    } else if(!*this && !rhs) {
        return true;
    } else {
        return position == rhs.position;
    }
}

bool RowItr::operator!=(const RowItr& rhs) const {
    return !(*this == rhs);
}

bool RowItr::operator<(const RowItr& rhs) const {
    if (step != rhs.step) {
        return false;
    } else if (rhs.step > 0) {
        return position < rhs.position;
    } else {
        return position > rhs.position;
    }
}

bool RowItr::operator>(const RowItr& rhs) const {
    return !(*this < rhs || *this == rhs);
}

bool RowItr::operator<=(const RowItr& rhs) const{
    return *this == rhs || *this < rhs;
}

bool RowItr::operator>=(const RowItr& rhs) const{
    return *this == rhs || *this > rhs;
}

double& RowItr::operator[] (int i) {

    std::stringstream errorString;

    errorString << "RowElementItr dereferenced out of bounds. Acceptable values 0 -" << (myMatrix.getNumRows())/2
                << ". Current position: " << i << std::endl;

    std::string errorMessage = errorString.str();
    if (i < 0 || i > myMatrix.getNumCols()) {
        throw std::out_of_range(errorMessage);
    }

    return myMatrix.myMatrix.at(static_cast<unsigned long>(position)).at(static_cast<unsigned long>(i));
}

RowElementItr RowItr::begin(){
    return RowElementItr(*this, 0);
}

RowElementItr RowItr::end() {
    return RowElementItr(*this, myMatrix.getNumCols());

}