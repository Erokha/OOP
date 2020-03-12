#ifndef OOP_LAB_01_MODEL_H
#define OOP_LAB_01_MODEL_H

#include "stdio.h"
#include "../rotation/modelRotation.h"
#include "../zoom/zoom.h"


int modelInitFromFile(myModel* model);

void modelReCalculatePoints(myModel* model);

int** createMatrix(int size);

int modelGetCenter(myModel* model);

int modelfillEdges(FILE* f, myModel* model);

int modelfillPoints(FILE* f, myModel* model);

int modelDraw(myModel* model);

void modelFullInfo(myModel* model);




#endif //OOP_LAB_01_MODEL_H
