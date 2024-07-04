#include "newrecord.h"
#include "spisok_recordov.h"
#include "ui_newrecord.h"

NewRecord::NewRecord(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NewRecord)
{
    ui->setupUi(this);
}

NewRecord::~NewRecord()
{
    delete ui;
}

void NewRecord::on_pushButton_clicked()
{
    QString s;
    s=ui->lineEdit->text();
    spisok_recordov sp;
    sp.read_from_file();
    sp.push(s,m,sec);
    sp.write_in_file();
    close();

}

