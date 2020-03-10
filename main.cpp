#include "point.h"
#include "model.h"
#include "defines.h"
#include <iostream>
#include <unistd.h>
#include <curses.h>


using namespace std;
myModel m;
int xRotation = 0;
int yRotation = 0;
int zRotation = 0;
const int ROT = 9;

void processNormalKeys(unsigned char key, int x, int y) {
    printf("%d ", xRotation);
    printf("%d ", yRotation);
    printf("%d\n", zRotation);

    switch(key) {
        case 113:
            zRotation+= ROT;
            zRotation %= 360;
            break;
        case 101:
            zRotation-= ROT;
            zRotation %= 360;
            break;
        case 119:
            xRotation+= ROT;
            zRotation %= 360;
            break;
        case 115:
            xRotation-= ROT;
            zRotation %= 360;
            break;
        case 97:
            yRotation+= ROT;
            zRotation %= 360;
            break;
        case 100:
            yRotation-= ROT;
            zRotation %= 360;
            break;
        case 32:
            xRotation = 0;
            yRotation = 0;
            zRotation = 0;
    }

}
void display123()
{
    rotateEnd(&m);
    rotateModelByX(&m, xRotation);
    rotateModelByY(&m, yRotation);
    rotateModelByZ(&m, zRotation);
    modelDraw(&m);
    //modelFullInfo(&m);
    usleep(100000);
    glutSwapBuffers();
}


int main(int argc, char **argv)
{
    readModelFromFile(&m);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(100, 740);
    glutCreateWindow("First window!");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200, 200, -200, 200, -200, 200);

    glutDisplayFunc(display123);
    glutKeyboardFunc(processNormalKeys);
    glutIdleFunc(display123);

    glutMainLoop();
    return OK;
}
