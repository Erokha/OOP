#include "myManager.h"
#include <iostream>


using namespace std;

int taskManager(request req)
{
    static myModel mod = modelBasicInit();
    myErrors error = OK;
    switch(req.action) {
        case modelRotation:
            error = modelRotateByAxis(mod, req.rotDat);
            break;
        case modelScale:
            error = modelZoom(mod, req.zoomDat);
            break;
        case modelMove:
            error = modelMoveCenter(mod, req.movDat);
            break;
        case drawMe:
            error = modelDraw(mod);
            break;
        case modelReadFromFile:
            error  = modelInitFromFile(mod, req.fileDat);
            break;
        default:
            error = NOTASK;
            break;
    }
    return error;
}