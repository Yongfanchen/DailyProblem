#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lsreader.h"

class lsreader : public QMainWindow
{
    Q_OBJECT

public:
    lsreader(QWidget *parent = Q_NULLPTR);

private:
    Ui::lsreaderClass ui;
};
