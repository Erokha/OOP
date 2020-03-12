#include "matrix.h"
#include <stdio.h>
int createMatrix(matrix* m, int size)
{
    m->mas = new int*[size];
    if (m->mas == NULL)
    {
        return NOFREESPACE;
    }
    for(int i = 0; i < size; i++)
    {
        m->mas[i] = new int[size];
        if (m->mas[i] == NULL)
        {
            return NOFREESPACE;
        }
        for (int j = 0; j < size; j++)
        {
            m->mas[i][j] = 0;
        }
    }
    return OK;
}