#ifndef OOP_LAB_01_REQUEST_H
#define OOP_LAB_01_REQUEST_H
#include "../defines.h"

struct rotationData
{
    char rotationAxis;
    int rotationAngle;
};

struct moveData
{
    int dx;
    int dy;
    int dz;
};

struct zoomData
{
    double zoom;
};

struct fileData
{
    const char* filename;
};

struct request
{
    myAction action;
    union {
        rotationData rotDat;
        moveData movDat;
        zoomData zoomDat;
        fileData fileDat;
    };
};

myErrors reqSetRotation(request& r, int rotK, char axis);

myErrors reqSetZoom(request& r, double zoomK);

myErrors reqSetMove(request& r, int dx, int dy, int dz);

myErrors reqSetDrawMe(request& r);

myErrors reqSetReadFromFile(request& r, char* filename);

myErrors fileDatSetFilename(fileData& fdat, char* filename);

myErrors movDatSetD(moveData& mdat, int dx, int dy, int dz);

myErrors zoomDatSet(zoomData& zdat, double zoom);

myErrors rotDatSet(rotationData& rdat, char axis, int rotK);

#endif //OOP_LAB_01_REQUEST_H
