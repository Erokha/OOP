#include "drawing.h"


myErrors draw_line(myPoint& a, myPoint& b)
{
    glBegin(GL_LINES);
    glColor3f(GLmodelColor);
    glVertex2f(a.x, a.y);
    glVertex2f(b.x, b.y);
    glEnd();
}

myErrors modelDraw(myModel &model)
{
    glClear(GL_COLOR_BUFFER_BIT);
    myErrors error;
    if (model.isInited)
    {
        for (int i = 0; i < model.num_of_points; i++) {
            for (int j = i; j < model.num_of_points; j++) {
                if (matrixGetElement(model.edges, i, j))
                {
                    myPoint a, b;
                    if (pointCoordinateAddition(a, model.masOfPointsOffset[i], model.center) != OK)
                    {
                        return POINTNOTINITED;
                    }
                    if (pointCoordinateAddition(b,model.masOfPointsOffset[j], model.center) != OK)
                    {
                        return POINTNOTINITED;
                    }
                    draw_line(a, b);
                }
            }
            glEnd();
        }
        glutSwapBuffers();
    }
}

myErrors drawThrowError(int error)
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
