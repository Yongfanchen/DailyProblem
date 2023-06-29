#include "mainwindow.h"

#include <QApplication>
#include <QWebEngineView>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QDir>
#include <QTextDocument>

int main(int argc, char *argv[]) {
    // 指定HTML文件路径和生成的PDF文件路径
        QString htmlFilePath = "/path/to/input.html";
        QString pdfFilePath = "/path/to/output.pdf";

        // 创建应用程序对象
        QApplication app(argc, argv);

        // 创建Web视图和页面对象
        QWebEngineView view;
        QWebEnginePage page;
        view.setPage(&page);

        // 加载HTML文件
        view.setUrl(QUrl::fromLocalFile(htmlFilePath));

        // 等待页面加载完成
        QObject::connect(&view, &QWebEngineView::loadFinished, [&]() {
            // 创建打印机对象
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(pdfFilePath);

            // 打开打印对话框
            QPrintDialog printDialog(&printer);
            if (printDialog.exec() == QDialog::Accepted) {
                // 打印页面到PDF文件
                view.print(&printer);
            }

            // 退出应用程序
            QApplication::quit();
        });

        // 运行应用程序事件循环
        app.exec();
}







