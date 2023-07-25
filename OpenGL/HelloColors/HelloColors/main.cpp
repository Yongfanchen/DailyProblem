#include "HelloColors.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloColors w;
    w.show();
    return a.exec();
}
