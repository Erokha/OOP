#ifndef CPP17TEST_MATRIX_H
#define CPP17TEST_MATRIX_H
#include <memory>
#include <cstdlib>
#include "BaseMatrix.h"
#include "Array.h"
#include <iostream>
#include <initializer_list>
#include "assert.h"
#include "errors.h"

template<typename T>
class Matrix : public BaseMatrix
{
private:
    std::shared_ptr<Array<T> []> array;


public:
    Array<T>& operator[](int id);

    Matrix();
    Matrix(int row, int col);
    Matrix(const Matrix& other);
    Matrix(std::initializer_list<std::initializer_list<T>> lst);
    ~Matrix() override;


    void print();
    T getElement(size_t i, size_t j) const { return this->array[i][j]; };
    Matrix<T>& add(const Matrix& other);
    Matrix<T>& sub(const Matrix& other);
    Matrix<T>& mul(const T value);
    Matrix<T>& mul(const Matrix& other);
    Matrix<T>& div(const T value);

    Matrix& operator= (const Matrix& other);

    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator+(const T value) = delete;
    Matrix<T>& operator+= (const T value) = delete;
    Matrix<T>& operator+=(const Matrix<T>& other)  { return add(other); };

    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator-(const T value) = delete;
    Matrix<T>& operator-= (const T value) = delete;
    Matrix<T>& operator-=(const Matrix<T>& other) { return sub(other); };

    Matrix<T> operator/(const Matrix<T>& other) = delete;
    Matrix<T> operator/(const T value);
    Matrix<T>& operator/= (const T value) { return div(value); };
    Matrix<T>& operator/=(const Matrix<T>& other) = delete;

    Matrix<T> operator*(const Matrix<T>& other);
    Matrix<T> operator*(const T value);
    Matrix<T>& operator*= (const T value) { return mul(value); };
    Matrix<T>& operator*= (const Matrix<T>& other) { return mul(other); };

};

template <typename T>
Matrix<T>::Matrix() {
    this->col = 0;
    this->row = 0;
    this->array.reset();
}

template<typename T>
Matrix<T>::Matrix(int row, int col) {
    if (row <= 0 || col <= 0)
    {
        throw badInitSizes(__FILE__, typeid(*this).name(), __LINE__);
    }
    this->col = col;
    this->row = row;

    array = std::shared_ptr<Array<T> []>(new Array<T>[row]);
    for (size_t i = 0; i < row; i++)
        array[i] = Array<T>(col);

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            array[i][j] = i * col + j;
        }
    }

}

template<typename T>
Matrix<T>::Matrix(const Matrix &other) {
    this->row = other.row;
    this->col = other.col;

    array = std::shared_ptr<Array<T> []>(new Array<T>[row]);
    for (size_t i = 0; i < row; i++)
        array[i] = Array<T>(col);

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            array[i][j] = other.array[i][j];//other->array[i][j];
        }
    }
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> lst)
{
    (*this) = Matrix(lst.size(), lst.size() ? lst.begin()->size() : 0);
    size_t i = 0, j = 0;
    for (const auto& l : lst)
    {
        for (const auto& v : l)
        {
            array[i][j] = v;
            ++j;
        }
        j = 0;
        ++i;
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    this->array.reset();
    col = row = 0;
}

template<typename T>
void Matrix<T>::print() {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            std::cout.width(4);
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
}

template<typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix &other) {
    this->col = other.col;
    this->row = other.col;

    this->array.reset();

    array = std::shared_ptr<Array<T> []>(new Array<T>[row]);
    for (size_t i = 0; i < row; i++)
        array[i] = Array<T>(col);

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            array[i][j] = other.array[i][j];
        }
    }
    return *this;
}

template <typename T>
Array<T>& Matrix<T>::operator[](int id)
{
    if (id < 0 || id > row - 1)
    {
        throw badIndexError(__FILE__, typeid(*this).name(), __LINE__);
    }
    return array[id];
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    auto res = Matrix(*this);
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            res.array[i][j] += other.array[i][j];
        }
    }
    return res;
}

//template<typename T>
//Matrix<T>& Matrix<T>::add(T value) {
//    for (size_t i = 0; i < this->row; i++) {
//        for (size_t j = 0; j < this->col; j++) {
//            this->array[i][j] += value;
//        }
//    }
//    return *this;
//}

template<typename T>
Matrix<T>& Matrix<T>::add(const Matrix<T>& other) {
    if ((this->col != other.col) || (this->row != other.row))
    {
        throw nonEqualSizesError(__FILE__, typeid(*this).name(), __LINE__);
    }
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            this->array[i][j] += other.array[i][j];
        }
    }
    return *this;
}


template<typename T>
Matrix<T> &Matrix<T>::sub(const Matrix &other) {
    if ((this->col != other.col) || (this->row != other.row))
    {
        throw nonEqualSizesError(__FILE__, typeid(*this).name(), __LINE__);
    }
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            this->array[i][j] -= other.array[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &other) const {
    if ((this->col != other.col) || (this->row != other.row))
    {
        throw nonEqualSizesError(__FILE__, typeid(*this).name(), __LINE__);
    }
    auto res = Matrix(*this);
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            res.array[i][j] -= other.array[i][j];
        }
    }
    return res;
}

template<typename T>
Matrix<T> &Matrix<T>::mul(const T value) {
    if (this->isEmpty())
    {
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__);
    }
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            this->array[i][j] *= value;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::div(const T value) {
    if (this->isEmpty())
    {
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__);
    }
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            this->array[i][j] /= value;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T value) {
    if (value == 0)
    {
        throw divisionByZeroError(__FILE__, typeid(*this).name(), __LINE__);
    }
        auto res = Matrix(*this);
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            res.array[i][j] /= value;
        }
    }
    return res;
}

template<typename T>
Matrix<T> &Matrix<T>::mul(const Matrix &other) {
    if (this->col != other.row)
    {
        throw badMultiplySizes(__FILE__, typeid(*this).name(), __LINE__);
    }
    if (this->isEmpty() || other.isEmpty())
    {
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__);
    }
    auto res = Matrix(*this);
    for (int i = 0; i < res.row; i++)
    {
        for (int j = 0; j < res.col; j++)
        {
            this->array[i][j] = 0;
            for (int k = 0; k < this->col; k++)
                this->array[i][j] += res.array[i][k] * other.array[k][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) {
    if (this->col != other.row)
    {
        throw badMultiplySizes(__FILE__, typeid(*this).name(), __LINE__);
    }
    if (this->isEmpty() || other.isEmpty())
    {
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__);
    }
    auto res = Matrix(*this);
    for (int i = 0; i < res.row; i++)
    {
        for (int j = 0; j < res.col; j++)
        {
            res.array[i][j] = 0;
            for (int k = 0; k < this->col; k++)
                res.array[i][j] += this->array[i][k] * other.array[k][j];
        }
    }
    return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T value) {
    if (this->isEmpty())
    {
        throw emptyError(__FILE__, typeid(*this).name(), __LINE__);
    }
    auto res = Matrix(*this);
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            res.array[i][j] *= value;
        }
    }
    return res;
}

template<class T>
std::ostream& operator<<(std::ostream& stream, const Matrix<T>& matrix)
{
    size_t r = matrix.getRows();
    size_t c = matrix.getColumns();
    for (size_t i = 0; i < r; ++i)
    {
        for (size_t j = 0; j < c; ++j) {
            stream.width(4);
            stream << matrix.getElement(i, j);
        }
        stream << std::endl;
    }
    return stream;
}


#endif //CPP17TEST_MATRIX_H
