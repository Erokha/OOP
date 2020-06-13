#ifndef OOP_LAB_01_MODEL_H
#define OOP_LAB_01_MODEL_H

#include "stdio.h"
#include "frameStructure.h"
#include "../request/request.h"
#include "modelRotation.h"
#include "zoom.h"
#include "../drawing/drawing.h"


myErrors modelInitFromFile(myModel& model, fileData& fdat);

myErrors modelReadAllPointsFromFile(myMasOfPoints& points, FILE *f);

myErrors modelReadAllEdgesFromFile(matrix& edges, int numOfPoints, FILE* f);

myErrors modelGetCenter(myPoint& center, myMasOfPoints& mas);

myErrors modelCalculateOffset(myMasOfPoints& mas, myPoint center);

myErrors modelMoveCenter(myModel& model, moveData& movdat);

myErrors modelFreeMemory(myModel& model);

myErrors modelTransfer(myModel& dest, myModel& source);

myModel modelBasicInit();

myErrors modelCheckInit(myModel& model);

myErrors readNPoints(myMasOfPoints& points, int n, FILE* f);

myErrors readNEdges(matrix& edges, int n, FILE* f);

myErrors readNumber(int &num, FILE *f);

myErrors modelDraw(myModel &model, drawData& ddat);

myErrors drawEdges(myMasOfProjectionPoint& mas, matrix& edges, drawData& ddat);

myErrors calculateRealPoints(myMasOfPoints& mas, myPoint& center);

myErrors calculateProjectionPoints(myMasOfProjectionPoint& dest, myMasOfPoints& source);

#endif //OOP_LAB_01_MODEL_H