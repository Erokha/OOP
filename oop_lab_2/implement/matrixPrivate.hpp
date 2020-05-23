#ifndef CPP17TEST_MATRIXPRIVATE_HPP
#define CPP17TEST_MATRIXPRIVATE_HPP


#include "../Matrix.h"

template<typename T>
void Matrix<T>::allocateMemory() {
    if (row <= 0 || col <= 0)
    {
        time_t curr_time;
        time(&curr_time);
        throw badMemoryAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    array = std::shared_ptr<Array<T> []>(new Array<T>[row]);
    for (size_t i = 0; i < row; i++)
        array[i] = Array<T>(col);
}



template<typename T>
void Matrix<T>::checkIndex(int i, int j) const {
    if ((i < 0 || j < 0) || (i >= row || j >= col))
    {
        time_t curr_time;
        time(&curr_time);
        throw badIndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
}

template<typename T>
Matrix<T> Matrix<T>::exclude(size_t ex_row, size_t ex_col) const{
    auto res = Matrix(row - 1, col - 1);
    int ri, ci;
    for (size_t i = 0; i < row - 1; ++i)
        for (size_t j = 0; j < col - 1; ++j) {
            ri = i >= ex_row ? i + 1 : i;
            ci = j >= ex_col ? j + 1: j;
            res[i][j] = this->array[ri][ci];
        }
    return res;
}




template<typename T>
Matrix<T> Matrix<T>::unitMatrix(int size) {
    auto res = Matrix<T>(size, size);
    for (int i = 0; i < size; i++)
    {
        res[i][i] = 1;
    }
    return res;
}



#endif //CPP17TEST_MATRIXPRIVATE_HPP
