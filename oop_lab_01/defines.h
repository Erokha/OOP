#ifndef OOP_LAB_01_DEFINES_H
#define OOP_LAB_01_DEFINES_H

enum myErrors
{
    OK,
    NOFILE,
    NOTENOUGHPOINTS,
    ERRORWHILEREADINGPOINTS,
    ERRORWHILEREADINGEDGES,
    NOTENOUGHEDGES,
    NOFREESPACE,
    OUTOFEDGES,
    modelNotInited,
    NOMEMORY
};

#define myGLWIDTH 400
#define myGLHEIGHT 400
#define myGLCLEARCOLOR 1.0, 1.0, 1.0, 1.0
#define myGLORTHO -200.0, 200.0, -200.0, 200.0, -200.0, 200.0


const int ROT = 6;
const int dMove = 20;

enum myAction
{
    modelReadFromFile,
    modelRotationXPositive,
    modelRotationXNegative,
    modelRotationYPositive,
    modelRotationYNegative,
    modelScalePositive,
    modelScaleNegative,
    modelMoveUp,
    modelMoveDown,
    modelMoveLeft,
    modelMoveRight,
    drawMe
};

#endif //OOP_LAB_01_DEFINES_H
