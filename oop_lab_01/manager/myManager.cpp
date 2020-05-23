#include "myManager.h"


using namespace std;

myErrors taskManager(request& req)
{
    static myModel mod = modelBasicInit();
    myErrors error = OK;
    switch(req.action) {
        case modelRotation:
            error = modelRotateByAxis(mod, req.rotDat);
            break;
        case modelScale:
            error = modelZoom(mod.points, req.zoomDat);
            break;
        case modelMove:
            error = modelMoveCenter(mod, req.movDat);
            break;
        case drawMe:
            error = modelDraw(mod, req.dDat);
            break;
        case modelReadFromFile:
            error  = modelInitFromFile(mod, req.fileDat);
            break;
        case endProgramm:
            error = modelFreeMemory(mod);
            break;
        default:
            error = NOTASK;
            break;
    }
    return error;
}