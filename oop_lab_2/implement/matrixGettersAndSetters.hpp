#ifndef CPP17TEST_MATRIXGETTERSANDSETTERS_HPP
#define CPP17TEST_MATRIXGETTERSANDSETTERS_HPP


#include "../Matrix.h"

template<typename T>
const T& Matrix<T>::getElement(unsigned int i, unsigned int j) const {
    checkIndex(i, j);
    return this->array[i][j];
}

template<typename T>
T &Matrix<T>::getElement(unsigned int i, unsigned int j) {
    checkIndex(i, j);
    return (*this)[i][j];
}

template<typename T>
void Matrix<T>::setElement(unsigned int i, unsigned int j, const T &value) {
    checkIndex(i, j);
    (*this)[i][j] = value;
}

template<typename T>
T& Matrix<T>::operator()(unsigned int i, unsigned int j) {
    return getElement(i, j);
}

template<typename T>
const Array<T> &Matrix<T>::operator[](int id) const {
    return this->array[id];
}

template <typename T>
Array<T>& Matrix<T>::operator[](int id)
{
    if (id < 0 || id > row - 1)
    {
        time_t curr_time;
        time(&curr_time);
        throw badIndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    return array[id];
}


#endif //CPP17TEST_MATRIXGETTERSANDSETTERS_HPP
