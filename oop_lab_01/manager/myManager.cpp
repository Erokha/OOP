#include "myManager.h"
#include <iostream>


using namespace std;

int taskManager(myAction action)
{
    static myModel mod;
    switch(action) {
        default:
            std::cout << "Error!";
        case modelRotationXPositive:
            rotateModelByX(mod, ROT);
            break;
        case modelRotationXNegative:
            rotateModelByX(mod, -ROT);
            break;
        case modelRotationYPositive:
            rotateModelByY(mod, ROT);
            break;
        case modelRotationYNegative:
            rotateModelByY(mod, -ROT);
            break;
        case modelScalePositive:
            modelZoom(mod, 2);
            break;
        case modelScaleNegative:
            modelZoom(mod, 0.5);
            break;
        case modelMoveUp:
            modelMove(mod, 0, 20, 0);
            break;
        case modelMoveLeft:
            modelMove(mod, -20, 0, 0);
            break;
        case modelMoveDown:
            modelMove(mod, 0, -20, 0);
            break;
        case modelMoveRight:
            modelMove(mod, 20, 0, 0);
            break;
        case modelReadFromFile:
            freeMyMemory(mod);
            int a = modelInitFromFile(mod);
            if (a != OK)
            {
                drawThrowError();
            }
            break;
    }
    modelDraw(mod);
    return OK;
}