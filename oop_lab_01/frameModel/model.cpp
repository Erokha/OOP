#include "model.h"

myErrors modelInitFromFile(myModel& model, fileData& fdat)
{
    FILE *f = fopen(fdat.filename, "r");
    if (!f)
    {
        return NOFILE;
    }

    myModel tmp = modelBasicInit();
    myErrors error = modelReadAllPointsFromFile(tmp.points, f);
    if (error != OK)
    {
//        modelFreeMemory(tmp);
        return ERRORWHILEREADINPOINTS;
    }
    error = modelReadAllEdgesFromFile(tmp.edges, getNumOfPoints(tmp.points), f);
    if (error != OK)
    {
//        modelFreeMemory(tmp);
        return ERRORWHILEREADINGEDGES;
    }
    fclose(f);


    modelGetCenter(tmp.center, tmp.points);
    modelCalculateOffset(tmp.points, tmp.center);
    modelFreeMemory(model);
    modelCheckInit(tmp);
    modelTransfer(model, tmp);
    modelFreeMemory(tmp);
    return error;
}


myErrors modelReadAllPointsFromFile(myMasOfPoints& points, FILE *f)
{
    int n;
    if (f == NULL)
    {
        return NOFILE;
    }
    myErrors error = readNumber(n, f);
    if (error != OK)
    {
        return error;
    }
    error = allocateMasOfPoints(points, n);
    if (error != OK)
    {
        return error;
    }
    error = readNPoints(points, n, f);
    if (error != OK)
    {
        masOfPointsFreeMemory(points);
    }
    masOfPointsCheck(points);
    return error;
}

myErrors modelReadAllEdgesFromFile(matrix& edges, int numOfPoints, FILE* f)
{
    if (f == NULL)
    {
        return NOFILE;
    }
    int n;
    myErrors error = readNumber(n, f);
    if (error != OK)
    {
        return error;
    }
    error = createMatrix(edges, numOfPoints);
    if (error != OK)
    {
        return error;
    }
    error = readNEdges(edges, n, f);
    if (error != OK)
    {
        matrixFreeMemory(edges);
    }
    matrixCheck(edges);
    return error;
}

myErrors modelGetCenter(myPoint& center, myMasOfPoints& mas)
{
    if (!mas.isInited)
    {
        return POINTNOTINITED;
    }
    double xmin = getPointX(mas.masOfPoints[0]);
    double xmax = getPointX(mas.masOfPoints[0]);
    double ymin = getPointY(mas.masOfPoints[0]);
    double ymax = getPointY(mas.masOfPoints[0]);
    double zmin = getPointZ(mas.masOfPoints[0]);
    double zmax = getPointZ(mas.masOfPoints[0]);
    double x, y, z;
    for(int i = 0; i < mas.numOfPoints; i++)
    {
        x = getPointX(mas.masOfPoints[i]);
        y = getPointY(mas.masOfPoints[i]);
        z = getPointZ(mas.masOfPoints[i]);

        if(x > xmax) {
            xmax = x;
        } else if(x < xmin) {
            xmin = x;
        }

        if (y > ymax) {
            ymax = y;
        } else if (y < ymin) {
            ymin = y;
        }

        if(z > zmax) {
            zmax = z;
        } else if(z < zmin) {
            zmin = z;
        }
    }
    return initPoint(center, ((xmax + xmin) / 2), ((zmax + zmin) / 2), ((zmax + zmin) / 2));
}

myErrors modelCalculateOffset(myMasOfPoints& mas, myPoint center)
{
    myErrors error = OK;
    for(int i = 0; (i < mas.numOfPoints && error == OK); i++)
    {
        error = calculatePointOffset(mas.masOfPoints[i], center);
    }
    return error;
}

myErrors modelMoveCenter(myModel& model, moveData& movdat)
{
    return pointMove(model.center, movdat.dx, movdat.dy, movdat.dz);
}

myErrors modelFreeMemory(myModel& model)
{
    masOfPointsFreeMemory(model.points);
    matrixFreeMemory(model.edges);
    model.isInited = false;
    return OK;
}

