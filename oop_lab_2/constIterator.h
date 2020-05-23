#ifndef CPP17TEST_CONSTITERATOR_H
#define CPP17TEST_CONSTITERATOR_H

#include <memory>
#include <cstring>
#include "errors.h"
#include <ctime>


template <typename T>
class Matrix;
template <typename T>
class Array;
template <typename T>
class ConstIterator: public std::iterator<std::output_iterator_tag, T> {
    friend class Matrix<T>;
public:

    bool operator != (ConstIterator const& other) const { return ind != other.ind; };
    bool operator == (ConstIterator const& other) const { return ind == other.ind; };
    bool operator < (ConstIterator const& other) const { return ind < other.ind; };
    bool operator <= (ConstIterator const& other) const { return ind <= other.ind; };
    bool operator > (ConstIterator const& other) const { return ind > other.ind; };
    bool operator >= (ConstIterator const& other) const { return ind >= other.ind; };
    ConstIterator<T>& operator++();
    ConstIterator<T> operator++(int);
    const T& operator*() const;
    const T* operator->() const;
    operator bool() const;



private:
    ConstIterator(const std::shared_ptr<Array<T> []> mas, const size_t rows,
                  size_t cols, size_t index = 0) : ptr(mas), row(rows), col(cols), ind(index) {}
    std::weak_ptr<Array<T> []> ptr;
    void checkInd();
    void checkValid();
    size_t row;
    size_t col;
    size_t ind = 0;
};


#include "implement/constIteratorImp.hpp"
#endif //CPP17TEST_CONSTITERATOR_H
