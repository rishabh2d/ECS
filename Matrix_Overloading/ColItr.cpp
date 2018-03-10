#include "ColItr.h"
#include "ColElementItr.h"

ColItr::ColItr( Matrix& matrix, int positionSetter, int stepSetter)
        :  position(positionSetter), step(stepSetter), myMatrix(matrix) {}

ColElementItr ColItr::operator*(){

    return ColElementItr(*this, 0);
}

ColItr& ColItr::operator++(){
    step = 1;
    position += step;
    return *this;
}

ColItr& ColItr::operator++(int){
    return ++(*this);
}

ColItr& ColItr::operator--(){
    step = 1;
    position -= step;
    return *this;
}

ColItr& ColItr::operator--(int){
    return --(*this);
}

ColItr& ColItr::operator+=(const int& rhs){
    step = rhs;
    position += step;
    return *this;
}

ColItr ColItr::operator+(const int& rhs){
    ColItr copy (*this);
    copy.position += rhs;
    return copy;
}

ColItr& ColItr::operator-=(const int& rhs){
    step = rhs;
    position -= step;
    return *this;
}

ColItr ColItr::operator-(const int& rhs){
    ColItr copy(*this);
    copy.position-= rhs;
    return copy;
}

ColItr::operator bool() const{
    if (position >= 0 && position < myMatrix.getNumRows()){
        return true;
    }
    else{
        return false;
    }
}

bool ColItr::operator!() const{
    if (position >= 0 && position < myMatrix.getNumRows()){
        return true;
    }
    else{
        return false;
    }
}

bool ColItr::operator==(const ColItr& rhs) const{
    if (&step != &rhs.step){
        return false;
    }
    else if(!*this && !rhs){
        return true;
    }
    else{
        return position == rhs.position;
    }
}

bool ColItr::operator!=(const ColItr& rhs) const{
    return !(*this == rhs);
}

bool ColItr::operator<(const ColItr& rhs) const{
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

bool ColItr::operator>(const ColItr& rhs) const{
    return !(*this < rhs || *this == rhs);
}

bool ColItr::operator<=(const ColItr& rhs) const{
    return *this == rhs || *this < rhs;
}

bool ColItr::operator>=(const ColItr& rhs) const{
    return *this == rhs || *this > rhs;
}

double& ColItr::operator[](int i){

    return myMatrix.myMatrix.at(static_cast<unsigned long>(i)).at(static_cast<unsigned long>(position));
}

void ColItr::setPosition (int setter){
    position = setter;
}
int ColItr::getPosition (){
    return position;
}

ColElementItr ColItr::begin() {
    return ColElementItr(*this, 0);
}

ColElementItr ColItr::end() {
    return ColElementItr(*this, myMatrix.getNumRows());
}