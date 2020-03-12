#ifndef OOP_LAB_01_MATRIX_H
#define OOP_LAB_01_MATRIX_H

#include "../defines.h"

struct matrix
{
    int ** mas;
    int size;
};

int createMatrix(matrix* m, int size);

#endif //OOP_LAB_01_MATRIX_H
