#ifndef CPP17TEST_ITERATOR_H
#define CPP17TEST_ITERATOR_H

#include <memory>
#include <cstring>
#include "errors.h"
#include <ctime>


template <typename T>
class Matrix;
template <typename T>
class Array;
template <typename T>
class Iterator: public std::iterator<std::input_iterator_tag, T> {
    friend class Matrix<T>;
public:

    bool operator != (Iterator const& other) const { return ind != other.ind; };
    bool operator == (Iterator const& other) const { return ind == other.ind; };
    bool operator < (Iterator const& other) const { return ind < other.ind; };
    bool operator <= (Iterator const& other) const { return ind <= other.ind; };
    bool operator > (Iterator const& other) const { return ind > other.ind; };
    bool operator >= (Iterator const& other) const { return ind >= other.ind; };

    Iterator<T>& operator++();
    Iterator<T> operator++(int);


    T& operator*();
    T* operator->();
    const T& operator*() const;
    const T* operator->() const;
    operator bool() const;



private:
    Iterator(const std::shared_ptr<Array<T> []> mas, const size_t rows,
                  size_t cols, size_t index = 0) : ptr(mas), row(rows), col(cols), ind(index) {}
    std::weak_ptr<Array<T> []> ptr; // expired
    void checkInd();
    void checkValid();
    size_t row;
    size_t col;
    size_t ind = 0;
};

#include "implement/iteratorImp.hpp"

#endif //CPP17TEST_ITERATOR_H
