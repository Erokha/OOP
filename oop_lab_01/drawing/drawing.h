#ifndef OOP_LAB_01_DRAWING_H
#define OOP_LAB_01_DRAWING_H

#include "GLUT/glut.h"
#include "../frameModel/frameStructure.h"
#include <iostream>
#include "../manager/myManager.h"
#include "colorsDefine.h"


void draw_line(myPoint& a, myPoint& b);

void modelDraw(myModel &model);

void drawThrowError(int errortype);

void processNormalKeys(unsigned char key, int x, int y);

//void display123();

void myOpenglWidnowInit(int argc, char **argv);

void GLmainLoop();

#endif //OOP_LAB_01_DRAWING_H
