//
// Created by Serg on 31.05.2019.
//

#include "OcvOclMatrix.h"

template <typename T>;

OcvOclMatrix::OcvOclMatrix<T>() {

}

OcvOclMatrix::~OcvOclMatrix<T>() {

}

Matrix<T> OcvOclMatrix::operator*() {
    return &this;
}
