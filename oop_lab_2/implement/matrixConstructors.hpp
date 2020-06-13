
#ifndef CPP17TEST_MATRIXCONSTRUCTORS_HPP
#define CPP17TEST_MATRIXCONSTRUCTORS_HPP

#include "../Matrix.h"

template<typename T>
Matrix<T>::Matrix(int row, int col) {
    if (row <= 0 || col <= 0)
    {
        time_t curr_time;
        time(&curr_time);
        throw badInitSizes(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    this->col = col;
    this->row = row;

    allocateMemory();

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            array[i][j] = 0;
        }
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix &other) {
    this->row = other.row;
    this->col = other.col;

    allocateMemory();

    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            array[i][j] = other.array[i][j];
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
Matrix<T>::Matrix(Iterator<T> st, Iterator<T> ed, int row, int col)
{
    this->row = row;
    this->col = col;
    int ind = 0;
    while (st != ed)
    {
        (*this)[ind / col][ind % col] = *st;
        st++;
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    this->array.reset();
    col = row = 0;
}

template<typename T>
Matrix<T>::Matrix(Matrix &&other) noexcept {
    this->row = other.row;
    this->col = other.col;
    this->array = other.array;
    other.array.reset();
}

template<typename T>
Matrix<T>::Matrix(T **mas, int row, int col) {
    if (mas == nullptr)
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    this->row = row;
    this->col = col;
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = mas[i][j];
        }
    }
}


template<typename T>
Matrix<T>& Matrix<T>::operator = (const Matrix &other) {
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

template<typename T>
Matrix<T>& Matrix<T>::operator = (Matrix &&other) noexcept {
    row = other.row;
    col = other.col;
    array = other.array;
    return *this;
}






#endif //CPP17TEST_MATRIXCONSTRUCTORS_HPP
