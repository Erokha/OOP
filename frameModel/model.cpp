#include "model.h"
#include "GLUT/glut.h"

int modelInitFromFile(myModel& model)
{
    model.isInited = false;
    FILE *f;
    f = fopen("model.txt", "r");

    if (modelfillPoints(f, model) != OK)
    {
        return ERRORWHILEREADINGPOINTS;
    }
    if (modelfillEdges(f, model) != OK)
    {
        return ERRORWHILEREADINGEDGES;
    }
    modelGetCenter(model);
    modelReCalculatePoints(model);
    model.isInited = true;
    return OK;
}

int modelfillPoints(FILE* f, myModel& model)
{
    int n;
    int ret = NOFILE;
    if (f != NULL)
    {
        ret = OK;
        if (fscanf(f, "%d", &n) != 1)
        {
            return NOTENOUGHPOINTS;
        }

        model.num_of_points = n;
        model.masOfPoints = new myPoint[n];
        if (model.masOfPoints == NULL)
        {
            return NOMEMORY;
        }
        if (createMatrix(model.edges, model.num_of_points) != OK)
        {
            return NOMEMORY;
        }

        for (int i = 0; i < n; i++)
        {
            double x, y, z;
            if (fscanf(f, "%lf %lf %lf", &x, &y, &z) != 3)
            {
                ret = NOTENOUGHPOINTS;
            }
            initPoint(model.masOfPoints[i], x, y, z);
        }
    }
    return ret;
}


int modelfillEdges(FILE* f, myModel& model)
{
    int n;
    int ret = NOFILE;
    if (f != NULL)
    {
        ret = OK;
        if (fscanf(f, "%d", &n) != 1)
        {
            ret = NOTENOUGHEDGES;
        }
        for (int i = 0; i < n; i++)
        {
            int a, b;
            if (fscanf(f, "%d %d", &a, &b) != 2)
            {
                ret = NOTENOUGHEDGES;
            }
            matrixSetElement(model.edges, 1, a, b);
            matrixSetElement(model.edges, 1, b, a);
        }
    }
    fclose(f);
    return ret;
}


void modelGetCenter(myModel& model)
{
    double xmin = model.masOfPoints[0].x, xmax = model.masOfPoints[0].x;
    double ymin = model.masOfPoints[0].y, ymax = model.masOfPoints[0].y;
    double zmin = model.masOfPoints[0].z, zmax = model.masOfPoints[0].z;
    for(int i = 0; i < model.num_of_points; i++)
    {
        if(model.masOfPoints[i].x > xmax) {
            xmax = getPointX(model.masOfPoints[i]);
        } else if(model.masOfPoints[i].x < xmin) {
            xmin = getPointX(model.masOfPoints[i]);
        }

        if(model.masOfPoints[i].y > ymax) {
            ymax = getPointY(model.masOfPoints[i]);;
        } else if(model.masOfPoints[i].x < ymin) {
            ymin = getPointY(model.masOfPoints[i]);;
        }

        if(model.masOfPoints[i].z > zmax) {
            zmax = getPointZ(model.masOfPoints[i]);
        } else if(model.masOfPoints[i].z < zmin) {
            zmin = getPointZ(model.masOfPoints[i]);
        }
    }
    initPoint(model.center, ((xmax + xmin) / 2), ((zmax + zmin) / 2), ((zmax + zmin) / 2));
}

void modelReCalculatePoints(myModel& model)
{
    for(int i = 0; i < model.num_of_points; i++)
    {
        double newx = getPointX(model.masOfPoints[i]) - getPointX(model.center);
        double newy = getPointY(model.masOfPoints[i]) - getPointY(model.center);
        double newz = getPointZ(model.masOfPoints[i]) - getPointZ(model.center);
        initPoint(model.masOfPoints[i], newx, newy, newz);
    }
}

void modelMove(myModel& model, double dx, double dy, double dz)
{
    pointMove(model.center, dx, dy, dz);
}

void freeMyMemory(myModel& model)
{
    delete model.masOfPoints;
    freeMyMatrix(model.edges);
}