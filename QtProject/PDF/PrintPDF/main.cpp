#include "mainwindow.h"

#include <QApplication>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 创建QTextDocument对象，并设置HTML内容
    // QTextDocument document;
    //document.setHtml("<html><body><h1>Hello, World!</h1></body></html>");
    // 创建QTextDocument对象，并加载HTML文件
    QString executablePath = QCoreApplication::applicationDirPath();

    QTextDocument document;
    QFile file(executablePath+"/../html/myFolder/1.1.1.html");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString htmlContent = stream.readAll();
        document.setHtml(htmlContent);
        file.close();
    }
    // 创建QPrinter对象，并设置相关参数
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("output.pdf");

    // 创建QPainter对象，并将其绑定到QPrinter
    QPainter painter;
    if (painter.begin(&printer)) {
        // 绘制QTextDocument内容
        document.drawContents(&painter);
        // 结束绘制
        painter.end();
    }
    // MainWindow w;
    // w.show();
    return a.exec();
}
