#include "HelloShader.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloShader w;
    w.show();
    return a.exec();
}
