#ifndef OOP_LAB_01_MATRIX_H
#define OOP_LAB_01_MATRIX_H

#include "../defines.h"

struct matrix
{
    int ** mas;
    int size;
};

myErrors freeMyMatrix(matrix& m);

myErrors createMatrix(matrix& m, int size);

myErrors matrixSetElement(matrix& m, int data, int posi, int posj);

int matrixGetElement(matrix &m, int posi, int posj);

myErrors createEmptyMatrix(matrix& m);

myErrors copyMatrix(matrix& source, matrix& dest);

#endif //OOP_LAB_01_MATRIX_H
