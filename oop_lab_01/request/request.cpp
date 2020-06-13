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
myErrors reqSetDrawMe(request& r, myColor& color)
{
    r.action = drawMe;
    drawDatSetColor(r.dDat, color);
    return OK;
}

myErrors reqSetReadFromFile(request& r, const char* filename)
{
    r.action = modelReadFromFile;
    fileDatSetFilename(r.fileDat, filename);
    return OK;
}

myErrors reqSetEnd(request& r)
{
    r.action = endProgramm;
    return OK;
}

myErrors fileDatSetFilename(fileData& fdat, const char* filename)
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

myErrors drawDatSetColor(drawData& dDat, myColor& color)
{
    dDat.color = color;
    dDat.clearColor = GL_COLOR_BUFFER_BIT;
    dDat.edgeType = GL_LINES;
    return OK;
}



