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
            modelZoom(mod, zoomConst);
            break;
        case modelScaleNegative:
            modelZoom(mod, outZoomConst);
            break;
        case modelMoveUp:
            modelMove(mod, moveUpConst);
            break;
        case modelMoveLeft:
            modelMove(mod, moveLeftConst);
            break;
        case modelMoveDown:
            modelMove(mod, moveDownConst);
            break;
        case modelMoveRight:
            modelMove(mod, moveRightConst);
            break;
        case drawMe:
            modelDraw(mod);
            break;
        case modelReadFromFile:
            int a = modelInitFromFile(mod);
            if (a != OK)
            {
                drawThrowError(a);
            }
            break;
    }
    return OK;
}