#ifndef CPP17TEST_ITERATORIMP_HPP
#define CPP17TEST_ITERATORIMP_HPP

template<typename T>
T& Iterator<T>::operator*() {
    checkInd();
    checkValid();
    std::shared_ptr<Array<T> []> tmp(ptr);
    return tmp[ind / col][ind % col];
}

template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
    if (ind < row * col)
        ind++;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator<T> it(*this);

    ++(*this);

    return it;
}
template <typename T>
T* Iterator<T>::operator->()
{
    checkInd();
    checkValid();
    std::shared_ptr<Array<T> []> tmp(ptr);
    return &tmp[ind / col][ind % col];
}


template<typename T>
void Iterator<T>::checkInd() {
    if (ind < 0 || ind > (row * col))
    {
        time_t curr_time;
        time(&curr_time);
        throw badIteratorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
}

template<typename T>
void Iterator<T>::checkValid() {
    if (ptr.expired())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
}

template<typename T>
const T &Iterator<T>::operator*() const {
    return operator *();
}

template<typename T>
const T *Iterator<T>::operator->() const {
    return operator->();
}

template<typename T>
Iterator<T>::operator bool() const {
    return ptr.expired();
}



#endif //CPP17TEST_ITERATORIMP_HPP
