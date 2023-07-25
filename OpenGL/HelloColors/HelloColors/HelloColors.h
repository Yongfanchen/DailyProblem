#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HelloColors.h"

class HelloColors : public QMainWindow
{
    Q_OBJECT

public:
    HelloColors(QWidget *parent = Q_NULLPTR);

private:
    Ui::HelloColorsClass ui;
};
