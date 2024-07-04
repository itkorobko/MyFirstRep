#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QMainWindow>
#include <w1.h>
#include "w2.h"
#include"w3.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
signals:

private:
    Ui::MainWindow *ui;
    W3* win3;


};
#endif // MAINWINDOW_H

