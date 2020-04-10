#define GL_SILENCE_DEPRECATION
#include "manager/myManager.h"

using namespace std;


int main(int argc, char **argv)
{
    myOpenglWidnowInit(argc, argv);
    request r{};
    reqSetReadFromFile(r);
    taskManager(r);
    reqSetDrawMe(r);
    taskManager(r);

    GLmainLoop();
    return OK;
}
