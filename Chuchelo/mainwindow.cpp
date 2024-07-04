#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "w1.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    win3=new W3;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    win3->show();
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

