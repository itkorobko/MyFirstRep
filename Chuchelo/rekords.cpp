#include "rekords.h"
#include "ui_rekords.h"
#include "spisok_recordov.h"
#include <QFile>
#include <QTextStream>
#include<QString>
#include<QRegularExpression>
#include<iostream>
Rekords::Rekords(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Rekords)
{
    ui->setupUi(this);

    QFile sp("D:/к лабам/Chuchelo/Records.txt");
    sp.open(QIODevice::ReadOnly);

    QTextStream potok(&sp);
    int Seconds[5];
    int Minutes[5];
    int i1=0;
    QString tmp;
    QString username[5];
    while(!potok.atEnd())
    {
        tmp=potok.readLine(0);
        bool fl=false;
          QString tmp1;
        tmp+=" ";

        for(int i=0;i<tmp.size();i++)
        {


              if(tmp[i]!=' ')
                tmp1+=tmp[i];
            else
            {
                bool fl1=false;

                for(int j=0;j<tmp1.size();j++)
                {
                    if(!tmp1[j].isDigit())
                    {
                        fl1=true;
                        break;
                    }
                }
                if(fl1)
                {
                    username[i1]=tmp1;
                    tmp1="";
                }

                else
                {
                    bool ok;
                    if(fl==true)
                    {
                        Seconds[i1]=tmp1.toInt(&ok,10);
                        tmp1="";
                    }

                    else
                    {

                        Minutes[i1]=tmp1.toInt(&ok,10);
                        tmp1="";
                        fl=true;
                    }
                }

            }
        }

        i1++;
    }
    if(i1==0)
        ui->label->setText("");
    else if(i1==1)
    {
        ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
    }
    else if(i1==2)
    {
        ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
        ui->label_2->setText("2."+username[1]+"  "+QString::number(Minutes[1])+":"+QString::number(Seconds[1]));
    }
    else if(i1==3)
    {
        ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
        ui->label_2->setText("2."+username[1]+"  "+QString::number(Minutes[1])+":"+QString::number(Seconds[1]));
        ui->label_3->setText("3."+username[2]+"  "+QString::number(Minutes[2])+":"+QString::number(Seconds[2]));
    }
    else if(i1==4)
    {
        ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
        ui->label_2->setText("2."+username[1]+"  "+QString::number(Minutes[1])+":"+QString::number(Seconds[1]));
        ui->label_3->setText("3."+username[2]+"  "+QString::number(Minutes[2])+":"+QString::number(Seconds[2]));
        ui->label_4->setText("4."+username[3]+"  "+QString::number(Minutes[3])+":"+QString::number(Seconds[3]));
    }
    else if(i1==5)
    {
        ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
        ui->label_2->setText("2."+username[1]+"  "+QString::number(Minutes[1])+":"+QString::number(Seconds[1]));
        ui->label_3->setText("3."+username[2]+"  "+QString::number(Minutes[2])+":"+QString::number(Seconds[2]));
        ui->label_4->setText("4."+username[3]+"  "+QString::number(Minutes[3])+":"+QString::number(Seconds[3]));
        ui->label_5->setText("5."+username[4]+"  "+QString::number(Minutes[4])+":"+QString::number(Seconds[4]));
    }
    sp.close();
}

Rekords::~Rekords()
{
    delete ui;
}
/*void Rekords::addRecord()
{
    QFile sp("D:/к лабам/Chuchelo/Records.txt");
    sp.open(QIODevice::ReadOnly);
    QTextStream potok(&sp);
    int Seconds[5];
    int Minutes[5];
    int i1=0;
    QString tmp;
    QString username[5];
    while(!potok.atEnd())
    {
        tmp=potok.readLine(1);
        bool fl=false;
        for(int i=0;i<tmp.size();i++)
        {
            QString tmp1;
            if(tmp[i]!=' ')
                tmp1+=tmp[i];
            else
            {
                bool fl1=false;

                for(int j=0;j<tmp1.size();j++)
                {
                    if(!tmp1[j].isDigit())
                    {
                        fl1=true;
                        break;
                    }
                }
                if(fl1)
                    username[i1]=tmp1;
                else
                {
                    if(fl==true)
                        Seconds[i1]=tmp1.toInt();

                    else
                    {
                        Minutes[i1]=tmp1.toInt();
                        fl=true;
                    }
                }

            }
        }

        i1++;
    }
    if(i1==1)
    {
        ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
    }
    else if(i1==2)
    {
         ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
        ui->label_2->setText("2."+username[1]+"  "+QString::number(Minutes[1])+":"+QString::number(Seconds[1]));
    }
    else if(i1==3)
    {
        ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
        ui->label_2->setText("2."+username[1]+"  "+QString::number(Minutes[1])+":"+QString::number(Seconds[1]));
        ui->label_3->setText("3."+username[2]+"  "+QString::number(Minutes[2])+":"+QString::number(Seconds[2]));
    }
    else if(i1==4)
    {
        ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
        ui->label_2->setText("2."+username[1]+"  "+QString::number(Minutes[1])+":"+QString::number(Seconds[1]));
        ui->label_3->setText("3."+username[2]+"  "+QString::number(Minutes[2])+":"+QString::number(Seconds[2]));
        ui->label_4->setText("4."+username[3]+"  "+QString::number(Minutes[3])+":"+QString::number(Seconds[3]));
    }
    else if(i1==5)
    {
        ui->label->setText("1."+username[0]+"  "+QString::number(Minutes[0])+":"+QString::number(Seconds[0]));
        ui->label_2->setText("2."+username[1]+"  "+QString::number(Minutes[1])+":"+QString::number(Seconds[1]));
        ui->label_3->setText("3."+username[2]+"  "+QString::number(Minutes[2])+":"+QString::number(Seconds[2]));
        ui->label_4->setText("4."+username[3]+"  "+QString::number(Minutes[3])+":"+QString::number(Seconds[3]));
        ui->label_5->setText("5."+username[5]+"  "+QString::number(Minutes[4])+":"+QString::number(Seconds[4]));
    }
}*/

void Rekords::on_pushButton_clicked()
{
    emit back_to_w3();
    this->close();

}

