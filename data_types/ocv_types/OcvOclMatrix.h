//
// Created by Serg on 31.05.2019.
//

#ifndef OCVOCLMATRIX_H
#define OCVOCLMATRIX_H

#include "../Matrix.h"

template <typename T> class OcvOclMatrix : public Matrix<T>  {
public:
    OcvOclMatrix<T>();

    ~OcvOclMatrix<T>();

    Matrix<T> operator*();

};


#endif //OCVOCLMATRIX_H
