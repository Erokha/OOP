#ifndef CPP17TEST_MATRIXPLUSMINUS_HPP
#define CPP17TEST_MATRIXPLUSMINUS_HPP


template<typename T>
Matrix<T> Matrix<T>::addedBy(const Matrix &other) const {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if ((this->col != other.col) || (this->row != other.row))
    {
        time_t curr_time;
        time(&curr_time);
        throw nonEqualSizesError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    auto res = Matrix(*this);
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            res[i][j] = this->array[i][j] + other.array[i][j];
        }
    }
    return res;
}

template<typename T>
Matrix<T>& Matrix<T>::add(const Matrix<T>& other) {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if ((this->col != other.col) || (this->row != other.row))
    {
        time_t curr_time;
        time(&curr_time);
        throw nonEqualSizesError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            this->array[i][j] += other.array[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::sub(const Matrix &other) {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if ((this->col != other.col) || (this->row != other.row))
    {
        time_t curr_time;
        time(&curr_time);
        throw nonEqualSizesError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            this->array[i][j] -= other.array[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::subbedBy(const Matrix &other) const {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    if ((this->col != other.col) || (this->row != other.row))
    {
        time_t curr_time;
        time(&curr_time);
        throw nonEqualSizesError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    auto res = Matrix(*this);
    for (size_t i = 0; i < this->row; i++) {
        for (size_t j = 0; j < this->col; j++) {
            res[i][j] = this->array[i][j] - other.array[i][j];
        }
    }
    return res;
}

template<typename T>
Matrix<T> &Matrix<T>::add(std::initializer_list<std::initializer_list<T>> lst) {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    auto b = Matrix<T>(lst);
    *this += b;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::addedBy(std::initializer_list<std::initializer_list<T>> lst) const {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    auto b = Matrix<T>(lst);
    auto c = *this + b;
    return c;
}

template<typename T>
Matrix<T> &Matrix<T>::sub(std::initializer_list<std::initializer_list<T>> lst) {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    auto b = Matrix<T>(lst);
    *this -= b;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::subbedBy(std::initializer_list<std::initializer_list<T>> lst) const {
    if (this->isEmpty())
    {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curr_time));
    }
    auto b = Matrix<T>(lst);
    auto c = *this - b;
    return c;
}

#endif //CPP17TEST_MATRIXPLUSMINUS_HPP
