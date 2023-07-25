#include "HelloCamerClass.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloCamerClass w;
    w.show();
    return a.exec();
}
