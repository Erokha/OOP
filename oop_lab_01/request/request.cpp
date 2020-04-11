#include "request.h"

myErrors reqSetRotation(request& r, int rotK, char axis)
{
    r.action = modelRotation;
    rotDatSet(r.rotDat, axis, rotK);
    return OK;
}

myErrors reqSetZoom(request& r, double zoomK)
{
    r.action = modelScale;
    zoomDatSet(r.zoomDat, zoomK);
    return OK;
}

myErrors reqSetMove(request& r, int dx, int dy, int dz)
{
    r.action = modelMove;
    movDatSetD(r.movDat, dx, dy, dz);
    return OK;
}
myErrors reqSetDrawMe(request& r)
{
    r.action = drawMe;
    return OK;
}
myErrors reqSetReadFromFile(request& r, char* filename)
{
    r.action = modelReadFromFile;
    fileDatSetFilename(r.fileDat, filename);
}

myErrors fileDatSetFilename(fileData& fdat, char* filename)
{
    fdat.filename = filename;
    return OK;
}

myErrors movDatSetD(moveData& mdat, int dx, int dy, int dz)
{
    mdat.dx = dx;
    mdat.dy = dy;
    mdat.dz = dz;
    return OK;
}

myErrors zoomDatSet(zoomData& zdat, double zoom)
{
    zdat.zoom = zoom;
    return OK;
}

myErrors rotDatSet(rotationData& rdat, char axis, int rotK)
{
    rdat.rotationAxis = axis;
    rdat.rotationAngle = rotK;
    return OK;
}

