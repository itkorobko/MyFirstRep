#include "w3.h"
#include "ui_w3.h"

W3::W3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::W3)
{

    ui->setupUi(this);
}

W3::~W3()
{
    delete ui;
}

void W3::on_pushButton_clicked()
{
    win1=new W1;
    win1->showMaximized();
    this->close();
}


void W3::on_pushButton_2_clicked()
{
    win2=new W2;
    connect(win2, &W2::back_to_w3, this,&W3::show);
    win2->show();
    this->close();
}



void W3::on_pushButton_3_clicked()
{
    rw=new Rekords;
    connect(rw, &Rekords::back_to_w3, this,&W3::show);
    rw->show();
    this->close();
}

