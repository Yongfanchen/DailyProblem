#include "HelloBasicLight.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloBasicLight w;
    w.show();
    return a.exec();
}
