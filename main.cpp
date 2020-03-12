#define GL_SILENCE_DEPRECATION
#include "frameModel/model.h"
#include <iostream>
#include "GLUT/glut.h"
#include "matrix/matrix.h"

using namespace std;
myModel m;
const int ROT = 9;

void openglWidnowInit(int argc, char **argv);
void display123();

int main(int argc, char **argv)
{
    int a = modelInitFromFile(&m);
    if (a != OK)
    {
        cout << "ERROR CORRUPTED, code: " << a;
        return a;
    }
    openglWidnowInit(argc, argv);
    return OK;
}

void processNormalKeys(unsigned char key, int x, int y) {
    switch(key) {
        case 119:
            rotateModelByX(&m, ROT);
            break;
        case 115:
            rotateModelByX(&m, -ROT);
            break;
        case 97:
            rotateModelByY(&m, ROT);
            break;
        case 100:
            rotateModelByY(&m, -ROT);
            break;
        case 61:
            modelZoom(&m, 2);
            modelFullInfo(&m);
            break;
        case 45:
            modelZoom(&m, 0.5);
            break;
        case 111:
            modelMove(&m, 0, 20, 0);
            break;
        case 107:
            modelMove(&m, -20, 0, 0);
            break;
        case 108:
            modelMove(&m, 0, -20, 0);
            break;
        case 59:
            modelMove(&m, 20, 0, 0);
            break;
    }

}

void display123()
{

    modelDraw(&m);
    glutSwapBuffers();
}

void openglWidnowInit(int argc, char **argv)
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
