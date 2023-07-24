#include "HelloTexture.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloTexture w;
    w.show();
    return a.exec();
}
