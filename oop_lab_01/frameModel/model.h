#ifndef OOP_LAB_01_MODEL_H
#define OOP_LAB_01_MODEL_H

#include "stdio.h"
#include "frameStructure.h"
#include "../request/request.h"
#include "modelRotation.h"
#include "zoom.h"
#include "../drawing/drawing.h"


myErrors modelInitFromFile(myModel& model, fileData& fdat);

void modelReCalculatePoints(myModel& model);

void modelGetCenter(myModel& model);

myErrors modelfillEdges(FILE* f, myModel& model);

myErrors modelfillPoints(FILE* f, myModel& model);

myErrors modelMoveCenter(myModel& model, moveData& movdat);

void freeMyMemory(myModel& model);

myModel modelBasicInit();

void modelCopy(myModel& source, myModel& dest);

int modelSetInited(myModel& model);

myErrors readNumber(int &num, FILE *f);

myErrors modeAllocateMasOfPointsOffset(myModel& model, int n);

myErrors readNPoints(myModel& model, int n, FILE* f);

myErrors readNEdges(myModel& model, int n, FILE* f);

myErrors modelDraw(myModel &model, drawData& ddat);

#endif //OOP_LAB_01_MODEL_H