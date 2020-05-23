#ifndef OOP_LAB_01_REQUEST_H
#define OOP_LAB_01_REQUEST_H
#include "../defines.h"
#include "../drawing/colorsDefine.h"
#include "/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/OpenGL.framework/Headers/gl.h"

typedef uint32_t primitiveType;
typedef uint32_t colorBufferBit;

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

struct drawData
{
    myColor color;
    colorBufferBit clearColor;
    primitiveType edgeType;
};

struct request
{
    myAction action;
    union {
        rotationData rotDat;
        moveData movDat;
        zoomData zoomDat;
        fileData fileDat;
        drawData dDat;
    };
};

myErrors reqSetRotation(request& r, int rotK, char axis);

myErrors reqSetZoom(request& r, double zoomK);

myErrors reqSetMove(request& r, int dx, int dy, int dz);

myErrors reqSetDrawMe(request& r, myColor& color);

myErrors reqSetReadFromFile(request& r, const char* filename);

myErrors reqSetEnd(request& r);

myErrors fileDatSetFilename(fileData& fdat, const char* filename);

myErrors movDatSetD(moveData& mdat, int dx, int dy, int dz);

myErrors zoomDatSet(zoomData& zdat, double zoom);

myErrors rotDatSet(rotationData& rdat, char axis, int rotK);

myErrors drawDatSetColor(drawData& dDat, myColor& color);

#endif //OOP_LAB_01_REQUEST_H
