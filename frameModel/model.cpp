#include "model.h"
#include "../defines.h"
#include "GLUT/glut.h"
#include "../drawing/drawing.h"

int modelInitFromFile(myModel* model)
{
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
    return OK;
}

int modelfillPoints(FILE* f, myModel* model)
{
    int n;
    int ret = NOFILE;
    if (f != NULL)
    {
        ret = OK;
        fscanf(f, "%d", &n);

        model->num_of_points = n;
        model->masOfPoints = new myPoint[n];
        createMatrix(&model->edges, model->num_of_points);

        for (int i = 0; i < n; i++)
        {
            double x, y, z;
            if (fscanf(f, "%lf %lf %lf", &x, &y, &z) != 3)
            {
                ret = NOTENOUGHPOINTS;
            }
            initPoint(&(model->masOfPoints[i]), x, y, z);
        }
    }
    return ret;
}


int modelfillEdges(FILE* f, myModel* model)
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
            model->edges.mas[a][b] = 1;
            model->edges.mas[b][a] = 1;
        }
    }
    return ret;
}




void modelDraw(myModel* model)
{
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i = 0; i < model->num_of_points; i++)
    {
        for(int j = i; j < model->num_of_points; j++)
        {
            if (model->edges.mas[i][j])
            {
                double x1, y1, x2, y2;
                x1 = model->masOfPoints[i].x + model->center.x;
                y1 = model->masOfPoints[i].y + model->center.y;
                x2 = model->masOfPoints[j].x + model->center.x;
                y2 = model->masOfPoints[j].y + model->center.y;
                draw_line(x1, y1,x2, y2);
            }
        }
    }
    glEnd();
}

void modelFullInfo(myModel* model)
{
    printf("num_of_points: %d\n", model->num_of_points);
    printf("num_of_edges: %d\n", model->num_of_edges);
    for(int i = 0; i < model->num_of_points; i++)
    {
        printf("Point %d: %lf %lf %lf\n", i, model->masOfPoints[i].x, model->masOfPoints[i].y, model->masOfPoints[i].z);
    }
    for(int i = 0; i < model->num_of_points; i++)
    {
        for (int j = 0; j < model->num_of_points; j++) {
            printf("%d ", model->edges.mas[i][j]);
        }
        printf("\n");
    }
    printf("Model center %lf %lf %lf\n", model->center.x, model->center.y, model->center.z);
}

void modelGetCenter(myModel* model)
{
    double xmin = model->masOfPoints[0].x, xmax = model->masOfPoints[0].x;
    double ymin = model->masOfPoints[0].y, ymax = model->masOfPoints[0].y;
    double zmin = model->masOfPoints[0].z, zmax = model->masOfPoints[0].z;
    for(int i = 0; i < model->num_of_points; i++)
    {
        if(model->masOfPoints[i].x > xmax) {
            xmax = model->masOfPoints[i].x;
        } else if(model->masOfPoints[i].x < xmin) {
            xmin = model->masOfPoints[i].x;
        }

        if(model->masOfPoints[i].y > ymax) {
            ymax = model->masOfPoints[i].y;
        } else if(model->masOfPoints[i].x < ymin) {
            ymin = model->masOfPoints[i].y;
        }

        if(model->masOfPoints[i].z > zmax) {
            zmax = model->masOfPoints[i].z;
        } else if(model->masOfPoints[i].z < zmin) {
            zmin = model->masOfPoints[i].z;
        }
    }
    initPoint(&model->center, ((xmax + xmin) / 2), ((zmax + zmin) / 2), ((zmax + zmin) / 2));
}

void modelReCalculatePoints(myModel* model)
{
    for(int i = 0; i < model->num_of_points; i++)
    {
        double newx = model->masOfPoints[i].x - model->center.x;
        double newy = model->masOfPoints[i].y - model->center.y;
        double newz = model->masOfPoints[i].z - model->center.z;
        initPoint(&model->masOfPoints[i], newx, newy, newz);
    }
}

void modelMove(myModel* model, double dx, double dy, double dz)
{
    pointMove(&model->center, dx, dy, dz);
}