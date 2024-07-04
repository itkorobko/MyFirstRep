#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    fileName = QFileDialog::getOpenFileName(this,"Выбор файла", "C:/", "*.txt  ;;  *.bin");
    QFile myFile(fileName);
    if (!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
        QByteArray a;
     if(fileName[fileName.size()-1]=='t')
        a=myFile.readAll();
     else
     {
         QDataStream potok(&myFile);
         while(!potok.atEnd())
            potok>>a;
     }
        ui->textEdit->setText(QString(a));
     myFile.close();
}


void MainWindow::on_action_2_triggered()
{


    QFile myFile(fileName);
    if(!myFile.exists())
        this->on_action_3_triggered();
    if (!myFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QByteArray strByteArray = ui->textEdit->toPlainText().toUtf8();
    if(fileName[fileName.size()-1]=='t')
        myFile.write(strByteArray);
    else
    {
        QDataStream potok(&myFile);
        potok<<strByteArray;
    }
    myFile.close();
}


void MainWindow::on_action_3_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "/newDoc.txt", tr("myDoc (*.txt);;myDoc (*.bin)"));
    if(!fileName.isEmpty())
    {    QFile myFile(fileName);
        if(!myFile.exists())
        {
            if (!myFile.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
            QByteArray strByteArray = ui->textEdit->toPlainText().toUtf8();
             if(fileName[fileName.size()-1]=='t')
                myFile.write(strByteArray);
             else
             {
                 QDataStream potok(&myFile);
                 potok<<strByteArray;
             }
            myFile.close();
        }
    }
}


void MainWindow::on_action_4_triggered()
{
    this->on_action_3_triggered();

}



