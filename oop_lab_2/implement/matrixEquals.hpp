#ifndef CPP17TEST_MATRIXEQUALS_HPP
#define CPP17TEST_MATRIXEQUALS_HPP

template<typename T>
bool Matrix<T>::equals(const Matrix &other) const{
    if (this->row != other.row || this->col != other.col)
    {
        return false;
    }
    bool flag = true;
    for (int i = 0; (i < this->row && flag); i++) {
        for (int j = 0; (j < this->col && flag); j++){
            if (this->array[i][j] != other.array[i][j]) {
                flag = false;
            }
        }
    }
    return flag;
}

template<typename T>
bool Matrix<T>::equals(std::initializer_list<std::initializer_list<T>> lst) const {
    int col = lst.begin()->size();
    int row = lst.size();
    if (this->row != lst.size() || this->col != lst.begin()->size()) {
        return false;
    }
    size_t i = 0, j = 0;
    for (const auto& l : lst)
    {
        for (const auto& v : l)
        {
            if (array[i][j] != v) {
                return false;
            }
            ++j;
        }
        j = 0;
        ++i;
    }
    return true;
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(std::initializer_list<std::initializer_list<T>> lst) {
    auto res = Matrix<T>(lst);
    *this = Matrix<T>(res);
    return (*this);
}

#endif //CPP17TEST_MATRIXEQUALS_HPP
