#include "myGLUT.h"


void processNormalKeys(unsigned char key, int x, int y) {
    request req{};
    myColor color = defaultModelColor;
    switch(key)
    {
        case 'w':
            reqSetRotation(req, ROTANG, xAxis);
            break;
        case 's':
            reqSetRotation(req, -ROTANG, xAxis);
            break;
        case 'a':
            reqSetRotation(req, ROTANG, yAxis);
            break;
        case 'd':
            reqSetRotation(req, -ROTANG, yAxis);
            break;
        case 'q':
            reqSetRotation(req, ROTANG, zAxis);
            break;
        case 'e':
            reqSetRotation(req, -ROTANG, zAxis);
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
            reqSetEnd(req);
            glutDestroyWindow(EXITNORMAL);
            break;
        default:
            reqSetDrawMe(req, color);
    }
    taskManager(req);
    reqSetDrawMe(req, color);
    taskManager(req);
}

void display123(){}


void myOpenglWidnowInit(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(myGLWIDTH, myGLHEIGHT);
    glutCreateWindow("3d frame viewer");


    glClearColor(clear.r, clear.g, clear.b, clear.a);
    myColor color = defaultModelColor;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(GLYFROM, GLYTO, GLXFROM, GLXTO, GLZFROM, GLZTO);

    glutDisplayFunc(display123);
    glutKeyboardFunc(processNormalKeys);
    glutIdleFunc(display123);


    request r;
    reqSetReadFromFile(r, argv[1]);
    taskManager(r);
    reqSetDrawMe(r, color);
    taskManager(r);
}

void GLmainLoop()
{
    glutMainLoop();
}