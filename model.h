#ifndef OOP_LAB_01_MODEL_H
#define OOP_LAB_01_MODEL_H
#include "point.h"
#include <stdio.h>

struct myModel
{
    int num_of_points;
    int num_of_edges;
    myPoint* masOfPoints;
    myPoint* rotatedPoints;
    int** edges;
};

int readModelFromFile(myModel* model);

int** createMatrix(int size);

int fillEdges(FILE* f, myModel* model);

int fillPoints(FILE* f, myModel* model);

int rotateModelByX(myModel* model, int angle);

int rotateModelByY(myModel* model, int angle);

int rotateModelByZ(myModel* model, int angle);

int rotateEnd(myModel* model);

int modelDraw(myModel* model);

void modelFullInfo(myModel* model);

#endif //OOP_LAB_01_MODEL_H
