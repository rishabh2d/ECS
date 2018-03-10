#include "ColElementItr.h"
#include "ColItr.h"
#include "Matrix.h"

ColElementItr::ColElementItr( ColItr &colItrSetter, int positionSetter, int stepSetter)
        : position(positionSetter), step(stepSetter), colItr(colItrSetter) {}


double& ColElementItr::operator*(){
    return colItr.myMatrix.myMatrix.at(static_cast<unsigned long>(position)).at(static_cast<unsigned long>(colItr.position));
}

ColElementItr& ColElementItr::operator++(){
    step = 1;
    position += step;
    return *this;
}

ColElementItr& ColElementItr::operator++(int){
    return ++(*this);
}

ColElementItr& ColElementItr::operator--(){
    step = 1;
    position -= step;
    return *this;
}

ColElementItr& ColElementItr::operator--(int){
    return --(*this);
}

ColElementItr& ColElementItr::operator+=(const int& rhs){
    step = rhs;
    position += step;
    return *this;
}

ColElementItr ColElementItr::operator+(const int& rhs){
    ColElementItr copy (*this);
    copy.position += rhs;
    return copy;
}

ColElementItr& ColElementItr::operator-=(const int& rhs){
    step = rhs;
    position -= step;
    return *this;
}

ColElementItr ColElementItr::operator-(const int& rhs){
    ColElementItr copy(*this);
    copy.position-= rhs;
    return copy;
}

ColElementItr::operator bool() const{
    if (position >= 0 && position < colItr.myMatrix.getNumCols()){
        return true;
    }
    else{
        return false;
    }
}

bool ColElementItr::operator!() const{
    if (position >= 0 && position < colItr.myMatrix.getNumCols()){
        return true;
    }
    else{
        return false;
    }
}

bool ColElementItr::operator==(const ColElementItr& rhs) const{
    if (step != rhs.step){
        return false;
    }
    else if(!*this && !rhs){
        return true;
    }
    else{
        return position == rhs.position;
    }
}

bool ColElementItr::operator!=(const ColElementItr& rhs) const{
    return !(*this == rhs);
}

bool ColElementItr::operator<(const ColElementItr& rhs) const{
    if (step !=  rhs.step){
        return false;
    }
    else if (rhs.step > 0){
        return position < rhs.position;
    }
    else{
        return position > rhs.position;
    }
}

bool ColElementItr::operator>(const ColElementItr& rhs) const{
    return !(*this < rhs || *this == rhs);
}

bool ColElementItr::operator<=(const ColElementItr& rhs) const{
    return *this == rhs || *this < rhs;
}

bool ColElementItr::operator>=(const ColElementItr& rhs) const{
    return *this == rhs || *this > rhs;
}