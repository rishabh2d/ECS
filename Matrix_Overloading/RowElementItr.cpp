#include "RowElementItr.h"
#include "Matrix.h"

RowElementItr::RowElementItr( RowItr &rowItrSetter, int positionSetter, int stepSetter)
        :  position(positionSetter), step(stepSetter), rowItr(rowItrSetter) {}


double& RowElementItr::operator*(){
    return rowItr.myMatrix.myMatrix.at(static_cast<unsigned long>(rowItr.position)).at(static_cast<unsigned long>(position));
}

RowElementItr& RowElementItr::operator++(){
    position++;
    return *this;
}

RowElementItr& RowElementItr::operator++(int){
    return ++(*this);
}

RowElementItr& RowElementItr::operator--(){
    position--;
    return *this;
}

RowElementItr& RowElementItr::operator--(int){
    return --(*this);
}

RowElementItr& RowElementItr::operator+=(const int& rhs){
    step = rhs;
    position += step;
    return *this;
}

RowElementItr RowElementItr::operator+(const int& rhs){
    RowElementItr copy (*this);
    copy.position += rhs;
    return copy;
}

RowElementItr& RowElementItr::operator-=(const int& rhs){
    step = rhs;
    position -= step;
    return *this;
}

RowElementItr RowElementItr::operator-(const int& rhs){
    RowElementItr copy(*this);
    copy.position-= rhs;
    return copy;
}

RowElementItr::operator bool() const{
    if (position >= 0 && position < rowItr.myMatrix.getNumCols()){
        return true;
    }
    else{
        return false;
    }
}

bool RowElementItr::operator!() const{
    if (position >= 0 && position < rowItr.myMatrix.getNumCols()){
        return true;
    }
    else{
        return false;
    }
}

bool RowElementItr::operator==(const RowElementItr& rhs) const{
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

bool RowElementItr::operator!=(const RowElementItr& rhs) const{
    return !(*this == rhs);
}

bool RowElementItr::operator<(const RowElementItr& rhs) const{
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

bool RowElementItr::operator>(const RowElementItr& rhs) const{
    return !(*this < rhs || *this == rhs);
}

bool RowElementItr::operator<=(const RowElementItr& rhs) const{
    return *this == rhs || *this < rhs;
}

bool RowElementItr::operator>=(const RowElementItr& rhs) const{
    return *this == rhs || *this > rhs;
}
