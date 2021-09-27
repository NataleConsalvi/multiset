#ifndef DENSE_MATRIX_H
#define DENSE_MATRIX_H

#include "Matrix.h"
#include <vector>
#include <algorithm>
#include <tuple>

template <typename T>
class DenseMatrix : public Matrix<T>{
    
    public:
        virtual DenseMatrix<T> operator+(const Matrix<T>& other) const{

        }

        virtual DenseMatrix<T> operator +=(const Matrix<T>& other) {

        }
};

#endif //DENSE_MATRIX_H