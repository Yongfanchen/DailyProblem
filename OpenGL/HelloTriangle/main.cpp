#pragma execution_character_set("utf-8")//用来让UI里控件显示中文
#include "HelloTriangle.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloTriangle w;
	w.setWindowTitle("简单三角形 by cyf");
    w.show();
    return a.exec();
}
