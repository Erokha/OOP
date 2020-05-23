#ifndef CPP17TEST_MATRIXMULTIPLYDIVISION_HPP
#define CPP17TEST_MATRIXMULTIPLYDIVISION_HPP

#include "../Matrix.h"

template<typename T>
Matrix<T> &Matrix<T>::div(const T& value) {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if (value == 0)
    {
        time_t curr_time;
        time(&curr_time);
        throw divisionByZeroError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    for (auto& element : *this)
    {
        element /= value;
    }

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::divedBy(const T& value) const {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if (value == 0)
    {
        time_t curr_time;
        time(&curr_time);
        throw divisionByZeroError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    auto res = Matrix(*this);
    for (auto& element : res)
    {
        element /= value;
    }

    return res;
}

template<typename T>
Matrix<T> &Matrix<T>::mul(const T& value) {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    for (auto& element : *this)
    {
        element *= value;
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::multipliedBy(const T& value) const {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    auto res = Matrix(*this);

    for (auto& element : res)
    {
        element *= value;
    }
    return res;
}

template<typename T>
Matrix<T>& Matrix<T>::mul(const Matrix &other) {
    if (this->col != other.row)
    {
        time_t curr_time;
        time(&curr_time);
        throw badMultiplySizes(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if (this->isEmpty() || other.isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
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
Matrix<T> Matrix<T>::multipliedBy(const Matrix &other) const {
    if (this->col != other.row)
    {
        time_t curr_time;
        time(&curr_time);
        throw badMultiplySizes(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if (this->isEmpty() || other.isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    auto res = Matrix(*this);
    for (int i = 0; i < res.row; i++)
    {
        for (int j = 0; j < res.col; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < this->col; k++)
                res[i][j] += this->array[i][k] * other.array[k][j];
        }
    }
    return res;
}

template<typename T>
Matrix<T>& Matrix<T>::mul(std::initializer_list<std::initializer_list<T>> lst) {
    auto b = Matrix<T>(lst);
    *this *= b;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::multipliedBy(std::initializer_list<std::initializer_list<T>> lst) const{
    auto b = Matrix<T>(lst);
    auto c = *this * b;
    return c;
}

#endif //CPP17TEST_MATRIXMULTIPLYDIVISION_HPP
