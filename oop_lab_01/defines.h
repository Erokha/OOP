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
    modelNotInited
};

#define myGLWIDTH 400
#define myGLHEIGHT 400
#define myGLCLEARCOLOR 1.0, 1.0, 1.0, 1.0
#define myGLORTHO -200.0, 200.0, -200.0, 200.0, -200.0, 200.0


#define myFilename "model.txt"//const char* myFilename = "model.txt";

enum myAction
{
    modelReadFromFile,
    modelRotation,
    modelScale,
    modelMove,
    drawMe
};

#endif //OOP_LAB_01_DEFINES_H
