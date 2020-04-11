#include "model.h"

myErrors modelInitFromFile(myModel& model, fileData& fdat)
{
    FILE *f = fopen(fdat.filename, "r");
    if (!f)
    {
        return NOFILE;
    }

    myModel tmp = modelBasicInit();
    myErrors error = modelfillPoints(f, tmp);
    if (error == OK)
    {
        error = modelfillEdges(f, tmp);
    }
    fclose(f);
    if (error == OK)
    {
        modelGetCenter(tmp);
        modelReCalculatePoints(tmp);

        freeMyMemory(model);
        modelCopy(model, tmp);
        modelSetInited(model);
    }
    freeMyMemory(tmp);
    return error;
}


myErrors modelfillPoints(FILE* f, myModel& model)
{
    int n;
    if (f != NULL)
    {
        if (readNumber(n, f) != OK)
        {
            return ERRORNUMOFPOINTS;
        }
        if (modeAllocateMasOfPointsOffset(model, n) != OK)
        {
            return NOFREESPACE;
        }
        if (readNPoints(model, n, f) != OK)
        {
            return ERRORWHILEREADINPOINTS;
        }
    }
    return OK;
}


myErrors modelfillEdges(FILE* f, myModel& model)
{
    int n;
    if (f != NULL)
    {
        if (readNumber(n, f) != OK)
        {
            return ERRORNUMOFEDGES;
        }
        if (createMatrix(model.edges, model.num_of_points) != OK)
        {
            return NOFREESPACE;
        }
        if (readNEdges(model, n, f) != OK)
        {
            return ERRORWHILEREADINGEDGES;
        }
    }
    return OK;
}


void modelGetCenter(myModel& model)
{
    double xmin = getPointX(model.masOfPointsOffset[0]);
    double xmax = getPointX(model.masOfPointsOffset[0]);
    double ymin = getPointY(model.masOfPointsOffset[0]);
    double ymax = getPointY(model.masOfPointsOffset[0]);
    double zmin = getPointZ(model.masOfPointsOffset[0]);
    double zmax = getPointZ(model.masOfPointsOffset[0]);
    double x, y, z;
    for(int i = 0; i < model.num_of_points; i++)
    {
        x = getPointX(model.masOfPointsOffset[i]);
        y = getPointY(model.masOfPointsOffset[i]);
        z = getPointZ(model.masOfPointsOffset[i]);

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
    initPoint(model.center, ((xmax + xmin) / 2), ((zmax + zmin) / 2), ((zmax + zmin) / 2));
}

void modelReCalculatePoints(myModel& model)
{
    for(int i = 0; i < model.num_of_points; i++)
    {
        double newx = getPointX(model.masOfPointsOffset[i]) - getPointX(model.center);
        double newy = getPointY(model.masOfPointsOffset[i]) - getPointY(model.center);
        double newz = getPointZ(model.masOfPointsOffset[i]) - getPointZ(model.center);
        initPoint(model.masOfPointsOffset[i], newx, newy, newz);
    }
}

myErrors modelMoveCenter(myModel& model, moveData& movdat)
{
    if (pointMove(model.center, movdat.dx, movdat.dy, movdat.dz) != OK)
    {
        return MOVERROR;
    } else {
        return OK;
    }
}

void freeMyMemory(myModel& model)
{
    delete model.masOfPointsOffset;
    freeMyMatrix(model.edges);
    model.num_of_points = 0;
    model.isInited = false;
}

void modelCopy(myModel& dest, myModel& source)
{
    dest = modelBasicInit();
    dest.isInited = source.isInited;
    dest.num_of_points = source.num_of_points;
    dest.center = source.center;
    dest.masOfPointsOffset = new myPoint[dest.num_of_points];
    for(int i = 0; i < dest.num_of_points; i++)
    {
        dest.masOfPointsOffset[i] = source.masOfPointsOffset[i];
    }
    copyMatrix(dest.edges, source.edges);
}

myModel modelBasicInit()
{
    myModel model;
    model.num_of_points = 0;
    model.isInited = false;
    model.masOfPointsOffset = NULL;
    createEmptyMatrix(model.edges);
    return model;
}

int modelSetInited(myModel& model)
{
    model.isInited = true;
}

myErrors modeAllocateMasOfPointsOffset(myModel& model, int n)
{
    model.num_of_points = n;
    model.masOfPointsOffset = new myPoint[n];
    if (model.masOfPointsOffset == NULL)
    {
        return NOFREESPACE;
    }
    return OK;
}

myErrors readNPoints(myModel& model, int n, FILE* f)
{
    if (f != NULL)
    {
        if (n >= 0) {
            for (int i = 0; i < n; i++)
            {
                double x, y, z;
                if (fscanf(f, "%lf %lf %lf", &x, &y, &z) != 3)
                {
                    return POINTSERROR;
                }
                initPoint(model.masOfPointsOffset[i], x, y, z);
            }
        }
    }
    else
    {
        return NOFILE;
    }
}

myErrors readNEdges(myModel& model, int n, FILE* f)
{
    if (f != NULL)
    {
        if (n >= 0) {
            for (int i = 0; i < n; i++)
            {
                int a, b;
                if (fscanf(f, "%d %d", &a, &b) != 2)
                {
                    return ERRORWHILEREADINGEDGES;
                }
                if (matrixSetElement(model.edges, 1, a, b) != OK)
                {
                    return OUTOFEDGES;
                }
            }
        }
    }
    else
    {
        return NOFILE;
    }
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

