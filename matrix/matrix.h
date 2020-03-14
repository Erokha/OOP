#ifndef OOP_LAB_01_MATRIX_H
#define OOP_LAB_01_MATRIX_H

#include "../defines.h"

struct matrix
{
    int ** mas;
    int size;
};

void freeMyMatrix(matrix& m);


int createMatrix(matrix& m, int size);

int matrixSetElement(matrix& m, int data, int posi, int posj);

#endif //OOP_LAB_01_MATRIX_H
