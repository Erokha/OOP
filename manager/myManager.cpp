#include "myManager.h"
#include <iostream>


using namespace std;

myModel mod;

void modelDraw(myModel& model)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (model.isInited) {
        for (int i = 0; i < model.num_of_points; i++) {
            for (int j = i; j < model.num_of_points; j++) {
                if (model.edges.mas[i][j]) {
                    double x1, y1, x2, y2;
                    x1 = getPointX(model.masOfPoints[i]) + getPointX(model.center);
                    y1 = getPointY(model.masOfPoints[i]) + getPointY(model.center);
                    x2 = getPointX(model.masOfPoints[j]) + getPointX(model.center);
                    y2 = getPointY(model.masOfPoints[j]) + getPointY(model.center);
                    draw_line(x1, y1, x2, y2);
                }
            }
        }
        glEnd();
    }
}


void processNormalKeys(unsigned char key, int x, int y) {
    switch(key) {
        case 'w':
            rotateModelByX(mod, ROT);
            break;
        case 's':
            rotateModelByX(mod, -ROT);
            break;
        case 'a':
            rotateModelByY(mod, ROT);
            break;
        case 'd':
            rotateModelByY(mod, -ROT);
            break;
        case '=':
            modelZoom(mod, 2);
            break;
        case '-':
            break;
        case 'o':
            modelMove(mod, 0, 20, 0);
            break;
        case 'k':
            modelMove(mod, -20, 0, 0);
            break;
        case 'l':
            modelMove(mod, 0, -20, 0);
            break;
        case ';':
            modelMove(mod, 20, 0, 0);
            break;
        case '`':
            freeMyMemory(mod);
            int a = modelInitFromFile(mod);
            break;
    }

}

void display123()
{
    modelDraw(mod);
    glutSwapBuffers();
}


void myOpenglWidnowInit(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutCreateWindow("3d frame viewer");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200.0, 200.0, -200.0, 200.0, -200.0, 200.0);

    glutDisplayFunc(display123);
    glutKeyboardFunc(processNormalKeys);
    glutIdleFunc(display123);

    glutMainLoop();
}

int taskManager(int argc, char **argv)
{
    int a = modelInitFromFile(mod);
    if (a != OK)
    {
        cout << "ERROR CORRUPTED, code: " << a;
        return a;
    }
    myOpenglWidnowInit(argc, argv);
    freeMyMemory(mod);
    return OK;
}

