#ifndef CPP17TEST_ARRAY_H
#define CPP17TEST_ARRAY_H
#include <memory>
#include <cstdlib>
#include "errors.h"

template <typename T>
class Array
{
private:
    std::shared_ptr<T []> mas;
    size_t size;
public:
    Array();
//    Array(std::shared_ptr<T []>arr);
    Array(size_t size);
    ~Array() {mas = nullptr; };
    T& operator[] (int id);
};

//template<typename T>
//Array<T>::Array(std::shared_ptr<T []> arr) {
//    mas = arr;
//}

template<typename T>
Array<T>::Array() {
    mas = nullptr;
}

template<typename T>
T& Array<T>::operator[](int id)  {
    if (id < 0 || id > size - 1)
    {
        throw badIndexError(__FILE__, typeid(*this).name(), __LINE__);
    }
    return mas[id];
}

template<typename T>
Array<T>::Array(size_t size) {
    mas = std::shared_ptr<T[]>(new T[size]);
    this->size = size;
}

#endif //CPP17TEST_ARRAY_H
