#ifndef CPP17TEST_MATRIX_H
#define CPP17TEST_MATRIX_H
#include <memory>
#include <cstdlib>
#include "BaseMatrix.h"
#include "Array.h"
#include <iostream>
#include <initializer_list>
#include "errors.h"
#include "constIterator.h"
#include "Iterator.h"
#include <ctime>


template<typename T>
class Matrix : public BaseMatrix
{
public:


    Matrix(int row, int col);
    explicit Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    Matrix(T** mas, int row, int col);
    Matrix(Iterator<T> st, Iterator<T> ed, int row, int col);
    Matrix(std::initializer_list<std::initializer_list<T>> lst);
    ~Matrix() override;




    const T& getElement(unsigned int i, unsigned int j) const;
    T& getElement(unsigned int i, unsigned int j);
    void setElement(unsigned int i, unsigned int j, const T& value);
    T& operator ()(unsigned int i, unsigned int j);
    Array<T>& operator[](int id);
    const Array<T>& operator[](int id) const;

    Matrix<T>& operator = (const Matrix& other);
    Matrix<T>& operator = (Matrix&& other) noexcept;
    Matrix<T>& operator = (std::initializer_list<std::initializer_list<T>> lst);

    bool equals (const Matrix & other) const ;
    bool equals (std::initializer_list<std::initializer_list<T>> lst) const ;
    bool operator == (const Matrix& other) const { return equals(other); };
    bool operator == (std::initializer_list<std::initializer_list<T>> lst) const { return equals(lst); };

    bool notEquals (const Matrix & other) const { return !equals(other); };
    bool notEquals (std::initializer_list<std::initializer_list<T>> lst) const { return !equals(lst); };;
    bool operator != (const Matrix& other) const { return notEquals(other); };
    bool operator != (std::initializer_list<std::initializer_list<T>> lst) const { return notEquals(lst); };


    Matrix<T>& add(const Matrix& other);
    Matrix<T> addedBy(const Matrix& other) const;
    Matrix<T>& add(std::initializer_list<std::initializer_list<T>> lst) ;
    Matrix<T> addedBy(std::initializer_list<std::initializer_list<T>> lst) const ;
    Matrix<T> operator+(const Matrix<T>& other) const {return addedBy(other); };
    Matrix<T> operator+(std::initializer_list<std::initializer_list<T>> lst) const {return addedBy(lst); };
    Matrix<T>& operator+=(const Matrix<T>& other)  { return add(other); };
    Matrix<T>& operator+=(std::initializer_list<std::initializer_list<T>> lst)  { return add(lst); };

    Matrix<T>& sub(const Matrix& other);
    Matrix<T>& sub(std::initializer_list<std::initializer_list<T>> lst);
    Matrix<T> subbedBy(const Matrix& other) const;
    Matrix<T> subbedBy(std::initializer_list<std::initializer_list<T>> lst) const;
    Matrix<T> operator-(const Matrix<T>& other) const { return subbedBy(other); };
    Matrix<T> operator-(std::initializer_list<std::initializer_list<T>> lst) const { return subbedBy(lst); };
    Matrix<T>& operator-=(const Matrix<T>& other) { return sub(other); };
    Matrix<T>& operator-=(std::initializer_list<std::initializer_list<T>> lst) { return sub(lst); };

    Matrix<T>& div(const T& value);
    Matrix<T> divedBy(const T& value) const;
    Matrix<T> operator/(const T& value) { return divedBy(value); };
    Matrix<T>& operator/= (const T& value) { return div(value); };

    Matrix<T>& mul(const T& value);
    Matrix<T> multipliedBy(const T& value) const;
    Matrix<T>& mul(const Matrix& other);
    Matrix<T> multipliedBy(const Matrix& other) const;
    Matrix<T>& mul(std::initializer_list<std::initializer_list<T>> lst) ;
    Matrix<T> multipliedBy(std::initializer_list<std::initializer_list<T>> lst) const ;
    Matrix<T> operator*(const Matrix<T>& other) const { return multipliedBy(other); };
    Matrix<T> operator*(const T& value) { return multipliedBy(value); };
    Matrix<T> operator * (std::initializer_list<std::initializer_list<T>> lst) { return multipliedBy(lst); };
    Matrix<T>& operator *= (const T& value) { return mul(value); };
    Matrix<T>& operator *= (std::initializer_list<std::initializer_list<T>> lst)  { return mul(lst); };
    Matrix<T>& operator *= (const Matrix<T>& other) { return mul(other); };


    Iterator<T> begin(){ return Iterator<T>(array, row, col); };
    Iterator<T> end() { return Iterator<T>(array, row, col, row * col); };
    ConstIterator<T> begin() const { return ConstIterator<T>(array, row, col); };
    ConstIterator<T> end() const { return ConstIterator<T>(array, row, col, row * col); };
    ConstIterator<T> cbegin() const { return ConstIterator<T>(array, row, col); };
    ConstIterator<T> cend() const { return ConstIterator<T>(array, row, col, row * col); };


    void transpose();
    double getDeterminant() const;
    void inverse();
    static Matrix<T> unitMatrix(int size);


private:
    Matrix<T> exclude(size_t ex_row, size_t ex_col) const ;
    void allocateMemory();
    std::shared_ptr<Array<T> []> array;
    void checkIndex(int i, int j) const;

};


#include "implement/matrixConstructors.hpp"
#include "implement/matrixGettersAndSetters.hpp"
#include "implement/matrixPlusMinus.hpp"
#include "implement/matrixEquals.hpp"
#include "implement/matrixMultiplyDivision.hpp"
#include "implement/matrixPrivate.hpp"
#include "implement/matrixInOutOperators.hpp"
#include "implement/matrixMath.hpp"
#endif //CPP17TEST_MATRIX_H
