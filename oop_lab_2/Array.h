#ifndef CPP17TEST_ARRAY_H
#define CPP17TEST_ARRAY_H
#include <memory>
#include <cstdlib>
#include "errors.h"
#include <ctime>

template <typename T>
class Array
{
private:
    std::shared_ptr<T []> mas;
    size_t size;
public:
    Array();
    explicit Array(size_t size);
    Array(const Array& other);
    ~Array() {mas = nullptr; };
    Array<T>& operator = (const Array& other);
    Array<T>& operator *= (const T& value);
    Array<T>& operator -= (const Array& other);
    const T& getElement(unsigned int i) const;
    int getSize() const;
    T& operator[] (int id);
};


template<typename T>
Array<T>::Array() {
    mas = nullptr;
}

template<typename T>
T& Array<T>::operator[](int id)  {
    if (id < 0 || id > size - 1)
    {
        time_t curr_time;
        time(&curr_time);
        throw badIndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    return mas[id];
}

template<typename T>
Array<T>::Array(size_t size) {
    mas = std::shared_ptr<T[]>(new T[size]);
    this->size = size;
}

template<typename T>
Array<T>::Array(const Array &other) {
    size = other.size;
    mas = std::shared_ptr<T[]>(new T[size]);
    for (int i = 0; i < size; i++)
    {
        this->mas[i] = other.mas[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    size = other.size;
    mas.reset();
    mas = std::shared_ptr<T[]>(new T[size]);
    for (int i = 0; i < size; i++)
    {
        this->mas[i] = other.mas[i];
    }
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator-=(const Array &other) {
    for(int i = 0; i < size; i++)
    {
        this->mas[i] -= other.mas[i];
    }
    return (*this);
}

template<typename T>
Array<T>& Array<T>::operator*=(const T &value) {
    for(int i = 0; i < size; i++)
    {
        this->mas[i] *= value;
    }
    return (*this);
}

template<typename T>
const T &Array<T>::getElement(unsigned int i) const {
    return mas[i];
}

template<typename T>
int Array<T>::getSize() const {
    return size;
}


template<typename T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& arr)
{
    size_t size = arr.getSize();
    for (size_t i = 0; i < size; ++i) {
        stream << arr.getElement(i) << " ";
    }
    stream << std::endl;
    return stream;
}

#endif //CPP17TEST_ARRAY_H
