#define GL_SILENCE_DEPRECATION
#include "manager/myManager.h"

using namespace std;


int main(int argc, char **argv)
{
    myOpenglWidnowInit(argc, argv);
    taskManager(modelReadFromFile);
    GLmainLoop();
    return OK;
}
