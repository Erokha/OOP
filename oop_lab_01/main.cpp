#define GL_SILENCE_DEPRECATION
#include "glutWindow/myGLUT.h"

using namespace std;


int main(int argc, char **argv)
{
    myOpenglWidnowInit(argc, argv);
    GLmainLoop();
    return OK;
}
