
#ifndef CPP17TEST_MATRIXINOUTOPERATORS_HPP
#define CPP17TEST_MATRIXINOUTOPERATORS_HPP

template<class T>
std::ostream& operator<<(std::ostream& stream, const Matrix<T>& matrix)
{
    size_t r = matrix.getRows();
    size_t c = matrix.getColumns();
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            stream.width(4);
            stream << matrix.getElement(i, j);
        }
        stream << std::endl;
    }
    return stream;
}

template<class T>
std::istream& operator>>(std::istream& stream, Matrix<T>& matrix)
{
    if (matrix.isEmpty()) {
        time_t curr_time;
        time(&curr_time);
        throw EmptyError(__FILE__, typeid(matrix).name(), __LINE__, ctime(&curr_time));
    }
    size_t r = matrix.getRows();
    size_t c = matrix.getColumns();
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            stream >> matrix[i][j];
        }
    }
    return stream;
}

#endif //CPP17TEST_MATRIXINOUTOPERATORS_HPP