myErrors modelTransfer(myModel& dest, myModel& source)
{
    myErrors error;
    dest = modelBasicInit();

    error = masOfPointsTransfer(dest.points, source.points);
    if (error != OK)
    {
        return error;
    }
    pointTransfer(dest.center, source.center);
    error = copyMatrix(dest.edges, source.edges);
    if (error == OK)
    {
        dest.isInited = source.isInited;
    }
    return error;
}

myModel modelBasicInit()
{
    myModel model;
    model.isInited = false;
    masOfPointsBasicInit(model.points);
    createEmptyMatrix(model.edges);
    return model;
}

myErrors modelCheckInit(myModel& model)
{
    model.isInited = masOfPointsShowInitialization(model.points) &&
                     matrixShowInitialization(model.edges) && pointShowInitialization(model.center);
    return OK;
}

myErrors readNPoints(myMasOfPoints& points, int n, FILE* f)
{
    if (f == NULL)
    {
        return NOFILE;
    }
    myErrors error = OK;
    if (n <= 0)
    {
        return INCORRECTPOINTSSIZE;
    }
    for (int i = 0; (i < n && error == OK); i++)
    {
        error = readPointFromFile(points.masOfPoints[i], f);
    }
    return error;
}

myErrors readNEdges(matrix& edges, int n, FILE* f)
{
    if (f == NULL)
    {
        return NOFILE;
    }

    myErrors error = OK;
    if (n <= 0) {
        return NOTENOUGHPOINTS;
    }

    for (int i = 0; (i < n && error == OK); i++)
    {
        error = matrixReadElementFromFile(edges, f);
    }
    return error;
}

myErrors readNumber(int &num, FILE *f)
{
    myErrors error = OK;
    if (!f)
    {
        error = NOFILE;
    }
    if (fscanf(f, "%d", &num) != 1)
    {
        error = FILEWRONGFORMAT;
    }
    if (num <= 0)
    {
        error = FILEWRONGFORMAT;
    }
    return error;
}

myErrors modelDraw(myModel &model, drawData& ddat)
{
    GLErase(ddat.clearColor);
    myErrors error = OK;
    myModel tmp = modelBasicInit();
    myMasOfProjectionPoint projection;
    if (!model.isInited)
    {
        return modelNotInited;
    }
    error = modelTransfer(tmp, model);
    if (error != OK)
    {
        modelFreeMemory(tmp);
        return error;
    }
    error = calculateRealPoints(tmp.points, tmp.center);
    if (error != OK)
    {
        modelFreeMemory(tmp);
        return error;
    }
    error = calculateProjectionPoints(projection, tmp.points);
    if (error != OK)
    {
        masOfProjectionsFreeMemory(projection);
        modelFreeMemory(tmp);
        return error;
    }
    error = drawEdges(projection, tmp.edges, ddat);
    GLShow();
    modelFreeMemory(tmp);
    return error;
}

myErrors drawEdges(myMasOfProjectionPoint& mas, matrix& edges, drawData& ddat)
{
    int n = mas.numOfPoints;
    myErrors error = OK;
    for (int i = 0; (i < n && error == OK); i++)
    {
        for (int j = i; (j < n && error == OK); j++)
        {
            if (edges.mas[i][j])
            {
                error = drawLine(mas.masOfPoints[i], mas.masOfPoints[j], ddat.color, ddat.edgeType);
            }
        }
    }
    return error;
}

myErrors calculateRealPoints(myMasOfPoints& mas, myPoint& center)
{
    myErrors error = OK;
    for (int i = 0; (i < mas.numOfPoints && error == OK); i++)
    {
        error = pointCoordinateAddition(mas.masOfPoints[i], center);
    }
    return error;
}

myErrors calculateProjectionPoints(myMasOfProjectionPoint& dest, myMasOfPoints& source)
{
    if (!source.isInited)
    {
        return modelNotInited;
    }
    if (allocateMasOf2dPoints(dest, source.numOfPoints) != OK)
    {
        return NOFREESPACE;
    }
    myErrors error = OK;
    for (int i = 0; (i < dest.numOfPoints && error == OK); i++)
    {
        error = calculatePointProjection(dest.masOfPoints[i], source.masOfPoints[i]);
    }
    return error;
}
