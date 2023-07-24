#include "HelloRect.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloRect w;
    w.show();
    return a.exec();
}
