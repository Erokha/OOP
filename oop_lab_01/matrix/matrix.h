#ifndef OOP_LAB_01_MATRIX_H
#define OOP_LAB_01_MATRIX_H

#include "../defines.h"

struct matrix
{
    int ** mas;
    int size;
    bool isInited;
};

myErrors matrixFreeMemory(matrix& m);

myErrors createMatrix(matrix& m, int size);

myErrors matrixSetElement(matrix& m, int data, int posi, int posj);

int matrixGetElement(matrix &m, int posi, int posj);

myErrors createEmptyMatrix(matrix& m);

myErrors copyMatrix(matrix& dest, matrix& source);

myErrors matrixReadElementFromFile(matrix& m, FILE*f);

myErrors matrixCheck(matrix& m);

bool matrixShowInitialization(matrix& m);

#endif //OOP_LAB_01_MATRIX_H
