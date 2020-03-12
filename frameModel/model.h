#ifndef OOP_LAB_01_MODEL_H
#define OOP_LAB_01_MODEL_H

#include "stdio.h"
#include "../rotation/modelRotation.h"
#include "../zoom/zoom.h"


int modelInitFromFile(myModel* model);

void modelReCalculatePoints(myModel* model);

void modelGetCenter(myModel* model);

int modelfillEdges(FILE* f, myModel* model);

int modelfillPoints(FILE* f, myModel* model);

void modelDraw(myModel* model);

void modelFullInfo(myModel* model);

void modelMove(myModel* model, double dx, double dy, double dz);




#endif //OOP_LAB_01_MODEL_H
