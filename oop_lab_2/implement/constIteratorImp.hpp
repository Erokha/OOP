#ifndef CPP17TEST_CONSTITERATORIMP_HPP
#define CPP17TEST_CONSTITERATORIMP_HPP



template<typename T>
const T& ConstIterator<T>::operator*() const {
    checkInd();
    checkValid();
    std::shared_ptr<Array<T> []> tmp(ptr);
    return tmp[ind / col][ind % col];
}

template<typename T>
ConstIterator<T>& ConstIterator<T>::operator++() {
    if (ind < row * col)
        ind++;

    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
    ConstIterator<T> it(*this);

    ++(*this);

    return it;
}
template <typename T>
const T* ConstIterator<T>::operator->() const {
    checkInd();
    checkValid();
    std::shared_ptr<Array<T> []> tmp(ptr);
    return &tmp[ind / col][ind % col];
}

template<typename T>
void ConstIterator<T>::checkInd() {
    if (ind < 0 || ind > row * col)
    {
        time_t curr_time;
        time(&curr_time);
        throw badIteratorIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
}

template<typename T>
void ConstIterator<T>::checkValid() {
    if (ptr.expired())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
}

template<typename T>
ConstIterator<T>::operator bool() const {
    return ptr.expired();
}


#endif //CPP17TEST_CONSTITERATORIMP_HPP
