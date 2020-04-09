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

void drawThrowError(int error)
{
    switch(error)
    {
        case NOFILE:
            std::cout << "No such file" << std::endl;
            break;
        case NOTENOUGHPOINTS:
            std::cout << "Error, while reading points" << std::endl;
            break;

        case ERRORWHILEREADINGEDGES:
            std::cout << "Error, while reading edges" << std::endl;
            break;
        case NOFREESPACE:
            std::cout << "Memory could not be allocated" << std::endl;
            break;
        case OUTOFEDGES:
            std::cout << "Somewhere we are out of edges" << std::endl;
            break;
        case modelNotInited:
            std::cout << "Model not inited" << std::endl;
            break;
        default:
            std::cout << "Unknown error" << std::endl;
            break;

    }
}

void processNormalKeys(unsigned char key, int x, int y) {
    myAction action;
    switch(key)
    {
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
    taskManager(drawMe);
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