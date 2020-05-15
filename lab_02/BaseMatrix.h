#ifndef CPP17TEST_BASEMATRIX_H
#define CPP17TEST_BASEMATRIX_H
#include <cstdlib>

class BaseMatrix {
public:
    BaseMatrix() = default;
    virtual ~BaseMatrix() = default;
    bool isEmpty() const { return (row == 0 || col == 0); };
    size_t getRows(void) const { return row; };
    size_t getColumns(void) const { return col; };


protected:
    size_t row;
    size_t col;
};


#endif //CPP17TEST_BASEMATRIX_H
