#include "mainwindow.h"
#include "qpushbutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton* btn = new QPushButton(this);
    btn->setText(QString("你好"));
    btn->show();
}

MainWindow::~MainWindow() = default;
