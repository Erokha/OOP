#include "matrix.h"
#include <stdio.h>

void freeMyMatrix(matrix& m)
{
    for (int i = 0; i < m.size; i++)
    {
        delete m.mas[i];
    }
    m.size = 0;
    delete m.mas;
}
int createMatrix(matrix& m, int size)
{
    m.size = size;
    m.mas = new int*[size];
    if (m.mas == NULL)
    {
        return NOFREESPACE;
    }
    for(int i = 0; i < size; i++)
    {
        m.mas[i] = new int[size];
        if (m.mas[i] == NULL)
        {
            return NOFREESPACE;
        }
        for (int j = 0; j < size; j++)
        {
            m.mas[i][j] = 0;
        }
    }
    return OK;
}

int matrixSetElement(matrix& m, int data, int posi, int posj)
{
    if ((posi >= m.size) || (posj >= m.size))
    {
        return OUTOFEDGES;
    }
    else
    {
        m.mas[posi][posj] = data;
        return OK;
    }
}

int matrixGetElement(matrix &m, int posi, int posj)
{
    if ((posi > m.size) || (posj > m.size))
    {
        return OUTOFEDGES;
    }
    else
    {
        return m.mas[posi][posj];
    }
}