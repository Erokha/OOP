#ifndef OOP_LAB_01_FRAMESTRUCTURE_H
#define OOP_LAB_01_FRAMESTRUCTURE_H
#include "../point/point.h"
#include "../matrix/matrix.h"

struct myModel
{
    myPoint center;
    myMasOfPoints points;
    matrix edges;
    bool isInited;
};

#endif //OOP_LAB_01_FRAMESTRUCTURE_H
