#pragma once

#include <iostream>
#include<memory>

namespace kmm {

    template<class s_t>
    class Matrix {

    private:
        s_t *data;
        int n_rows;
        int n_cols;

        // constructors
    public:
        Matrix(int n_rows, int n_cols);
           // allocate();
           
        Matrix(const std::initializer_list<std::initializer_list<s_t>> &rhs) ;

        // copy constructor
        Matrix(const Matrix &rhs);

        ~ Matrix();


        // overload operators

        Matrix & operator=(const Matrix &rhs);
        Matrix operator+(Matrix &rhs);

        s_t &operator()(int i, int j);

    private:
        void allocate();


        friend std::ostream &operator<<(std::ostream &lhs, Matrix<s_t> &rhs);

    }; // of class

}// of namespace


#include "libkmMatrix.hpp"