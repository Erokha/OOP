#ifndef CPP17TEST_MATRIXMATH_HPP
#define CPP17TEST_MATRIXMATH_HPP

#include "../Matrix.h"

const double EPS = 1e-5;


template<typename T>
void Matrix<T>::transpose() {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if (isSquare())
    {
        for (int i = 0; i < row; i ++) {
            for (int j = i; j < col; j++) {
                T save = array[i][j];
                array[i][j] = array[j][i];
                array[j][i] = save;
            }
        }
    } else {
        Matrix<T> tmp(col, row);
        for (int i = 0; i < tmp.row; i++)
        {
            for (int j = 0; j < tmp.col; j++)
            {
                tmp[i][j] = array[j][i];
            }
        }
        *this = Matrix(tmp);
    }
}

template<typename T>
double Matrix<T>::getDeterminant() const {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if (!isSquare())
    {
        time_t curr_time;
        time(&curr_time);
        throw UnableToFindDeterminant(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }


    auto matrix = Matrix(*this);

    if (matrix.getRows() == 2)
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    if (matrix.getRows() == 1)
        return matrix[0][0];

    T res = {};
    for (size_t i = 0; i < matrix.getRows(); ++i) {
        Matrix<T> tmp = Matrix(this->exclude(0, i));
        T minor = tmp.getDeterminant();
        if (i % 2)
            minor = -minor;
        res += minor * matrix[0][i];
    }

    return res;
}

template<typename T>
void Matrix<T>::inverse() {
    T det = this->getDeterminant();
    if (!isSquare() || !det) {
        time_t curr_time;
        time(&curr_time);
        throw UnableToInverse(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }

    Matrix<T> res(row, col);
    (Matrix<T>(row - 1, col - 1));
    T value;

    for (size_t i = 0; i < row; ++i)
        for (size_t j = 0; j < col; ++j)
        {
            Matrix<T> tmp = Matrix(this->exclude(i, j));
            value = tmp.getDeterminant() / det;
            if ((i + j) & 1)
                value = -value;
            res[j][i] = value;
        }

    *this = res;
}



#endif //CPP17TEST_MATRIXMATH_HPP
