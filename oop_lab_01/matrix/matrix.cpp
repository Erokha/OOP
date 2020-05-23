#include "matrix.h"

myErrors matrixFreeMemory(matrix& m)
{
    for (int i = 0; i < m.size; i++)
    {
        if (m.mas[i] != NULL)
        {
            delete m.mas[i];
        }
    }
    m.size = 0;
    m.isInited = false;
    delete m.mas;
    return OK;
}
myErrors createMatrix(matrix& m, int size)
{
    m.size = size;
    m.mas = new int*[size];
    if (m.mas == NULL)
    {
        m.size = 0;
        return NOFREESPACE;
    } else {
        for (int i = 0; i < size; i++) {
            m.mas[i] = new int[size];
            if (m.mas[i] == NULL) {
                m.size = 0;
                return NOFREESPACE;
            }
            for (int j = 0; j < size; j++) {
                m.mas[i][j] = 0;
            }
        }
    }
    return OK;
}

myErrors matrixSetElement(matrix& m, int data, int posi, int posj)
{
    if (((posi >= m.size) || (posj >= m.size)) || (posi < 0) || (posj < 0))
    {
        return OUTOFEDGES;
    }
    else
    {
        m.mas[posi][posj] = data;
        m.mas[posj][posi] = data;
        return OK;
    }
}

myErrors matrixReadElementFromFile(matrix& m, FILE*f)
{
    if (f == NULL)
    {
        return NOFILE;
    }
    int a, b;
    if (fscanf(f, "%d %d", &a, &b) != 2)
    {
        return ERRORWHILEREADINGEDGES;
    }
    if (((a >= m.size) || (b >= m.size)) || (a < 0) || (b < 0))
    {
        return OUTOFEDGES;
    }
    m.mas[a][b] = 1;
    m.mas[b][a] = 1;
    return OK;
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

myErrors createEmptyMatrix(matrix& m)
{
    m.size = 0;
    m.isInited = false;
    m.mas = NULL;
    return OK;
}

myErrors copyMatrix(matrix& dest, matrix& source)
{
    if (!source.isInited)
    {
        return MATRIXNOTINITED;
    }
    if (createMatrix(dest, source.size) != OK)
    {
        return NOFREESPACE;
    }
    for (int i = 0; i < source.size; i++) {
        for (int j = 0; j < source.size; j++) {
            dest.mas[i][j] = source.mas[i][j];
        }
    }
    dest.isInited = source.isInited;
    return OK;
}

myErrors matrixCheck(matrix& m)
{
    if (m.size <= 0 || m.mas == NULL)
    {
        m.isInited = false;
    } else
    {
        m.isInited = true;
    }
    return OK;
}

bool matrixShowInitialization(matrix& m)
{
    return m.isInited;
}