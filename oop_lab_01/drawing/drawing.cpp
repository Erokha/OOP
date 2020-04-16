#include "drawing.h"
#include "GLUT/glut.h"



myErrors drawLine(myPoint& a, myPoint& b, myColor& color)
{
    glBegin(GL_LINES);
    glColor3f(color.r, color.g, color.b);
    glVertex2f(a.x, a.y);
    glVertex2f(b.x, b.y);
    glEnd();
    return OK;
}

myErrors GLShow()
{
    glutSwapBuffers();
    return OK;
}

myErrors GLEnd()
{
    glEnd();
    return OK;
}

myErrors GLErase()
{
    glClear(GL_COLOR_BUFFER_BIT);
    return OK;
}


myErrors showError(int error)
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
