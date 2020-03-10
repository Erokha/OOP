#include "model.h"
#include "stdio.h"
#include "defines.h"

int readModelFromFile(myModel* model)
{
    FILE *f;
    f = fopen("model.txt", "r");

    fillPoints(f, model);
    fillEdges(f, model);

    return OK;
}

int fillPoints(FILE* f, myModel* model)
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
            int x, y, z;
            fscanf(f, "%d %d %d", &x, &y, &z);
            initPoint(&(model->masOfPoints[i]), x, y, z);
            initPoint(&(model->rotatedPoints[i]), x, y, z);
        }

    }
}


int fillEdges(FILE* f, myModel* model)
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
}


int rotateModelByX(myModel* model, int angle)
{
    for(int i = 0; i < model->num_of_points; i++)
    {
        rotatePointByX(&(model->rotatedPoints[i]), angle);
    }
}

int rotateModelByY(myModel* model, int angle)
{
    for(int i = 0; i < model->num_of_points; i++)
    {
        rotatePointByY(&(model->rotatedPoints[i]), angle);
    }
}

int rotateModelByZ(myModel* model, int angle)
{
    for(int i = 0; i < model->num_of_points; i++)
    {
        rotatePointByZ(&(model->rotatedPoints[i]), angle);
    }
}

int rotateEnd(myModel* model)
{
    for(int j = 0; j < model->num_of_points; j++)
    {
        initPoint(&model->rotatedPoints[j], model->masOfPoints[j].x, model->masOfPoints[j].y, model->masOfPoints[j].z);
    }
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
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);

    for(int i = 0; i < model->num_of_points; i++)
    {
        for(int j = i; j < model->num_of_points; j++)
        {
            if (model->edges[i][j])
            {
                draw_line(&model->rotatedPoints[i], &model->rotatedPoints[j]);
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
        printf("Point %d: %d %d %d\n", i, model->masOfPoints[i].x, model->masOfPoints[i].y, model->masOfPoints[i].z);
    }
    for(int i = 0; i < model->num_of_points; i++)
    {
        for (int j = 0; j < model->num_of_points; j++) {
            printf("%d ", model->edges[i][j]);
        }
        printf("\n");
    }
}