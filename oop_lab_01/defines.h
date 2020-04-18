#ifndef OOP_LAB_01_DEFINES_H
#define OOP_LAB_01_DEFINES_H
#include <string>




enum myErrors
{
    OK,
    NOFILE,
    NOTENOUGHPOINTS,
    ERRORNUMOFPOINTS,
    POINTNOTINITED,
    POINTSERROR,
    ERRORWHILEREADINPOINTS,
    ERRORWHILEREADINGEDGES,
    ERRORNUMOFEDGES,
    OUTOFEDGES,
    NOFREESPACE,
    FILEWRONGFORMAT,
    ZOOMERROR,
    MOVERROR,
    EMPTYMAS,
    MATRIXNOTINITED,
    NOAXIS,
    INCORRECTPOINTSSIZE,
    NOTASK,
    modelNotInited
};

enum myAction
{
    modelReadFromFile,
    modelRotation,
    modelScale,
    modelMove,
    endProgramm,
    drawMe
};

#endif //OOP_LAB_01_DEFINES_H
