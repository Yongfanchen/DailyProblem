#pragma execution_character_set("utf-8")//������UI��ؼ���ʾ����
#include "HelloTriangle.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloTriangle w;
	w.setWindowTitle("�������� by cyf");
    w.show();
    return a.exec();
}
