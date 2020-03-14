#ifndef OOP_LAB_01_MYMANAGER_H
#define OOP_LAB_01_MYMANAGER_H

#include "../drawing/drawing.h"
#include "../frameModel/model.h"
#include "../defines.h"
#include "GLUT/glut.h"
#include <iostream>

void myOpenglWidnowInit(int argc, char **argv);

int taskManager(int argc, char **argv);

void modelDraw(myModel& model);

#endif //OOP_LAB_01_MYMANAGER_H
