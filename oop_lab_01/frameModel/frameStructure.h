#ifndef OOP_LAB_01_FRAMESTRUCTURE_H
#define OOP_LAB_01_FRAMESTRUCTURE_H
#include "../point/point.h"

struct myModel
{
    int num_of_points;
    int num_of_edges;
    double RotationAngleX, RotationAngleY, RotationAngleZ;
    myPoint center;
    myPoint* masOfPoints;
    myPoint* rotatedPoints;
    int** edges;
};

#endif //OOP_LAB_01_FRAMESTRUCTURE_H
