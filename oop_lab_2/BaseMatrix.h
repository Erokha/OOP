#ifndef CPP17TEST_BASEMATRIX_H
#define CPP17TEST_BASEMATRIX_H
#include <cstdlib>


class BaseMatrix {
public:
    BaseMatrix() = default;
    virtual ~BaseMatrix() = 0;
    bool isEmpty() const { return (row == 0 || col == 0); };
    bool isSquare() const { return (row == col); };
    size_t getRows(void) const { return row; };
    size_t getColumns(void) const { return col; };


protected:
    size_t row;
    size_t col;
};

BaseMatrix::~BaseMatrix() = default; // to cpp


#endif //CPP17TEST_BASEMATRIX_H
