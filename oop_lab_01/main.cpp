#include "frameModel/model.h"
#include <curses.h>
#include "GLUT/glut.h"

using namespace std;
myModel m;
const int ROT = 9;

void processNormalKeys(unsigned char key, int x, int y) {
    printf("pressed key %d\n", key);
    switch(key) {
        case 113:
            modelPositiveRotationZ(&m, ROT);
            modelPerformRotate(&m);
            break;
        case 101:
            modelNegativeRotationZ(&m, ROT);
            modelPerformRotate(&m);
            break;
        case 119:
            modelPositiveRotationX(&m, ROT);
            modelPerformRotate(&m);
            break;
        case 115:
            modelNegativeRotationX(&m, ROT);
            modelPerformRotate(&m);
            break;
        case 97:
            modelPositiveRotationY(&m, ROT);
            modelPerformRotate(&m);
            break;
        case 100:
            modelNegativeRotationY(&m, ROT);
            modelPerformRotate(&m);
            break;
        case 32:
            //
            break;
        case 61:
            modelZoom(&m, 2);
            modelFullInfo(&m);
            break;
        case 45:
            modelZoom(&m, 0.5);
            break;
    }


}
void display123()
{

    modelDraw(&m);
    //modelFullInfo(&m);
    //usleep(100000);
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


int main(int argc, char **argv)
{
    modelInitFromFile(&m);
    modelFullInfo(&m);
    openglWidnowInit(argc, argv);
    return OK;
}
