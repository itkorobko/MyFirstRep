#include "w2.h"
#include "ui_w2.h"
#include"mainwindow.h"
#include"hranitel.h"
W2::W2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::W2)
{
    ui->setupUi(this);
}

W2::~W2()
{
    delete ui;
}

void W2::on_pushButton_clicked()
{
    Hranitel::pole=1;
    emit back_to_w3();
    this->close();
}


void W2::on_pushButton_2_clicked()
{

    Hranitel::pole=2;
    emit back_to_w3();
    this->close();
}


void W2::on_pushButton_3_clicked()
{


    Hranitel::pole=3;
    emit back_to_w3();
    this->close();
}


void W2::on_pushButton_4_clicked()
{

    Hranitel::pole=4;
    emit back_to_w3();
    this->close();
}


void W2::on_pushButton_5_clicked()
{


    Hranitel::pole=5;
    emit back_to_w3();
    this->close();
}

