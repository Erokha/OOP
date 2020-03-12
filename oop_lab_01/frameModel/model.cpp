#include "model.h"
#include "../defines.h"
#include "GLUT/glut.h"
#include "../drawing/drawing.h"

int modelInitFromFile(myModel* model)
{
    FILE *f;
    f = fopen("model.txt", "r");

    modelfillPoints(f, model);
    modelfillEdges(f, model);
    modelGetCenter(model);
    modelReCalculatePoints(model);
    return OK;
}

int modelfillPoints(FILE* f, myModel* model)
{
    int n;
    if (f != NULL)
    {
        fscanf(f, "%d", &n);

        model->num_of_points = n;
        model->masOfPoints = new myPoint[n];
        model->rotatedPoints = new myPoint[n];
        model->edges = createMatrix(n);

        for (int i = 0; i < n; i++)
        {
            double x, y, z;
            fscanf(f, "%lf %lf %lf", &x, &y, &z);
            initPoint(&(model->masOfPoints[i]), x, y, z);
            initPoint(&(model->rotatedPoints[i]), x, y, z);
        }
    }
    return OK;
}


int modelfillEdges(FILE* f, myModel* model)
{
    int n;
    if (f != NULL)
    {
        fscanf(f, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            fscanf(f, "%d %d", &a, &b);
            model->edges[a][b] = 1;
            model->edges[b][a] = 1;
        }
    }
    return OK;
}



int** createMatrix(int size)
{
    int** mas = new int*[size];
    for(int i = 0; i < size; i++)
    {
        mas[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            mas[i][j] = 0;
        }
    }
    return mas;
}

int modelDraw(myModel* model)
{
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i = 0; i < model->num_of_points; i++)
    {
        for(int j = i; j < model->num_of_points; j++)
        {
            if (model->edges[i][j])
            {

                draw_line(model->rotatedPoints[i].x, model->rotatedPoints[i].y, model->rotatedPoints[j].x, model->rotatedPoints[j].y);
                //draw_line(&model->rotatedPoints[i], &model->rotatedPoints[j]);
            }
        }
    }
    glEnd();
    //glFlush();
}

void modelFullInfo(myModel* model)
{
    printf("num_of_points: %d\n", model->num_of_points);
    printf("num_of_edges: %d\n", model->num_of_edges);
    for(int i = 0; i < model->num_of_points; i++)
    {
        printf("Point %d: %lf %lf %lf\n", i, model->rotatedPoints[i].x, model->rotatedPoints[i].y, model->rotatedPoints[i].z);
    }
    for(int i = 0; i < model->num_of_points; i++)
    {
        for (int j = 0; j < model->num_of_points; j++) {
            printf("%d ", model->edges[i][j]);
        }
        printf("\n");
    }
    printf("Model center %lf %lf %lf\n", model->center.x, model->center.y, model->center.z);
}

int modelGetCenter(myModel* model)
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
    return OK;
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