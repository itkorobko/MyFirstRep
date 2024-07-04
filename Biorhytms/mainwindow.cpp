#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <math.h>
#include <QDebug>
#include <windows.h>

int days = 0;
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

QTimer *timer = new QTimer;
connect(timer, SIGNAL(timeout()), this, SLOT(update()));
timer->start(10);
ui->setupUi(this);
ui->current_date->setDate(QDate::currentDate()); // сразу установим текущую дату
ui->birthday_date->setDate(QDate::currentDate());
}
MainWindow::~MainWindow()
{
delete ui;
}
void MainWindow::paintEvent(QPaintEvent* )
{
days = (ui->current_date->date().toJulianDay() - ui->birthday_date->date().toJulianDay());
ui->livedays->setText("Количество прожитых дней: " + QString::number(days));
QPainter painter;
painter.begin(this);
painter.setRenderHint(QPainter::Antialiasing, true);
//QPoint pos = QCursor::pos(); //позиция курсора
//QPoint pos2 = this->pos(); //позиция окна
//int diffx = pos.x()-pos2.x();
//painter.drawLine(diffx, 0,diffx ,height()); // отнимая от положения курсора положение
//окна будем рисовать вертикальную линию
//diffx -= width()/2;
//ui->result_label->setText("Физиологический:\t"
//+QString::number(sin(-diffx*M_PI/23/15)*100) +
//"\nПсихологический:\t" +
//QString::number(sin(-diffx*M_PI/28/15)*100) +
//"\nУмственный:\t\t" +
//QString::number(sin(-diffx*M_PI/33/15)*100));
painter.translate(width()/2,height()/2 + 50); // перенесем начало координат
painter.drawLine(-width(),0,width(),0); // ось
QPoint point;
painter.save();
ui->result_label->setText("Физиологический:\t"
                          +QString::number(sin(days*2*M_PI/23)*100) +
                          "\nПсихологический:\t" +
                          QString::number(sin(days*2*M_PI/28)*100) +
                          "\nУмственный:\t\t" +
                          QString::number(sin(days*2*M_PI/33)*100));
for(double j = -width()/60, i = -width() / 60; i < width() / 60; i += 0.01){ // будем
//растягивать ось Х в 30 раз поэтому делим на 30 значения
j += 0.01;
point.setX(j*30);
QPen linepen(Qt::red);
linepen.setWidth(3);
painter.setPen(linepen);
point.setY(sin(-(i+days)*2*M_PI/23)*100);
painter.drawPoint(point);
linepen.setColor(Qt::blue);
painter.setPen(linepen);
point.setY(sin(-(i+days)*2*M_PI/28)*100);
painter.drawPoint(point);
linepen.setColor(QColor(64,38,52));
painter.setPen(linepen);
point.setY(sin(-(i+days)*2*M_PI/33)*100);
painter.drawPoint(point);
}
painter.restore();
for (int j=-width()/60; j <= width()/60; j++){
if(j == 0){
painter.save();
QPen linepen(Qt::black);
linepen.setWidth(3);
painter.setPen(linepen);
QFont font = painter.font();
font.setPointSize(10);
painter.setFont(font);
painter.drawLine(j*30,-20, j*30,20);
painter.rotate(90);
QString date= ui->current_date->date().addDays(-j).toString();
painter.drawText(10, j*30, date);
painter.restore();
}
else{
painter.drawLine(j*30,-10, j*30,10);
painter.save();
painter.rotate(90);
QString date= ui->current_date->date().addDays(-j).toString();
painter.drawText(10, j*30, date);
painter.restore();
}
}
painter.end();
//update();
}
void MainWindow::on_action_triggered()
{
QApplication::quit();
}
void MainWindow::on_action_2_triggered()
{
QMessageBox::about(this, "О программе", "Эта программа считает биоритмы. Жизнь человека, как и все в природе, подвержено влиянию циклических изменений. Успешность того или иного вида деятельности в каждый момент времени определяется балансом притока и оттока его внутренней энергии. Такой баланс изменяется в соответствии с циклами биоритмов человека");
}
