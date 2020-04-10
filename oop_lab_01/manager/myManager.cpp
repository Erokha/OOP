#include "myManager.h"
#include <iostream>


using namespace std;

int taskManager(request req)
{
    static myModel mod;
    switch(req.action) {
        default:
            std::cout << "Error!";
        case modelRotation:
            rotateModelbyAxis(mod, req.rotation, req.rotationAxis);
            break;
        case modelScale:
            modelZoom(mod, req.zoom);
            break;
        case modelMove:
            modelMoveCenter(mod, req.dx, req.dy, req.dz);
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