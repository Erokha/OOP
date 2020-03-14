#ifndef OOP_LAB_01_DEFINES_H
#define OOP_LAB_01_DEFINES_H

#define OK 0
#define NOFILE 1
#define NOTENOUGHPOINTS 2
#define ERRORWHILEREADINGPOINTS 3
#define ERRORWHILEREADINGEDGES 4
#define NOTENOUGHEDGES 5
#define NOFREESPACE 6
#define OUTOFEDGES 7
#define NOMEMORY 8
#define myGLWIDTH 400
#define myGLHEIGHT 400
#define myGLCLEARCOLOR 1.0, 1.0, 1.0, 1.0
#define myGLORTHO -200.0, 200.0, -200.0, 200.0, -200.0, 200.0


const int ROT = 2;
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
