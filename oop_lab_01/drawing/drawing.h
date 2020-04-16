#ifndef OOP_LAB_01_DRAWING_H
#define OOP_LAB_01_DRAWING_H

#include <iostream>
#include "../point/point.h"
#include "colorsDefine.h"
//#include "GLUT/glut.h"


myErrors drawLine(myPoint& a, myPoint& b, myColor& color);

myErrors GLErase();

myErrors GLShow();

myErrors GLEnd();

myErrors showError(int error);


#endif //OOP_LAB_01_DRAWING_H
