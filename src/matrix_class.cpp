#include<iostream>
#include<memory>
#include <chrono>
#include <thread>

#include <initializer_list>

template<class s_t>
class Matrix {

public:
    s_t *data;
    int n_rows;
    int n_cols;

public:
    Matrix(int n_rows, int n_cols) : data(0), n_rows(n_rows), n_cols(n_cols) {
        allocate();
    }


    Matrix(const std::initializer_list<std::initializer_list<s_t>> &rhs) : data(0) {
        n_rows = rhs.size();

        int i = 0;
        for (auto &row:rhs) {

            if (i == 0) {
                n_cols = row.size();
                allocate();
            }

            int j = 0;
            for (auto &elem:row) {
                operator()(i, j) = elem;
                j++;
            }
            i++;
        }
    }

// copy constructor
    Matrix(const Matrix &rhs) : data(0) {
        std::cout << "Calling Matrix copy constructor, this=" << this << "\t &rhs=" << &rhs << std::endl;

        n_cols = rhs.n_cols;
        n_rows = rhs.n_rows;
        allocate();

        memcpy(data, rhs.data, sizeof(s_t) * n_rows * n_cols);
    }

    // destructor

    ~ Matrix() {
        delete[]data;
    }

// overloading = operator
    Matrix &operator=(const Matrix &rhs) {
        std::cout << "calling operator=" << std::endl;
        n_cols = rhs.n_cols;
        n_rows = rhs.n_rows;
        //allocate();

        memcpy(data, rhs.data, sizeof(s_t) * n_rows * n_cols);
        return *this;
    }

// overloading + operator
    Matrix operator+(Matrix &rhs) {

        Matrix result(n_rows, n_cols);

        // std::cout << "Calling Matrix operator+, this=" << this << "\t &rhs=" << &rhs << "\t" << "&return=" << &result
        //         << "\tresult.data=" << result.data << std::endl;

        Matrix &lhs = *this;

        if (rhs.n_rows != n_rows or rhs.n_cols != n_cols)
            throw std::runtime_error("shape mismatch");

        for (int i = 0; i < n_rows; i++)
            for (int j = 0; j < n_cols; j++)
                result(i, j) = lhs(i, j) + rhs(i, j);
        //result(i,j)= this->operator()(i,j)+ rhs(i,j);

        return result;
    }

// overloading () operator to access elements of matrix
    s_t &operator()(int i, int j) {
        if (data == nullptr)
            throw std::runtime_error("not initialized");
        return data[n_cols * i + j];
    }

// fill matrix elements with constant value
//    void fill(s_t k) {
//        for (int i = 0; i < n_rows; i++)
//            for (int j = 0; j < n_cols; j++)
//                operator()(i, j) = k;
//   }

private:
    void allocate() {
        if (data != 0)
            throw std::runtime_error("already allocated");

        data = new s_t[n_cols * n_rows];
        //data = (s_t *) malloc(sizeof(s_t) * n_cols * n_rows);
    }

    friend std::ostream &operator<<(std::ostream &lhs, Matrix<s_t> &rhs);
};

std::ostream &operator<<(std::ostream &lhs, Matrix<int> &rhs) {
    for (int i = 0; i < rhs.n_rows; i++)
        for (int j = 0; j < rhs.n_cols; j++)
            lhs << rhs(i, j) << " ";
    return lhs;


}

int main() {


// test for memory leak
        for (int i = 0; i < 1000; i++) {
            Matrix<int> A({{0, 0},
                           {1, 1}});
            Matrix<int> B({{1, 1},
                           {0, 0}});

            auto S = A + B;
        }
        std::cout << "ping" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));


}

