#include "drawing.h"


void draw_line(myPoint& a, myPoint& b)
{
    glBegin(GL_LINES);
    glColor3f(GLmodelColor);
    glVertex2f(a.x, a.y);
    glVertex2f(b.x, b.y);
    glEnd();
}

void modelDraw(myModel &model)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (model.isInited)
    {
        for (int i = 0; i < model.num_of_points; i++) {
            for (int j = i; j < model.num_of_points; j++) {
                if (matrixGetElement(model.edges, i, j))
                {
                    myPoint a, b;
                    pointCoordinateAddition(model.masOfPointsOffset[i], model.center, a);
                    pointCoordinateAddition(model.masOfPointsOffset[j], model.center, b);
                    draw_line(a, b);
                }
            }
            glEnd();
        }
        glutSwapBuffers();
    }
}

void drawThrowError()
{
    std::cout << "Here will be error!" << std::endl;
}

void processNormalKeys(unsigned char key, int x, int y) {
    myAction action;
    switch(key) {
        case 'w':
            action = modelRotationXNegative;
            break;
        case 's':
            action = modelRotationXPositive;
            break;
        case 'a':
            action = modelRotationYPositive;
            break;
        case 'd':
            action = modelRotationYNegative;
            break;
        case '=':
            action = modelScalePositive;
            break;
        case '-':
            action = modelScaleNegative;
            break;
        case 'o':
            action = modelMoveUp;
            break;
        case 'k':
            action = modelMoveLeft;
            break;
        case 'l':
            action = modelMoveDown;
            break;
        case ';':
            action = modelMoveRight;
            break;
        case '`':
            action = modelReadFromFile;
            break;
        default:
            action = drawMe;
    }
    taskManager(action);
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