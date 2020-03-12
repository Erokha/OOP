#ifndef OOP_LAB_01_FRAMESTRUCTURE_H
#define OOP_LAB_01_FRAMESTRUCTURE_H
#include "../point/point.h"
#include "../matrix/matrix.h"

struct myModel
{
    int num_of_points;
    int num_of_edges;
    myPoint center;
    myPoint* masOfPoints;
    matrix edges;
};

#endif //OOP_LAB_01_FRAMESTRUCTURE_H
