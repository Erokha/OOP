#include "myGLUT.h"

void processNormalKeys(unsigned char key, int x, int y) {
    request req{};
    switch(key)
    {
        case 'w':
            reqSetRotation(req, ROT, xAxis);
            break;
        case 's':
            reqSetRotation(req, -ROT, xAxis);
            break;
        case 'a':
            reqSetRotation(req, ROT, yAxis);
            break;
        case 'd':
            reqSetRotation(req, -ROT, yAxis);
            break;
        case '=':
            reqSetZoom(req, zoomConst);
            break;
        case '-':
            reqSetZoom(req, outZoomConst);
            break;
        case 'o':
            reqSetMove(req, dState, dMovePos, dState);
            break;
        case 'k':
            reqSetMove(req, dMoveNeg, dState, dState);
            break;
        case 'l':
            reqSetMove(req, dState, dMoveNeg, dState);
            break;
        case ';':
            reqSetMove(req, dMovePos, dState, dState);
            break;
        case '`':
            reqSetReadFromFile(req);
            break;
        default:
            reqSetDrawMe(req);
    }
    taskManager(req);
    reqSetDrawMe(req);
    taskManager(req);
}

void display123()
{

    //taskManager(drawMe);
//    glutSwapBuffers();
}


void myOpenglWidnowInit(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(myGLWIDTH, myGLHEIGHT);
    glutCreateWindow("3d frame viewer");



    glClearColor(myGLCLEARCOLOR);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(myGLORTHO);

    glutDisplayFunc(display123);
    glutKeyboardFunc(processNormalKeys);
    glutIdleFunc(display123);
}



void GLmainLoop()
{
    glutMainLoop();
}